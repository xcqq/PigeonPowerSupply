#ifndef GUI_H_
#define GUI_H_

#include "lvgl.h"

#define GUI_TOP_BAR_SIZE 35
typedef enum
{
    GUI_PAGE_WELCOME = 0,
    GUI_PAGE_OUTPUT,
    GUI_PAGE_MENU,
    GUI_PAGE_MENU_ITEM,
    GUI_PAGE_END,
}e_gui_page;

typedef enum 
{
    MENU_ITEM_QUICK_VOLT = 0,
    MENU_ITEM_QUICK_CURRENT,
    MENU_ITEM_CALIBRATION,
    MENU_ITEM_UPGRADE_FIRMWARE,
    MENU_ITEM_ABOUT,
}e_menu_item;

typedef struct
{
    lv_obj_t *page;
    void (*enter_func)();
    void (*refresh_func)();
    void (*exit_func)();
    void *update_obj;
}s_page_func;

struct s_gui_status
{
    e_gui_page gui_page;
    e_menu_item menu_item;

    uint16_t set_current;
    uint16_t set_volt;
    uint16_t real_current;
    uint16_t real_volt;
    uint16_t output_power;
    uint16_t output_resistor;
    uint8_t output_enable;

    lv_obj_t *gui_cont_top_bar;
    lv_obj_t *gui_label_top_status;
};

#define GUI_KEY_START           KEY_4
#define GUI_KEY_SWITCH_CANCEL   KEY_3
#define GUI_KEY_RIGHT_PLUS      KEY_2
#define GUI_KEY_LEFT_MINUS      KEY_1

extern struct s_gui_status gui_status;

void gui_control_task(void const *argument);
void gui_refresh_task(void const *argument);
bool input_read_encoder(lv_indev_drv_t *drv, lv_indev_data_t *data);
bool input_read_key(lv_indev_drv_t *drv, lv_indev_data_t *data);


#endif