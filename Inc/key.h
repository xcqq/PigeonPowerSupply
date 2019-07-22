#ifndef _KEY_H
#define _KEY_H


typedef enum
{
    KEY_STATE_RELEASE,
    KEY_STATE_PRESS,
    KEY_STATE_LONG_PRESS,
    KEY_STATE_CLICK,
} key_state_e;
typedef enum
{
    KEY_1 = 0,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_ENCODER,
} key_num_e;

void key_init();
void key_task();
key_state_e key_read(key_num_e key_num);
key_state_e key_read_raw(key_num_e key_num);

#endif

