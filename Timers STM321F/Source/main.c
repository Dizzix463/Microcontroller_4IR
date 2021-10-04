#include "stm32f10x.h"
#include "timer.h"
#include "gpio.h"

#define LED 10

// Define led structure
MyGPIO_Struct_TypeDef led;
	
void Callback(void) {
	MyGPIO_Toggle(led.GPIO, led.GPIO_Pin);
}

int main(void){
	
	// Define Timer structure
	MyTimer_Struct_TypeDef myTimer;
	
	// Configure the GPIOC of the led
	led.GPIO = GPIOC;
	led.GPIO_Pin = LED;
	led.GPIO_Conf = Out_Ppull;
	MyGPIO_Init(&led);
	
	// Configure timer settings
	myTimer.Timer = TIM2;
	myTimer.ARR = 720 ;
	myTimer.PSC = 1 ;
	
	
	// Fix period of the Timer for 500 ms
	/*
	TIM2->ARR = 6000 - 1;
	TIM2->PSC = 6000 - 1;
	TIM2->CR1 |= (1<<0);
	TIM2->DIER |= TIM_DIER_UIE;
	NVIC->ISER[0] |= (1 << TIM2_IRQn);
	*/
	
	
	
	MyTimer_Base_Init(&myTimer);
	MyTimer_Base_Start(myTimer.Timer);
	MyTimer_ActiveIT(myTimer.Timer , 4, &Callback ) ;
	
	Rapport_Cyclique (myTimer.Timer ,1 , 0.7 );
	
	MyTimer_PWM(myTimer.Timer ,1 ) ;
	
		
	while(1) {
	}
}
