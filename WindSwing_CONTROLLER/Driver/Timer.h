#ifndef __TIMER_H
#define __TIMER_H

#include "stm32f10x.h"

extern vu16 CCR1_Val;					// 声明输出比较通道1计数周期变量
extern vu16 CCR2_Val;					// 声明输出比较通道2计数周期变量
extern vu16 CCR3_Val;					// 声明输出比较通道3计数周期变量
extern vu16 CCR4_Val;					// 声明输出比较通道4计数周期变量
void TIM5_Init(void);
void TIM_Init(void);
void TIM3_Int_Init(u16 arr,u16 psc);
#endif
