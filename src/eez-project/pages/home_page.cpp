#include "home_page.h"
#include "settings/root_setting_page.h"
#include "user_actions.h"
#include "../../config.h"
#include "eez-project/i18n/lv_i18n.h"

const std::string HomePage::PAGE_NAME = "home";

// Helper functions
float HomePage::adjust_value(float value, float min, float max) { return clamp(value, min, max); }

void HomePage::update_settings(float set_volt, float set_curr)
{
    LOG_DEBUG("Updating power settings - V:%.2f A:%.2f", set_volt, set_curr);
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
}

void HomePage::adjust_step_size()
{
    int set_step = flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP).getInt();
    set_step *= 10;
    if (set_step > 1000) set_step = 1;
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_STEP, IntegerValue(set_step));
    io.set_power_module_status(power_settings);
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
}

void HomePage::toggle_output()
{
    power_settings.enable_flag = !power_settings.enable_flag;
    io.set_power_module_status(power_settings);
    io.save_config();
    LOG_INFO("Power output %s", power_settings.enable_flag ? "enabled" : "disabled");
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
    LOG_INFO("Added recall setting: %.2fV %.2fA", set_volt, set_curr);
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
    LOG_DEBUG("Initializing home page");
    JsonVariant config_recall = io.get_config_json()["recall_settings"]["recall"];
    if (config_recall.isNull()) {
        recall_settings = io.get_config_json()["recall_settings"].createNestedArray("recall");
    } else {
        recall_settings = config_recall;
    }

    recall_group = lv_group_create();
    recall_list = objects.recall_list;
    LOG_DEBUG("Home page initialization completed");
}

static HomePage *timer_instance = nullptr;

void HomePage::timer_callback(TimerHandle_t timer)
{
    if (timer_instance) {
        timer_instance->update_status_variables();
    }
}

void HomePage::onEnter()
{
    recall_list_open = false;
    lv_obj_add_flag(recall_list, LV_OBJ_FLAG_HIDDEN);
    power_settings = io.get_power_module_settings();
    timer_instance = this;
    int refresh_rate = io.get_refresh_rate();
    status_update_timer =
        user_actions.registerTimer("status_update", HomePage::timer_callback, refresh_rate, true);
}

void HomePage::onExit()
{
    timer_instance = nullptr;
    user_actions.unregisterTimer(status_update_timer);
}

void HomePage::update() {
    power_module_status power_status = io.get_power_module_status();
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_CC_CV_FLAG, power_status.cc_cv_flag);
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_OUT_ENABLE, power_status.enable_flag);
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_VOLT,
                            IntegerValue(float_to_int_rounded(power_status.set_volt, 1000)));
    flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SET_CURR,
                            IntegerValue(float_to_int_rounded(power_status.set_curr, 1000)));
}

void HomePage::handle_long_press(uint8_t keys)
{
    struct hmi_module_settings hmi_settings = {0};

    switch (keys) {
    case KEY_M5_A:
        if (!recall_list_open) {
            add_recall_setting(power_settings.set_volt, power_settings.set_curr);
            io.set_buzzer_beep(BUZZER_TONE_MID, BUZZER_DURATION_LONG);
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
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
        break;

    case KEY_HMI_2:
        set_voltage_mode(false, hmi_settings);
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
        break;

    case KEY_HMI_S:
        if (recall_list_open) {
            lv_obj_t *focused_obj = lv_group_get_focused(recall_group);
            uint32_t index = lv_obj_get_index(focused_obj);

            if (index < recall_settings.size()) {
                JsonObject recall_item = recall_settings[index];
                float set_volt = recall_item["set_volt"];
                float set_curr = recall_item["set_curr"];
                LOG_INFO("Recall setting loaded: %.2fV %.2fA", set_volt, set_curr);
                update_settings(set_volt, set_curr);
            }

            recall_list_open = false;
            lv_obj_add_flag(recall_list, LV_OBJ_FLAG_HIDDEN);
        } else {
            adjust_step_size();
        }
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
        break;

    case KEY_M5_A:
        if (recall_list_open) {
            recall_list_open = false;
            lv_obj_add_flag(recall_list, LV_OBJ_FLAG_HIDDEN);
            lv_obj_t *middle_button_label = objects.middle_button_label;
            lv_label_set_text(middle_button_label, _("ON/OFF"));
            lv_obj_t *right_button_label = objects.right_button_label;
            lv_label_set_text(right_button_label, _("Menu"));
        } else {
            recall_list_open = true;
            lv_obj_clear_flag(recall_list, LV_OBJ_FLAG_HIDDEN);
            load_recall_settings_list(recall_list);
            lv_obj_t *middle_button_label = objects.middle_button_label;
            lv_label_set_text(middle_button_label, _("Del"));
            lv_obj_t *right_button_label = objects.right_button_label;
            lv_label_set_text(right_button_label, _("Clear"));
        }
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
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
            io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
        } else {
            toggle_output();
            io.set_buzzer_beep(BUZZER_TONE_MID, BUZZER_DURATION_MID);
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
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
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
    float old_volt = set_volt;
    float old_curr = set_curr;

    if (recall_list_open) {
        if (hmi_status.encoder_inc < 0)
            lv_group_focus_next(recall_group);
        else
            lv_group_focus_prev(recall_group);
        LOG_DEBUG("Navigating recall list");
    } else {
        if (vc_sel_flag == 0) {
            float new_curr =
                adjust_value(set_curr + set_step * hmi_status.encoder_inc, 0, io.get_max_current());
            if ((new_curr * set_volt) <= io.get_power_limit()) {
                set_curr = new_curr;
            } else {
                LOG_DEBUG("Current adjustment limited by power limit");
            }
        } else {
            float new_volt =
                adjust_value(set_volt + set_step * hmi_status.encoder_inc, 0, io.get_max_voltage());
            if ((new_volt * set_curr) <= io.get_power_limit()) {
                set_volt = new_volt;
            } else {
                LOG_DEBUG("Voltage adjustment limited by power limit");
            }
        }

        if (old_volt != set_volt || old_curr != set_curr) {
            LOG_DEBUG("Encoder adjustment - V:%.2f->%.2f A:%.2f->%.2f", old_volt, set_volt,
                      old_curr, set_curr);
        }
    }

    update_settings(set_volt, set_curr);
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}