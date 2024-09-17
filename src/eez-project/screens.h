#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *home_page;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *outa_text_label;
    lv_obj_t *outc_num_label;
    lv_obj_t *outv_num_label;
    lv_obj_t *outv_text_label;
    lv_obj_t *seta_spinbox;
    lv_obj_t *seta_text_label;
    lv_obj_t *setv_spinbox;
    lv_obj_t *setv_text_label;
    lv_obj_t *vin_text_label;
    lv_obj_t *vin_text_label_1;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_HOME_PAGE = 1,
    SCREEN_ID_MY_SPIN_BOX = 2,
};

void create_screen_home_page();
void tick_screen_home_page();

void create_user_widget_my_spin_box(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_my_spin_box(void *flowState, int startWidgetIndex);

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/