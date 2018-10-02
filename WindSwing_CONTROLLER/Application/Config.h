#ifndef _CONFIG_
#define _CONFIG_
#include "Gpio.h"
#include "delay.h"
#include "USART.h"
#include "WB_LCD.h"
#include "Controller.h"
#include "mpu6050.h"
#include "Timer.h"
#include "Debug.h"
#include "SDS.h"
#define k1 0.995
#define ThrMax 8990
#define Xbias 7.49f
#define Ybias 7.68f
#define KP 38.0f
#define KD 2.5f
#define KI 0.6f
struct TestStruct 
{
	uint16_t testduty1;
	uint16_t testduty2;
	uint16_t testduty;
};
#define ABS(x) ( (x)>0?(x):-(x) )
#define LIMIT( x,min,max ) ( (x) < (min)  ? (min) : ( (x) > (max) ? (max) : (x) ) )
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
struct  Infostruct{
	int16_t gx,gy,gz;
	int16_t ax,ay,az;
	float thx;
	float thy;
	float GyroxIntegral;
	float GyroyIntegral;
	float GyrozIntegral;
	float Gyrox,Gyroy,Gyroz;
	float anglex,angley;
	int16_t Xout,Yout;
	float XInt,YInt;
	int16_t Thr;
	float setpointy;
	float setpointx;
	int16_t MotorEnable;
};

struct PIDstruct{
	float setpointone;
	float setpointtwo;
	float Kp;
	float Ki;
	float Kd;
	float duty1,duty2,duty3,duty4;
	
	
};

#endif
