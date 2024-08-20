#include "gpio.h"

Gpio::Gpio(GPIO_TypeDef* port, uint32_t pin) : port(port), pin(pin){

    // Enable clock for GPIO ports
    if (port == GPIOA) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    } else if (port == GPIOB) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    }
}

void Gpio::set_mode(uint32_t mode){

    // There are 4 "states" in which mode can be (binary view)
    // 00. input (reset state, always reset mode at the beginning)
    // 01. general purpose output mode
    // 10. alternate function mode
    // 11. analog mode

    port->MODER &= ~(0x3 << (pin * 2)); 
    port->MODER |= (mode << (pin * 2)); 
}

void Gpio::set_input_pull(uint32_t pull){

    // Pull-up and pull-down resistors ensure the pin has a defined logic level when no external signal is present
    // Pull-up - ensures "high level" when no external signals pull it low (because it must be logic level 1)
    // Pull-down - connects pin to ground when no external device pulls it high (because it must be logic level 0)

    port->PUPDR &= ~(0x3 << (pin * 2)); 
    port->PUPDR |= (pull << (pin * 2)); 
}

void Gpio::set_output_type(uint32_t type){

    // Specifies how the GPIO pin can drive voltages and currents, crucial for reliable communication and control in microcontroller-based systems

    port->OTYPER &= ~(0x1 << pin); 
    port->OTYPER |= (type << pin); 
}

void Gpio::set_output_speed(uint32_t speed){

    // GPIO_SPEED_LOW, GPIO_SPEED_MEDIUM, GPIO_SPEED_HIGH when called

    port->OSPEEDR &= ~(0x3 << (pin * 2)); 
    port->OSPEEDR |= (speed << (pin * 2)); 
}

void Gpio::set_alt_func(uint32_t alt_func){

    // Enables various functionalities without needing dedicated pins for each task

    if (pin < 8) {
        port->AFR[0] &= ~(0xF << (pin * 4)); // Clear alternate function bits for lower pins
        port->AFR[0] |= (alt_func << (pin * 4)); // Set alternate function for lower pins
    } else if (pin < 16) {
        port->AFR[1] &= ~(0xF << ((pin - 8) * 4)); // Clear alternate function bits for upper pins
        port->AFR[1] |= (alt_func << ((pin - 8) * 4)); // Set alternate function for upper pins
    }
}

void Gpio::write(const bool value){

    // ODR - direct register for setting individual GPIO pin states
    // BSRR - Provides atomic set/reset operations for GPIO pins, enhancing reliability in concurrent environments and simplifying certain types of GPIO control operations.

    if (value) {
        port->BSRR = (1 << pin); // Set pin
    } else {
        port->BSRR = (1 << (pin + 16)); // Reset pin
    }
}

uint32_t Gpio::read(){

    return (port->IDR & (1 << pin)) >> pin;
}


