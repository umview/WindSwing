#ifndef __TIMER_H
#define __TIMER_H

#include "stm32f10x.h"

extern vu16 CCR1_Val;					// ��������Ƚ�ͨ��1�������ڱ���
extern vu16 CCR2_Val;					// ��������Ƚ�ͨ��2�������ڱ���
extern vu16 CCR3_Val;					// ��������Ƚ�ͨ��3�������ڱ���
extern vu16 CCR4_Val;					// ��������Ƚ�ͨ��4�������ڱ���
void TIM5_Init(void);
void TIM_Init(void);
void TIM3_Int_Init(u16 arr,u16 psc);
#endif
