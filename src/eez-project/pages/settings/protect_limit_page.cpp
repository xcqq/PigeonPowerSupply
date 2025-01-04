#include "protect_limit_page.h"
#include "user_actions.h"

const std::string ProtectLimitPage::PAGE_NAME = "protect_limit";

void ProtectLimitPage::onInit()
{
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
                             });
    lv_obj_t *current_limit_item_obj = current_limit_item->render(protect_limit_list);
    lv_group_add_obj(protect_limit_group, current_limit_item_obj);

    voltage_limit_item =
        new FloatSettingItem("Voltage Limit", config["protection_limits"]["voltage_limit"], io,
                             [](ConfigSettingItem<float> *item, io_service &io) {
                                 io.set_voltage_limit(item->getValue());
                             });
    lv_obj_t *voltage_limit_item_obj = voltage_limit_item->render(protect_limit_list);
    lv_group_add_obj(protect_limit_group, voltage_limit_item_obj);

    power_limit_item = new IntSettingItem(
        "Power Limit", config["protection_limits"]["power_limit"], io,
        [](ConfigSettingItem<int> *item, io_service &io) { io.set_power_limit(item->getValue()); });
    lv_obj_t *power_limit_item_obj = power_limit_item->render(protect_limit_list);
    lv_group_add_obj(protect_limit_group, power_limit_item_obj);

    temperature_limit_item =
        new IntSettingItem("Temperature Limit", config["protection_limits"]["temperature_limit"],
                           io, [](ConfigSettingItem<int> *item, io_service &io) {
                               io.set_temperature_limit(item->getValue());
                           });
    lv_obj_t *temperature_limit_item_obj = temperature_limit_item->render(protect_limit_list);
    lv_group_add_obj(protect_limit_group, temperature_limit_item_obj);

    lv_group_focus_obj(current_limit_item_obj);
    current_selected_btn = nullptr;
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
    } else {
        if (hmi_status.encoder_inc < 0) {
            Serial.println("Encoder up");
            key = LV_KEY_UP;
            lv_event_send(current_selected_btn, LV_EVENT_KEY, (void *)&key);
        } else {
            Serial.println("Encoder down");
            key = LV_KEY_DOWN;
            lv_event_send(current_selected_btn, LV_EVENT_KEY, (void *)&key);
        }
    }

    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}

void ProtectLimitPage::handle_short_press(uint8_t keys)
{
    Serial.print(F("[INFO] Protect limit page key pressed: "));
    Serial.println(keys);
    lv_obj_t *focused_obj = nullptr;

    switch (keys) {
    case KEY_HMI_S:
        if (current_selected_btn) {
            current_selected_btn = nullptr;
        } else {
            focused_obj = lv_group_get_focused(protect_limit_group);
            if (focused_obj) {
                if (auto item = (ConfigSettingItem<int> *)lv_obj_get_user_data(focused_obj)) {
                    if (item->can_select()) {
                        current_selected_btn = focused_obj;
                    } else {
                        lv_group_send_data(protect_limit_group, LV_KEY_ENTER);
                    }
                }
            }
        }
        break;
    case KEY_M5_A:
        if (current_selected_btn) {
            current_selected_btn = nullptr;
        } else {
            user_actions.goBack();
        }
        break;
    default:
        break;
    }
}

void ProtectLimitPage::onExit() { io.save_config(); }

void ProtectLimitPage::onDestroy()
{
    if (protect_limit_list) {
        lv_obj_clean(protect_limit_list);
    }
    if (protect_limit_group) {
        lv_group_remove_all_objs(protect_limit_group);
        lv_group_del(protect_limit_group);
        protect_limit_group = nullptr;
    }
}
