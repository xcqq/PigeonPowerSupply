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
    Serial.printf("Power module sync:\n");
    Serial.printf("set volt:%.3f\n", _power_module_status.set_volt);
    Serial.printf("set curr:%.3f\n", _power_module_status.set_curr);
    Serial.printf("out volt:%.3f\n", _power_module_status.out_volt);
    Serial.printf("out curr:%.3f\n", _power_module_status.out_curr);
    Serial.printf("cc/cv flag:%d\n", _power_module_status.cc_cv_flag);
    Serial.printf("enable flag:%d\n", _power_module_status.enable_flag);
    Serial.printf("temperature:%f\n", _power_module_status.temperature);
    Serial.printf("in volt:%f\n", _power_module_status.in_volt);
    if (_power_set_flag) {
        _pps.setOutputVoltage(_power_module_settings.set_volt);
        _pps.setOutputCurrent(_power_module_settings.set_curr);
        _pps.setPowerEnable(_power_module_settings.enable_flag);
        _power_set_flag = false;
    }
}

void IRAM_ATTR io_service::hmi_module_sync(void) {
    int encoder_inc = _hmi.getIncrementValue();
    _hmi_module_status.button_1 = _hmi.getButton1();
    _hmi_module_status.button_2 = _hmi.getButton2();
    _hmi_module_status.button_s = _hmi.getButtonS();
    _hmi_module_status.encoder_inc_raw += encoder_inc;
    Serial.printf("Power module sync:\n");
    Serial.printf("btn1:%d btn2:%d btns:%d\n", _hmi_module_status.button_1,
                  _hmi_module_status.button_2, _hmi_module_status.button_s);
    Serial.printf("encoder inc:%d\n", _hmi_module_status.encoder_inc_raw);
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

void IRAM_ATTR io_service::setup()
{
    Serial.begin(115200);
    Serial.printf("==========Init power module==========\n");
    uint32_t uid[3];
    while (!_pps.begin(&Wire, 21, 22, MODULE_POWER_ADDR, 100000U)) {
        Serial.println("module pps connect error");
        delay(100);
    }
    _pps.setOutputVoltage(0.0);
    _pps.setOutputCurrent(0.0);
    _pps.setPowerEnable(false);
    _pps.getUID(&uid[0], &uid[1], &uid[2]);
    Serial.printf("Power module UID:0x%x%x%x\n", uid[0],uid[1],uid[2]);
    Serial.printf("====================\n");
    Serial.printf("==========Init hmi module==========\n");
    while (!_hmi.begin(&Wire)) {
        Serial.println("module hmi connect error");
        delay(100);
    }
    _hmi.resetCounter();
    Serial.printf("====================\n");
    M5.Speaker.begin();
    M5.Speaker.mute();

} // end io setup

void IRAM_ATTR io_service::loop()
{
    power_module_sync();
    hmi_module_sync();
    // delay(100);
} // end loop
