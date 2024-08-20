#include "usart.h"

Usart::Usart(USART_TypeDef* usart) : usart(usart) {

    if (usart == USART1) {
        // enables the clock for USART1 by setting the USART1EN bit in the APB2ENR register.
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    } else if (usart == USART2) {
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    } else if (usart == USART6) {
        RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
    }
}

void Usart::init(uint32_t baud_rate, uint32_t oversampling){

    usart->CR1 &= ~USART_CR1_OVER8; //Clear the OVER8 Bit in CR1 Register
    if (oversampling == 8) {
        usart->CR1 |= USART_CR1_OVER8;
    }

    uint32_t usartdiv = (SystemCoreClock / (baud_rate * (oversampling == 8 ? 8 : 16))) + 0.5; // Calculate USARTDIV
    usart->BRR = usartdiv; // Set the Baud Rate Register (BRR), The baud rate defines the speed of communication channel

    usart->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE; // Enable the USART, Transmitter, and Receiver, so pin TX And RX can transmit and receive data 
}


void Usart::write_byte(const char byte){
    while(!(usart->SR & USART_SR_TXE));
    usart->DR = byte;
}

void Usart::write_buf(const char* buf, const int len){
    for (int i = 0; i < len; i++) {
        write_byte(buf[i]);
    }
}
