#include "stm32f10x.h"
#include "timer.h"

int main(void){
	
	// Initialize clock
	 RCC->APB2ENR |= (1<<2) | (1<<3) | (1<<4);
	
	// Branch the GPIO A to the APB2 clock (Activer ??)
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	
	// Fix period of the Timer for 500 ms
	// TIM2->SR = 0;
	TIM2->ARR = 6000 - 1;
	TIM2->PSC = 6000 - 1;
}
