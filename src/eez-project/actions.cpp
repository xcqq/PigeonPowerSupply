#include <lvgl.h>

#include "M5Stack.h"
#include "actions.h"
#include "io_service.h"
#include "screens.h"
#include "structs.h"
#include "ui.h"
#include "vars.h"

// Power Supply Control Class
class PowerSupply {
private:
    static const constexpr float SET_CURR_MAX = 5.0;  // Maximum current setting 5A 
    static const constexpr float SET_VOLT_MAX = 30.0; // Maximum voltage setting 30V
    
    io_service& io;
    power_module_settings power_settings;

    // Handle encoder input
    void handle_encoder(const hmi_module_status& hmi_status) {
        if (!hmi_status.encoder_inc) return;

        float set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt() / 1000.0;
        int vc_sel_flag = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG).getInt();
        float set_curr = power_settings.set_curr;
        float set_volt = power_settings.set_volt;

        if (vc_sel_flag == 0) {
            set_curr = adjust_value(set_curr + set_step * hmi_status.encoder_inc, 0, SET_CURR_MAX);
        } else {
            set_volt = adjust_value(set_volt + set_step * hmi_status.encoder_inc, 0, SET_VOLT_MAX);
        }

        update_settings(set_volt, set_curr);
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
    }

    // Handle short press
    void handle_short_press(uint8_t keys) {
        struct hmi_module_settings hmi_settings = {0};
        
        switch (keys) {
            case KEY_HMI_1:
                set_voltage_mode(true, hmi_settings);
                break;

            case KEY_HMI_2:
                set_voltage_mode(false, hmi_settings);
                break;

            case KEY_HMI_S:
            case KEY_M5_C:
                adjust_step_size();
                break;

            case KEY_M5_A:
                adjust_output(-1);
                break;

            case KEY_M5_B:
                adjust_output(1);
                break;
        }
    }

    // Handle long press
    void handle_long_press(uint8_t keys) {
        struct hmi_module_settings hmi_settings = {0};
        
        switch (keys) {
            case KEY_M5_C:
                toggle_output();
                break;

            case KEY_M5_A:
            case KEY_M5_B:
                toggle_voltage_current_mode(hmi_settings);
                break;
        }
    }

    // Helper functions
    float adjust_value(float value, float min, float max) {
        return clamp(value, min, max);
    }

    void update_settings(float set_volt, float set_curr) {
        power_settings.set_volt = set_volt;
        power_settings.set_curr = set_curr;
        io.set_power_module_status(power_settings);
    }

    void set_voltage_mode(bool is_voltage, hmi_module_settings& hmi_settings) {
        flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG, IntegerValue(is_voltage));
        if (is_voltage) hmi_settings.led_1 = true;
        else hmi_settings.led_2 = true;
        io.set_hmi_module_status(hmi_settings);
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
    }

    void adjust_step_size() {
        int set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt();
        set_step *= 10;
        if (set_step > 1000) set_step = 1;
        flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP, IntegerValue(set_step));
        io.set_power_module_status(power_settings);
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
    }

    void adjust_output(int direction) {
        float set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt() / 1000.0;
        int vc_sel_flag = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG).getInt();
        float set_curr = power_settings.set_curr;
        float set_volt = power_settings.set_volt;
        
        if (vc_sel_flag == 0) {
            set_curr = adjust_value(set_curr + direction * set_step, 0, SET_CURR_MAX);
        } else {
            set_volt = adjust_value(set_volt + direction * set_step, 0, SET_VOLT_MAX);
        }
        
        update_settings(set_volt, set_curr);
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
    }

    void toggle_output() {
        power_settings.enable_flag = !power_settings.enable_flag;
        io.set_power_module_status(power_settings);
        io.set_buzzer_beep(BUZZER_TONE_MID, BUZZER_DURATION_MID);
        io.save_config();
    }

    void toggle_voltage_current_mode(hmi_module_settings& hmi_settings) {
        int vs_sel_flag = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG).getInt();
        vs_sel_flag = !vs_sel_flag;
        flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG, IntegerValue(vs_sel_flag));
        if (vs_sel_flag) hmi_settings.led_1 = true;
        else hmi_settings.led_2 = true;
        io.set_hmi_module_status(hmi_settings);
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
    }

    int float_to_int_rounded(float value, float scale) {
        return static_cast<int>(value * scale + 0.5f);
    }

    void update_status_variables() {
        power_module_status power_status = io.get_power_module_status();
        
        flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_OUT_VOLT,
                              IntegerValue(float_to_int_rounded(power_status.out_volt, 1000)));
        flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_OUT_CURR,
                              IntegerValue(float_to_int_rounded(power_status.out_curr, 1000)));
        flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_VOLT,
                              IntegerValue(float_to_int_rounded(power_status.set_volt, 1000)));
        flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_CURR,
                              IntegerValue(float_to_int_rounded(power_status.set_curr, 1000)));
        
        flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_CC_CV_FLAG, power_status.cc_cv_flag);
        flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_OUT_ENABLE, power_status.enable_flag);
        flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_POWER_TEMP,
                              IntegerValue(float_to_int_rounded(power_status.temperature, 1)));
        flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_INPUT_VOLT,
                              IntegerValue(float_to_int_rounded(power_status.in_volt, 100)));
    }

public:
    PowerSupply(io_service& io_service) : io(io_service) {}

    void init() {
        power_module_status power_status = io.get_power_module_status();
        power_settings.set_curr = power_status.set_curr;
        power_settings.set_volt = power_status.set_volt;
        io.set_power_module_status(power_settings);
    }

    void update() {
        hmi_module_status hmi_status = io.get_hmi_module_status();
        handle_encoder(hmi_status);

        uint8_t keys;
        key_state state = io.get_key_state(keys);
        
        if (state == KEY_PRESSED) {
            handle_short_press(keys);
        }
        else if (state == KEY_LONG_PRESSED) {
            handle_long_press(keys);
        }

        update_status_variables();
    }
};

extern io_service io;
PowerSupply power_supply(io);

void IRAM_ATTR action_init_power_module_status(lv_event_t *e) {
    power_supply.init();
}

void IRAM_ATTR action_update_power_module_status(lv_event_t *e) {
    power_supply.update();
}