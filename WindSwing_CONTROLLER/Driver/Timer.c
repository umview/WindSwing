/**
  * @file    Timer.c 
  * @author  WB R&D Team - openmcu666
  * @version V1.0
  * @date    2016.05.06
  * @brief   Timer Driver
  */

#include "Timer.h"
#include "Filter.h"
float anx=11.65,any;
extern int pwmy,pwmx;
extern unsigned char flag,setlong,flag2;
extern unsigned char rsetlong;
/**
  * @brief  TIM2初始化配置
  * @param  None
  * @retval None
  */   
	

/*	
void TIM_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   //定义 TIM_TimeBase 初始化结构体 TIM_TimeBaseStructure 
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);	//选择优先级分组0 
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; //开启 TIM2 中断, 0级先占优先级，0级后占优先级 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2, ENABLE );        //使能TIM2时钟
	TIM_DeInit(TIM2);
	TIM_TimeBaseStructure.TIM_Period = 1000-1;                      //计数重载值为65535
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1;                       //预分频0
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                   //时钟分割0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	   //向上计数
	TIM_TimeBaseInit(TIM2 , &TIM_TimeBaseStructure);               //初始化TIM2
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	//使能 TIM 中断 
	TIM_ITConfig(TIM2 , TIM_IT_Update , ENABLE);
	TIM_Cmd(TIM2 , ENABLE);	                                        //启动 TIM 计数 

}
*/
/*
void TIM_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   //定义 TIM_TimeBase 初始化结构体 TIM_TimeBaseStructure 
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;           //定义 TIM_OCInit 初始化结构体 TIM_OCInitStructure 
 
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2, ENABLE );
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              //复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;            //翻转频率50MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = 20000-1;                       //重装载值20000
	TIM_TimeBaseStructure.TIM_Prescaler = 0;                        //预分频0
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;                    //时钟分割0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	    //向上计数模式
	TIM_TimeBaseInit(TIM2 , &TIM_TimeBaseStructure);                //初始化时基单元

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;               //PWM1模式
	
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	  //输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;       //输出极性为高

	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //使能预装载寄存器 
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //使能预装载寄存器 	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //使能预装载寄存器 
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //使能预装载寄存器 
	TIM_ARRPreloadConfig(TIM2, ENABLE);
	
	TIM_Cmd(TIM2 , ENABLE);	                                        //启动 TIM 计数 
			 TIM2->CCR1 = 0;
		 	 TIM2->CCR2 = 0;
		 	 TIM2->CCR3 = 0;
			 TIM2->CCR4 = 0;
}
*/
void TIM3_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能

	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Down;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

	TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设						 
}
void TIM5_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   //定义 TIM_TimeBase 初始化结构体 TIM_TimeBaseStructure 
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);	//选择优先级分组0 
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn; //开启 TIM2 中断, 0级先占优先级，0级后占优先级 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM5, ENABLE );        //使能TIM2时钟
	TIM_DeInit(TIM5);
	TIM_TimeBaseStructure.TIM_Period = 1000-1;                      //计数重载值为65535
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1;                       //预分频0
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                   //时钟分割0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	   //向上计数
	TIM_TimeBaseInit(TIM5 , &TIM_TimeBaseStructure);               //初始化TIM2
	TIM_ClearFlag(TIM5,TIM_FLAG_Update);
	//使能 TIM 中断 
	TIM_ITConfig(TIM5 , TIM_IT_Update , ENABLE);
	TIM_Cmd(TIM5 , ENABLE);	                                        //启动 TIM 计数 

}
void TIM_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   //定义 TIM_TimeBase 初始化结构体 TIM_TimeBaseStructure 
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;           //定义 TIM_OCInit 初始化结构体 TIM_OCInitStructure 
 
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM3, ENABLE );
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE );
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              //复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;            //翻转频率50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = 9000-1;                       //重装载值20000
	TIM_TimeBaseStructure.TIM_Prescaler = 20-1;                        //预分频0
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;                    //时钟分割0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	    //向上计数模式
	TIM_TimeBaseInit(TIM3 , &TIM_TimeBaseStructure);                //初始化时基单元

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;               //PWM1模式
	
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	  //输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;       //输出极性为高

	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //使能预装载寄存器 
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //使能预装载寄存器 	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //使能预装载寄存器 
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3 , TIM_OCPreload_Enable);	            //使能预装载寄存器 
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	
	TIM_Cmd(TIM3 , ENABLE);	                                        //启动 TIM 计数 
			 TIM3->CCR1 = 0;
		 	 TIM3->CCR2 = 0;
		 	 TIM3->CCR3 = 0;
			 TIM3->CCR4 = 0;
}
