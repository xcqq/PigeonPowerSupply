#include "protect_limit_page.h"
#include "user_actions.h"
#include "../../../config.h"
#include "eez-project/styles.h"

const std::string ProtectLimitPage::PAGE_NAME = "protect_limit";

void ProtectLimitPage::onInit()
{
    LOG_DEBUG("Initializing protect limit page");
    lv_obj_t *protect_limit_list = objects.protect_limit_list;
    protect_limit_group = lv_group_create();
    lv_obj_clean(protect_limit_list);
    lv_group_remove_all_objs(protect_limit_group);
    lv_group_set_wrap(protect_limit_group, false);

    JsonVariant config = io.get_config_json();
    current_limit_item =
        new FloatSettingItem("Current Limit", config["protection_limits"]["current_limit"], io,
                             [](ConfigSettingItem<float> *item, io_service &io) {
                                 io.set_current_limit(item->getValue());
                                 LOG_INFO("Current limit updated to: %.2fA", item->getValue());
                             });
    lv_obj_t *current_limit_item_obj = current_limit_item->render(protect_limit_list);
    lv_group_add_obj(protect_limit_group, current_limit_item_obj);

    voltage_limit_item =
        new FloatSettingItem("Voltage Limit", config["protection_limits"]["voltage_limit"], io,
                             [](ConfigSettingItem<float> *item, io_service &io) {
                                 io.set_voltage_limit(item->getValue());
                                 LOG_INFO("Voltage limit updated to: %.2fV", item->getValue());
                             });
    lv_obj_t *voltage_limit_item_obj = voltage_limit_item->render(protect_limit_list);
    lv_group_add_obj(protect_limit_group, voltage_limit_item_obj);

    power_limit_item = new IntSettingItem(
        "Power Limit", config["protection_limits"]["power_limit"], io,
        [](ConfigSettingItem<int> *item, io_service &io) { 
            io.set_power_limit(item->getValue());
            LOG_INFO("Power limit updated to: %dW", item->getValue());
        });
    lv_obj_t *power_limit_item_obj = power_limit_item->render(protect_limit_list);
    lv_group_add_obj(protect_limit_group, power_limit_item_obj);

    temperature_limit_item =
        new IntSettingItem("Temperature Limit", config["protection_limits"]["temperature_limit"],
                           io, [](ConfigSettingItem<int> *item, io_service &io) {
                               io.set_temperature_limit(item->getValue());
                               LOG_INFO("Temperature limit updated to: %d°C", item->getValue());
                           });
    lv_obj_t *temperature_limit_item_obj = temperature_limit_item->render(protect_limit_list);
    lv_group_add_obj(protect_limit_group, temperature_limit_item_obj);

    add_style_setting_list_button_style(current_limit_item_obj);
    add_style_setting_list_button_style(voltage_limit_item_obj);
    add_style_setting_list_button_style(power_limit_item_obj);
    add_style_setting_list_button_style(temperature_limit_item_obj);

    lv_group_focus_obj(current_limit_item_obj);
    current_selected_btn = nullptr;
    LOG_DEBUG("Protect limit page initialization completed");
}

void ProtectLimitPage::update() {}

void ProtectLimitPage::handle_encoder(const hmi_module_status &hmi_status)
{
    lv_key_t key = 0;
    if (!hmi_status.encoder_inc) return;

    if (!current_selected_btn) {
        if (hmi_status.encoder_inc < 0)
            lv_group_focus_next(protect_limit_group);
        else
            lv_group_focus_prev(protect_limit_group);
        LOG_DEBUG("Navigating protection settings");
    } else {
        if (hmi_status.encoder_inc > 0) {
            key = LV_KEY_UP;
            lv_event_send(current_selected_btn, LV_EVENT_KEY, (void *)&key);
        } else {
            key = LV_KEY_DOWN;
            lv_event_send(current_selected_btn, LV_EVENT_KEY, (void *)&key);
        }
        LOG_DEBUG("Adjusting protection value");
    }

    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}

void ProtectLimitPage::handle_short_press(uint8_t keys)
{
    lv_obj_t *focused_obj = nullptr;

    switch (keys) {
    case KEY_HMI_S:
        if (current_selected_btn) {
            lv_obj_clear_state(current_selected_btn, LV_STATE_PRESSED | LV_STATE_CHECKED);
            current_selected_btn = nullptr;
        } else {
            focused_obj = lv_group_get_focused(protect_limit_group);
            if (focused_obj) {
                if (auto item = (ConfigSettingItem<int> *)lv_obj_get_user_data(focused_obj)) {
                    if (item->can_select()) {
                        current_selected_btn = focused_obj;
                        lv_obj_add_state(current_selected_btn, LV_STATE_PRESSED | LV_STATE_CHECKED);
                    } else {
                        lv_group_send_data(protect_limit_group, LV_KEY_ENTER);
                    }
                }
            }
        }
        break;
    case KEY_M5_A:
        if (current_selected_btn) {
            lv_obj_clear_state(current_selected_btn, LV_STATE_PRESSED | LV_STATE_CHECKED);
            current_selected_btn = nullptr;
        } else {
            user_actions.goBack();
        }
        break;
    default:
        break;
    }
}

void ProtectLimitPage::onExit() 
{ 
    LOG_DEBUG("Saving protection settings");
    io.save_config(); 
}

void ProtectLimitPage::onDestroy()
{
    LOG_DEBUG("Destroying protect limit page");
    /* temporary remove the code since it will case crash, 
       could be cause by reentrancy problem
    */
    /*
    if (protect_limit_list) {
        lv_obj_clean(protect_limit_list);
    }
    */
    if (protect_limit_group) {
        lv_group_remove_all_objs(protect_limit_group);
        lv_group_del(protect_limit_group);
        protect_limit_group = nullptr;
    }
}
