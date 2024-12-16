#pragma once

#include "../page.h"
#include "setting_item.h"
#include <memory>
#include <vector>

class RootSettingPage : public Page {
private:
    lv_obj_t *setting_list;
    lv_group_t *setting_group;
    
public:
    RootSettingPage(io_service& io_service) : Page(io_service) {}
    void init() override;
    void update() override;
    void handle_short_press(uint8_t keys) override;
    void handle_encoder(const hmi_module_status& hmi_status) override;
}; 