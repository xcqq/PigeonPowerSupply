#include <Arduino.h>
#include "M5Module-PPS/M5ModulePPS.h"
#include "io_service.h"
#include "config.h"
#include "M5Stack.h"

io_service::io_service() {}
io_service::~io_service() {}

void IRAM_ATTR io_service::power_module_sync(void) {
    _power_module_status.set_volt = _pps.getOutputVoltage();
    _power_module_status.set_curr = _pps.getOutputCurrent();
    _power_module_status.out_volt = _pps.getReadbackVoltage();
    _power_module_status.out_curr = _pps.getReadbackCurrent();
    _power_module_status.cc_cv_flag = _pps.getMode();
    _power_module_status.enable_flag = _pps.getPowerEnable();
    _power_module_status.temperature = _pps.getTemperature();
    _power_module_status.in_volt = _pps.getVIN();
    if (_power_set_flag) {
        _pps.setOutputVoltage(_power_module_settings.set_volt);
        _pps.setOutputCurrent(_power_module_settings.set_curr);
        _pps.setPowerEnable(_power_module_settings.enable_flag);
        _power_set_flag = false;
    }
#ifdef _DEBUG_
    Serial.printf("Power module sync:\n");
    Serial.printf("set volt:%.3f\n", _power_module_status.set_volt);
    Serial.printf("set curr:%.3f\n", _power_module_status.set_curr);
    Serial.printf("out volt:%.3f\n", _power_module_status.out_volt);
    Serial.printf("out curr:%.3f\n", _power_module_status.out_curr);
    Serial.printf("cc/cv flag:%d\n", _power_module_status.cc_cv_flag);
    Serial.printf("enable flag:%d\n", _power_module_status.enable_flag);
    Serial.printf("temperature:%f\n", _power_module_status.temperature);
    Serial.printf("in volt:%f\n", _power_module_status.in_volt);
#endif
}

void IRAM_ATTR io_service::hmi_module_sync(void) {
    int encoder_inc = _hmi.getIncrementValue();
    _hmi_module_status.button_1 = _hmi.getButton1();
    _hmi_module_status.button_2 = _hmi.getButton2();
    _hmi_module_status.button_s = _hmi.getButtonS();
    _hmi_module_status.encoder_inc_raw += encoder_inc;
    if(_hmi_set_flag){
        _hmi.setLEDStatus(0, _hmi_module_settings.led_1);
        _hmi.setLEDStatus(1, _hmi_module_settings.led_2);
        _hmi_set_flag = false;
    }
#ifdef _DEBUG_
    Serial.printf("Power module sync:\n");
    Serial.printf("btn1:%d btn2:%d btns:%d\n", _hmi_module_status.button_1,
                  _hmi_module_status.button_2, _hmi_module_status.button_s);
    Serial.printf("encoder inc:%d\n", _hmi_module_status.encoder_inc_raw);
#endif
}

struct hmi_module_status IRAM_ATTR io_service::get_hmi_module_status(void) {
    struct hmi_module_status status;
    _hmi_module_status.encoder_inc = _hmi_module_status.encoder_inc_raw / 4;
    status = _hmi_module_status;
    _hmi_module_status.encoder_inc_raw %= 4;
    return status;
}

void IRAM_ATTR io_service::set_power_module_status(struct power_module_settings settings) {
    _power_module_settings = settings;
    _power_set_flag = true;
}

void IRAM_ATTR io_service::set_hmi_module_status(struct hmi_module_settings settings){
    _hmi_module_settings = settings;
    _hmi_set_flag = true;
}

int IRAM_ATTR io_service::read_config_file(void)
{
    _config_file = _fs.open(_config_file_name, FILE_READ);
    if (!_config_file){
        _config_file.close();
        return -1;
    }
    DeserializationError ret = deserializeJson(_config_json, _config_file);
    if(ret) {
        _config_file.close();
        return -1;
    }

    _config_file.close();
    return 0;
}

int IRAM_ATTR io_service::save_config_file(void)
{
    Serial.println("start open config");
    _config_file = _fs.open(_config_file_name, FILE_WRITE);
    if (!_config_file){
        _config_file.close();
        return -1;
    }
    serializeJson(_config_json, _config_file);
    Serial.println("end save config");
    Serial.printf("Set voltage:%f Set current:%f\n", _power_module_settings.set_volt, _power_module_settings.set_curr);
    _config_file.close();

    return 0;
}

int IRAM_ATTR io_service::init_config_file(void)
{
    _config_file = _fs.open(_config_file_name, FILE_WRITE);
    if (!_config_file){
        return -1;
    }
    _config_json.clear();
    _config_json["version"] = VERSION;
    serializeJson(_config_json, _config_file);
    _config_file.close();

    return 0;

}

const uint16_t io_service::_beep_tone[3] = {4000, 6000, 8000};
const uint16_t io_service::_beep_duration[3] = {15, 100, 500};

void IRAM_ATTR io_service::set_buzzer_beep(enum buzzer_tone tone, enum buzzer_duration duration) {
    M5.Speaker.tone(_beep_tone[tone], _beep_duration[duration]);
}

void IRAM_ATTR io_service::save_config(void)
{
    _config_update_flag = true;
    if (_config_update_flag){
        _config_json["set_volt"] = _power_module_settings.set_volt;
        _config_json["set_curr"] = _power_module_settings.set_curr;
        save_config_file();
        _config_update_flag = false;
    }
}

void IRAM_ATTR io_service::setup()
{
    Serial.begin(115200);

    Serial.printf("==========Init power module==========\n");
    uint32_t uid[3];
    while (!_pps.begin(&Wire, SDA, SCL, MODULE_POWER_ADDR, I2C_SPEED)) {
        Serial.println("module pps connect error");
        delay(100);
    }
    _pps.begin(&Wire, SDA, SCL, MODULE_POWER_ADDR, I2C_SPEED);
    _pps.setOutputVoltage(0.0);
    _pps.setOutputCurrent(0.0);
    _pps.setPowerEnable(false);
    _pps.getUID(&uid[0], &uid[1], &uid[2]);
    Serial.printf("Power module UID:0x%x%x%x\n", uid[0],uid[1],uid[2]);
    Serial.printf("====================\n");

    Serial.printf("==========Init hmi module==========\n");
    while (!_hmi.begin(&Wire, HMI_ADDR, SDA, SCL, I2C_SPEED)) {
        Serial.println("module hmi connect error");
        delay(100);
    }
    _hmi.begin(&Wire, HMI_ADDR, SDA, SCL, I2C_SPEED);
    _hmi.resetCounter();
    Serial.printf("====================\n");

    Serial.printf("==========Init SPIFFS==========\n");
    if (!_fs.begin(true)) {
        Serial.println("SPIFFS failed to init. Formatting......");
        if (!_fs.format()) {
            while (1) {
                Serial.println("SPIFFS format failed");
                delay(1000);
            }
        }
    }
    Serial.printf("Total size:%x Used size:%x\n", _fs.totalBytes(), _fs.usedBytes());
    if (read_config_file()) {
        Serial.println(F("Config file read failed"));
        init_config_file();
        /* initialized and retry */
        if (read_config_file()) {
            while (1) {
                Serial.println(F("Initialize config file failed"));
                delay(1000);
            }
        }
    }
    if (strcmp(VERSION, _config_json["version"])) {
        Serial.println("Config version missmatched, initialize the config");
        init_config_file();
        if (read_config_file()) {
            while (1) {
                Serial.println(F("Initialize config file failed"));
                delay(1000);
            }
        }
    } else {
        Serial.printf("Reading config file, version:%s\n", (const char *)_config_json["version"]);
    }

    /* update to settings */
    _power_module_settings.set_volt = _config_json["set_volt"] | 0.0;
    _power_module_settings.set_curr = _config_json["set_curr"] | 0.0;

    set_power_module_status(_power_module_settings);

    Serial.printf("====================\n");

    M5.Speaker.begin();
    M5.Speaker.mute();
}

void IRAM_ATTR io_service::loop()
{
    power_module_sync();
    hmi_module_sync();
}
