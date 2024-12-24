#include "protect_limit_page.h"

void ProtectLimitPage::init() {
    lv_obj_t *protect_limit_list = objects.protect_limit_list;
    protect_limit_group = lv_group_create();
    lv_obj_clean(protect_limit_list);
}

void ProtectLimitPage::update() {

}
