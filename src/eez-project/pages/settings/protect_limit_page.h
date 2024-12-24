#pragma once

#include "../page.h"

class ProtectLimitPage : public Page {
private:
    lv_obj_t *protect_limit_list;
    lv_group_t *protect_limit_group;
public:
    ProtectLimitPage(io_service& io_service) : Page(io_service) {}
    void init() override;
    void update() override;
};
