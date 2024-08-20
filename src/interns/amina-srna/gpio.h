#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdint.h>
#include "stm32f4xx.h"

class Gpio {
    private:
        GPIO_TypeDef* port;
        uint32_t pin;

    public:
        Gpio(GPIO_TypeDef* port, uint32_t pin);
        void set_mode(uint32_t mode);
        void set_input_pull(uint32_t pull);
        void set_output_type(uint32_t type);
        void set_output_speed(uint32_t speed);
        void set_alt_func(uint32_t alt_func);

        void write(bool value);
        uint32_t read();
};

#endif
