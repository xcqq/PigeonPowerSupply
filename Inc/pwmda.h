#ifndef _PWMDA_H_
#define _PWMDA_H_

enum e_da_channel
{
    DA_CH1,
    DA_CH2,
};

#include <stdint.h>
void pwmda_init();
void pwmda_set_duty(enum e_da_channel channel, uint16_t duty);

#endif // !_PWMDA_H_