#ifndef MyTimer_H
#define MyTimer_H
#include "stm32f10x.h"

typedef  struct
{
		TIM_TypeDef * Timer ;   // TIM1 � TIM4
		unsigned short ARR;
		unsigned short PSC;
} MyTimer_Struct_TypeDef ;


/*******************************************************************************************
	*@brief
	*		@param -> Param�tre sous forme d�une structure ( son adresse ) contenant les
			informations de base
	*		@Note-> Fonction � lancer  syst�matiquement avant d'aller plus en d�tail dans les conf  
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

/* 
**@brief
*@param   . . . .
*@Note    Active le channel sp�cifi� du Timerr le timer sp� c i f i �*la  gestion  de  la  configuration   I /O n � est  pas  f a i t e  dans  cette  fonction*ni  le  r � glage de  la p� riode de  la PWM (ARR, PSC)*/
void MyTimer_PWM(TIM_TypeDef*Timer ,char Channel ) ;

void Rapport_Cyclique (TIM_TypeDef * Timer,char Channel, float Ratio ) ;
#endif
