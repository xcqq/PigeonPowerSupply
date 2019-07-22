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
    lv_obj_t *cont_backgroud;
} update_obj_menu;

void gui_menu_list_cb(lv_obj_t * obj, lv_event_t event)
{
    uint8_t index = 0;
    if (event == LV_EVENT_VALUE_CHANGED)
    {
        index = lv_roller_get_selected(obj);
        switch(index)
        {
            case 5:
                gui_status.gui_page = GUI_PAGE_OUTPUT;
                break;
            default:
                break;
        }
        lv_obj_del(update_obj_menu.cont_backgroud);
    }
}

void gui_menu_page_enter()
{
    update_obj_menu.cont_backgroud = lv_cont_create(lv_layer_sys(), NULL);
    lv_obj_set_size(update_obj_menu.cont_backgroud, LV_HOR_RES, LV_VER_RES - GUI_TOP_BAR_SIZE);
    lv_obj_align(update_obj_menu.cont_backgroud, gui_status.gui_cont_top_bar, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);


    LV_IMG_DECLARE(img_update);
    LV_IMG_DECLARE(img_volt);
    LV_IMG_DECLARE(img_current);
    LV_IMG_DECLARE(img_update);
    LV_IMG_DECLARE(img_about);
    LV_IMG_DECLARE(img_calibration);

    lv_obj_t *roller = lv_roller_create(update_obj_menu.cont_backgroud, NULL);
    lv_roller_set_fix_width(roller, LV_HOR_RES);

    LV_FONT_DECLARE(font_chinese_30);
    lv_style_t *style_chinese = lv_roller_get_style(roller, LV_ROLLER_STYLE_BG);
    style_chinese->text.font = &font_chinese_30;
    style_chinese->text.line_space = 40;
    lv_roller_set_style(roller, LV_ROLLER_STYLE_BG, style_chinese);
    style_chinese = lv_roller_get_style(roller, LV_ROLLER_STYLE_SEL);
    style_chinese->text.font = &font_chinese_30;
    lv_roller_set_style(roller, LV_ROLLER_STYLE_SEL, style_chinese);

    lv_roller_set_options(roller,
                          "快捷电压\n"
                          "快捷电流\n"
                          "校准\n"
                          "固件升级\n"
                          "关于\n"
                          "退出",
                          LV_ROLLER_MODE_NORMAL);

    lv_roller_set_visible_row_count(roller, 4);
    lv_obj_align(roller, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_event_cb(roller, gui_menu_list_cb);

    lv_group_t *group = lv_group_create();
    lv_group_add_obj(group, roller);
    lv_group_set_editing(group, roller);
    lv_group_focus_freeze(group, roller);

    lv_group_set_style_mod_cb(group, NULL);
    lv_group_set_style_mod_edit_cb(group, NULL);

    lv_indev_drv_t encoder_drv;
    lv_indev_drv_init(&encoder_drv);
    encoder_drv.type = LV_INDEV_TYPE_ENCODER;
    encoder_drv.read_cb = input_read_encoder;
    lv_indev_t *encoder_indev = lv_indev_drv_register(&encoder_drv);
    lv_indev_set_group(encoder_indev, group);
}

void gui_menu_page_refresh()
{
}