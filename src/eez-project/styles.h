#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void apply_style_home_set_num_label_style(lv_obj_t *obj);
extern void apply_style_home_out_num_label_style(lv_obj_t *obj);
extern void apply_style_home_bar_num_style(lv_obj_t *obj);
extern void apply_style_home_bar_label_style(lv_obj_t *obj);
extern void apply_style_home_set_text_label_style(lv_obj_t *obj);
extern void apply_style_home_out_text_label_style(lv_obj_t *obj);
extern void apply_style_home_set_volt_spinbox(lv_obj_t *obj);
extern void apply_style_home_set_curr_spinbox(lv_obj_t *obj);
extern void apply_style_home_out_title_style(lv_obj_t *obj);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/