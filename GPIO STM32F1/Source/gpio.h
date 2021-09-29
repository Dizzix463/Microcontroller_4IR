#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"

/**
 * @brief GPIO PIN config structure
 */
typedef struct
{
	GPIO_TypeDef * GPIO;
	char GPIO_Pin;  //numero de 0 a 15
	char GPIO_Conf; // voir ci dessous
} MyGPIO_Struct_TypeDef;

/* GPIO Control Settings Values */
#define In_Floating 0x04
#define In_PullDown 0x08
#define In_PullUp 0x08
#define In_Analog 0x00
#define Out_Ppull 0x02
#define Out_OD 0x06
#define AltOut_Ppull 0x0a
#define AltOut_OD 0x0e

/* GPIO Ports Clock Configuration */
/*
#define RCC_AFIO_CLK_ENABLE()        (RCC->APB2ENR |=  (1 << 0) )
#define RCC_GPIOA_CLK_ENABLE()       (RCC->APB2ENR |=  (1 << 2) )
#define RCC_GPIOB_CLK_ENABLE()       (RCC->APB2ENR |=  (1 << 3) )
#define RCC_GPIOC_CLK_ENABLE()       (RCC->APB2ENR |=  (1 << 4) )
#define RCC_GPIOD_CLK_ENABLE()       (RCC->APB2ENR |=  (1 << 5) )
#define RCC_GPIOE_CLK_ENABLE()       (RCC->APB2ENR |=  (1 << 6) )

#define RCC_GPIOA_CLK_DISABLE()       (RCC->APB2ENR &=  ~(1 << 2) )
#define RCC_GPIOB_CLK_DISABLE()       (RCC->APB2ENR &=  ~(1 << 3) )
#define RCC_GPIOC_CLK_DISABLE()       (RCC->APB2ENR &=  ~(1 << 4) )
#define RCC_GPIOD_CLK_DISABLE()       (RCC->APB2ENR &=  ~(1 << 5) )
#define RCC_GPIOE_CLK_DISABLE()       (RCC->APB2ENR &=  ~(1 << 6) )
*/

// Functions
void MyGPIO_Init(MyGPIO_Struct_TypeDef * GPIOStructPtr);
int MyGPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin);
void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin);

#endif
