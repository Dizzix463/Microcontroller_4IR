#include "gpio.h"

void MyGPIO_Init (MyGPIO_Struct_TypeDef * GPIOStructPtr){
	// Activate the corresponding GPIO Clock
	if (GPIOStructPtr->GPIO == GPIOA) {
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	} else if (GPIOStructPtr->GPIO == GPIOB) {
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	} else if (GPIOStructPtr->GPIO == GPIOC) {
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	} else if (GPIOStructPtr->GPIO == GPIOD) {
		RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
	} else if (GPIOStructPtr->GPIO == GPIOE) {
		RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
	}
	
	// Configurate the correct settings for the corresponding GPIO Pin
	if (GPIOStructPtr->GPIO_Pin > 7) {
		GPIOStructPtr->GPIO->CRH &= ~(0x0f << (GPIOStructPtr->GPIO_Pin - 8) * 4);
		GPIOStructPtr->GPIO->CRH |= (GPIOStructPtr->GPIO_Conf << (GPIOStructPtr->GPIO_Pin - 8) * 4);
	} else {
		GPIOStructPtr->GPIO->CRL &= ~(0x0f << (GPIOStructPtr->GPIO_Pin) * 4);
		GPIOStructPtr->GPIO->CRL |= (GPIOStructPtr->GPIO_Conf << (GPIOStructPtr->GPIO_Pin) * 4);
	}
}

int MyGPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	return (GPIO->IDR & (0x01 << GPIO_Pin));	
}

void MyGPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	GPIO->ODR |= (0x01 << GPIO_Pin);
}

void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	GPIO->ODR &= (0x0 << GPIO_Pin);	
}
void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	if (MyGPIO_Read(GPIO, GPIO_Pin)) {
		MyGPIO_Reset(GPIO, GPIO_Pin);
	} else {
		MyGPIO_Set(GPIO, GPIO_Pin);
	}
}
