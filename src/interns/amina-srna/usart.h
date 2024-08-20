#ifndef _USART_H_
#define _USART_H_

#include <stdint.h>
#include "stm32f4xx.h"

class Usart {
    
    private:
        USART_TypeDef* usart;

    public:
        Usart(USART_TypeDef* usart);
        void init(uint32_t baud_rate, uint32_t oversampling);
        void write_byte(const char byte);
        void write_buf(const char* buf, const int len);
};

#endif
