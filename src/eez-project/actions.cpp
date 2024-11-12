#include <lvgl.h>

#include "M5Stack.h"
#include "actions.h"
#include "io_service.h"
#include "screens.h"
#include "structs.h"
#include "ui.h"
#include "vars.h"

#define LONG_PRESSED_TIME 500

#define SET_CURR_MAX 5000
#define SET_VOLT_MAX 30000

extern io_service io;
struct power_module_settings power_settings;

void IRAM_ATTR action_init_power_module_status(lv_event_t *e)
{
    struct power_module_status power_status;

    power_status = io.get_power_module_status();
    power_settings.set_curr = power_status.set_curr;
    power_settings.set_volt = power_status.set_volt;
    io.set_power_module_status(power_settings);
}

void IRAM_ATTR action_update_power_module_status(lv_event_t *e)
{
    struct power_module_status power_status;
    struct hmi_module_status hmi_status;
    struct hmi_module_settings hmi_settings = {0};

    hmi_status = io.get_hmi_module_status();

    // Handle encoder
    if (hmi_status.encoder_inc) {
        int set_step;
        int vc_sel_flag;
        int set_volt, set_curr;
        set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt();
        vc_sel_flag = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG).getInt();
        set_curr = power_settings.set_curr * 1000;
        set_volt = power_settings.set_volt * 1000;
        if (vc_sel_flag == 0) {
            set_curr = set_curr + set_step * hmi_status.encoder_inc;
            set_curr = MIN(set_curr, SET_CURR_MAX);
            set_curr = MAX(set_curr, 0);
        } else {
            set_volt = set_volt + set_step * hmi_status.encoder_inc;
            set_volt = MIN(set_volt, SET_VOLT_MAX);
            set_volt = MAX(set_volt, 0);
        }
        power_settings.set_volt = set_volt / 1000.0;
        power_settings.set_curr = set_curr / 1000.0;
        io.set_power_module_status(power_settings);
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
    }

    // Handle keys
    uint8_t keys;
    key_state state = io.get_key_state(keys);
    
    if (state == KEY_PRESSED) {
        // Handle short press
        switch (keys) {
            case KEY_HMI_1:  // Button 1
                flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG, IntegerValue(1));
                hmi_settings.led_1 = true;
                io.set_hmi_module_status(hmi_settings);
                io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
                break;

            case KEY_HMI_2:  // Button 2
                flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG, IntegerValue(0));
                hmi_settings.led_2 = true;
                io.set_hmi_module_status(hmi_settings);
                io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
                break;

            case KEY_HMI_S:  // Button S
            case KEY_M5_C:   // Button C
                {
                    int set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt();
                    set_step *= 10;
                    if (set_step > 1000) set_step = 1;
                    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP, IntegerValue(set_step));
                    io.set_power_module_status(power_settings);
                    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
                }
                break;

            case KEY_M5_A:  // Button A
                {
                    int set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt();
                    int vc_sel_flag = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG).getInt();
                    int set_curr = power_settings.set_curr * 1000;
                    int set_volt = power_settings.set_volt * 1000;
                    
                    if (vc_sel_flag == 0) {
                        set_curr = set_curr - set_step;
                        set_curr = MIN(set_curr, SET_CURR_MAX);
                        set_curr = MAX(set_curr, 0);
                    } else {
                        set_volt = set_volt - set_step;
                        set_volt = MIN(set_volt, SET_VOLT_MAX);
                        set_volt = MAX(set_volt, 0);
                    }
                    power_settings.set_volt = set_volt / 1000.0;
                    power_settings.set_curr = set_curr / 1000.0;
                    io.set_power_module_status(power_settings);
                    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
                }
                break;

            case KEY_M5_B:  // Button B
                {
                    int set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt();
                    int vc_sel_flag = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG).getInt();
                    int set_curr = power_settings.set_curr * 1000;
                    int set_volt = power_settings.set_volt * 1000;
                    
                    if (vc_sel_flag == 0) {
                        set_curr = set_curr + set_step;
                        set_curr = MIN(set_curr, SET_CURR_MAX);
                        set_curr = MAX(set_curr, 0);
                    } else {
                        set_volt = set_volt + set_step;
                        set_volt = MIN(set_volt, SET_VOLT_MAX);
                        set_volt = MAX(set_volt, 0);
                    }
                    power_settings.set_volt = set_volt / 1000.0;
                    power_settings.set_curr = set_curr / 1000.0;
                    io.set_power_module_status(power_settings);
                    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
                }
                break;
        }
    }
    else if (state == KEY_LONG_PRESSED) {
        // Handle long press
        switch (keys) {
            case KEY_M5_C:  // Button C long press
                power_settings.enable_flag = !power_settings.enable_flag;
                io.set_power_module_status(power_settings);
                io.set_buzzer_beep(BUZZER_TONE_MID, BUZZER_DURATION_MID);
                io.save_config();
                break;

            case KEY_M5_A:  // Button A long press
            case KEY_M5_B:  // Button B long press
                {
                    int vs_sel_flag = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG).getInt();
                    vs_sel_flag = !vs_sel_flag;
                    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG, IntegerValue(vs_sel_flag));
                    if (vs_sel_flag)
                        hmi_settings.led_1 = true;
                    else
                        hmi_settings.led_2 = true;
                    io.set_hmi_module_status(hmi_settings);
                    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
                }
                break;
        }
    }

    // Update status variables
    power_status = io.get_power_module_status();
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_OUT_VOLT,
                            IntegerValue(int(power_status.out_volt * 1000)));
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_OUT_CURR,
                            IntegerValue(int(power_status.out_curr * 1000)));
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_VOLT,
                            IntegerValue(int(power_status.set_volt * 1000)));
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_CURR,
                            IntegerValue(int(power_status.set_curr * 1000)));
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_CC_CV_FLAG, power_status.cc_cv_flag);
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_OUT_ENABLE, power_status.enable_flag);
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_POWER_TEMP,
                            IntegerValue(int(power_status.temperature)));
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_INPUT_VOLT,
                            IntegerValue(int(power_status.in_volt * 100)));
}