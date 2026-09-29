#pragma once

#include "main.h"

class GPIO {
public:
    GPIO(GPIO_TypeDef* port, uint16_t pin);

    void HIGH();
    void LOW();
    void toggle();

private:
    GPIO_TypeDef* port;
    uint16_t pin;
};