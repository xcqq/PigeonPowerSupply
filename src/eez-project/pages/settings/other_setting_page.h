#pragma once

#include "../page.h"
#include "setting_item.h"

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
    OtherSettingPage(io_service &io_service) : Page(io_service) {}
    void init() override;
    void update() override;
    void handle_short_press(uint8_t keys) override;
    void handle_encoder(const hmi_module_status &hmi_status) override;
};
