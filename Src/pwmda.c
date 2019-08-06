#include "stm32f4xx_hal.h"
#include "pwmda.h"

TIM_HandleTypeDef tim3_handle;

#define PWMDA_PORT GPIOB
#define PWMDA_PIN1 GPIO_PIN_0
#define PWMDA_PIN2 GPIO_PIN_1

static void pwmda_pin_init()
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitStructure.Pin = PWMDA_PIN1 | PWMDA_PIN2;
    GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStructure.Alternate = GPIO_AF2_TIM3;
    HAL_GPIO_Init(PWMDA_PORT, &GPIO_InitStructure);
}

void pwmda_init()
{
    __HAL_RCC_TIM3_CLK_ENABLE();
    pwmda_pin_init();

    TIM_MasterConfigTypeDef master_config = {0};
    TIM_OC_InitTypeDef oc_config = {0};

    tim3_handle.Instance = TIM3;
    tim3_handle.Init.Prescaler = 1;
    tim3_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
    tim3_handle.Init.Period = 10000 - 1;
    tim3_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    if (HAL_TIM_PWM_Init(&tim3_handle) != HAL_OK)
    {
        Error_Handler();
    }
    master_config.MasterOutputTrigger = TIM_TRGO_RESET;
    master_config.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&tim3_handle, &master_config) != HAL_OK)
    {
        Error_Handler();
    }
    oc_config.OCMode = TIM_OCMODE_PWM1;
    oc_config.Pulse = 0;
    oc_config.OCPolarity = TIM_OCPOLARITY_HIGH;
    oc_config.OCFastMode = TIM_OCFAST_DISABLE;
    if (HAL_TIM_PWM_ConfigChannel(&tim3_handle, &oc_config, TIM_CHANNEL_3) != HAL_OK)
    {
        Error_Handler();
    }
    if (HAL_TIM_PWM_ConfigChannel(&tim3_handle, &oc_config, TIM_CHANNEL_4) != HAL_OK)
    {
        Error_Handler();
    }
    HAL_TIM_PWM_Start(&tim3_handle, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&tim3_handle, TIM_CHANNEL_4);
}

void pwmda_set_duty(enum e_da_channel channel, uint16_t duty)
{
    if (duty > 10000)
        duty = 10000;
    if (channel == DA_CH1)
        __HAL_TIM_SET_COMPARE(&tim3_handle, TIM_CHANNEL_3, duty);
    else if (channel == DA_CH2)
        __HAL_TIM_SET_COMPARE(&tim3_handle, TIM_CHANNEL_4, duty);
    // HAL_TIM_PWM_Start(&tim3_handle, TIM_CHANNEL_3);
    // HAL_TIM_PWM_Start(&tim3_handle, TIM_CHANNEL_4);
}