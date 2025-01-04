#include "root_setting_page.h"
#include "../home_page.h"
#include "./about_page.h"
#include "./other_setting_page.h"
#include "./protect_limit_page.h"
#include "user_actions.h"

const std::string RootSettingPage::PAGE_NAME = "root_setting";

void RootSettingPage::onInit()
{
    setting_list = objects.setting_list;
    if (setting_list) {
        lv_obj_clean(setting_list);
    }
    setting_group = lv_group_create();
    lv_group_remove_all_objs(setting_group);

    // Add buttons and add them to group
    btn_protect = lv_list_add_btn(setting_list, NULL, "Protect Limit");
    btn_other = lv_list_add_btn(setting_list, NULL, "Other Setting");
    btn_about = lv_list_add_btn(setting_list, NULL, "About");
    lv_obj_add_event_cb(
        btn_about,
        [](lv_event_t *e) {
            auto page = (RootSettingPage *)lv_event_get_user_data(e);
            lv_event_code_t code = lv_event_get_code(e);
            Serial.print(F("[INFO] About page event code: "));
            Serial.println(code);
            if (code == LV_EVENT_KEY) {
                page->user_actions.switchToPage(AboutPage::PAGE_NAME);
            }
        },
        LV_EVENT_KEY, this);

    lv_obj_add_event_cb(
        btn_other,
        [](lv_event_t *e) {
            auto page = (RootSettingPage *)lv_event_get_user_data(e);
            lv_event_code_t code = lv_event_get_code(e);
            Serial.print(F("[INFO] Other setting page event code: "));
            Serial.println(code);
            if (code == LV_EVENT_KEY) {
                page->user_actions.switchToPage(OtherSettingPage::PAGE_NAME);
            }
        },
        LV_EVENT_KEY, this);

    lv_obj_add_event_cb(
        btn_protect,
        [](lv_event_t *e) {
            auto page = (RootSettingPage *)lv_event_get_user_data(e);
            lv_event_code_t code = lv_event_get_code(e);
            Serial.print(F("[INFO] Protect limit page event code: "));
            Serial.println(code);
            if (code == LV_EVENT_KEY) {
                page->user_actions.switchToPage(ProtectLimitPage::PAGE_NAME);
            }
        },
        LV_EVENT_KEY, this);

    lv_group_add_obj(setting_group, btn_protect);
    lv_group_add_obj(setting_group, btn_other);
    lv_group_add_obj(setting_group, btn_about);
    lv_group_set_wrap(setting_group, false);
}

void RootSettingPage::onEnter() { lv_group_focus_obj(btn_protect); }

void RootSettingPage::handle_encoder(const hmi_module_status &hmi_status)
{
    if (!hmi_status.encoder_inc) return;

    if (hmi_status.encoder_inc < 0)
        lv_group_focus_next(setting_group);
    else
        lv_group_focus_prev(setting_group);
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}

void RootSettingPage::handle_short_press(uint8_t keys)
{
    Serial.print(F("[INFO] Setting page key pressed: "));
    Serial.println(keys);
    lv_obj_t *focused_obj = nullptr;

    switch (keys) {
    case KEY_HMI_S:
        Serial.print(F("[DEBUG] Setting page S key pressed, focused obj: "));
        focused_obj = lv_group_get_focused(setting_group);
        Serial.println(focused_obj ? "exists" : "null");
        if (focused_obj) {
            Serial.println(F("[DEBUG] Sending ENTER key to focused object"));
            lv_group_send_data(setting_group, LV_KEY_ENTER);
        }
        break;
    case KEY_M5_A:
        user_actions.goBack();
        break;
    default:
        break;
    }
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}

void RootSettingPage::update() {}

void RootSettingPage::onDestroy()
{
    if (setting_list) {
        lv_obj_clean(setting_list);
    }
    if (setting_group) {
        lv_group_remove_all_objs(setting_group);
        lv_group_del(setting_group);
        setting_group = nullptr;
    }
}
