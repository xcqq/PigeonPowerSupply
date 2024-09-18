#ifndef DISPLAY_SERVICE_H
#define DISPLAY_SERVICE_H

#include "lvgl.h"
#include "M5Stack.h"

class display_service
{
private:
    lv_indev_drv_t _inter_key_indev_drv;
    lv_indev_drv_t _hmi_key_indev_drv;
    lv_indev_drv_t _hmi_encoder_indev_drv;
  void ICACHE_FLASH_ATTR lv_setup();
#ifdef KEYPAD
  void ICACHE_FLASH_ATTR keypad_setup();
#endif

  static void IRAM_ATTR update_global_vars(void);
  static void IRAM_ATTR my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area,
                                      lv_color_t *color_p);
#ifdef KEYPAD
  static void IRAM_ATTR inter_keypad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);
  static void IRAM_ATTR hmi_keypad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);
  static void IRAM_ATTR hmi_encoder_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);
#endif

public:
  display_service();
  ~display_service();

  void IRAM_ATTR setup();
  void IRAM_ATTR loop();
};
#endif