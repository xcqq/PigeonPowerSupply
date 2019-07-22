#ifndef __LED_H
#define __LED_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include <stdint.h>


#define LED_PORT        GPIOE
#define LED_SYS_PIN     GPIO_PIN_1
#define LED_FAULT_PIN   GPIO_PIN_0

void led_init();
void led_set(uint16_t led_pin, uint8_t value);
void led_toggle(uint16_t led_pin);

#endif // !__LED_H
