#pragma once

#ifdef __cplusplus
extern "C" {
#endif


#include "main.h"

/*
@brief Enables GPIO clk for GPIO to function
@param GPIO port 
@param GPIO pin
@return None
*/
void Enable_GPIO_Clk(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/*
@brief Sets GPIO mode to output 
@param GPIO port 
@param GPIO pin
@return None
*/
void GPIO_Output_Mode_Enable(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/*
@brief Sets GPIO to Push Pull
@param GPIO port 
@param GPIO pin
@return None
*/
void Push_Pull_enable(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/*
@breif Disable internal pull up/pull down resistors
@param GPIO port 
@param GPIO pin
@return None
*/
void Disable_Internal_Resistors(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/*
@breif Set GPIO pin HIGH
@param GPIO port 
@param GPIO pin
@return None
*/
void GPIO_HIGH(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/*
@breif Set GPIO pin LOW
@param GPIO port 
@param GPIO pin
@return None
*/
void GPIO_LOW(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/*
@breif Toggle GPIO pin
@param GPIO port 
@param GPIO pin
@return None
*/
void GPIO_Toggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#ifdef __cplusplus
}
#endif
