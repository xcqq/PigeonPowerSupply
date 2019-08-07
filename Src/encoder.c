#include "encoder.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_exti.h"
#include "stm32f4xx_hal_gpio.h"


#define ENCODER_PORT        GPIOB
#define ENCODER_A_PIN       GPIO_PIN_6
#define ENCODER_C_PIN       GPIO_PIN_7
#define ENCODER_KEY_PIN     GPIO_PIN_8

static int encoder_cnt = 0;

void encoder_init()
{
    GPIO_InitTypeDef GPIO_InitStructure={0};

    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitStructure.Pin = ENCODER_A_PIN;
    GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(ENCODER_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.Pin = ENCODER_C_PIN | ENCODER_KEY_PIN;
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(ENCODER_PORT, &GPIO_InitStructure);

    HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

int encoder_get_value()
{
    int ret = encoder_cnt;
    encoder_cnt = 0;
    return ret;
}

uint8_t encoder_get_key()
{
    if(HAL_GPIO_ReadPin(ENCODER_PORT, ENCODER_KEY_PIN)==RESET)
        return 1;
    else
        return 0;
}

void EXTI9_5_IRQHandler()
{
    if(HAL_GPIO_ReadPin(ENCODER_PORT, ENCODER_C_PIN)==SET)
    {
        encoder_cnt--;
    }
    else
    {
        encoder_cnt++;
    }
    HAL_GPIO_EXTI_IRQHandler(ENCODER_A_PIN);
}