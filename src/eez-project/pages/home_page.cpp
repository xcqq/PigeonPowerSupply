#include "home_page.h"
#include "settings/root_setting_page.h"
#include "user_actions.h"

const std::string HomePage::PAGE_NAME = "home";

// Helper functions
float HomePage::adjust_value(float value, float min, float max) { return clamp(value, min, max); }

void HomePage::update_settings(float set_volt, float set_curr)
{
    power_settings.set_volt = set_volt;
    power_settings.set_curr = set_curr;
    io.set_power_module_status(power_settings);
}

void HomePage::set_voltage_mode(bool is_voltage, hmi_module_settings &hmi_settings)
{
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG, IntegerValue(is_voltage));
    if (is_voltage)
        hmi_settings.led_1 = true;
    else
        hmi_settings.led_2 = true;
    io.set_hmi_module_status(hmi_settings);
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}

void HomePage::adjust_step_size()
{
    int set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt();
    set_step *= 10;
    if (set_step > 1000) set_step = 1;
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP, IntegerValue(set_step));
    io.set_power_module_status(power_settings);
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}

void HomePage::adjust_output(int direction)
{
    float set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt() / 1000.0;
    int vc_sel_flag = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG).getInt();
    float set_curr = power_settings.set_curr;
    float set_volt = power_settings.set_volt;

    if (vc_sel_flag == 0) {
        set_curr = adjust_value(set_curr + direction * set_step, 0, io.get_max_current());
    } else {
        set_volt = adjust_value(set_volt + direction * set_step, 0, io.get_max_voltage());
    }

    update_settings(set_volt, set_curr);
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}

void HomePage::toggle_output()
{
    power_settings.enable_flag = !power_settings.enable_flag;
    io.set_power_module_status(power_settings);
    io.set_buzzer_beep(BUZZER_TONE_MID, BUZZER_DURATION_MID);
    io.save_config();
}

void HomePage::toggle_voltage_current_mode(hmi_module_settings &hmi_settings)
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

int HomePage::float_to_int_rounded(float value, float scale)
{
    return static_cast<int>(value * scale + 0.5f);
}

void HomePage::update_status_variables()
{
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

void HomePage::add_recall_setting(float set_volt, float set_curr)
{
    if (recall_settings.isNull()) {
        recall_settings = io.get_config_json()["recall_settings"].createNestedArray("recall");
    }

    JsonObject recall_setting = recall_settings.createNestedObject();
    recall_setting["set_volt"] = set_volt;
    recall_setting["set_curr"] = set_curr;

    io.save_config();
}

void HomePage::load_recall_settings_list(lv_obj_t *list)
{
    char buf[20];
    lv_group_remove_all_objs(recall_group);
    lv_obj_clean(list);
    lv_group_set_wrap(recall_group, false);
    for (JsonVariant recall_setting : recall_settings) {
        if (recall_setting.isNull()) {
            sprintf(buf, "%.2f V, %.2f A", 0.0, 0.0);
        } else {
            if (recall_setting["set_volt"].isNull() || recall_setting["set_curr"].isNull()) {
                sprintf(buf, "%.2f V, %.2f A", 0.0, 0.0);
            } else {
                sprintf(buf, "%.2f V, %.2f A", recall_setting["set_volt"].as<float>(),
                        recall_setting["set_curr"].as<float>());
            }
        }
        lv_obj_t *btn = lv_list_add_btn(list, NULL, buf);
        lv_group_add_obj(recall_group, btn);
    }
    if (lv_obj_get_child_cnt(list) > 0) {
        lv_obj_t *first_btn = lv_obj_get_child(list, 0);
        lv_group_focus_obj(first_btn);
    }
}

void HomePage::onInit()
{
    JsonVariant config_recall = io.get_config_json()["recall_settings"]["recall"];
    if (config_recall.isNull()) {
        recall_settings = io.get_config_json()["recall_settings"].createNestedArray("recall");
    } else {
        recall_settings = config_recall;
    }

    recall_group = lv_group_create();
    recall_list = objects.recall_list;
}

void HomePage::onEnter()
{
    recall_list_open = false;
    lv_obj_add_flag(recall_list, LV_OBJ_FLAG_HIDDEN);
    power_settings = io.get_power_module_settings();
}

void HomePage::update() { update_status_variables(); }

void HomePage::handle_long_press(uint8_t keys)
{
    struct hmi_module_settings hmi_settings = {0};

    switch (keys) {
    case KEY_M5_A:
        if (!recall_list_open) {
            add_recall_setting(power_settings.set_volt, power_settings.set_curr);
            io.set_buzzer_beep(BUZZER_TONE_MID, BUZZER_DURATION_MID);
        }
        break;
    default:
        break;
    }
}

void HomePage::handle_short_press(uint8_t keys)
{
    struct hmi_module_settings hmi_settings = {0};

    switch (keys) {
    case KEY_HMI_1:
        set_voltage_mode(true, hmi_settings);
        break;

    case KEY_HMI_2:
        set_voltage_mode(false, hmi_settings);
        break;

    case KEY_HMI_S:
        if (recall_list_open) {
            lv_obj_t *focused_obj = lv_group_get_focused(recall_group);
            uint32_t index = lv_obj_get_index(focused_obj);

            if (index < recall_settings.size()) {
                JsonObject recall_item = recall_settings[index];
                float set_volt = recall_item["set_volt"];
                float set_curr = recall_item["set_curr"];
                update_settings(set_volt, set_curr);
            }

            recall_list_open = false;
            lv_obj_add_flag(recall_list, LV_OBJ_FLAG_HIDDEN);
        } else {
            adjust_step_size();
        }
        break;

    case KEY_M5_A:
        if (recall_list_open) {
            recall_list_open = false;
            lv_obj_add_flag(recall_list, LV_OBJ_FLAG_HIDDEN);
            lv_obj_t *middle_button_label = objects.middle_button_label;
            lv_label_set_text(middle_button_label, "ON/OFF");
            lv_obj_t *right_button_label = objects.right_button_label;
            lv_label_set_text(right_button_label, "Menu");
        } else {
            recall_list_open = true;
            lv_obj_clear_flag(recall_list, LV_OBJ_FLAG_HIDDEN);
            load_recall_settings_list(recall_list);
            lv_obj_t *middle_button_label = objects.middle_button_label;
            lv_label_set_text(middle_button_label, "Del");
            lv_obj_t *right_button_label = objects.right_button_label;
            lv_label_set_text(right_button_label, "Clear");
        }
        break;

    case KEY_M5_B:
        if (recall_list_open) {
            lv_obj_t *focused_obj = lv_group_get_focused(recall_group);
            uint32_t index = lv_obj_get_index(focused_obj);

            if (index < recall_settings.size()) {
                recall_settings.remove(index);
                io.save_config();
                load_recall_settings_list(recall_list);
            }
        } else {
            toggle_output();
        }
        break;

    case KEY_M5_C:
        if (recall_list_open) {
            recall_settings.clear();
            io.save_config();
            load_recall_settings_list(recall_list);
        } else {
            user_actions.switchToPage(RootSettingPage::PAGE_NAME);
        }
        break;
    }
}

void HomePage::handle_encoder(const hmi_module_status &hmi_status)
{
    if (!hmi_status.encoder_inc) return;

    float set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt() / 1000.0;
    int vc_sel_flag = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_VC_SEL_FLAG).getInt();
    float set_curr = power_settings.set_curr;
    float set_volt = power_settings.set_volt;

    if (recall_list_open) {
        if (hmi_status.encoder_inc < 0)
            lv_group_focus_next(recall_group);
        else
            lv_group_focus_prev(recall_group);
    } else {
        if (vc_sel_flag == 0) {
            float new_curr =
                adjust_value(set_curr + set_step * hmi_status.encoder_inc, 0, io.get_max_current());
            // Check if new current would exceed power limit
            if ((new_curr * set_volt) <= io.get_power_limit()) {
                set_curr = new_curr;
            }
        } else {
            float new_volt =
                adjust_value(set_volt + set_step * hmi_status.encoder_inc, 0, io.get_max_voltage());
            // Check if new voltage would exceed power limit
            if ((new_volt * set_curr) <= io.get_power_limit()) {
                set_volt = new_volt;
            }
        }
    }

    update_settings(set_volt, set_curr);
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}