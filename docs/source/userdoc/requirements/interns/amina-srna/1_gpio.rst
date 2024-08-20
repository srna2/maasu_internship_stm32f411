==========================
GPIO Requirements by Amina
==========================

Constructor: Gpio::Gpio
=======================

Informational Requirements
==========================

.. req:: Constructor: Gpio::Gpio
   :id: REQ_INT3_1722240082
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The "Gpio::Gpio" constructor initializes a Gpio object with a specified GPIO port and pin, and is responsible for activating the clock for the corresponding GPIO port to ensure the pin is operational.

.. req:: Constructor: Gpio::Gpio
   :id: REQ_INT3_1722241737
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The GPIO_TypeDef* port parameter is a pointer to a structure representing a GPIO port on the STM32 microcontroller.

.. req:: Constructor: Gpio::Gpio
   :id: REQ_INT3_1722241771
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The AHB1ENR (AHB1 Peripheral Clock Enable Register) is a register in the STM32 microcontroller's Reset and Clock Control (RCC) peripheral.

Functional Requirements
=======================

.. req:: Constructor: Gpio::Gpio
   :id: REQ_INT3_1722240416
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> "Gpio::Gpio" must accept two parameters. Port (GPIO_TypeDef* port) as a first parameter and pin number (uint32_t pin) within the specified port as a second parameter.

.. req:: Constructor: Gpio::Gpio
   :id: REQ_INT3_1722241158
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The function must determine and enable the correct GPIO port's clock based on the port parameter.


Non-functional Requirements
===========================

.. req:: Constructor: Gpio::Gpio
   :id: REQ_INT3_1722242095
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The constructor must initialize the GPIO object and enable the appropriate clock within a single clock cycle.

.. req:: Constructor: Gpio::Gpio
   :id: REQ_INT3_1722242395
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The clock enabling operations in the AHB1ENR register must avoid unnecessary register accesses or operations that could impact performance.

.. req:: Constructor: Gpio::Gpio
   :id: REQ_INT3_1722242453
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The constructor must enable the clock for the specified GPIO port based on the port parameter. It must handle the enabling of clocks for different GPIO ports (e.g., GPIOA, GPIOB) without error.

.. req:: Constructor: Gpio::Gpio
   :id: REQ_INT3_1722242575
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The constructor must ensure that the clock for each GPIO port is enabled by setting the corresponding bit in the RCC_AHB1ENR register.


Function: Gpio::Set_mode
========================

Informational Requirements
==========================

.. req:: Function: Gpio::set_mode
   :id: REQ_INT3_1722242689
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The "set_mode" function is responsible for configuring the operating mode of a GPIO pin associated with an instance of the Gpio class.

.. req:: Function: Gpio::set_mode
   :id: REQ_INT3_1722439674
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> MODER is a register that configures the mode of the GPIO pins for a particular port.
         There are 4 "states" in which mode can be (binary view):
         00. input mode (reset state, always reset mode at the beginning)
         01. general purpose output mode
         10. alternate function mode
         11. analog mode


Functional Requirements
=======================

.. req:: Function: Gpio::set_mode
   :id: REQ_INT3_1722242789
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The function must reset the mode bits (MODER) corresponding to the GPIO pin (pin).

.. req:: Function: Gpio::set_mode
   :id: REQ_INT3_1722242875
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The function must set the mode bits (MODER) according to the value of mode.

Non-functional Requirements
===========================

.. req:: Function: Gpio::set_mode
   :id: REQ_INT3_1722242976
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The function must ensure atomic access to maintain system stability when configuring the GPIO pin mode.


.. req:: Function: Gpio::set_mode
   :id: REQ_INT3_1722243056
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The function must exhibit consistent behavior across all supported STM32 microcontroller platforms.


Function: Gpio::set_input_pull
==============================

Informational Requirements
==========================

.. req:: Function: Gpio::set_input_pull
   :id: REQ_INT3_1722243369
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The "set_input_pull" function configures the pull-up or pull-down resistor for a GPIO pin.

.. req:: Function: Gpio::set_input_pull
   :id: REQ_INT3_1722243404
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The pull-up resistor ensures the pin reads high when not actively driven by an external signal, while the pull-down resistor ensures the pin reads low.

Functional Requirements
=======================

.. req:: Function: Gpio::set_input_pull
   :id: REQ_INT3_1722243473
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The function must clear the existing pull-up or pull-down configuration for the specified pin by using a bitwise AND operation with the inverted mask, and then update the configuration using a bitwise OR operation.

.. req:: Function: Gpio::set_input_pull
   :id: REQ_INT3_1722243552
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The function must update the pull-up or pull-down configuration by first clearing the relevant bits in the PUPDR register for the pin and then writing the provided pull value into those bits.

.. req:: Function: Gpio::set_input_pull
   :id: REQ_INT3_1722243590
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The pull parameter must specify the type of pull configuration: GPIO_NOPULL, GPIO_PULLUP, or GPIO_PULLDOWN.

Non-functional Requirements
===========================

.. req:: Function: Gpio::set_input_pull
   :id: REQ_INT3_1722243624
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The function must execute efficiently to minimize delay in configuring the GPIO pin’s pull-up or pull-down resistors.

.. req:: Function: Gpio::set_input_pull
   :id: REQ_INT3_1722243729
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> When the pin is linked to an external signal while internal pull-up or pull-down resistors are configured, the voltage level on the pin must primarly represent the external signal.


Function: Gpio::set_output_type
===============================

Informational Requirements
==========================

.. req:: Function: Gpio::set_output_type
   :id: REQ_INT3_1722243908
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The "set_output_type" function configures the output type of a GPIO pin, which determines how the pin drives voltage and current. 

.. req:: Function: Gpio::set_output_type
   :id: REQ_INT3_1722243989
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The type parameter specifies the desired output type for the GPIO pin. This value should be one of the predefined constants, typically GPIO_OUTPUT_PUSH_PULL or GPIO_OUTPUT_OPEN_DRAIN.

Functional Requirements
=======================

.. req:: Function: Gpio::set_output_type
   :id: REQ_INT3_1722244193
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The function must clear the existing output type configuration in the OTYPER register for the specified GPIO pin by masking out the relevant bits.

.. req:: Function: Gpio::set_output_type
   :id: REQ_INT3_1722244229
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The function must set the output type configuration bits in the OTYPER register to the value specified by the type parameter, in accordance with the STM32 microcontroller’s GPIO output type specifications.

.. req:: Function: Gpio::set_output_type
   :id: REQ_INT3_1722244328
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The type parameter must specify the desired output type, such as GPIO_OUTPUT_PUSH_PULL or GPIO_OUTPUT_OPEN_DRAIN.

.. req:: Function: Gpio::set_output_type
   :id: REQ_INT3_1722244265
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The function must correctly shift and mask bits in the OTYPER register to target the specific pin’s configuration.

.. req:: Function: Gpio::set_output_type
   :id: REQ_INT3_1722244363
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The function must verify that the provided type parameter is within the valid range of output types supported by the hardware (e.g., GPIO_OUTPUT_PUSH_PULL, GPIO_OUTPUT_OPEN_DRAIN).

Non-functional Requirements
===========================

.. req:: Function: Gpio::set_output_type
   :id: REQ_INT3_1722244437
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil:
   :references:
   :verification-and-validation:

   --> The Gpio::set_output_type function must complete its execution within a maximum of 10 CPU cycles to ensure efficient performance and minimize the impact on system processing time.


Function: Gpio::set_output_speed
================================

Informational Requirements
==========================

.. req:: Function: Gpio::set_output_speed
   :id: REQ_INT3_1722245953
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "set_output_speed" function configures the output speed of a GPIO pin, which determines how fast the pin can switch between high and low states.

.. req:: Function: Gpio::set_output_speed
   :id: REQ_INT3_1722245993
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The OSPEEDR register controls the output speed of GPIO pins, determining how quickly the pin can transition between high and low states.    

Functional Requirements
=======================

.. req:: Function: Gpio::set_output_speed
   :id: REQ_INT3_1722246172
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must clear the existing speed configuration in the OSPEEDR register for the specified GPIO pin by masking out the relevant bits.

.. req:: Function: Gpio::set_output_speed
   :id: REQ_INT3_1722246202
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must set the output speed configuration bits in the OSPEEDR register to the value specified by the speed parameter.

.. req:: Function: Gpio::set_output_speed
   :id: REQ_INT3_1722246222
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The speed parameter must specify the desired output speed, such as GPIO_SPEED_LOW, GPIO_SPEED_MEDIUM, or GPIO_SPEED_HIGH.

.. req:: Function: Gpio::set_output_speed
   :id: REQ_INT3_1722246250
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must correctly shift and mask bits in the OSPEEDR register to target the specific pin’s speed configuration.

Non-functional Requirements
===========================

.. req:: Function: Gpio::set_output_speed
   :id: REQ_INT3_1722246342
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: `Amina Srna`_
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function’s behavior must be consistent across different STM32 microcontroller platforms where the GPIO and OSPEEDR register configurations are similar.


Function: Gpio::set_alt_func
============================

Informational Requirements
==========================

.. req:: Function: Gpio::set_alt_func
   :id: REQ_INT3_1722246919
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "set_alt_func" function is responsible for configuring an alternate function for a GPIO pin.

.. req:: Function: Gpio::set_alt_func
   :id: REQ_INT3_1722246945
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "alt_func" parameter represents the alternate function selection for the GPIO pin and must be a value that corresponds to one of the valid alternate functions for that pin.

.. req:: Function: Gpio::set_alt_func
   :id: REQ_INT3_1722246959
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The AFR (Alternate Function Register) is used to configure the alternate functions of GPIO pins. The register is split into two 32-bit registers: AFR[0] for pins 0-7 and AFR[1] for pins 8-15.

Functional Requirements
=======================

.. req:: Function: Gpio::set_alt_func
   :id: REQ_INT3_1722247055
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must check whether the pin number is in the lower range (0-7) or the upper range (8-15) to determine which part of the AFR register to modify.

.. req:: Function: Gpio::set_alt_func
   :id: REQ_INT3_1722247074
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> For pins 0-7, the function must clear the alternate function bits in AFR[0] for the specified pin before setting the new alternate function.

.. req:: Function: Gpio::set_alt_func
   :id: REQ_INT3_1722247086
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> For pins 8-15, the function must clear the alternate function bits in AFR[1] for the specified pin (adjusted to the lower nibble of the register) before setting the new alternate function.

.. req:: Function: Gpio::set_alt_func
   :id: REQ_INT3_1722247097
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must shift and mask bits correctly to set the alternate function for the specified pin in the appropriate AFR register.

Non-functional Requirements
===========================

.. req:: Function: Gpio::set_alt_func
   :id: REQ_INT3_1722247215
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The Gpio::set_alt_func function must execute within a maximum of 20 microseconds to ensure efficient configuration of the GPIO pin's alternate function.

.. req:: Function: Gpio::set_alt_func
   :id: REQ_INT3_1722247238
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function’s behavior must be consistent and predictable across different microcontroller platforms, as long as the pin number and alt_func values are valid and properly configured.


Function: Gpio::write
=====================

Informational Requirements
==========================

.. req:: Function: Gpio::write
   :id: REQ_INT3_1722247409
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "write" function is used to set or reset the state of a GPIO pin based on the boolean value parameter. If value is true, the pin is set; if false, the pin is reset.

.. req:: Function: Gpio::write
   :id: REQ_INT3_1722247414
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The BSRR (Bit Set/Reset Register) is used to set or reset individual GPIO pins. Writing a 1 to a specific bit in this register will set the corresponding pin, while writing a 1 to a bit in the upper half of the register will reset the corresponding pin.

.. req:: Function: Gpio::write
   :id: REQ_INT3_1722247427
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The ODR (Output Data Register) is another register for controlling GPIO pins, but it does not provide atomic set/reset operations like BSRR.

Functional Requirements
=======================

.. req:: Function: Gpio::write
   :id: REQ_INT3_1722247474
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must check the value parameter and write to the BSRR register accordingly to either set or reset the specified GPIO pin.

.. req:: Function: Gpio::write
   :id: REQ_INT3_1722247486
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> When the value is true, the function must set the pin by writing a value where only the bit corresponding to the pin number is set to 1 in the BSRR register.

.. req:: Function: Gpio::write
   :id: REQ_INT3_1722247540
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> When the value is false, the function must reset the pin by setting the bit corresponding to the pin number and add additional 16 bits in the BSRR register to 1.

.. req:: Function: Gpio::write
   :id: REQ_INT3_1722247555
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must use the appropriate bit-shift operations to ensure that the correct bit is set or reset in the BSRR register.

Non-functional Requirements
===========================

.. req:: Function: Gpio::write
   :id: REQ_INT3_1722247637
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must utilize the atomic properties of the BSRR register to handle concurrent modifications safely, preventing race conditions and ensuring reliable pin state changes.

.. req:: Function: Gpio::write
   :id: REQ_INT3_1722247648
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must perform consistently across all supported microcontroller platforms, provided that the GPIO pin and value parameters are correctly configured and valid.


Function: Gpio::read
====================

Informational Requirements
==========================

.. req:: Function: Gpio::read
   :id: REQ_INT3_1722247927
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "read" function retrieves the current state of the specified GPIO pin by reading the value from the IDR (Input Data Register). Possible states include:
      Low level (0): The pin is at a logical low voltage level
      High level (1): The pin is at a logical high voltage level
      

.. req:: Function: Gpio::read
   :id: REQ_INT3_1722247995
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The IDR (Input Data Register) is used to read the current state of all GPIO pins on the port. Each bit in this register represents the state of a corresponding pin.

.. req:: Function: Gpio::read
   :id: REQ_INT3_1722248007
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function returns a uint32_t value representing the state of the specified GPIO pin, where the least significant bit corresponds to the pin's state.

Functional Requirements
=======================

.. req:: Function: Gpio::read
   :id: REQ_INT3_1722248127
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must read the value of the IDR register for the specified GPIO port to obtain the current pin state.

.. req:: Function: Gpio::read
   :id: REQ_INT3_1722248138
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must mask out the bits in the IDR register that do not correspond to the specified pin using a bitwise AND operation.

.. req:: Function: Gpio::read
   :id: REQ_INT3_1722248144
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must shift the result of the bitwise AND operation right by the pin number to obtain the pin's state as a single bit value.

.. req:: Function: Gpio::read
   :id: REQ_INT3_1722248158
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must return the pin's state as a uint32_t value, where the least significant bit represents the pin's current state (0 or 1).

Non-functional Requirements
===========================

.. req:: Function: Gpio::read
   :id: REQ_INT3_1722248255
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must consistently return the GPIO pin's state as a uint32_t value with precise bit-shifting, ensuring that the least significant bit accurately represents the pin's current state without errors or deviations.

