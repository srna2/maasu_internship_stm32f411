===========================
Usart Requirements by Amina
===========================


Constructor: Usart::Usart
=========================

Informational Requirements
==========================

.. req:: Constructor: Usart::Usart
   :id: REQ_INT3_1722886847
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The "Usart::Usart" constructor initializes a USART instance by enabling the appropriate USART peripheral clock.

.. req:: Constructor: Usart::Usart
   :id: REQ_INT3_1722892007
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> "Usart::Usart" constructor accepts a single input parameter, which is a pointer to a "USART_TypeDef" structure and determines which USART peripheral to initialize.

.. req:: Constructor: Usart::Usart
   :id: REQ_INT3_1722892186
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> APB1ENR and APB2ENR are part of the RCC (Reset and Clock Control) module, which manages the microcontroller’s clocks and resets.


Functional Requirements
=======================

.. req:: Constructor: Usart::Usart
   :id: REQ_INT3_1722894061
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The constructor must enable the USART1 peripheral clock by setting the USART1EN bit in the APB2ENR register when USART1 is passed as a parameter.

.. req:: Constructor: Usart::Usart
   :id: REQ_INT3_1722894230
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The constructor must enable the USART2 peripheral clock by setting the USART2EN bit in the APB1ENR register when USART2 is passed as a parameter.

.. req:: Constructor: Usart::Usart
   :id: REQ_INT3_1722894259
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The constructor must enable the USART6 peripheral clock by setting the USART6EN bit in the APB2ENR register when USART6 is passed as a parameter.


Non-functional Requirements
===========================

.. req:: Constructor: Usart::Usart
   :id: REQ_INT3_1722894786
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The "Usart::Usart" constructor should complete the peripheral clock enabling process within a maximum of 50 CPU cycles to ensure minimal impact on system initialization time.


Function: Usart::init
=====================

Informational Requirements
==========================

.. req:: Function: Usart::init
   :id: REQ_INT3_1722895245
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   --> The "Usart::init" function initializes the USART peripheral with the specified baud rate and oversampling settings, and it enables the USART, transmitter, and receiver.

.. req:: Function: Usart::init
   :id: REQ_INT3_1722895538
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> Baud rate is the speed at which data is transmitted over a serial communication channel. It defines the number of bits transmitted per second.
       Oversampling refers to the process of sampling the data line multiple times per bit to improve data reliability and reduce noise.


.. req:: Function: Usart::init
   :id: REQ_INT3_1722895377
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "OVER8" bit in the USART Control Register configures the oversampling mode for USART communication. 
       When "OVER8" is set to 1, the USART operates with 8x oversampling, allowing for higher baud rates. When cleared to 0, the USART operates with 16x oversampling, providing more sampling points per bit for better accuracy in data reception.

.. req:: Function: Usart::init
   :id: REQ_INT3_1722897094
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "USARTDIV" value is a calculated divisor used to set the baud rate of the USART peripheral. It is derived from the system clock frequency "SystemCoreClock", the desired baud rate, and the oversampling factor.


Functional Requirements
=======================

.. req:: Function: Usart::init
   :id: REQ_INT3_1722897263
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must clear the "OVER8" bit in the USART Control Register by writing "0" to the bit position corresponding to "USART_CR1_OVER8".

.. req:: Function: Usart::init
   :id: REQ_INT3_1722897546
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must check if the oversampling parameter is 8 and set the "OVER8" bit in the USART Control Register by writing "1" to the bit position corresponding to "USART_CR1_OVER8" to enable 8x oversampling mode.

.. req:: Function: Usart::init
   :id: REQ_INT3_1722897849
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must calculate the "USARTDIV" value using the formula "USARTDIV = (SystemCoreClock / (baud_rate * (oversampling == 8 ? 8 : 16))) + 0.5".

.. req:: Function: Usart::init
   :id: REQ_INT3_1722898048
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must write the calculated "USARTDIV" value to the Baud Rate Register (BRR) of the USART peripheral.

.. req:: Function: Usart::init
   :id: REQ_INT3_1722898117
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must enable the USART peripheral by setting the "UE" (USART Enable), "TE" (Transmitter Enable), and "RE" (Receiver Enable) bits in the USART Control Register 1 (CR1). 


Non-functional Requirements
===========================

.. req:: Function: Usart::init
   :id: REQ_INT3_1722898257
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function should execute within 50 microseconds under a system clock of 100 MHz.


Function: Usart::write_byte
===========================

Informational Requirements
==========================

.. req:: Function: Usart::write_byte
   :id: REQ_INT3_1722940136
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The "USART_SR_TXE" bit in the USART Status Register indicates whether the transmit data register is empty. When set to "1", it means the DR is ready to accept a new byte for transmission.


Functional Requirements
=======================

.. req:: Function: Usart::write_byte
   :id: REQ_INT3_1722940302
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must continuously check the "USART_SR_TXE" bit in the USART Status Register and only proceed when this bit is set to "1".

.. req:: Function: Usart::write_byte
   :id: REQ_INT3_1722940418
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must write the provided "byte" to the Data Register of the USART, initiating the transmission of the byte over the USART interface.


Non-functional Requirements
===========================

.. req:: Function: Usart::write_byte
   :id: REQ_INT3_1722940552
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function should check the "USART_SR_TXE" bit in the USART Status Register with a latency not exceeding 2 CPU cycles at a clock speed of 100 MHz.


Function: Usart::write_buf
==========================

Informational Requirements
==========================

.. req:: Function: Usart::write_buf
   :id: REQ_INT3_1722941163
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function transmits a buffer of characters over the USART interface by calling the "write_byte" function repeatedly for each character in the buffer.


Functional Requirements
=======================

.. req:: Function: Usart::write_buf
   :id: REQ_INT3_1722941237
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function must iterate over the buffer from the first character to the character at position "len - 1" and transmit each character using the "write_byte" function.


Non-functional Requirements
===========================

.. req:: Function: Usart::write_buf
   :id: REQ_INT3_1722941448
   :status: In review
   :date-released:
   :priority: Low
   :submitted-by: Amina Srna
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   --> The function should complete the transmission of the entire buffer within a time frame proportional to the baud rate.


