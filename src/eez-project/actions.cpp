#include <lvgl.h>

#include "M5Stack.h"
#include "actions.h"
#include "io_service.h"
#include "screens.h"
#include "structs.h"
#include "ui.h"
#include "vars.h"

enum key_state { KEY_PRESSING, KEY_PRESSED, KEY_LONG_PRESSED, KEY_RELEASED };

#define LONG_PRESSED_TIME 500

#define SET_CURR_MAX 5000
#define SET_VOLT_MAX 30000

void action_update_power_module_status(lv_event_t *e)
{
    extern io_service io;
    struct power_module_status power_status;
    struct hmi_module_status hmi_status;
    static struct power_module_settings power_settings;
    static int last_button;
    static TickType_t last_button_time = 0;

    hmi_status = io.get_hmi_module_status();

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
    }

    if (!hmi_status.button_1) {
        if (last_button != 1) {
            last_button_time = xTaskGetTickCount();
        }
        last_button = 1;
    } else if (!hmi_status.button_2) {
        if (last_button != 2) {
            last_button_time = xTaskGetTickCount();
        }
        last_button = 2;
    } else if (!hmi_status.button_s) {
        if (last_button != 3) {
            last_button_time = xTaskGetTickCount();
        }
        last_button = 3;
    } else if (M5.BtnA.isPressed()) {
        if (last_button != 4) {
            last_button_time = xTaskGetTickCount();
        }
        last_button = 4;
    } else if (M5.BtnB.isPressed()) {
        if (last_button != 5) {
            last_button_time = xTaskGetTickCount();
        }
        last_button = 5;
    } else if (M5.BtnC.isPressed()) {
        if (last_button != 6) {
            last_button_time = xTaskGetTickCount();
        }
        last_button = 6;
    } else if (last_button) {
        int set_step;
        int vc_sel_flag;
        int set_volt, set_curr;
        if (xTaskGetTickCount() - last_button_time > pdMS_TO_TICKS(LONG_PRESSED_TIME)) {
            int vs_sel_flag;

            switch (last_button) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 6:
                power_settings.enable_flag = !power_settings.enable_flag;
                io.set_power_module_status(power_settings);
                break;
            case 4:
            case 5:
                vs_sel_flag = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG).getInt();
                vs_sel_flag = !vs_sel_flag;
                flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG,
                                        IntegerValue(vs_sel_flag));
                break;
            default:
                break;
            }
        } else {
            switch (last_button) {
            case 1:
                flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG, IntegerValue(1));
                break;
            case 2:
                flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG, IntegerValue(0));
                break;
            case 3:
                set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt();
                set_step *= 10;
                if (set_step > 1000) set_step = 1;
                flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP, IntegerValue(set_step));
                io.set_power_module_status(power_settings);
                break;
            case 4:
                set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt();
                vc_sel_flag = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG).getInt();
                set_curr = power_settings.set_curr * 1000;
                set_volt = power_settings.set_volt * 1000;
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
                break;
            case 5:
                set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt();
                vc_sel_flag = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG).getInt();
                set_curr = power_settings.set_curr * 1000;
                set_volt = power_settings.set_volt * 1000;
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
                break;
            case 6:
                set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt();
                set_step *= 10;
                if (set_step > 1000) set_step = 1;
                flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP, IntegerValue(set_step));
                io.set_power_module_status(power_settings);
                break;

            default:
                break;
            }
        }
        last_button = 0;
    }

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