#pragma once

#include "page.h"

class HomePage : public Page {
private:
    power_module_settings power_settings;
    
    void update_settings(float set_volt, float set_curr);
    void toggle_output();
    void set_voltage_mode(bool is_voltage, hmi_module_settings& hmi_settings);
    void adjust_step_size();
    void update_status_variables();
    int float_to_int_rounded(float value, float scale);
    void toggle_voltage_current_mode(hmi_module_settings& hmi_settings);
    void adjust_output(int direction);
    float adjust_value(float value, float min, float max);

public:
    HomePage(io_service& io_service)
        : Page(io_service) {}
        
    void init() override;
    void update() override;
    void handle_short_press(uint8_t keys) override;
    void handle_long_press(uint8_t keys) override;
    void handle_encoder(const hmi_module_status& hmi_status) override;
}; 