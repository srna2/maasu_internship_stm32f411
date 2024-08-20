#include <stdint.h>
#include <stdio.h>
#include "gpio.h"
#include "usart.h"
#include "pwm.h"
#include "stm32f4xx.h"

//#define STM32F411xE


uint32_t ticks{};

void systick_handler() {
    ticks++;
}

void delay_ms(const uint32_t &ms) {
    uint32_t start = ticks;
    uint32_t end = start + ms;

    // Check overflow
    if (end < start)
        while (ticks > start);

    // Wait for ticks to wrap around to zero
    while (ticks < end);
}

void clock_init() {
    // Enable external clock source
    RCC->CR |= RCC_CR_HSEBYP;
    RCC->CR |= RCC_CR_HSEON;

    // Wait to be ready (HSE oscillator)
    while (!(RCC->CR & RCC_CR_HSERDY));

    // Enable power controller
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;

    // Set voltage scale to scale 1 (for the maximum performance)
    PWR->CR &= ~PWR_CR_VOS;
    PWR->CR |= PWR_CR_VOS;

    // Configure flash controller to 3 wait states
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;

    // Clear and config PLLM, PLLN, PLLP 
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLP);
    RCC->PLLCFGR |= ((4 << RCC_PLLCFGR_PLLM_Pos) | (200 << RCC_PLLCFGR_PLLN_Pos) | (1 << RCC_PLLCFGR_PLLP_Pos)) | RCC_PLLCFGR_PLLSRC_HSE;

    // Set APB1 prescaler so its frq = 50 MHz 
    RCC->CFGR &= ~RCC_CFGR_PPRE1;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

    // Enable PLL
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // Select PLL output as system clock
    RCC->CFGR |= (RCC_CFGR_SW_PLL << RCC_CFGR_SW_Pos);
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL));

    SystemCoreClockUpdate();
}

// Create a Usart instance for USART2
Usart usart2(USART2);

// Create a Pwm instance for TIM3 and Channel 1
PwmTimer pwm_timer_tim3_ch1(TIM3, 1);

void usart_init() {
    Gpio pa2(GPIOA, 2);
    pa2.set_mode(2);
    pa2.set_alt_func(7);

    Gpio pa3(GPIOA, 3);
    pa3.set_mode(2);
    pa3.set_alt_func(7);

    usart2.init(115200, 16); // Initialize USART2
}

void pwm_init() {
    // Initialize PWM for TIM3 Channel 1 with prescaler and auto-reload value
    pwm_timer_tim3_ch1.set_prescaler(84); // Set prescaler (assuming 84 gives the desired timer clock)
    pwm_timer_tim3_ch1.set_frequency(1000); // Set PWM frequency to 1 kHz
    pwm_timer_tim3_ch1.set_duty_cycle(50); // Set PWM duty cycle to 50%
}

int main() {

    clock_init();

    // Configures the SysTick timer to generate an interrupt every 1 ms.
    SysTick_Config(100000);
    // Enable interrupts
    __enable_irq();

    Gpio myGpio(GPIOA, 5);
    myGpio.set_mode(1);

    // Initialize USART
    usart_init();

    // Initialize PWM
    pwm_init();

    while (1) {
        // turn on output signal
        myGpio.write(1);
        //delay_ms(1000);
        //myGpio.write(0);
        //delay_ms(1000);

        printf("abc\r\n");  // Sends the data, string "abc", \r puts cursor on the beginning
        delay_ms(500); 

    }

    return 0;
}
