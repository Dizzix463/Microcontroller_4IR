#include "stm32f10x.h"
#include "gpio.h"

#define BROCHE_DIODE 5
#define BROCHE_BUTTON 13
#define LED_EXTERN 10
#define BP_EXTERN 8

int main ( void )
{
	/* Initialize the pin for the GPIO_DIODE */
	GPIO_InitStruct GPIO_DIODE;
	
	/* Initialize the GPIO for the extern led */
	GPIO_InitStruct GPIO_LED_EXTERN;
	
	/* Initialize the GPIO for the Broche button */
	GPIO_InitStruct GPIO_BROCHE_BUTTON;
	
	/* Initialize the GPIO for the extern button */
	GPIO_InitStruct GPIO_EXTERN_BUTTON;
	
	/* Enabling GPIOA clock */
	RCC_GPIOA_CLK_ENABLE();
	
	/* Enabling GPIOC clock */
	RCC_GPIOC_CLK_ENABLE();
	
	/* Configure the GPIOA pin of the DIODE */
	GPIO_DIODE.Pin = BROCHE_DIODE;
	GPIO_DIODE.Mode = GPIO_PIN_MODE_OUTPUT_2MHZ;
	GPIO_DIODE.OutputMode = GPIO_PIN_OUTPUT_PUSHPULL;
	GPIO_Init(GPIOA, &GPIO_DIODE); // Init the GPIO
	
	
	/* Configure the GPIOC pin for the exetern diode */
	GPIO_LED_EXTERN.Pin = LED_EXTERN;
	GPIO_LED_EXTERN.Mode = GPIO_PIN_MODE_OUTPUT_2MHZ;
	GPIO_LED_EXTERN.OutputMode = GPIO_PIN_OUTPUT_PUSHPULL;
	GPIO_Init(GPIOC, &GPIO_LED_EXTERN); // Init the GPIO

	
	
	/* Configure the GPIOC pin for the broche button */ 
	GPIO_BROCHE_BUTTON.Pin = BROCHE_BUTTON;
	GPIO_BROCHE_BUTTON.Mode = GPIO_PIN_MODE_INPUT;
	GPIO_BROCHE_BUTTON.OutputMode = GPIO_PIN_INPUT_FLOATING;
	GPIO_Init(GPIOC, &GPIO_BROCHE_BUTTON);
	
	/* Configure the GPIOC pin for the broche button */ 
	GPIO_EXTERN_BUTTON.Pin = BP_EXTERN;
	GPIO_EXTERN_BUTTON.Mode = GPIO_PIN_MODE_INPUT;
	GPIO_EXTERN_BUTTON.OutputMode = GPIO_PIN_INPUT_FLOATING;
	GPIO_Init(GPIOC, &GPIO_EXTERN_BUTTON);
	
	while (1)
	{
		
		if (GPIO_Input_Check(GPIOC,&GPIO_BROCHE_BUTTON)){ //(GPIOC->IDR & (1<<BROCHE_BUTTON)
			GPIO_unMark(GPIOA, &GPIO_DIODE); //Masque pour mettre l'octet de rang 1 de GPIOA_ODR à 2 => coché la 5eme case
		}
		else{
			GPIO_Mark(GPIOA, &GPIO_DIODE);
		}
		
		if (GPIO_Input_Check(GPIOC,&GPIO_EXTERN_BUTTON)){
			GPIO_Mark(GPIOC, &GPIO_LED_EXTERN); //Masque pour mettre l'octet de rang 1 de GPIOA_ODR à 2 => coché la 5eme case
		}
		else{
			GPIO_unMark(GPIOC, &GPIO_LED_EXTERN);
		}
	}

}
