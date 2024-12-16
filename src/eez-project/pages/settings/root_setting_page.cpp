#include "root_setting_page.h"


void RootSettingPage::init() {
    lv_obj_t *setting_list = objects.setting_list;
    setting_group = lv_group_create();
    lv_obj_clean(setting_list);
    
    // Add buttons and add them to group
    lv_obj_t* btn_recall = lv_list_add_btn(setting_list, LV_SYMBOL_EDIT, "Recall Setting");
    lv_obj_t* btn_protect = lv_list_add_btn(setting_list, LV_SYMBOL_CHARGE, "Protect Limit");
    lv_obj_t* btn_other = lv_list_add_btn(setting_list, LV_SYMBOL_SETTINGS, "Other Setting");
    lv_obj_t* btn_about = lv_list_add_btn(setting_list, LV_SYMBOL_BELL, "About");

    lv_obj_add_event_cb(btn_about, [](lv_event_t *e) {
        auto page = (RootSettingPage*)lv_event_get_user_data(e);
        lv_event_code_t code = lv_event_get_code(e);
        Serial.print(F("[INFO] About page event code: "));
        Serial.println(code);
        if (code == LV_EVENT_KEY) {
            eez_flow_set_screen(SCREEN_ID_ABOUT_PAGE, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0);
        }
    }, LV_EVENT_KEY, NULL);

    lv_group_remove_all_objs(setting_group);
    lv_group_add_obj(setting_group, btn_recall);
    lv_group_add_obj(setting_group, btn_protect);
    lv_group_add_obj(setting_group, btn_other);
    lv_group_add_obj(setting_group, btn_about);

    lv_group_focus_obj(btn_recall);
}

void RootSettingPage::handle_encoder(const hmi_module_status& hmi_status) {
    if (!hmi_status.encoder_inc) return;

    if (hmi_status.encoder_inc < 0) lv_group_focus_next(setting_group);
    else lv_group_focus_prev(setting_group);
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}

void RootSettingPage::handle_short_press(uint8_t keys) {
    Serial.print(F("[INFO] Setting page key pressed: "));
    Serial.println(keys);
    lv_obj_t* focused_obj = nullptr;

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
            eez_flow_set_screen(SCREEN_ID_HOME_PAGE, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0);
            break;
        default:
            break;
    }
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}

void RootSettingPage::update() {
    hmi_module_status hmi_status = io.get_hmi_module_status();
    handle_encoder(hmi_status);
    uint8_t keys;
    key_state state = io.get_key_state(keys);
    if (state == KEY_PRESSED) handle_short_press(keys);
}


