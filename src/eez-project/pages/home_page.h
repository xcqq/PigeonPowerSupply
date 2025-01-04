#pragma once

#include "page.h"
#include <ArduinoJson.h>

class HomePage : public Page {
private:
    power_module_settings power_settings;
    JsonArray recall_settings;
    bool recall_list_open = false;
    lv_group_t* recall_group;
    lv_obj_t* recall_list;

    void update_settings(float set_volt, float set_curr);
    void toggle_output();
    void set_voltage_mode(bool is_voltage, hmi_module_settings& hmi_settings);
    void adjust_step_size();
    void update_status_variables();
    int float_to_int_rounded(float value, float scale);
    void toggle_voltage_current_mode(hmi_module_settings& hmi_settings);
    void adjust_output(int direction);
    float adjust_value(float value, float min, float max);
    void add_recall_setting(float set_volt, float set_curr);
    void load_recall_settings_list(lv_obj_t* list);

public:
    static const std::string PAGE_NAME;
    int getScreenId() const override { return SCREEN_ID_HOME_PAGE; }
    
    HomePage(UserActions& user_actions, io_service& io)
        : Page(user_actions, io) {}
        
    void onInit() override;
    void onEnter() override;
    void update() override;
    void handle_short_press(uint8_t keys) override;
    void handle_long_press(uint8_t keys) override;
    void handle_encoder(const hmi_module_status& hmi_status) override;
}; 