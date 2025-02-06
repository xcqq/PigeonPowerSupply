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
    bool buzzer;
    int brightness;
    float current_limit;
    float voltage_limit;
    int power_limit;
    int temperature_limit;
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

enum key_state { 
    KEY_PRESSING,     // Key is being pressed
    KEY_PRESSED,      // Short press released
    KEY_LONG_PRESSED, // Long press released 
    KEY_RELEASED      // No key pressed
};

// Define key positions using bitmap
struct KeyBitmap {
    static const uint8_t HMI_1 = 0;  // bit 0
    static const uint8_t HMI_2 = 1;  // bit 1
    static const uint8_t HMI_S = 2;  // bit 2
    static const uint8_t M5_A  = 3;  // bit 3
    static const uint8_t M5_B  = 4;  // bit 4
    static const uint8_t M5_C  = 5;  // bit 5
};

// Use inline function to generate key codes
constexpr uint8_t KEY_BIT(uint8_t pos) { return 1 << pos; }

// Define individual key codes
enum key_code {
    KEY_NONE = 0,
    KEY_HMI_1 = KEY_BIT(KeyBitmap::HMI_1),    // 0b000001
    KEY_HMI_2 = KEY_BIT(KeyBitmap::HMI_2),    // 0b000010
    KEY_HMI_S = KEY_BIT(KeyBitmap::HMI_S),    // 0b000100
    KEY_M5_A  = KEY_BIT(KeyBitmap::M5_A),     // 0b001000
    KEY_M5_B  = KEY_BIT(KeyBitmap::M5_B),     // 0b010000
    KEY_M5_C  = KEY_BIT(KeyBitmap::M5_C)      // 0b100000
};

static const char* const CONFIG_FILE_DEFAULT = "/default_config.json";
static const char* const CONFIG_FILE_USER = "/user_config.json";

class io_service
{
private:
    static const uint16_t _beep_tone[3];
    static const uint16_t _beep_duration[3];

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

    static const uint32_t LONG_PRESSED_TIME = 500;  // Long press detection time (ms)
    static const uint32_t COMBO_KEY_TIMEOUT = 100;   // Combo key detection timeout (ms)
    uint8_t _current_keys = KEY_NONE;                // Currently pressed keys
    uint8_t _last_keys = KEY_NONE;                   // Previous key state
    TickType_t _key_press_time = 0;                  // Key press timestamp
    
    // Helper function: Check if specified bit is set
    inline bool is_key_set(uint8_t keys, uint8_t pos) {
        return (keys & KEY_BIT(pos)) != 0;
    }

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
  JsonDocument& get_config_json(void);
  void set_brightness(int brightness);
  void set_buzzer(bool buzzer);
  void set_current_limit(float current_limit);
  void set_voltage_limit(float voltage_limit);
  void set_power_limit(int power_limit);
  void set_temperature_limit(int temperature_limit);
  struct power_module_settings get_power_module_settings(void);

  key_state get_key_state(uint8_t &keys);

  float get_max_current(void);
  float get_max_voltage(void);
  int get_power_limit(void);
  int get_temperature_limit(void);
  int get_refresh_rate(void);
  const char* get_language(void);
};
#endif
