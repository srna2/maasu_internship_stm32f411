===============================
PWM Timer Requirements by Amina
===============================


Constructor: PwmTimer::PwmTimer
===============================

Informational Requirements
==========================

.. req:: Constructor: PwmTimer::PwmTimer
   :id: REQ_INT3_1722945707
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The PwmTimer constructor enables the clock for a specific timer peripheral by setting the corresponding enable bit in the APB1ENR or APB2ENR register of the RCC (Reset and Clock Control) module. 
        The APB1ENR register is used for TIM2, TIM3, TIM4, and TIM5, while the APB2ENR register is used for TIM1, TIM9, TIM10, and TIM11.

.. req:: Constructor: PwmTimer::PwmTimer
   :id: REQ_INT3_1722946607
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The PwmTimer constructor initializes a GPIO pin for PWM output based on the specified timer and channel.

.. req:: Constructor: PwmTimer::PwmTimer
   :id: REQ_INT3_1723116524
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The switch-case statement configures the appropriate timer channel (1, 2, 3, or 4) for PWM output by setting specific bits in the timer's registers.

.. req:: Constructor: PwmTimer::PwmTimer
   :id: REQ_INT3_1723116566
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The switch-case statement modifies the Capture/Compare Mode Register (CCMR) and the Capture/Compare Enable Register (CCER) to configure the timer channels for PWM mode 1 with the preload feature enabled.

Functional Requirements
=======================

.. req:: Constructor: PwmTimer::PwmTimer
   :id: REQ_INT3_1722946736
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The constructor must set the appropriate bit in the APB1ENR or APB2ENR register to enable the clock for the specified timer.

.. req:: Constructor: PwmTimer::PwmTimer
   :id: REQ_INT3_1722946798
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The timer peripheral clock must be enabled for all valid timer instances passed to the constructor.

.. req:: Constructor: PwmTimer::PwmTimer
   :id: REQ_INT3_1722946823
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The constructor must initialize GPIO pin PB4, when the timer is TIM3 and the channel is 1. The pin must be set to mode 2 and configured for alternate function 2 to support TIM3_CH1 PWM output.

.. req:: Constructor: PwmTimer::PwmTimer
   :id: REQ_INT3_1723116609
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The switch-case statement must set the output compare mode to PWM mode 1 by setting the OCxM bits in the CCMR1 or CCMR2 register for the specified channel.

.. req:: Constructor: PwmTimer::PwmTimer
   :id: REQ_INT3_1723116652
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The switch-case statement must enable the preload feature for the specified channel by setting the OCxPE bit in the CCMR1 or CCMR2 register.

.. req:: Constructor: PwmTimer::PwmTimer
   :id: REQ_INT3_1723116693
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The switch-case statement must enable the capture/compare function for the specified channel by setting the CCxE bit in the CCER register.

Non-functional Requirements
===========================

.. req:: Constructor: PwmTimer::PwmTimer
   :id: REQ_INT3_1722952180
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The clock enabling process for the timer should execute with a delay of no more than 1 millisecond to ensure timely initialization of the PWM functionality.


Function: PwmTimer::set_frequency
=================================

Informational Requirements
==========================

.. req:: Function: PwmTimer::set_frequency
   :id: REQ_INT3_1722955291
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "set_frequency" function configures the timer's frequency by calculating the value of the Auto-Reload Register (ARR) based on the desired frequency and the current prescaler value. The function uses different timer clock speeds depending on the timer instance.

Functional Requirements
=======================

.. req:: Function: PwmTimer::set_frequency
   :id: REQ_INT3_1723119164
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must use the following timer clock speeds:
         - 100 MHz for APB2 timers: TIM1, TIM9, TIM10, TIM11
         - 50 MHz for APB1 timers: TIM2, TIM3, TIM4, TIM5

.. req:: Function: PwmTimer::set_frequency
   :id: REQ_INT3_1722955338
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must compute the timer clock frequency as SystemCoreClock / (timer->PSC + 1) to reflect the actual operating frequency of the timer.

.. req:: Function: PwmTimer::set_frequency
   :id: REQ_INT3_1722955520
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must set the auto-reload register (ARR) to timer_clock / frequency to ensure the PWM signal frequency matches the specified frequency. The ARR value must be updated immediately after the calculation to ensure the PWM output is correctly configured.

Non-functional Requirements
===========================

.. req:: Function: PwmTimer::set_frequency
   :id: REQ_INT3_1722955908
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The PwmTimer::set_frequency function should complete execution within 100 microseconds to ensure timely updates to the PWM frequency and prevent delays in signal generation.


Function: PwmTimer::set_duty_cycle
==================================

Informational Requirements
==========================

.. req:: Function: PwmTimer::set_duty_cycle
   :id: REQ_INT3_1722956095
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "set_duty_cycle" function assigns the calculated duty cycle value to the appropriate Capture/Compare Register (CCR) depending on the channel used (CCR1, CCR2, CCR3, or CCR4) based on the current auto-reload value (ARR).

Functional Requirements
=======================

.. req:: Function: PwmTimer::set_duty_cycle
   :id: REQ_INT3_1722957926
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must calculate the CCR1 value by multiplying the desired duty cycle percentage by the current arr_value and dividing the result by 100.

.. req:: Function: PwmTimer::set_duty_cycle
   :id: REQ_INT3_1722957957
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must set the appropriate CCR register (CCR1, CCR2, CCR3, or CCR4) based on the channel being used, to adjust the PWM signal's duty cycle accordingly.

.. req:: Function: PwmTimer::set_duty_cycle
   :id: REQ_INT3_1723117122
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must handle all valid PWM channels (1, 2, 3, 4) and set the corresponding CCR register.

Non-functional Requirements
===========================

.. req:: Function: PwmTimer::set_duty_cycle
   :id: REQ_INT3_1722958057
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must execute within 100 microseconds to ensure timely updates of the PWM signal's duty cycle, minimizing latency and maintaining accurate signal generation.


Function: PwmTimer::set_prescaler
==================================

Informational Requirements
==========================

.. req:: Function: PwmTimer::set_prescaler
   :id: REQ_INT3_1723118453
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "set_prescaler" function adjusts the timer's prescaler by writing the provided value minus one to the PSC (Prescaler) register.

Functional Requirements
=======================

.. req:: Function: PwmTimer::set_prescaler
   :id: REQ_INT3_1723118513
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must set the PSC register of the timer to prescaler - 1.

Non-functional Requirements
===========================

.. req:: Function: PwmTimer::set_prescaler
   :id: REQ_INT3_1723118919
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function should complete the duty cycle update within 1 millisecond to ensure that changes are applied with minimal delay.