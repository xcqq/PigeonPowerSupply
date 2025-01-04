#include "config.h"
#include "display_service.h"
#include "eez-project/ui.h"
#include "esp_freertos_hooks.h"
#include <Arduino.h>
#include <lvgl.h>
#include "io_service.h"
#include "eez-project/ui.h"
#include "eez-project/vars.h"
#include "eez-project/structs.h"
#include "io_service.h"
#include "M5Stack.h"

#ifdef KEYPAD
#include "keypad.h"
#endif


display_service::display_service() {}
display_service::~display_service() {}

static void lv_tick_task();
static lv_disp_draw_buf_t disp_buf;
static lv_color_t buf1[DISP_BUF_SIZE];

/* =============================icache functions========================= */
#ifdef KEYPAD
extern lv_group_t *keypad_group;
void ICACHE_FLASH_ATTR display_service::keypad_setup()
{
#if 1
    lv_indev_t *keypad_indev;

    lv_indev_drv_init(&_inter_key_indev_drv);
    _inter_key_indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    _inter_key_indev_drv.read_cb = inter_keypad_read;
    keypad_indev = lv_indev_drv_register(&_inter_key_indev_drv);

    lv_indev_set_group(keypad_indev, keypad_group);

    // lv_indev_drv_init(&_hmi_key_indev_drv);
    // _hmi_key_indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    // _hmi_key_indev_drv.read_cb = hmi_keypad_read;
    // keypad_indev = lv_indev_drv_register(&_hmi_key_indev_drv);
    // lv_indev_set_group(keypad_indev, keypad_group);

    // lv_indev_drv_init(&_hmi_encoder_indev_drv);
    // _hmi_encoder_indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    // _hmi_encoder_indev_drv.read_cb = hmi_encoder_read;
    // keypad_indev = lv_indev_drv_register(&_hmi_encoder_indev_drv);
    // lv_indev_set_group(keypad_indev, keypad_group);
#endif
}
#endif

static void IRAM_ATTR lv_tick_task(TimerHandle_t xTimer) { lv_tick_inc(portTICK_PERIOD_MS); }

void ICACHE_FLASH_ATTR display_service::lv_setup()
{
    lv_init();

    M5.Lcd.begin(); /* TFT init */
    M5.Lcd.invertDisplay(1);
    M5.Lcd.setRotation(ROTATION); /* Landscape orientation */
    lv_color_t *buf2 = (lv_color_t *)malloc(DISP_BUF_SIZE * sizeof(lv_color_t));
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, DISP_BUF_SIZE);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.full_refresh = 0;
    disp_drv.draw_buf = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    ui_init();

    extern void ui_init_input_groups();
    ui_init_input_groups();
}

void ICACHE_FLASH_ATTR display_service::setup()
{
    lv_setup();
    TimerHandle_t timer = xTimerCreate("lv_tick_task", pdMS_TO_TICKS(1), pdTRUE, NULL, lv_tick_task);
    if (timer == NULL) {
        return;
    }

    if (xTimerStart(timer, 0) != pdPASS) {
        return;
    }

#ifdef KEYPAD
    keypad_setup();
#endif
} // end display service setup

/* =========================end icache functions======================== */

#ifdef KEYPAD
extern io_service io;
void IRAM_ATTR display_service::inter_keypad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    uint32_t button;
    bool isPressed;

    m5stack_keypad_read(button, isPressed);

    data->key = 0;
    switch (button) {
    case MY_BUTTON_A:
        data->key = LV_KEY_BACKSPACE;
        break;
    case MY_BUTTON_B:
        data->key = LV_KEY_UP;
        break;
    case MY_BUTTON_C:
        data->key = LV_KEY_DOWN;
        break;
    }

    if (isPressed) {
        data->state = LV_INDEV_STATE_PRESSED;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void IRAM_ATTR display_service::hmi_keypad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    struct hmi_module_status hmi_status;
    static int last_button = 0;

    hmi_status = io.get_hmi_module_status();
    if (!hmi_status.button_1) {
        data->key = LV_KEY_PREV;
        last_button = LV_KEY_PREV;
        data->state = LV_INDEV_STATE_PRESSED;
    } else if (!hmi_status.button_2) {
        last_button = LV_KEY_NEXT;
        data->key = LV_KEY_NEXT;
            data->state = LV_INDEV_STATE_PRESSED;
    } else if (!hmi_status.button_s) {
        data->key = LV_KEY_ENTER;
        last_button = LV_KEY_ENTER;
        data->state = LV_INDEV_STATE_PRESSED;
    } else if (last_button) {
        data->key = last_button;
        last_button = 0;
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void IRAM_ATTR display_service::hmi_encoder_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    struct hmi_module_status hmi_status;

    hmi_status = io.get_hmi_module_status();
    data->enc_diff = hmi_status.encoder_inc;
    if (!hmi_status.button_s)
        data->state = LV_INDEV_STATE_PRESSED;
    else
        data->state = LV_INDEV_STATE_RELEASED;
}
#endif

void IRAM_ATTR display_service::loop()
{
    lv_timer_handler();
    ui_tick();
    delay(5);
} // end loop

void IRAM_ATTR display_service::my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area,
                                              lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    M5.Lcd.setAddrWindow(area->x1, area->y1, w, h);
    M5.Lcd.startWrite();
    M5.Lcd.setSwapBytes(true);
    M5.Lcd.pushColors(&color_p->full, w * h); // Push line to screen
    M5.Lcd.endWrite();

    lv_disp_flush_ready(disp);
}

/* ===========================end iram functions=========================== */