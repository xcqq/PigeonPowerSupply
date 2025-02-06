#include "other_setting_page.h"
#include "./root_setting_page.h"
#include "user_actions.h"
#include "../../../config.h"
#include "eez-project/styles.h"
#include "lvgl.h"
#include "eez-project/i18n/lv_i18n.h"

const std::string OtherSettingPage::PAGE_NAME = "other_setting";

void OtherSettingPage::onInit()
{
    LOG_DEBUG("Initializing other setting page");
    lv_obj_t *other_setting_list = objects.other_setting_list;
    JsonVariant config = io.get_config_json();
    if (other_setting_list) {
        lv_obj_clean(other_setting_list);
    }
    other_setting_group = lv_group_create();
    lv_group_remove_all_objs(other_setting_group);

    beep_setting_item = new BoolSettingItem(
        _("Buzzer"), config["user_preferences"]["buzzer"], io,
        [](ConfigSettingItem<bool> *item, io_service &io) { 
            io.set_buzzer(item->getValue());
            LOG_INFO("Buzzer %s", item->getValue() ? "enabled" : "disabled");
        });
    lv_obj_t *btn_beep = beep_setting_item->render(other_setting_list);
    lv_group_add_obj(other_setting_group, btn_beep);

    brightness_setting_item = new IntSettingItem(
        _("Brightness"), config["user_preferences"]["brightness"], io,
        [](ConfigSettingItem<int> *item, io_service &io) { 
            io.set_brightness(item->getValue());
            LOG_INFO("Brightness set to: %d", item->getValue());
        });
    lv_obj_t *btn_brightness = brightness_setting_item->render(other_setting_list);
    lv_group_add_obj(other_setting_group, btn_brightness);

    refresh_rate_setting_item =
        new ListSettingItem(_("Refresh Rate"), config["user_preferences"]["refresh_rate"], io, 
            [](ConfigSettingItem<std::string> *item, io_service &io) {
                LOG_INFO("Refresh rate set to: %s", item->getValue().c_str());
            });
    lv_obj_t *btn_refresh_rate = refresh_rate_setting_item->render(other_setting_list);
    lv_group_add_obj(other_setting_group, btn_refresh_rate);

    language_setting_item =
        new ListSettingItem(_("Language"), config["user_preferences"]["language"], io, 
            [](ConfigSettingItem<std::string> *item, io_service &io) {
                LOG_INFO("Language set to: %s", item->getValue().c_str());
                lv_i18n_set_locale(item->getValue().c_str());
            });
    lv_obj_t *btn_language = language_setting_item->render(other_setting_list);
    lv_group_add_obj(other_setting_group, btn_language);

    add_style_setting_list_button_style(btn_language);
    add_style_setting_list_button_style(btn_refresh_rate);
    add_style_setting_list_button_style(btn_beep);
    add_style_setting_list_button_style(btn_brightness);

    lv_group_set_wrap(other_setting_group, false);

    lv_group_focus_obj(btn_beep);
    current_selected_btn = nullptr;
    LOG_DEBUG("Other setting page initialization completed");
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
        LOG_DEBUG("Navigating other settings");
    } else {
        if (hmi_status.encoder_inc > 0) {
            key = LV_KEY_UP;
            lv_event_send(current_selected_btn, LV_EVENT_KEY, (void *)&key);
        } else {
            key = LV_KEY_DOWN;
            lv_event_send(current_selected_btn, LV_EVENT_KEY, (void *)&key);
        }
        LOG_DEBUG("Adjusting setting value");
    }
    io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
}

void OtherSettingPage::handle_short_press(uint8_t keys)
{
    lv_obj_t *focused_obj = nullptr;

    switch (keys) {
    case KEY_HMI_S:
        if (current_selected_btn) {
            lv_obj_clear_state(current_selected_btn, LV_STATE_CHECKED | LV_STATE_PRESSED);
            current_selected_btn = nullptr;
        } else {
            focused_obj = lv_group_get_focused(other_setting_group);
            if (focused_obj) {
                if (auto item = (ConfigSettingItem<int> *)lv_obj_get_user_data(focused_obj)) {
                    if (item->can_select()) {
                        current_selected_btn = focused_obj;
                        lv_obj_add_state(current_selected_btn, LV_STATE_PRESSED | LV_STATE_CHECKED);
                    } else {
                        lv_group_send_data(other_setting_group, LV_KEY_ENTER);
                    }
                }
            }
        }
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
        break;
    case KEY_M5_A:
        if (current_selected_btn) {
            lv_obj_clear_state(current_selected_btn, LV_STATE_PRESSED | LV_STATE_CHECKED);
            current_selected_btn = nullptr;
        } else {
            user_actions.goBack();
        }
        io.set_buzzer_beep(BUZZER_TONE_HIGH, BUZZER_DURATION_SHORT);
        break;
    default:
        break;
    }
}

void OtherSettingPage::update() {}

void OtherSettingPage::onExit() 
{ 
    LOG_DEBUG("Saving other settings");
    io.save_config(); 
}

void OtherSettingPage::onDestroy()
{
    LOG_DEBUG("Destroying other setting page");
    /* temporary remove the code since it will case crash, 
       could be cause by reentrancy problem
    */
   /*
    if (other_setting_list) {
        lv_obj_clean(other_setting_list);
    }
    */
    if (other_setting_group) {
        lv_group_remove_all_objs(other_setting_group);
        lv_group_del(other_setting_group);
        other_setting_group = nullptr;
    }
}
