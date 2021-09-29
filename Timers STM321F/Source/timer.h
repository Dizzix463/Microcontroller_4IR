#ifndef MyTimer_H
#define MyTimer_H
#include "stm32f10x.h"

typedef  struct
{
		TIM_TypeDef * Timer ;   // TIM1 à TIM4
		unsigned short ARR;
		unsigned short PSC;
} MyTimer_Struct_TypeDef ;


/*******************************************************************************************
	*@brief
	*		@param -> Paramètre sous forme d’une structure ( son adresse ) contenant les
			informations de base
	*		@Note-> Fonction à lancer  systématiquement avant d'aller plus en détail dans les conf  
					plus  fines  (PWM, codeur  inc . . . )
*************************************************************************************************
*/
void MyTimer_Base_Init ( MyTimer_Struct_TypeDef*Timer ) ;

// Enable/disable CEN
#define MyTimer_Base_Start(Timer) (Timer->CR1 |= (1<<0))
#define MyTimer_Base_Stop(Timer) (Timer->CR1 &= ~(1<<0))


void MyTimer_ActiveIT ( TIM_TypeDef  * Timer1 , char Prio, void (*IT_function) (void)) ;

/*
void TIM1_UP_IRQHandler(void);

void TIM2_IRQHandler(void);

void TIM3_IRQHandler(void);

void TIM4_IRQHandler(void);
*/

#endif
