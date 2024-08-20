===========================
Pulse Width Modulation (PWM)
===========================

Introduction
============

Pulse Width Modulation (PWM) is a technique used to reduce the electrical power supplied to a device by switching the signal on and off at a high frequency. The average voltage of the signal is controlled by varying the relative on-time of the signal. This average voltage effectively reduces the power supplied while maintaining full voltage during the pulse's on-time. Two key parameters control the PWM signal: the frequency of switching and the relative duration of the on-time, known as the duty cycle.

PWM Carrier Frequency
=====================

The frequency of the PWM signal depends on the load device. For example, an electrical heater or motor might use a frequency in the range of tens to hundreds of Hz, while a solid-state device like a relay or LED may require frequencies in the tens of thousands of Hz. The key factor is the response rate of the load device.

PWM Duty Cycle
==============

The duty cycle of a PWM signal represents the percentage of time the signal is on. A duty cycle of 100% means the signal is always on, while 50% means the signal is on for half of the period and off for the other half. For instance, with a 12V DC PWM signal and a 50% duty cycle, the effective voltage supplied to the load is 6V DC.

Implementation of the PWM Timer
===============================

First, separate files for `pwm.h` and `pwm.cpp` were created.

pwm.h
======

In `pwm.h`, a `Pwm` class is defined to initialize the timer and call functions for setting frequency and duty cycle.

```cpp
class PwmTimer {
    public:
        PwmTimer(TIM_TypeDef* timer, uint32_t channel);
        void init(uint32_t prescaler, uint32_t arr);
        void set_frequency(uint32_t frequency);
        void set_duty_cycle(uint32_t duty_cycle);
    
    private:
        TIM_TypeDef* timer;
        uint32_t channel;
        uint32_t arr_value;
};

pwm.cpp
=======

In `pwm.cpp`, the timer pointer is passed, and the appropriate timer and clock are enabled. For the STM32F411, we have timers on APB1 and APB2:

- Timers on APB1: TIM2, TIM3, TIM4, TIM5
- Timers on APB2: TIM9, TIM10, TIM11

The code loops through the available timers and enables the clock for the selected timer.

Next, the prescaler and auto-reload register are set.

**Prescaler**:
A prescaler divides the input clock frequency by a predetermined factor, allowing the microcontroller to work with longer time intervals and lower frequencies. In the context of PWM, the prescaler determines the frequency of the PWM signal.

For `tim->PSC`, setting the value to 0 means the timer clock frequency is equal to the system clock frequency. This configuration allows the timer to operate at the highest possible frequency.

**Auto-Reload Register (ARR)**:
The ARR defines the period of the timer's cycle by setting the value at which the timer counter resets to zero. This value controls the duration of each timer period.

```cpp
tim->ARR = 5000;

Selecting the Channel
=====================

Configure the output compare mode using the `TIM_CCMR1` and `TIM_CCMR2` registers, and enable the output with the `TIM_CCER` register. PWM mode 1 is used, which means the output is high when the timer counter is less than the compare value (CCR) and low when it is equal to or greater.

Setting Frequency
=================

To set the frequency, use the following formula:

```cpp
// uint32_t period = SystemCoreClock / (tim->PSC + 1) / frequency;
// tim->ARR = period - 1;

With a prescaler of 0, the formula simplifies to:

```cpp
tim->ARR = (SystemCoreClock / frequency) - 1;


Setting Duty Cycle
==================

The duty cycle is used to calculate the compare value, which determines how long the PWM signal remains high during each period.

```cpp
uint32_t compare = (tim->ARR + 1) * duty_cycle / 100;

Finally, an instance for TIM3 and channel 1 is created:

Pwm pwm_timer(TIM3, 1);
