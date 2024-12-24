#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_update_power_module_status(lv_event_t * e);
extern void action_init_power_module_status(lv_event_t * e);
extern void action_init_root_setting_page(lv_event_t * e);
extern void action_update_root_setting_page(lv_event_t * e);
extern void action_init_about_page(lv_event_t * e);
extern void action_update_about_page(lv_event_t * e);
extern void action_init_protect_limit_page(lv_event_t * e);
extern void action_update_protect_limit_page(lv_event_t * e);
extern void action_init_other_setting_page(lv_event_t * e);
extern void action_update_other_setting_page(lv_event_t * e);
extern void action_init_recall_setting_page(lv_event_t * e);
extern void action_update_recall_setting_page(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/