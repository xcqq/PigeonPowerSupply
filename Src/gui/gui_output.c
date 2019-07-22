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

#define GUI_OUTPUT_REAL_HEIGHT 120

struct
{
    lv_obj_t *cont_backgroud;
    lv_obj_t *real_volt;
    lv_obj_t *real_current;
    lv_obj_t *set_volt;
    lv_obj_t *set_current;
    lv_obj_t *status;
    lv_obj_t *output_power;
    lv_obj_t *input_volt;
} update_obj_output;

void gui_output_page_enter()
{
    update_obj_output.cont_backgroud=lv_cont_create(lv_layer_sys(), NULL);
    lv_obj_set_size(update_obj_output.cont_backgroud, LV_HOR_RES, LV_VER_RES - GUI_TOP_BAR_SIZE);
    lv_obj_align(update_obj_output.cont_backgroud, gui_status.gui_cont_top_bar, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);


    lv_obj_t *cont_real_text=lv_cont_create(update_obj_output.cont_backgroud, NULL);
    lv_obj_set_size(cont_real_text, LV_HOR_RES / 2, GUI_OUTPUT_REAL_HEIGHT);
    lv_cont_set_layout(cont_real_text, LV_LAYOUT_CENTER);
    lv_obj_align(cont_real_text, gui_status.gui_cont_top_bar, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);

    lv_obj_t *real_volt_text = lv_label_create(cont_real_text, NULL);
    lv_obj_t *real_current_text = lv_label_create(cont_real_text, NULL);
    static lv_style_t style_chinese;
    LV_FONT_DECLARE(font_chinese_30);
    lv_style_copy(&style_chinese, &lv_style_scr);
    style_chinese.text.font = &font_chinese_30;
    style_chinese.text.color = LV_COLOR_WHITE;
    lv_label_set_style(real_volt_text, LV_LABEL_STYLE_MAIN, &style_chinese);
    lv_label_set_style(real_current_text, LV_LABEL_STYLE_MAIN, &style_chinese);
    lv_label_set_text(real_volt_text, "电压:");
    lv_label_set_text(real_current_text, "电流:");


    lv_obj_t *cont_real_value=lv_cont_create(update_obj_output.cont_backgroud, NULL);
    lv_obj_set_size(cont_real_value, LV_HOR_RES / 2, GUI_OUTPUT_REAL_HEIGHT);
    lv_cont_set_layout(cont_real_value, LV_LAYOUT_CENTER);
    lv_obj_align(cont_real_value, cont_real_text, LV_ALIGN_OUT_RIGHT_TOP, 0, 0);

    update_obj_output.real_volt = lv_label_create(cont_real_value, NULL);
    update_obj_output.real_current = lv_label_create(cont_real_value, NULL);
    static lv_style_t style_real_value;
    LV_FONT_DECLARE(font_digit_40);
    lv_style_copy(&style_real_value, &lv_style_scr);
    style_real_value.text.font = &font_digit_40;
    style_real_value.text.color = LV_COLOR_WHITE;
    lv_label_set_style(update_obj_output.real_volt, LV_LABEL_STYLE_MAIN, &style_real_value);
    lv_label_set_style(update_obj_output.real_current, LV_LABEL_STYLE_MAIN, &style_real_value);
    lv_label_set_text(update_obj_output.real_volt, "00.00V");
    lv_label_set_text(update_obj_output.real_current, "00.00A");


    lv_obj_t *cont_set_value=lv_cont_create(update_obj_output.cont_backgroud, NULL);
    lv_obj_set_size(cont_set_value, LV_HOR_RES, LV_VER_RES - GUI_TOP_BAR_SIZE - GUI_OUTPUT_REAL_HEIGHT);
    lv_cont_set_layout(cont_set_value, LV_LAYOUT_ROW_M);
    lv_obj_align(cont_set_value, cont_real_text, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);


    lv_obj_t *set_volt_text = lv_label_create(cont_set_value, NULL);
    update_obj_output.set_volt = lv_label_create(cont_set_value, NULL);
    lv_obj_t *set_current_text = lv_label_create(cont_set_value, NULL);
    update_obj_output.set_current = lv_label_create(cont_set_value, NULL);
    static lv_style_t style_set_text;
    LV_FONT_DECLARE(font_chinese_20);
    lv_style_copy(&style_set_text, &lv_style_scr);
    style_set_text.text.color = LV_COLOR_WHITE;
    style_set_text.text.font = &font_chinese_20;
    lv_label_set_style(set_volt_text, LV_LABEL_STYLE_MAIN, &style_set_text);
    lv_label_set_style(set_current_text, LV_LABEL_STYLE_MAIN, &style_set_text);
    lv_label_set_text(set_volt_text, "设定电压:");
    lv_label_set_text(set_current_text, "设定电流:");

    static lv_style_t style_set_value;
    lv_style_copy(&style_set_value, &lv_style_scr);
    style_set_value.text.color = LV_COLOR_WHITE;
    style_set_value.text.font = &lv_font_roboto_22;
    lv_label_set_style(update_obj_output.set_volt, LV_LABEL_STYLE_MAIN, &style_set_value);
    lv_label_set_style(update_obj_output.set_current, LV_LABEL_STYLE_MAIN, &style_set_value);
    lv_label_set_text(update_obj_output.set_volt, "00.00V");
    lv_label_set_text(update_obj_output.set_current, "00.00A");

}

void gui_output_page_refresh()
{
    static uint8_t set_pos = 0;
    static uint8_t set_step = 1;
    char temp_text[16];

    snprintf(temp_text, sizeof(temp_text), "%02d.%02dV", gui_status.real_volt / 100, gui_status.real_volt % 100);
    lv_label_set_text(update_obj_output.real_volt, temp_text);
    snprintf(temp_text, sizeof(temp_text), "%02d.%02dA", gui_status.real_current / 100, gui_status.real_current % 100);
    lv_label_set_text(update_obj_output.real_current, temp_text);
    snprintf(temp_text, sizeof(temp_text), "%02d.%02dV", gui_status.set_volt / 100, gui_status.set_volt % 100);
    lv_label_set_text(update_obj_output.set_volt, temp_text);
    snprintf(temp_text, sizeof(temp_text), "%02d.%02dV", gui_status.set_current / 100, gui_status.set_current % 100);
    lv_label_set_text(update_obj_output.set_current, temp_text);


    if(key_read(KEY_ENCODER)==KEY_STATE_LONG_PRESS)
    {
        gui_status.gui_page = GUI_PAGE_MENU;
        lv_obj_del(update_obj_output.cont_backgroud);
    }
    if(key_read(KEY_4)==KEY_STATE_CLICK)
    {
        gui_status.output_enable = (!gui_status.output_enable) & 0x01;
    }
    if(key_read(KEY_3)==KEY_STATE_CLICK)
    {
        set_pos = (!set_pos) & 0x01;
    }
    if(key_read(KEY_1)==KEY_STATE_CLICK)
    {
        if(set_step>1)
        {
            set_step--;
        }
    }
    if(key_read(KEY_2)==KEY_STATE_CLICK)
    {
        if(set_step<4)
        {
            set_step++;
        }
    }
    int8_t encoder_value = encoder_get_value();
    uint8_t step;
    switch (set_step)
    {
    case 1:
        step = 1;
        break;
    case 2:
        step = 10;
        break;
    case 3:
        step = 100;
        break;
    case 4:
        step = 1000;
        break;
    default:
        break;
    }
    if (set_pos==0)
    {
        gui_status.set_volt += encoder_value*step;
    }
    else
    {
        gui_status.set_current += encoder_value*step;
    }
    
}