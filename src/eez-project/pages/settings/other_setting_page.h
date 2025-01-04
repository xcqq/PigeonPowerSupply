#pragma once

#include "../page.h"
#include "setting_item.h"
#include <string>

using std::string;

class OtherSettingPage : public Page
{
private:
    lv_obj_t *other_setting_list;
    lv_group_t *other_setting_group;
    lv_obj_t *current_selected_btn;
    BoolSettingItem *beep_setting_item;
    IntSettingItem *brightness_setting_item;
    ListSettingItem *refresh_rate_setting_item;
    ListSettingItem *language_setting_item;

public:
    static const std::string PAGE_NAME;
    static const int SCREEN_ID = SCREEN_ID_OTHER_SETTING_PAGE;
    OtherSettingPage(UserActions &user_actions, io_service &io) : Page(user_actions, io) {}
    void onInit() override;
    void onEnter() override;
    void update() override;
    void handle_short_press(uint8_t keys) override;
    void handle_encoder(const hmi_module_status &hmi_status) override;
    void onExit() override;
    void onDestroy() override;
    int getScreenId() const override { return SCREEN_ID_OTHER_SETTING_PAGE; }
};
