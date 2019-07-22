#include "gui.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#include "lvgl.h"
#include "font.h"
#include "key.h"
#include "encoder.h"
#include "led.h"
#include <stdint.h>
#include <string.h>

struct
{
    lv_obj_t *progress_bar;
    lv_obj_t *backgroud;
} update_obj_welcome;

void gui_welcome_page_enter()
{
    LV_IMG_DECLARE(img_welcome_logo);

    update_obj_welcome.backgroud = lv_cont_create(lv_scr_act(), NULL);
    lv_obj_set_size(update_obj_welcome.backgroud, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_pos(update_obj_welcome.backgroud, 0, 0);

    lv_obj_set_auto_realign(update_obj_welcome.backgroud, true); /*Auto realign when the size changes*/
    lv_cont_set_layout(update_obj_welcome.backgroud, LV_LAYOUT_CENTER);
    lv_style_t *style_backgroud = lv_cont_get_style(update_obj_welcome.backgroud, LV_CONT_STYLE_MAIN);
    style_backgroud->body.padding.inner = 20;
    style_backgroud->body.radius = 0;
    lv_cont_set_style(update_obj_welcome.backgroud, LV_CONT_STYLE_MAIN, style_backgroud);

    lv_obj_t *cont_welcome_label = lv_cont_create(update_obj_welcome.backgroud, NULL);
    lv_obj_align_origo(cont_welcome_label, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_auto_realign(cont_welcome_label, true);
    lv_cont_set_fit(cont_welcome_label, LV_FIT_TIGHT);
    lv_cont_set_layout(cont_welcome_label, LV_LAYOUT_ROW_M);

    lv_obj_t *img_welcome = lv_img_create(cont_welcome_label, NULL);
    lv_img_set_src(img_welcome, &img_welcome_logo);
    lv_obj_t *label_welcome = lv_label_create(cont_welcome_label, NULL);
    LV_FONT_DECLARE(font_chinese);
    lv_style_t *style_chinese = lv_label_get_style(label_welcome, LV_LABEL_STYLE_MAIN);
    style_chinese->text.font = &font_chinese;
    lv_label_set_style(label_welcome, LV_LABEL_STYLE_MAIN, style_chinese);
    lv_label_set_text(label_welcome, "鸽子数控电源");

    update_obj_welcome.progress_bar = lv_bar_create(update_obj_welcome.backgroud, NULL);
    lv_style_t *style_bar = lv_bar_get_style(update_obj_welcome.progress_bar, LV_BAR_STYLE_INDIC);
    style_bar->body.main_color = LV_COLOR_WHITE;
    style_bar->body.grad_color = LV_COLOR_WHITE;
    style_bar->body.main_color = LV_COLOR_WHITE;
    lv_obj_set_size(update_obj_welcome.progress_bar, 200, 10);
    lv_bar_set_range(update_obj_welcome.progress_bar, 0, 100);
    lv_bar_set_anim_time(update_obj_welcome.progress_bar, 1000);
    lv_bar_set_value(update_obj_welcome.progress_bar, 100, LV_ANIM_ON);
}

void gui_welcome_page_update()
{
    osDelay(1100);
    gui_status.gui_page = GUI_PAGE_OUTPUT;
    lv_obj_del(update_obj_welcome.backgroud);
}