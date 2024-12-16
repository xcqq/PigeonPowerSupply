#include <lvgl.h>

#include "M5Stack.h"
#include "actions.h"
#include "io_service.h"
#include "screens.h"
#include "structs.h"
#include "ui.h"
#include "vars.h"
#include "config.h"
#include "pages/home_page.h"
#include "pages/settings/root_setting_page.h"
#include "pages/settings/about_page.h"

extern io_service io;
HomePage home_page(io);
RootSettingPage root_setting_page(io);
AboutPage about_page(io);

void IRAM_ATTR action_init_power_module_status(lv_event_t *e) {
    home_page.init();
}

void IRAM_ATTR action_update_power_module_status(lv_event_t *e) {
    home_page.update();
}

void IRAM_ATTR action_init_setting_page(lv_event_t *e) {
    root_setting_page.init();
}

void IRAM_ATTR action_update_setting_page(lv_event_t *e) {
    root_setting_page.update();
}

void IRAM_ATTR action_init_about_page(lv_event_t *e) {
    about_page.init();
}

void IRAM_ATTR action_update_about_page(lv_event_t *e) {
    about_page.update();
}