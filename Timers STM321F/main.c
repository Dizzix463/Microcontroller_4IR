#include "stm32f10x.h"

int main(void){
	
	//Fix period of the Timer for 500 ms
	TIM2->SR = 0;
	TIM2->ARR = 5000;
	TIM2->PSC = 7200;
	
}
