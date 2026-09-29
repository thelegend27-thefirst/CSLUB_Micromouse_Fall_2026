#include "GPIO.hpp"
#include "gpio_driver.h"

GPIO::GPIO(GPIO_TypeDef* port, uint16_t pin)
    : port(port), pin(pin)
{
    Enable_GPIO_Clk(port, pin);
    GPIO_Output_Mode_Enable(port, pin);
    Push_Pull_enable(port, pin);
    Disable_Internal_Resistors(port, pin);
}

void GPIO::HIGH()
{
    GPIO_HIGH(port, pin);
}

void GPIO::LOW()
{
    GPIO_LOW(port, pin);
}

void GPIO::toggle()
{
    GPIO_Toggle(port, pin);

}
