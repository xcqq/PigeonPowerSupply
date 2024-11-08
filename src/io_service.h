#ifndef IO_SERVICE_H
#define IO_SERVICE_H

#include "M5Module-PPS/M5ModulePPS.h"
#include "M5Unit-HMI/MODULE_HMI.h"
#include "LittleFS.h"
#include "ArduinoJson.h"

struct power_module_status {
    float set_volt;
    float set_curr;
    float out_volt;
    float out_curr;
    int enable_flag;
    float temperature;
    int cc_cv_flag;
    float in_volt;
};

struct power_module_settings {
    float set_volt;
    float set_curr;
    bool enable_flag;
};

struct hmi_module_status {
    bool button_s;
    bool button_1;
    bool button_2;
    int32_t encoder_inc_raw;
    int32_t encoder_inc;
};

struct hmi_module_settings {
    bool led_1;
    bool led_2;
};

enum buzzer_tone {
    BUZZER_TONE_LOW = 0,
    BUZZER_TONE_MID,
    BUZZER_TONE_HIGH,
};

enum buzzer_duration {
    BUZZER_DURATION_SHORT = 0,
    BUZZER_DURATION_MID,
    BUZZER_DURATION_LONG,
};

class io_service
{
private:
    static const uint16_t _beep_tone[3];
    static const uint16_t _beep_duration[3];
    static const constexpr char DRAM_ATTR *_config_file_name = "/config.json";

    struct power_module_status _power_module_status;
    struct hmi_module_status _hmi_module_status;
    struct power_module_settings _power_module_settings;
    struct hmi_module_settings _hmi_module_settings;
    bool _hmi_reset_flag = false;
    bool _hmi_set_flag = false;
    bool _power_set_flag = false;
    bool _config_update_flag = false;
    M5ModulePPS _pps;
    MODULE_HMI _hmi;
    fs::LittleFSFS _fs;
    File _config_file;
    JsonDocument _config_json;
    void IRAM_ATTR power_module_sync(void);
    void IRAM_ATTR hmi_module_sync(void);
    int IRAM_ATTR read_config_file(void);
    int IRAM_ATTR save_config_file(void);
    int IRAM_ATTR init_config_file(void);

public : io_service();
  ~io_service();


  void ICACHE_FLASH_ATTR setup();
  void IRAM_ATTR loop();
  struct power_module_status get_power_module_status() { return _power_module_status; }
  void set_power_module_status(struct power_module_settings);
  struct hmi_module_status get_hmi_module_status();
  void set_hmi_module_status(struct hmi_module_settings);
  void set_buzzer_beep(enum buzzer_tone tone, enum buzzer_duration duration);
  void IRAM_ATTR save_config(void);
};
#endif