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

enum set_value_e
{
    SET_VALUE_VOLT = 0,
    SET_VALUE_CURRENT,
};

struct
{
    lv_obj_t *cont_backgroud;
    lv_obj_t *real_volt;
    lv_obj_t *real_current;
    lv_obj_t *set_volt;
    lv_obj_t *set_current;
    lv_obj_t *status;
    lv_obj_t *output_power;
    lv_obj_t *output_resistor;
    lv_obj_t *set_value_cursor;
    uint8_t set_value_step;
    enum set_value_e set_value_switch;
} update_obj_output;

static uint8_t get_step_value(step)
{
    switch (step)
    {
    case 1:
        return 1;
    case 2:
        return 10;
    case 3:
        return 100;
    case 4:
        return 1000;
    case 5:
        return 10000;
    default:
        break;
    }
}

void gui_output_page_enter()
{
    lv_obj_t *style_temp;
    update_obj_output.cont_backgroud = lv_cont_create(lv_layer_sys(), NULL);
    lv_obj_set_size(update_obj_output.cont_backgroud, LV_HOR_RES, LV_VER_RES - GUI_TOP_BAR_SIZE);
    lv_obj_align(update_obj_output.cont_backgroud, gui_status.gui_cont_top_bar, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);

    lv_obj_t *cont_real_text = lv_cont_create(update_obj_output.cont_backgroud, NULL);
    lv_obj_set_size(cont_real_text, LV_HOR_RES / 2, GUI_OUTPUT_REAL_HEIGHT);
    lv_cont_set_layout(cont_real_text, LV_LAYOUT_CENTER);
    lv_obj_align(cont_real_text, gui_status.gui_cont_top_bar, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);

    lv_obj_t *real_volt_text = lv_label_create(cont_real_text, NULL);
    lv_obj_t *real_current_text = lv_label_create(cont_real_text, NULL);
    static lv_style_t style_chinese;
    LV_FONT_DECLARE(font_chinese_30);
    style_temp = lv_label_get_style(real_volt_text, LV_LABEL_STYLE_MAIN);
    lv_style_copy(&style_chinese, style_temp);
    style_chinese.text.font = &font_chinese_30;
    style_chinese.text.color = LV_COLOR_WHITE;
    lv_label_set_style(real_volt_text, LV_LABEL_STYLE_MAIN, &style_chinese);
    lv_label_set_style(real_current_text, LV_LABEL_STYLE_MAIN, &style_chinese);
    lv_label_set_text(real_volt_text, "电压:");
    lv_label_set_text(real_current_text, "电流:");

    lv_obj_t *cont_real_value = lv_cont_create(update_obj_output.cont_backgroud, NULL);
    lv_obj_set_size(cont_real_value, LV_HOR_RES / 2, GUI_OUTPUT_REAL_HEIGHT);
    lv_cont_set_layout(cont_real_value, LV_LAYOUT_CENTER);
    lv_obj_align(cont_real_value, cont_real_text, LV_ALIGN_OUT_RIGHT_TOP, 0, 0);

    update_obj_output.real_volt = lv_label_create(cont_real_value, NULL);
    update_obj_output.real_current = lv_label_create(cont_real_value, NULL);
    static lv_style_t style_real_value;
    LV_FONT_DECLARE(font_digit_40);
    style_temp = lv_label_get_style(update_obj_output.real_volt, LV_LABEL_STYLE_MAIN);
    lv_style_copy(&style_real_value, style_temp);
    style_real_value.text.font = &font_digit_40;
    style_real_value.text.color = LV_COLOR_WHITE;
    lv_label_set_style(update_obj_output.real_volt, LV_LABEL_STYLE_MAIN, &style_real_value);
    lv_label_set_style(update_obj_output.real_current, LV_LABEL_STYLE_MAIN, &style_real_value);
    lv_label_set_text(update_obj_output.real_volt, "00.00V");
    lv_label_set_text(update_obj_output.real_current, "00.00A");

    lv_obj_t *cont_set_value = lv_cont_create(update_obj_output.cont_backgroud, NULL);
    lv_obj_set_size(cont_set_value, LV_HOR_RES, LV_VER_RES - GUI_TOP_BAR_SIZE - GUI_OUTPUT_REAL_HEIGHT);
    lv_cont_set_layout(cont_set_value, LV_LAYOUT_PRETTY);
    lv_obj_align(cont_set_value, cont_real_text, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);

    lv_obj_t *set_volt_text = lv_label_create(cont_set_value, NULL);
    update_obj_output.set_volt = lv_label_create(cont_set_value, NULL);
    lv_obj_t *set_current_text = lv_label_create(cont_set_value, NULL);
    update_obj_output.set_current = lv_label_create(cont_set_value, NULL);
    static lv_style_t style_set_text;
    LV_FONT_DECLARE(font_chinese_20);
    style_temp = lv_label_get_style(update_obj_output.real_volt, LV_LABEL_STYLE_MAIN);
    lv_style_copy(&style_set_text, style_temp);
    style_set_text.text.color = LV_COLOR_WHITE;
    style_set_text.text.font = &font_chinese_20;
    lv_label_set_style(set_volt_text, LV_LABEL_STYLE_MAIN, &style_set_text);
    lv_label_set_style(set_current_text, LV_LABEL_STYLE_MAIN, &style_set_text);
    lv_label_set_text(set_volt_text, "设定电压:");
    lv_label_set_text(set_current_text, "设定电流:");

    LV_FONT_DECLARE(font_monospace_20);
    static lv_style_t style_set_value;
    style_temp = lv_label_get_style(update_obj_output.set_volt, LV_LABEL_STYLE_MAIN);
    lv_style_copy(&style_set_value, &lv_style_scr);
    style_set_value.text.color = LV_COLOR_WHITE;
    style_set_value.text.font = &font_monospace_20;
    lv_label_set_style(update_obj_output.set_volt, LV_LABEL_STYLE_MAIN, &style_set_value);
    lv_label_set_style(update_obj_output.set_current, LV_LABEL_STYLE_MAIN, &style_set_value);
    lv_label_set_text(update_obj_output.set_volt, "00.00V");
    lv_label_set_text(update_obj_output.set_current, "00.00A");

    lv_obj_t *output_power_text = lv_label_create(cont_set_value, NULL);
    update_obj_output.output_power = lv_label_create(cont_set_value, NULL);
    lv_obj_t *output_resistor_text = lv_label_create(cont_set_value, NULL);
    update_obj_output.output_resistor = lv_label_create(cont_set_value, NULL);
    lv_label_set_style(output_power_text, LV_LABEL_STYLE_MAIN, &style_set_text);
    lv_label_set_style(output_resistor_text, LV_LABEL_STYLE_MAIN, &style_set_text);
    lv_label_set_text(output_power_text, "输出功率:");
    lv_label_set_text(output_resistor_text, "输出电阻:");

    lv_label_set_style(update_obj_output.output_power, LV_LABEL_STYLE_MAIN, &style_set_value);
    lv_label_set_style(update_obj_output.output_resistor, LV_LABEL_STYLE_MAIN, &style_set_value);
    lv_label_set_text(update_obj_output.output_power, "00.00W");
    lv_label_set_text(update_obj_output.output_resistor, "000.0Ω");

    update_obj_output.set_value_cursor = lv_label_create(update_obj_output.cont_backgroud, NULL);
    static lv_style_t style_cursor;
    style_temp = lv_label_get_style(update_obj_output.set_value_cursor, LV_LABEL_STYLE_MAIN);
    lv_style_copy(&style_cursor, style_temp);
    style_cursor.text.color = LV_COLOR_WHITE;
    style_cursor.text.font = &lv_font_roboto_12;
    lv_label_set_style(update_obj_output.set_value_cursor, LV_LABEL_STYLE_MAIN, &style_cursor);
    lv_label_set_text(update_obj_output.set_value_cursor, LV_SYMBOL_UP);
    lv_obj_align(update_obj_output.set_value_cursor, update_obj_output.set_volt, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);

    update_obj_output.set_value_step = 1;
    update_obj_output.set_value_switch = SET_VALUE_VOLT;
}

void gui_output_page_operation()
{
    if (key_read(KEY_ENCODER) == KEY_STATE_LONG_PRESS)
    {
        gui_status.gui_page = GUI_PAGE_MENU;
        lv_obj_del(update_obj_output.cont_backgroud);
    }
    if (key_read(GUI_KEY_START) == KEY_STATE_CLICK)
    {
        gui_status.output_enable = (!gui_status.output_enable) & 0x01;
    }
    if (key_read(GUI_KEY_SWITCH_CANCEL) == KEY_STATE_CLICK)
    {
        if (update_obj_output.set_value_switch == SET_VALUE_VOLT)
            update_obj_output.set_value_switch = SET_VALUE_CURRENT;
        else
            update_obj_output.set_value_switch = SET_VALUE_VOLT;
    }
    if (key_read(GUI_KEY_LEFT_MINUS) == KEY_STATE_CLICK)
    {
        if (update_obj_output.set_value_step > 1)
        {
            update_obj_output.set_value_step--;
        }
    }
    if (key_read(GUI_KEY_RIGHT_PLUS) == KEY_STATE_CLICK)
    {
        if (update_obj_output.set_value_step < 3)
        {
            update_obj_output.set_value_step++;
        }
    }

    if (update_obj_output.set_value_switch == SET_VALUE_VOLT)
    {
        int32_t temp_set_volt = gui_status.set_volt;
        temp_set_volt += encoder_get_value() * get_step_value(update_obj_output.set_value_step);
        if (temp_set_volt > 3000)
            temp_set_volt = 3000;
        else if (temp_set_volt < 0)
            temp_set_volt = 0;
        gui_status.set_volt = temp_set_volt;
    }
    else if (update_obj_output.set_value_switch == SET_VALUE_CURRENT)
    {
        int32_t temp_set_current = gui_status.set_current;
        temp_set_current += encoder_get_value() * get_step_value(update_obj_output.set_value_step);
        if (temp_set_current > 3000)
            temp_set_current = 3000;
        else if (temp_set_current < 0)
            temp_set_current = 0;
        gui_status.set_current = temp_set_current;
    }
}

void gui_output_page_refresh()
{
    char temp_text[16];
    snprintf(temp_text, sizeof(temp_text), "%02d.%02dV", gui_status.real_volt / 100, gui_status.real_volt % 100);
    lv_label_set_text(update_obj_output.real_volt, temp_text);
    snprintf(temp_text, sizeof(temp_text), "%02d.%02dA", gui_status.real_current / 100, gui_status.real_current % 100);
    lv_label_set_text(update_obj_output.real_current, temp_text);
    snprintf(temp_text, sizeof(temp_text), "%02d.%02dV", gui_status.set_volt / 100, gui_status.set_volt % 100);
    lv_label_set_text(update_obj_output.set_volt, temp_text);
    snprintf(temp_text, sizeof(temp_text), "%02d.%02dV", gui_status.set_current / 100, gui_status.set_current % 100);
    lv_label_set_text(update_obj_output.set_current, temp_text);
    snprintf(temp_text, sizeof(temp_text), "%02d.%02dW", gui_status.output_power / 100, gui_status.output_power % 100);
    lv_label_set_text(update_obj_output.output_power, temp_text);
    snprintf(temp_text, sizeof(temp_text), "%03d.%01dΩ", gui_status.output_resistor / 100, gui_status.output_resistor % 100);
    lv_label_set_text(update_obj_output.output_resistor, temp_text);
    if (update_obj_output.set_value_switch == SET_VALUE_VOLT)
    {
        //integer part
        if (update_obj_output.set_value_step > 2)
            lv_obj_align(update_obj_output.set_value_cursor, update_obj_output.set_volt, LV_ALIGN_OUT_BOTTOM_LEFT, 14 * (4 - update_obj_output.set_value_step), 0);
        //decimal part
        else
            lv_obj_align(update_obj_output.set_value_cursor, update_obj_output.set_volt, LV_ALIGN_OUT_BOTTOM_RIGHT, -14 * (update_obj_output.set_value_step), 0);
    }
    else if (update_obj_output.set_value_switch == SET_VALUE_CURRENT)
    {
        //integer part
        if (update_obj_output.set_value_step > 2)
            lv_obj_align(update_obj_output.set_value_cursor, update_obj_output.set_current, LV_ALIGN_OUT_BOTTOM_LEFT, 14 * (4 - update_obj_output.set_value_step), 0);
        //decimal part
        else
            lv_obj_align(update_obj_output.set_value_cursor, update_obj_output.set_current, LV_ALIGN_OUT_BOTTOM_RIGHT, -14 * (update_obj_output.set_value_step), 0);    }
    gui_output_page_operation();
}