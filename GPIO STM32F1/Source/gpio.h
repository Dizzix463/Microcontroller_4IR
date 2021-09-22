#include "stm32f10x.h"

/* GPIO Control Settings Values */
#define GPIO_PIN_INPUT_ANALOG_MODE ( (uint32_t) 0x00)
#define GPIO_PIN_INPUT_FLOATING ( (uint32_t) 0x01)
#define GPIO_PIN_INPUT_PUPD ( (uint32_t) 0x10)

#define GPIO_PIN_OUTPUT_PUSHPULL ( (uint32_t) 0x00)
#define GPIO_PIN_OUTPUT_OPENDRAIN ( (uint32_t) 0x01)
#define GPIO_PIN_OUTPUT_ALT_PUSHPULL ( (uint32_t) 0x10)
#define GPIO_PIN_OUTPUT_ALT_OPENDRAIN ( (uint32_t) 0x11)

#define GPIO_PIN_MODE_INPUT ( (uint32_t) 0x00)
#define GPIO_PIN_MODE_OUTPUT_10MHZ ( (uint32_t) 0x10)
#define GPIO_PIN_MODE_OUTPUT_2MHZ ( (uint32_t) 0x2)
#define GPIO_PIN_MODE_OUTPUT_50MHZ ( (uint32_t) 0x11)


/* GPIO Ports Clock Configuration */
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

/**
 * @brief GPIO PIN config structure
 */

typedef struct
{
    uint32_t Pin;
    uint32_t Mode;
    uint32_t OutputMode;
}GPIO_InitStruct;


/**
 * @brief GPIO function set mode
 */
void GPIO_Configure_Pin_Mode(GPIO_TypeDef * GPIOx, uint16_t pin, uint32_t mode);


/**
 * @brief GPIO functon set outputmode
 */
void GPIO_Configure_Pin_OutputMode(GPIO_TypeDef * GPIOx, uint16_t pin, uint32_t mode, uint32_t outputmode);


/**
 * @brief GPIO function header
 */

void GPIO_Init(GPIO_TypeDef * GPIOx, GPIO_InitStruct * GPIO_PIN_CONF);

/**
 * @brief Check the correspondant pin 
 */
uint16_t GPIO_Input_Check(GPIO_TypeDef * GPIOx, GPIO_InitStruct * GPIO_CONF);

/**
 * @brief Mark the correspondant pin of a GPIO 
 */
void GPIO_Mark(GPIO_TypeDef * GPIOx, GPIO_InitStruct * gpio_config);


/**
 * @brief unMark the correspondant pin of a GPIO 
 */
void GPIO_unMark(GPIO_TypeDef * GPIOx, GPIO_InitStruct * gpio_config);
