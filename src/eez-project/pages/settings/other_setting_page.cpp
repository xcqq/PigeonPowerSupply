#include "other_setting_page.h"
#include "./root_setting_page.h"
#include "user_actions.h"

const std::string OtherSettingPage::PAGE_NAME = "other_setting";

void OtherSettingPage::onInit()
{
    lv_obj_t *other_setting_list = objects.other_setting_list;
    JsonVariant config = io.get_config_json();
    if (other_setting_list) {
        lv_obj_clean(other_setting_list);
    }
    other_setting_group = lv_group_create();
    lv_group_remove_all_objs(other_setting_group);

    beep_setting_item = new BoolSettingItem(
        "Buzzer", config["user_preferences"]["buzzer"], io,
        [](ConfigSettingItem<bool> *item, io_service &io) { io.set_buzzer(item->getValue()); });
    lv_obj_t *btn_beep = beep_setting_item->render(other_setting_list);
    lv_group_add_obj(other_setting_group, btn_beep);

    brightness_setting_item = new IntSettingItem(
        "Brightness", config["user_preferences"]["brightness"], io,
        [](ConfigSettingItem<int> *item, io_service &io) { io.set_brightness(item->getValue()); });
    lv_obj_t *btn_brightness = brightness_setting_item->render(other_setting_list);
    lv_group_add_obj(other_setting_group, btn_brightness);

    refresh_rate_setting_item =
        new ListSettingItem("Refresh Rate", config["user_preferences"]["refresh_rate"], io, NULL);
    lv_obj_t *btn_refresh_rate = refresh_rate_setting_item->render(other_setting_list);
    lv_group_add_obj(other_setting_group, btn_refresh_rate);

    language_setting_item =
        new ListSettingItem("Language", config["user_preferences"]["language"], io, NULL);
    lv_obj_t *btn_language = language_setting_item->render(other_setting_list);
    lv_group_add_obj(other_setting_group, btn_language);

    lv_group_set_wrap(other_setting_group, false);

    lv_group_focus_obj(btn_beep);
    current_selected_btn = nullptr;
}

void OtherSettingPage::onEnter()
{
    lv_group_focus_obj(beep_setting_item->getObj());
    current_selected_btn = nullptr;
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
            user_actions.goBack();
        }
        break;
    default:
        break;
    }
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}

void OtherSettingPage::update() {}

void OtherSettingPage::onExit() { io.save_config(); }

void OtherSettingPage::onDestroy()
{
    if (other_setting_list) {
        lv_obj_clean(other_setting_list);
    }
    if (other_setting_group) {
        lv_group_remove_all_objs(other_setting_group);
        lv_group_del(other_setting_group);
        other_setting_group = nullptr;
    }
}
