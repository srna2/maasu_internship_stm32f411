#ifndef PWM_H
#define PWM_H

#include "stm32f4xx.h"

class PwmTimer {
    public:
        PwmTimer(TIM_TypeDef* timer, uint32_t channel);
        void set_frequency(uint32_t frequency);
        void set_duty_cycle(uint32_t duty_cycle);
        void set_prescaler(uint32_t prescaler);

    private:
        TIM_TypeDef* timer;
        uint32_t channel;
        uint32_t arr_value;
};

#endif // PWM_H
