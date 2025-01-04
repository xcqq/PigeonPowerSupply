#pragma once

#include "../page.h"
#include "setting_item.h"
#include <memory>
#include <vector>

class RootSettingPage : public Page {
private:
    lv_obj_t *setting_list;
    lv_group_t *setting_group;
    lv_obj_t *btn_protect;
    lv_obj_t *btn_other;
    lv_obj_t *btn_about;
    
public:
    static const std::string PAGE_NAME;
    static const int SCREEN_ID = SCREEN_ID_ROOT_SETTING_PAGE;
    RootSettingPage(UserActions& user_actions, io_service& io) : Page(user_actions, io) {}
    void onInit() override;
    void onEnter() override;
    void update() override;
    void handle_short_press(uint8_t keys) override;
    void handle_encoder(const hmi_module_status& hmi_status) override;
    void onDestroy() override;
    int getScreenId() const override { return SCREEN_ID_ROOT_SETTING_PAGE; }
}; 
