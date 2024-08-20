==========================================
Clock Initialization Requirements by Amina
==========================================

Function clock_init
===================

Informational Requirements
==========================


.. req:: Function clock_init
   :id: REQ_INT3_1722584947
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> A High-Speed External (HSE) oscillator is a clock source that operates at a high frequency and is provided by an external crystal or ceramic resonator connected to the microcontroller's oscillator pins.

.. req:: Function clock_init
   :id: REQ_INT3_1722550759
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> "HSEBYP" is a bit in the RCC_CR (Clock Control Register) that is used to bypass the High-Speed External (HSE) oscillator.

.. req:: Function clock_init
   :id: REQ_INT3_1722551798
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> "HSEON" is a bit in the RCC_CR (Clock Control Register) that is used to enable the High-Speed External (HSE) oscillator.

.. req:: Function clock_init
   :id: REQ_INT3_1722552056
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> "HSERDY" is a bit in the RCC_CR (Clock Control Register) that indicates the status of the High-Speed External (HSE) oscillator.

.. req:: Function clock_init
   :id: REQ_INT3_1722551868
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function configures the external high-speed oscillator (HSE) by first bypassing it if an external clock source is used, and then enabling the oscillator to provide a stable clock signal for the system.

.. req:: Function clock_init
   :id: REQ_INT3_1722552224
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> "PWR_CR_VOS" is a bit field in the Power Control Register (PWR_CR) that controls the voltage scaling level for the microcontroller's core.

      Three voltage scale levels:
      Scale 1: Allows the microcontroller to run at the maximum frequency (up to 100 MHz for STM32F411) with the highest performance.
      Scale 2: Reduces the maximum allowable frequency, thus lowering power consumption.
      Scale 3: Further reduces the maximum frequency, optimizing for low power consumption at the cost of performance.

.. req:: Function clock_init
   :id: REQ_INT3_1722585605
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "FLASH_ACR_LATENCY_3WS" setting in the Flash Access Control Register configures the flash memory interface to use 3 wait states in order to ensure stable and reliable flash memory read operations when the system clock frequency is high. 
      Three wait states mean that the processor will wait for 3 additional clock cycles to ensure the flash memory is ready to be accessed.

.. req:: Function clock_init
   :id: REQ_INT3_1722586358
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> PLLM, PLLN, and PLLP are parameters used to configure the Phase-Locked Loop (PLL) in the RCC_PLLCFGR register to generate the system clock.

      - PLLM divides the input clock frequency (range: 1 to 63) before it is fed into the PLL, ensuring it is within the PLL's operating range.
      - PLLP divides the VCO output frequency (range: 2, 4, 6, or 8) to provide the final PLL clock output used by the microcontroller.
      - PLLP divides the VCO output frequency (range: 2, 4, 6, or 8) to set the final PLL clock output frequency for the microcontroller.

.. req:: Function clock_init
   :id: REQ_INT3_1722586449
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The APB1 prescaler is set by configuring the "RCC_CFGR_PPRE1" bits in the RCC_CFGR register. Dividing the system clock by 2 results in a clock frequency of 50 MHz for the APB1 peripheral when "RCC_CFGR_PPRE1_DIV2" is used.

.. req:: Function clock_init
   :id: REQ_INT3_1722591283
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> PLL (Phase-Locked Loop) is an electronic circuit used to generate a stable output frequency from a variable input frequency or to synchronize a signal with a reference signal. The PLL is enabled by setting the "RCC_CR_PLLON" bit in the RCC_CR register.

.. req:: Function clock_init
   :id: REQ_INT3_1722592906
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> To configure the system to use the PLL as the clock source, the "RCC_CFGR_SW_PLL" bits in the RCC_CFGR register are set.

.. req:: Function clock_init
   :id: REQ_INT3_1722593107
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "SystemCoreClockUpdate()" function is used to update the "SystemCoreClock" global variable with the current system clock frequency. This function recalculates the frequency based on the current configuration of the clock system, including settings for the PLL and prescalers.


Functional Requirements
=======================

.. req:: Function clock_init
   :id: REQ_INT3_1722552891
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The function must set the HSEBYP bit in the RCC clock control register to bypass the High-Speed External (HSE) oscillator, allowing the use of an external clock signal directly.

.. req:: Function clock_init
   :id: REQ_INT3_1722553319
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The function must set the HSEON bit in the RCC clock control register to enable the High-Speed External (HSE) oscillator as the system clock source.

.. req:: Function clock_init
   :id: REQ_INT3_1722583704
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must continuously check the HSERDY bit in the RCC clock control register and wait until this bit is set, indicating that the High-Speed External (HSE) oscillator is stable and ready to be used as a clock source.

.. req:: Function clock_init
   :id: REQ_INT3_1722583880
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must clear the voltage scale bits in the PWR control register by resetting the "PWR_CR_VOS" bits to ensure any previous settings are removed before applying a new voltage scale configuration.

.. req:: Function clock_init
   :id: REQ_INT3_1722585088
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must configure the PWR control register by setting the "PWR_CR_VOS" bits to "Scale 1".

.. req:: Function clock_init
   :id: REQ_INT3_1722585415
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must configure the Flash Access Control Register to set the latency to 3 wait states by setting the "FLASH_ACR_LATENCY_3WS" bits. 

.. req:: Function clock_init
   :id: REQ_INT3_1722585852
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must clear the existing configuration of the PLLM, PLLN, and PLLP bits in the RCC_PLLCFGR register by using a bitwise AND operation with the inverse of the respective bit masks.

.. req:: Function clock_init
   :id: REQ_INT3_1722585988
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must configure the PLLM bits in the RCC_PLLCFGR register by setting them to divide the input clock frequency by a factor of 4.

.. req:: Function clock_init
   :id: REQ_INT3_1722586043
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must configure the PLLN bits in the RCC_PLLCFGR register by setting them to multiply the VCO input frequency by a factor of 200.

.. req:: Function clock_init
   :id: REQ_INT3_1722586102
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   -> The function must configure the PLLP bits in the RCC_PLLCFGR register by setting them to divide the VCO output frequency by a factor of 2.

.. req:: Function clock_init
   :id: REQ_INT3_1722586147
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must set the "PLLSRC" bit in the RCC_PLLCFGR register to select the High-Speed External (HSE) oscillator as the source clock for the PLL.

.. req:: Function clock_init
   :id: REQ_INT3_1722586799
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must clear the existing APB1 prescaler settings in the RCC_CFGR register by using a bitwise AND operation with the inverse of the "RCC_CFGR_PPRE1" mask.

.. req:: Function clock_init
   :id: REQ_INT3_1722587041
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must configure the APB1 prescaler in the RCC_CFGR register by setting the "RCC_CFGR_PPRE1_DIV2" bits.

.. req:: Function clock_init
   :id: REQ_INT3_1722587147
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must enable the Phase-Locked Loop (PLL) by setting the "RCC_CR_PLLON" bit in the RCC_CR register.

.. req:: Function clock_init
   :id: REQ_INT3_1722589510
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   "After enabling the PLL, the function must wait for the PLL to stabilize by monitoring the "RCC_CR_PLLRDY" bit in the RCC_CR register.

.. req:: Function clock_init
   :id: REQ_INT3_1722589558
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must ensure that the PLL is fully operational and ready by verifying that the "RCC_CR_PLLRDY" bit is set. 

.. req:: Function clock_init
   :id: REQ_INT3_1722590051
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must select the PLL output as the system clock by setting the "RCC_CFGR_SW_PLL" bits in the RCC_CFGR register.

.. req:: Function clock_init
   :id: REQ_INT3_1722590092
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> After setting the PLL as the system clock source, the function must wait until the "RCC_CFGR_SWS_PLL" bit in the RCC_CFGR register is set, indicating that the PLL is now the active system clock source.

.. req:: Function clock_init
   :id: REQ_INT3_1722590154
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must validate that the PLL output is correctly used as the system clock by checking that the `RCC_CFGR_SWS_PLL` bit is set in the RCC_CFGR register.

.. req:: Function clock_init
   :id: REQ_INT3_1722590262
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must call the "SystemCoreClockUpdate()" function to update the "SystemCoreClock" global variable with the current system clock frequency.


Non-functional Requirements
===========================

.. req:: Function clock_init
   :id: REQ_INT3_1722594174
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The process of enabling the external clock source must ensure that the HSE oscillator is correctly bypassed and enabled without introducing errors.

.. req:: Function clock_init
   :id: REQ_INT3_1722593988
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The clock initialization process must complete within a maximum duration of 200 milliseconds to ensure efficient startup time and minimize delays during system boot.

.. req:: Function clock_init
   :id: REQ_INT3_1722594391
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The configuration of the voltage scale to Scale 1 must ensure that the power supply is set to the required voltage level for maximum performance.

.. req:: Function clock_init
   :id: REQ_INT3_1722594782
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The clock initialization must set up the system clock to PLL output with no errors.