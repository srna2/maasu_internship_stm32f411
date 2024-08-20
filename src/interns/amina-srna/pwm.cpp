#include "pwm.h"


PwmTimer::PwmTimer(TIM_TypeDef* timer, uint32_t channel) : timer(timer), channel(channel) {
    // Enable clock timer
    if (timer == TIM1) {
        RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    } else if (timer == TIM2) {
        RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    } else if (timer == TIM3) {
        RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    } else if (timer == TIM4) {
        RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
    } else if (timer == TIM5) {
        RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
    } else if (timer == TIM9) {
        RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;
    } else if (timer == TIM10) {
        RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;
    } else if (timer == TIM11) {
        RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;
    }


    // Switch case to choose which channel we are using (1, 2, 3 or 4)
    switch (channel) {
        case 1:
            timer->CCMR1 |= (6 << TIM_CCMR1_OC1M_Pos); // First put OUTPUT COMPARE MODE of the timer to PWM 1   
            timer->CCMR1 |= TIM_CCMR1_OC1PE; // enables the preload feature for Channel 1.
            timer->CCER |= TIM_CCER_CC1E; // represents the Capture/Compare Enable bit for Channel 1
            break;
        case 2:
            timer->CCMR1 |= (6 << TIM_CCMR1_OC2M_Pos);
            timer->CCMR1 |= TIM_CCMR1_OC2PE;
            timer->CCER |= TIM_CCER_CC2E;
            break;
        case 3:
            timer->CCMR2 |= (6 << TIM_CCMR2_OC3M_Pos);
            timer->CCMR2 |= TIM_CCMR2_OC3PE;
            timer->CCER |= TIM_CCER_CC3E;
            break;
        case 4:
            timer->CCMR2 |= (6 << TIM_CCMR2_OC4M_Pos);
            timer->CCMR2 |= TIM_CCMR2_OC4PE;
            timer->CCER |= TIM_CCER_CC4E;
            break;
        default:
            break;
    }

    timer->CR1 |= TIM_CR1_CEN;
}


void PwmTimer::set_frequency(uint32_t frequency) {

    uint32_t timer_clock;

    if (timer == TIM1 || timer == TIM9 || timer == TIM10 || timer == TIM11) {
        timer_clock = 100000000; 
    } else if (timer == TIM2 || timer == TIM3 || timer == TIM4 || timer == TIM5) {
        timer_clock = 50000000; 
    } else {
        return;
    }
    arr_value = timer_clock / (frequency * (timer->PSC + 1));
    timer->ARR = arr_value;
}


// added special case for each channel because based on the channel we use appropriate register
void PwmTimer::set_duty_cycle(uint32_t duty_cycle) {
    uint32_t ccr_value = (duty_cycle * arr_value) / 100;
    switch (channel) {
        case 1:
            timer->CCR1 = ccr_value;
            break;
        case 2:
            timer->CCR2 = ccr_value;
            break;
        case 3:
            timer->CCR3 = ccr_value;
            break;
        case 4:
            timer->CCR4 = ccr_value;
            break;
        default:
            break;
    }
}

void PwmTimer::set_prescaler(uint32_t prescaler) {
    timer->PSC = prescaler - 1;
}
