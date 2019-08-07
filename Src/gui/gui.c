#include "gui.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"
#include "font.h"
#include "key.h"
#include "encoder.h"
#include "led.h"
#include <stdint.h>
#include <string.h>

#include "gui_output.h"
#include "gui_menu.h"
#include "gui_welcome.h"


osThreadId GUIControlTaskHandle;

static lv_color_t lv_screen_buf[LV_HOR_RES_MAX * LV_VER_RES_MAX/4];


struct s_gui_status gui_status = {GUI_PAGE_WELCOME, 0, 1010, 1010, 1010, 1010, 0};

bool input_read_encoder(lv_indev_drv_t * drv, lv_indev_data_t*data)
{
    data->enc_diff = encoder_get_value();
    if(encoder_get_key()==0)
        data->state = LV_INDEV_STATE_REL;
    else
        data->state = LV_INDEV_STATE_PR;
    return false;
}

bool input_read_key(lv_indev_drv_t * drv, lv_indev_data_t*data)
{
    //TODO:read key
}

void gui_lcd_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{

    lcd_draw_bmp(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (uint8_t *)color_p);
    lv_disp_flush_ready(disp_drv);
}

static void style_focus_cb(lv_group_t * group, lv_style_t * style)
{
    style->body.border.opa   = LV_OPA_COVER;
    style->body.border.color = LV_COLOR_WHITE;
    style->body.border.width = LV_DPI / 40;

    style->body.main_color   = lv_color_mix(style->body.main_color, LV_COLOR_WHITE, LV_OPA_70);
    style->body.grad_color   = lv_color_mix(style->body.grad_color, LV_COLOR_WHITE, LV_OPA_70);
    style->body.shadow.color = lv_color_mix(style->body.shadow.color, LV_COLOR_WHITE, LV_OPA_60);

    style->text.color = lv_color_mix(style->text.color, LV_COLOR_WHITE, LV_OPA_70);

    if(style->image.intense < LV_OPA_MIN) {
        style->image.color = LV_COLOR_WHITE;
        style->image.intense = LV_OPA_40;
    }
}

static void style_edit_cb(lv_group_t *group, lv_style_t *style)
{
    style->body.border.opa   = LV_OPA_COVER;
    style->body.border.color = LV_COLOR_WHITE;
    style->body.border.width = LV_DPI / 20;

    style->body.main_color   = lv_color_mix(style->body.main_color, LV_COLOR_WHITE, LV_OPA_70);
    style->body.grad_color   = lv_color_mix(style->body.grad_color, LV_COLOR_WHITE, LV_OPA_70);
    style->body.shadow.color = lv_color_mix(style->body.shadow.color, LV_COLOR_WHITE, LV_OPA_60);

    style->text.color = lv_color_mix(style->text.color, LV_COLOR_WHITE, LV_OPA_70);

    if(style->image.intense < LV_OPA_MIN) {
        style->image.color = LV_COLOR_WHITE;
        style->image.intense = LV_OPA_40;
    }
}

s_page_func page_func[] =
{
    {NULL,gui_welcome_page_enter,gui_welcome_page_update,NULL},
    {NULL,gui_output_page_enter,gui_output_page_refresh,NULL},
    {NULL,gui_menu_page_enter,NULL,NULL},
};

void gui_control_task(void const *argument)
{
    e_gui_page gui_page_last = GUI_PAGE_END;
    lv_theme_t *theme = lv_theme_night_init(210, NULL);
    lv_theme_set_current(theme);
    gui_status.gui_cont_top_bar = lv_cont_create(lv_layer_sys(), NULL);
    lv_obj_set_size(gui_status.gui_cont_top_bar, LV_HOR_RES, GUI_TOP_BAR_SIZE);
    lv_cont_set_layout(gui_status.gui_cont_top_bar, LV_LAYOUT_COL_M);
    static lv_style_t top_bar_style;
    lv_style_t *top_bar_style_old = lv_cont_get_style(gui_status.gui_cont_top_bar, LV_CONT_STYLE_MAIN);
    lv_style_copy(&top_bar_style, top_bar_style_old);
    LV_FONT_DECLARE(font_chinese_20);
    top_bar_style.text.font = &font_chinese_20;
    top_bar_style.body.radius = 0;
    top_bar_style.body.main_color = LV_COLOR_BLACK;
    lv_cont_set_style(gui_status.gui_cont_top_bar, LV_CONT_STYLE_MAIN, &top_bar_style);
    gui_status.gui_label_top_status = lv_label_create(gui_status.gui_cont_top_bar, NULL);
    lv_label_set_text(gui_status.gui_label_top_status, "");

    while (1)
    {
        switch (gui_status.gui_page)
        {
            case GUI_PAGE_WELCOME:
                lv_label_set_text(gui_status.gui_label_top_status, "欢迎使用");
                top_bar_style.body.main_color = LV_COLOR_BLACK;
                top_bar_style.body.grad_color  = LV_COLOR_BLACK;
                lv_cont_set_style(gui_status.gui_cont_top_bar, LV_CONT_STYLE_MAIN, &top_bar_style);
                break;
            case GUI_PAGE_OUTPUT:
                if(gui_status.output_enable == 0)
                {
                    top_bar_style.body.main_color = LV_COLOR_RED;
                    top_bar_style.body.grad_color  = LV_COLOR_RED;
                    lv_cont_set_style(gui_status.gui_cont_top_bar, LV_CONT_STYLE_MAIN, &top_bar_style);
                    lv_label_set_text(gui_status.gui_label_top_status, "输出关闭");
                }
                else
                {
                    top_bar_style.body.main_color = LV_COLOR_GREEN;
                    top_bar_style.body.grad_color  = LV_COLOR_GREEN;
                    lv_cont_set_style(gui_status.gui_cont_top_bar, LV_CONT_STYLE_MAIN, &top_bar_style);
                    lv_label_set_text(gui_status.gui_label_top_status, "输出开启");
                }
                break;
            case GUI_PAGE_MENU:
                lv_label_set_text(gui_status.gui_label_top_status, "设置");
                top_bar_style.body.main_color = LV_COLOR_BLACK;
                top_bar_style.body.grad_color  = LV_COLOR_BLACK;
                lv_cont_set_style(gui_status.gui_cont_top_bar, LV_CONT_STYLE_MAIN, &top_bar_style);
                break;
            default:
                break;
        }
        if(gui_page_last != gui_status.gui_page)
        {
            if (page_func[gui_status.gui_page].enter_func != NULL)
                page_func[gui_status.gui_page].enter_func();
            gui_page_last = gui_status.gui_page;
        }
        if (page_func[gui_status.gui_page].refresh_func != NULL)
            page_func[gui_status.gui_page].refresh_func();
        osDelay(100);
    }
}

//this is the task for GUI refresh
void gui_refresh_task(void const *argument)
{
    lv_disp_drv_t disp_drv;
    static lv_disp_buf_t disp_buf;

    lcd_init();
    lcd_clear();
    lv_init();
    lv_disp_buf_init(&disp_buf, lv_screen_buf, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX/4);
    lv_disp_drv_init(&disp_drv);
    disp_drv.buffer = &disp_buf;
    disp_drv.flush_cb = gui_lcd_flush;
    lv_disp_drv_register(&disp_drv);
    osThreadDef(GUIControlTask, gui_control_task, osPriorityNormal, 0, 512);
    GUIControlTaskHandle = osThreadCreate(osThread(GUIControlTask), NULL);
    osDelay(10);
    while (1)
    {
        lv_task_handler();
        led_toggle(LED_SYS_PIN);
        osDelay(1000 / 60);
    }
}