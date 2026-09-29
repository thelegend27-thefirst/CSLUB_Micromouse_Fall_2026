#include "gpio_driver.h"
#include <stdint.h>

void Enable_GPIO_Clk(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
    RCC->AHB2ENR |= GPIO_Pin;
}

void GPIO_Output_Mode_Enable(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    uint8_t pin_pos;

    for (pin_pos = 0; pin_pos < 16; pin_pos++)
    {
        if (GPIO_Pin & (1U << pin_pos))
        {
            /* Clear MODER bits for this pin */
            GPIOx->MODER &= ~(0x3U << (pin_pos * 2U));

            /* Set mode to 01: General purpose output mode */
            GPIOx->MODER |=  (0x1U << (pin_pos * 2U));
        }
    }
}

void Push_Pull_enable(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
    GPIOx->OTYPER &= ~GPIO_Pin;
    // OTYPER can set GPIO to either push pull or open drain. 
    // Push Pull:  GPIO Can drive High & Low 
    // Open Drain: GPIO Can only drive Low, external/internal pull up resistor required
}

void Disable_Internal_Resistors(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    uint8_t pinNumber;

    for (pinNumber = 0; pinNumber < 16; pinNumber++)
    {
        if (GPIO_Pin & (1U << pinNumber))
        {
            /* Clear the 2 PUPDR bits for this pin: 00 = No pull-up, no pull-down */
            GPIOx->PUPDR &= ~(0x3U << (pinNumber * 2U));
        }
    }
}

void GPIO_HIGH(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIOx->BSRR = GPIO_Pin;
}


void GPIO_LOW(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIOx->BSRR = (GPIO_Pin << 16U);
}

void GPIO_Toggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIOx->ODR ^= GPIO_Pin;
}