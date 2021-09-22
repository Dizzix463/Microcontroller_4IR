#include "gpio.h"


/**
 * @brief Set the mode of a selected pin : Input, Output Analog or Alternative mode
 * @param GPIOx : GPIO adress
 * @param pin : GPIO pin number
 * @param mode : mode to be selected
 * @return null
 */

void GPIO_Configure_Pin_Mode(GPIO_TypeDef * GPIOx, uint16_t pin, uint32_t mode){
    /* Need to compare if the pin is above 8 or not */
    if (pin < 8){
        /* We are in the CRL */
        GPIOx->CRL &= ~(0x03 << (4 * pin)); //set the mask to clear mode bits
        GPIOx->CRL |=  (mode << (4* pin)); //set the mode
    }
    else if(pin > 7)
    {
        /* We are in the CRH */
        GPIOx->CRH &= ~(0x03 << (4 * (pin % 8))); //set the mask to clear mode bits
        GPIOx->CRH |= (mode << (4 * (pin % 8))); //set the mode
    }
}

/**
 * @brief Set the output mode of a pin
 * @param GPIOx : GPIO adress
 * @param pin : pin number
 * @param outputmode : Output type to be set
 * @return null
 */

void GPIO_Configure_Pin_OutputMode(GPIO_TypeDef * GPIOx, uint16_t pin, uint32_t mode, uint32_t outputmode){
    
    GPIOx->BSRR &= ~(0x1 << pin);	// clear bit
	GPIOx->BSRR |= (0x1 << pin);	// as an output

    if(pin < 8)
    {
        GPIOx->CRL &= ~(0x03 << ( 4 * pin + 2)); // clear cnf bits
        GPIOx->CRL |= (outputmode << ( 4 * pin + 2)); // select output type
    }
    else if(pin > 7)
    {
        GPIOx->CRH &= ~(0x03 << ( 4 * (pin % 8) + 2)); // clear cnf bits
        GPIOx->CRH |= (outputmode << ( 4 * (pin % 8) + 2)); // select output type
    }
}

void GPIO_Init(GPIO_TypeDef * GPIOx, GPIO_InitStruct * gpio_config){
    GPIO_Configure_Pin_Mode(GPIOx, gpio_config->Pin, gpio_config->Mode);
    GPIO_Configure_Pin_OutputMode(GPIOx, gpio_config->Pin,gpio_config->Mode,gpio_config->OutputMode);
}

uint16_t GPIO_Input_Check(GPIO_TypeDef * GPIOx, GPIO_InitStruct * gpio_config){
		return (GPIOx->IDR & (1<<gpio_config->Pin));	
}

void GPIO_Mark(GPIO_TypeDef * GPIOx, GPIO_InitStruct * gpio_config){
		GPIOx->ODR |= (0x1 << gpio_config->Pin);
}

void GPIO_unMark(GPIO_TypeDef * GPIOx, GPIO_InitStruct * gpio_config){
		GPIOx->ODR &= (0x0 << gpio_config->Pin);;	
}
