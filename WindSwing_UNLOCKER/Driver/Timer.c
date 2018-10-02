/**
  * @file    Timer.c 
  * @author  WB R&D Team - openmcu666
  * @version V1.0
  * @date    2016.05.06
  * @brief   Timer Driver
  */

#include "Timer.h"
/**
  * @brief  TIM2��ʼ������
  * @param  None
  * @retval None
  */   
	

/*	
void TIM_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   //���� TIM_TimeBase ��ʼ���ṹ�� TIM_TimeBaseStructure 
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);	//ѡ�����ȼ�����0 
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; //���� TIM2 �ж�, 0����ռ���ȼ���0����ռ���ȼ� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2, ENABLE );        //ʹ��TIM2ʱ��
	TIM_DeInit(TIM2);
	TIM_TimeBaseStructure.TIM_Period = 1000-1;                      //��������ֵΪ65535
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1;                       //Ԥ��Ƶ0
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                   //ʱ�ӷָ�0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	   //���ϼ���
	TIM_TimeBaseInit(TIM2 , &TIM_TimeBaseStructure);               //��ʼ��TIM2
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	//ʹ�� TIM �ж� 
	TIM_ITConfig(TIM2 , TIM_IT_Update , ENABLE);
	TIM_Cmd(TIM2 , ENABLE);	                                        //���� TIM ���� 

}
*/
/*
void TIM_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   //���� TIM_TimeBase ��ʼ���ṹ�� TIM_TimeBaseStructure 
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;           //���� TIM_OCInit ��ʼ���ṹ�� TIM_OCInitStructure 
 
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2, ENABLE );
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              //�����������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;            //��תƵ��50MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = 20000-1;                       //��װ��ֵ20000
	TIM_TimeBaseStructure.TIM_Prescaler = 0;                        //Ԥ��Ƶ0
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;                    //ʱ�ӷָ�0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	    //���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2 , &TIM_TimeBaseStructure);                //��ʼ��ʱ����Ԫ

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;               //PWM1ģʽ
	
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	  //���ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;       //�������Ϊ��

	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //ʹ��Ԥװ�ؼĴ��� 
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //ʹ��Ԥװ�ؼĴ��� 	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //ʹ��Ԥװ�ؼĴ��� 
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //ʹ��Ԥװ�ؼĴ��� 
	TIM_ARRPreloadConfig(TIM2, ENABLE);
	
	TIM_Cmd(TIM2 , ENABLE);	                                        //���� TIM ���� 
			 TIM2->CCR1 = 0;
		 	 TIM2->CCR2 = 0;
		 	 TIM2->CCR3 = 0;
			 TIM2->CCR4 = 0;
}
*/
void TIM5_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   //���� TIM_TimeBase ��ʼ���ṹ�� TIM_TimeBaseStructure 
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);	//ѡ�����ȼ�����0 
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn; //���� TIM2 �ж�, 0����ռ���ȼ���0����ռ���ȼ� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM5, ENABLE );        //ʹ��TIM2ʱ��
	TIM_DeInit(TIM5);
	TIM_TimeBaseStructure.TIM_Period = 1000-1;                      //��������ֵΪ65535
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1;                       //Ԥ��Ƶ0
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                   //ʱ�ӷָ�0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	   //���ϼ���
	TIM_TimeBaseInit(TIM5 , &TIM_TimeBaseStructure);               //��ʼ��TIM2
	TIM_ClearFlag(TIM5,TIM_FLAG_Update);
	//ʹ�� TIM �ж� 
	TIM_ITConfig(TIM5 , TIM_IT_Update , ENABLE);
	TIM_Cmd(TIM5 , ENABLE);	                                        //���� TIM ���� 

}
void TIM_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   //���� TIM_TimeBase ��ʼ���ṹ�� TIM_TimeBaseStructure 
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;           //���� TIM_OCInit ��ʼ���ṹ�� TIM_OCInitStructure 
 
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM3, ENABLE );
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE );
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;              //�����������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;            //��תƵ��50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = 9000-1;                       //��װ��ֵ20000
	TIM_TimeBaseStructure.TIM_Prescaler = 20-1;                        //Ԥ��Ƶ0
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;                    //ʱ�ӷָ�0
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	    //���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3 , &TIM_TimeBaseStructure);                //��ʼ��ʱ����Ԫ

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;               //PWM1ģʽ
	
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	  //���ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;       //�������Ϊ��

	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //ʹ��Ԥװ�ؼĴ��� 
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //ʹ��Ԥװ�ؼĴ��� 	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM2 , TIM_OCPreload_Enable);	            //ʹ��Ԥװ�ؼĴ��� 
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3 , TIM_OCPreload_Enable);	            //ʹ��Ԥװ�ؼĴ��� 
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	
	TIM_Cmd(TIM3 , ENABLE);	                                        //���� TIM ���� 
			 TIM3->CCR1 = 0;
		 	 TIM3->CCR2 = 0;
		 	 TIM3->CCR3 = 0;
			 TIM3->CCR4 = 0;
}
