#include "stm32f10x.h"
#include "timer.h"

void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) {
	Timer->Timer = TIM2;
	Timer->ARR = 6000 - 1;
	Timer->PSC = 6000 - 1;
}
