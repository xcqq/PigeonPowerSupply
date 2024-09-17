#include "styles.h"
#include "images.h"
#include "fonts.h"

void apply_style_home_set_num_label_style(lv_obj_t *obj) {
    lv_obj_set_style_text_font(obj, &ui_font_lcd_font_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_home_out_num_label_style(lv_obj_t *obj) {
    lv_obj_set_style_text_font(obj, &ui_font_roboto_50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff767676), LV_PART_MAIN | LV_STATE_DISABLED);
};
void apply_style_home_bar_num_style(lv_obj_t *obj) {
    lv_obj_set_style_text_font(obj, &ui_font_lcd_font_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_home_bar_label_style(lv_obj_t *obj) {
    apply_style_home_bar_num_style(obj);
    lv_obj_set_style_text_font(obj, &ui_font_roboto_10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_home_set_text_label_style(lv_obj_t *obj) {
    lv_obj_set_style_text_font(obj, &ui_font_roboto_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff767676), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff767676), LV_PART_MAIN | LV_STATE_DISABLED);
};
void apply_style_home_out_text_label_style(lv_obj_t *obj) {
    apply_style_home_set_text_label_style(obj);
    lv_obj_set_style_text_font(obj, &ui_font_roboto_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
};
void apply_style_home_set_volt_spinbox(lv_obj_t *obj) {
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_CURSOR | LV_STATE_DISABLED);
    lv_obj_set_style_text_font(obj, &ui_font_roboto_24, LV_PART_CURSOR | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(obj, 0, LV_PART_CURSOR | LV_STATE_DISABLED);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_CURSOR | LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff3b30), LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(obj, &ui_font_roboto_24, LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(obj, 4, LV_PART_CURSOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(obj, &ui_font_roboto_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(obj, 0, LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_outline_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DISABLED);
};
void apply_style_home_set_curr_spinbox(lv_obj_t *obj) {
    apply_style_home_set_volt_spinbox(obj);
    lv_obj_set_style_outline_color(obj, lv_color_hex(0xff521414), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff34c759), LV_PART_CURSOR | LV_STATE_DEFAULT);
};
void apply_style_home_out_title_style(lv_obj_t *obj) {
    lv_obj_set_style_text_font(obj, &ui_font_roboto_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
};

