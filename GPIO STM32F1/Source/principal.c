#include "stm32f10x.h"
#include "gpio.h"

#define BROCHE_DIODE 5
#define BROCHE_BUTTON 13
#define LED_EXTERN 10
#define BP_EXTERN 8

int main ( void )
{	
	/* Initialize the pin for the GPIO_DIODE */
	MyGPIO_Struct_TypeDef diode;
	
	/* Initialize the GPIO for the extern led */
	MyGPIO_Struct_TypeDef led;
	
	/* Initialize the GPIO for the Broche button */
	MyGPIO_Struct_TypeDef brocheButton;
	
	/* Initialize the GPIO for the extern button */
	MyGPIO_Struct_TypeDef externalButton;
	
	
	/* Configure the GPIOA pin of the diode */
	diode.GPIO = GPIOA;
	diode.GPIO_Pin = BROCHE_DIODE;
	diode.GPIO_Conf = Out_Ppull;
	MyGPIO_Init(&diode);
	
	
	/* Configure the GPIOC pin for the led */
	led.GPIO = GPIOC;
	led.GPIO_Pin = LED_EXTERN;
	led.GPIO_Conf = Out_Ppull;
	MyGPIO_Init(&led);

	
	/* Configure the GPIOC pin for the broche button */ 
	brocheButton.GPIO = GPIOC;
	brocheButton.GPIO_Pin = BROCHE_BUTTON;
	brocheButton.GPIO_Conf = In_Floating;
	MyGPIO_Init(&brocheButton);
	
	
	/* Configure the GPIOC pin for the external button */ 
	externalButton.GPIO = GPIOC;
	externalButton.GPIO_Pin = BP_EXTERN;
	externalButton.GPIO_Conf = In_Floating;
	MyGPIO_Init(&externalButton);
	
	MyGPIO_Reset(diode.GPIO, diode.GPIO_Pin);
	MyGPIO_Set(diode.GPIO, diode.GPIO_Pin);
	MyGPIO_Reset(diode.GPIO, diode.GPIO_Pin);
	
	MyGPIO_Set(led.GPIO, led.GPIO_Pin);
	MyGPIO_Reset(led.GPIO, led.GPIO_Pin);			
	MyGPIO_Set(led.GPIO, led.GPIO_Pin);


	
	while (1)
	{
		// Onboard diode lights up when onboard user button is pressed
		if (MyGPIO_Read(brocheButton.GPIO, brocheButton.GPIO_Pin)) {
			MyGPIO_Reset(diode.GPIO, diode.GPIO_Pin);
		} else {
			MyGPIO_Set(diode.GPIO, diode.GPIO_Pin);
		}
		
		// external led lights up when external button is pressed
		if (MyGPIO_Read(externalButton.GPIO, externalButton.GPIO_Pin)) {
			MyGPIO_Set(led.GPIO, led.GPIO_Pin);
		} else {
			MyGPIO_Reset(led.GPIO, led.GPIO_Pin);
		}
	}
}
