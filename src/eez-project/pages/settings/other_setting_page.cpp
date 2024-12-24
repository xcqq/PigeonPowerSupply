#include "other_setting_page.h"

void OtherSettingPage::init()
{
    lv_obj_t *other_setting_list = objects.other_setting_list;
    other_setting_group = lv_group_create();
    lv_obj_clean(other_setting_list);
    JsonVariant config = io.get_config_json();
    beep_setting_item = new BoolSettingItem("Buzzer", config["user_preferences"]["buzzer"]);
    lv_obj_t *btn = beep_setting_item->render(other_setting_list);

    brightness_setting_item =
        new IntSettingItem("Brightness", config["user_preferences"]["brightness"]);
    lv_obj_t *btn_brightness = brightness_setting_item->render(other_setting_list);

    refresh_rate_setting_item =
        new ListSettingItem("Refresh Rate", config["user_preferences"]["refresh_rate"]);
    lv_obj_t *btn_refresh_rate = refresh_rate_setting_item->render(other_setting_list);

    language_setting_item = new ListSettingItem("Language", config["user_preferences"]["language"]);
    lv_obj_t *btn_language = language_setting_item->render(other_setting_list);

    lv_group_remove_all_objs(other_setting_group);
    lv_group_add_obj(other_setting_group, btn);
    lv_group_add_obj(other_setting_group, btn_brightness);
    lv_group_add_obj(other_setting_group, btn_refresh_rate);
    lv_group_add_obj(other_setting_group, btn_language);
    lv_group_set_wrap(other_setting_group, false);

    lv_group_focus_obj(btn);
}

void OtherSettingPage::handle_encoder(const hmi_module_status &hmi_status)
{
    lv_key_t key = 0;
    if (!hmi_status.encoder_inc) return;

    if (!current_selected_btn) {
        if (hmi_status.encoder_inc < 0)
            lv_group_focus_next(other_setting_group);
        else
            lv_group_focus_prev(other_setting_group);
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

void OtherSettingPage::handle_short_press(uint8_t keys)
{
    Serial.print(F("[INFO] Other setting page key pressed: "));
    Serial.println(keys);
    lv_obj_t *focused_obj = nullptr;

    switch (keys) {
    case KEY_HMI_S:
        if (current_selected_btn) {
            current_selected_btn = nullptr;
        } else {
            focused_obj = lv_group_get_focused(other_setting_group);
            if (focused_obj) {
                if (auto item = (ConfigSettingItem<int> *)lv_obj_get_user_data(focused_obj)) {
                    if (item->can_select()) {
                        current_selected_btn = focused_obj;
                    } else {
                        lv_group_send_data(other_setting_group, LV_KEY_ENTER);
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
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}

void OtherSettingPage::update()
{
    hmi_module_status hmi_status = io.get_hmi_module_status();
    handle_encoder(hmi_status);
    uint8_t keys;
    key_state state = io.get_key_state(keys);
    if (state == KEY_PRESSED) handle_short_press(keys);
}
