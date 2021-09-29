#include "timer.h"

#define BROCHE_DIODE 5

void ( * callback)(void);


void MyTimer_Base_Init(MyTimer_Struct_TypeDef * Timer1)
{
	// Activate the correponding timer
	if (Timer1->Timer == (TIM1)){
			RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}else if (Timer1->Timer == (TIM2)){
			RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}else if (Timer1->Timer == (TIM3)){
			RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}else if (Timer1->Timer == (TIM4)){
			RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
			
	// Assign values for ARR and PSCMets les valeur pour ARR et PSC
	Timer1->Timer->ARR = Timer1->ARR ;
	Timer1->Timer->PSC = Timer1->PSC;
				
}

void MyTimer_ActiveIT ( TIM_TypeDef  * Timer , char Prio, void (*IT_function) (void)) 
{
    
  // Authorize interruption
	// On met en 1 le bit0 (UIE) du registre DIER
	Timer->DIER |= TIM_DIER_UIE;
	callback = IT_function;
	
	// Configuration du Timer correspondant sur le coeur
	if (Timer == TIM1){
		NVIC->ISER[0] |= (1 << TIM1_UP_IRQn);
		NVIC->IP[TIM1_UP_IRQn] |= (Prio << 4);
		
	}else if (Timer == TIM2){
		NVIC->ISER[0] |= (1 << TIM2_IRQn);
		NVIC->IP[TIM1_UP_IRQn] |= (Prio << 4);
		
	}else if (Timer == TIM3){
		NVIC->ISER[0] |= (1 << TIM3_IRQn);
		NVIC->IP[TIM3_IRQn] |= (Prio << 4);
		
	}else if (Timer == TIM4){
		NVIC->ISER[0] |= (1 << TIM4_IRQn);
		NVIC->IP[TIM4_IRQn] |= (Prio << 4);
	}
}

void TIM1_UP_IRQHandler(void) { 
	
    //Si il y a un d?bordement -> On ?teint le bit UIF
    if (TIM1->SR & TIM_SR_UIF) {
        TIM1->SR &= ~TIM_SR_UIF;
    }
		( * callback)();
}

void TIM2_IRQHandler(void) { 
	
    //Si il y a un d?bordement -> On ?teint le bit UIF
    if (TIM2->SR & TIM_SR_UIF) {
        TIM2->SR &= ~TIM_SR_UIF;
    }
		( * callback)();
}

void TIM3_IRQHandler(void) { 
	
    //Si il y a un d?bordement	-> On ?teint le bit UIF
    if (TIM3->SR & TIM_SR_UIF) {
        TIM3->SR &= ~TIM_SR_UIF;
    }
		( * callback)();
}

void TIM4_IRQHandler(void) { 
	
    //Si il y a un d?bordement -> On ?teint le bit UIF
    if (TIM4->SR & TIM_SR_UIF) {
        TIM4->SR &= ~TIM_SR_UIF;
    }
		( * callback)();
}
