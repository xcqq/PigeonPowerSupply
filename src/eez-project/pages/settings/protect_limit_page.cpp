#include "protect_limit_page.h"

void ProtectLimitPage::init() {
    lv_obj_t *protect_limit_list = objects.protect_limit_list;
    protect_limit_group = lv_group_create();
    lv_obj_clean(protect_limit_list);
    lv_group_remove_all_objs(protect_limit_group);
    lv_group_set_wrap(protect_limit_group, false);

    JsonVariant config = io.get_config_json();
    current_limit_item = new FloatSettingItem("Current Limit", config["protection_limits"]["current_limit"]);
    lv_obj_t *current_limit_item_obj = current_limit_item->render(protect_limit_list);
    lv_group_add_obj(protect_limit_group, current_limit_item_obj);
    voltage_limit_item = new FloatSettingItem("Voltage Limit", config["protection_limits"]["voltage_limit"]);
    lv_obj_t *voltage_limit_item_obj = voltage_limit_item->render(protect_limit_list);
    lv_group_add_obj(protect_limit_group, voltage_limit_item_obj);
    power_limit_item = new IntSettingItem("Power Limit", config["protection_limits"]["power_limit"]);
    lv_obj_t *power_limit_item_obj = power_limit_item->render(protect_limit_list);
    lv_group_add_obj(protect_limit_group, power_limit_item_obj);
    temperature_limit_item = new IntSettingItem("Temperature Limit", config["protection_limits"]["temperature_limit"]);
    lv_obj_t *temperature_limit_item_obj = temperature_limit_item->render(protect_limit_list);
    lv_group_add_obj(protect_limit_group, temperature_limit_item_obj);

    lv_group_focus_obj(current_limit_item_obj);
}

void ProtectLimitPage::update() {
    hmi_module_status hmi_status = io.get_hmi_module_status();
    handle_encoder(hmi_status);
    uint8_t keys;
    key_state state = io.get_key_state(keys);
    if (state == KEY_PRESSED) handle_short_press(keys);
}

void ProtectLimitPage::handle_encoder(const hmi_module_status &hmi_status) {
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

void ProtectLimitPage::handle_short_press(uint8_t keys) {
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
                eez_flow_set_screen(SCREEN_ID_ROOT_SETTING_PAGE, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0);
            }
            break;
        default:
            break;
    }
}

