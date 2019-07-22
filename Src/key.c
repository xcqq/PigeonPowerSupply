#include "key.h"
#include "stm32f4xx_hal.h"
#include "stdio.h"

#define KEY_PULLUP

#ifdef KEY_PULLUP
#define KEY_PRESS RESET
#define KEY_RELEASE SET
#endif // KEY_PULLUP
#ifdef KEY_PULLDOWN
#ifdef KEY_PULLUP
#error "You can't define pullup and pulldown at the same time"
#endif
#define KEY_PRESS SET
#define KEY_RELEASE RESET
#endif // KEY_PULLDOWN

#define LONG_PRESS_SHORT    500
#define LONG_PRESS_MIDIUM   1000
#define LONG_PRESS_SLOW     5000


#define ENCODER_PORT        GPIOB
#define ENCODER_KEY_PIN     GPIO_PIN_8

typedef struct
{
    GPIO_TypeDef *port;
    uint16_t pin;
    key_state_e state;
    key_state_e last_state;
    uint16_t press_time;
    uint16_t long_press_threshold;
    // uint8_t continuous_long_press;
} key_data_t;

key_data_t key_data[] = {
    {GPIOE, GPIO_PIN_5, 0, 0, 0, LONG_PRESS_MIDIUM},
    {GPIOE, GPIO_PIN_4, 0, 0, 0, LONG_PRESS_MIDIUM},
    {GPIOE, GPIO_PIN_3, 0, 0, 0, LONG_PRESS_MIDIUM},
    {GPIOE, GPIO_PIN_2, 0, 0, 0, LONG_PRESS_MIDIUM},
    {ENCODER_PORT, ENCODER_KEY_PIN, 0, 0, 0, LONG_PRESS_MIDIUM},    
    NULL,
};

void key_init()
{
    GPIO_InitTypeDef GPIO_InitStructure={0};
    uint8_t i;

    __HAL_RCC_GPIOE_CLK_ENABLE();
    for (i = 0; key_data[i].port != 0; i++)
    {
            GPIO_InitStructure.Pin |= key_data[i].pin;
            
    }
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);
}

key_state_e key_read(key_num_e key_num)
{
    if (key_data[key_num].state == KEY_STATE_CLICK)
    {
        key_data[key_num].state = KEY_STATE_RELEASE;
        return KEY_STATE_CLICK;
    }
    else if (key_data[key_num].state == KEY_STATE_LONG_PRESS)
    {
        key_data[key_num].state = KEY_STATE_RELEASE;
        return KEY_STATE_LONG_PRESS;
    }
    else
    {
        return key_data[key_num].state;
    }
}

//return raw key level, used for GUI
key_state_e key_read_raw(key_num_e key_num)
{
    if(HAL_GPIO_ReadPin(key_data[key_num].port, key_data[key_num].pin)==RESET)
        return KEY_STATE_PRESS;
    else
        return KEY_STATE_RELEASE;
}

void key_task()
{
    uint8_t i, current_level;
    for (i = 0; key_data[i].port != NULL; i++)
    {
        current_level = HAL_GPIO_ReadPin(key_data[i].port, key_data[i].pin);
        if (key_data[i].last_state == KEY_STATE_RELEASE)
        {
            if (current_level == KEY_PRESS)
            {
                key_data[i].last_state = KEY_STATE_PRESS;
                key_data[i].state = KEY_STATE_PRESS;
            }
            else
            {
                key_data[i].last_state = KEY_STATE_RELEASE;
                key_data[i].press_time = 0;
            }
        }
        else if (key_data[i].last_state == KEY_STATE_PRESS)
        {
            if (current_level == KEY_PRESS)
            {
                key_data[i].last_state = KEY_STATE_PRESS;
                if (key_data[i].press_time < LONG_PRESS_SLOW + 1)
                    key_data[i].press_time++;
            }
            else
            {
                key_data[i].last_state = KEY_STATE_RELEASE;
                if (key_data[i].press_time >= key_data[i].long_press_threshold)
                    key_data[i].state = KEY_STATE_LONG_PRESS;
                else
                    key_data[i].state = KEY_STATE_CLICK;
                key_data[i].press_time = 0;
            }
        }
    }
}