#pragma once

#include "../page.h"
#include "setting_item.h"

class ProtectLimitPage : public Page
{
private:
    lv_obj_t *protect_limit_list;
    lv_group_t *protect_limit_group;
    lv_obj_t *current_selected_btn;

    FloatSettingItem *current_limit_item;
    FloatSettingItem *voltage_limit_item;
    IntSettingItem *power_limit_item;
    IntSettingItem *temperature_limit_item;

public:
    static const std::string PAGE_NAME;
    static const int SCREEN_ID = SCREEN_ID_PROTECT_LIMIT_PAGE;
    ProtectLimitPage(UserActions &user_actions, io_service &io) : Page(user_actions, io) {}
    void onInit() override;
    void update() override;
    void handle_encoder(const hmi_module_status &hmi_status) override;
    void handle_short_press(uint8_t keys) override;
    void onExit() override;
    void onDestroy() override;
    int getScreenId() const override { return SCREEN_ID_PROTECT_LIMIT_PAGE; }
};
