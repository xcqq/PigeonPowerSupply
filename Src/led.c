#include "led.h"


void led_init()
{
    GPIO_InitTypeDef GPIO_InitStruct={0};

    __HAL_RCC_GPIOE_CLK_ENABLE();
    GPIO_InitStruct.Pin = LED_SYS_PIN | LED_FAULT_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);

}

void led_set(uint16_t led_pin,uint8_t value)
{
    HAL_GPIO_WritePin(LED_PORT, led_pin, value);
}

void led_toggle(uint16_t led_pin)
{
    HAL_GPIO_TogglePin(LED_PORT, led_pin);
}
