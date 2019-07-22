#ifndef __LCD_H
#define __LCD_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

#define LCD_LANDSCAPE
#ifdef LCD_LANDSCAPE
#define LCD_WIDTH (432)
#define LCD_HEIGHT (240)
#else
#define LCD_WIDTH (240)
#define LCD_HEIGHT (432)
#endif

#define RED 0xf800
#define GREEN 0x07e0
#define BLUE 0x001f
#define WHITE 0xffff
#define BLACK 0x0000
#define YELLOW 0xFFE0
#define RGB(R, G, B) ((uint16_t)((((R) >> 3) << 11) | (((G) >> 2) << 5) | ((B) >> 3)))

void lcd_init();
void lcd_clear();
void lcd_display_color_bar(void);
void lcd_display_gray_bar(void);
void lcd_draw_bmp(uint16_t x_start, uint16_t y_start, uint16_t width, uint16_t height, uint8_t *bmp);

#endif // !__LCD_H