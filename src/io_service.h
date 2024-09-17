#ifndef IO_SERVICE_H
#define IO_SERVICE_H

#include "M5Module-PPS/M5ModulePPS.h"
#include "M5Unit-HMI/MODULE_HMI.h"

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

class io_service
{
private:
    struct power_module_status _power_module_status;
    struct hmi_module_status _hmi_module_status;
    struct power_module_settings _power_module_settings;
    bool _hmi_reset_flag = false;
    bool _power_set_flag = false;
    M5ModulePPS _pps;
    MODULE_HMI _hmi;
    void power_module_sync(void);
    void hmi_module_sync(void);

public:
  io_service();
  ~io_service();


  void IRAM_ATTR setup();
  void IRAM_ATTR loop();
  struct power_module_status get_power_module_status() { return _power_module_status; }
  void set_power_module_status(struct power_module_settings);
  struct hmi_module_status get_hmi_module_status();
};
#endif