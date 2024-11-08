#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: home_set_num_label_style
lv_style_t *get_style_home_set_num_label_style_MAIN_DEFAULT();
void add_style_home_set_num_label_style(lv_obj_t *obj);
void remove_style_home_set_num_label_style(lv_obj_t *obj);

// Style: home_out_num_label_style
lv_style_t *get_style_home_out_num_label_style_MAIN_DEFAULT();
lv_style_t *get_style_home_out_num_label_style_MAIN_DISABLED();
void add_style_home_out_num_label_style(lv_obj_t *obj);
void remove_style_home_out_num_label_style(lv_obj_t *obj);

// Style: home_bar_num_style
lv_style_t *get_style_home_bar_num_style_MAIN_DEFAULT();
void add_style_home_bar_num_style(lv_obj_t *obj);
void remove_style_home_bar_num_style(lv_obj_t *obj);

// Style: home_bar_label_style
lv_style_t *get_style_home_bar_label_style_MAIN_DEFAULT();
void add_style_home_bar_label_style(lv_obj_t *obj);
void remove_style_home_bar_label_style(lv_obj_t *obj);

// Style: home_set_text_label_style
lv_style_t *get_style_home_set_text_label_style_MAIN_DEFAULT();
lv_style_t *get_style_home_set_text_label_style_MAIN_DISABLED();
void add_style_home_set_text_label_style(lv_obj_t *obj);
void remove_style_home_set_text_label_style(lv_obj_t *obj);

// Style: home_out_text_label_style
lv_style_t *get_style_home_out_text_label_style_MAIN_DEFAULT();
lv_style_t *get_style_home_out_text_label_style_MAIN_DISABLED();
void add_style_home_out_text_label_style(lv_obj_t *obj);
void remove_style_home_out_text_label_style(lv_obj_t *obj);

// Style: home_set_volt_spinbox
lv_style_t *get_style_home_set_volt_spinbox_CURSOR_DISABLED();
lv_style_t *get_style_home_set_volt_spinbox_CURSOR_DEFAULT();
lv_style_t *get_style_home_set_volt_spinbox_MAIN_DEFAULT();
lv_style_t *get_style_home_set_volt_spinbox_MAIN_DISABLED();
void add_style_home_set_volt_spinbox(lv_obj_t *obj);
void remove_style_home_set_volt_spinbox(lv_obj_t *obj);

// Style: home_set_curr_spinbox
lv_style_t *get_style_home_set_curr_spinbox_MAIN_DEFAULT();
lv_style_t *get_style_home_set_curr_spinbox_MAIN_DISABLED();
lv_style_t *get_style_home_set_curr_spinbox_CURSOR_DEFAULT();
lv_style_t *get_style_home_set_curr_spinbox_CURSOR_DISABLED();
void add_style_home_set_curr_spinbox(lv_obj_t *obj);
void remove_style_home_set_curr_spinbox(lv_obj_t *obj);

// Style: home_out_title_style
lv_style_t *get_style_home_out_title_style_MAIN_DEFAULT();
void add_style_home_out_title_style(lv_obj_t *obj);
void remove_style_home_out_title_style(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/