#include "stm32f10x.h"
#include "math.h"
#include "Filter.h"
#include "MPU6050.h"

float Angle_gy;         //ǰһʱ�̵Ļ��ֽǶ�
float Angle_A,Angle_B;	//X.Y������ٶ��ݴ�
float Angle_X,Angle_Y;	//�������X.Y

/* ���ٶȼƵķ���ֵ�ݴ���� */
float JSDx = 0;		
float JSDy = 0;
float JSDz = 0;
/* �����ǵķ���ֵ�ݴ���� */
float TLYx = 0;
float TLYy = 0;
float TLYz = 0;

//�����˲�
//-------------------------------------------------------
//-------------------------------------------------------
float bias_cfx;
float angle_dotx; 		//�ⲿ��Ҫ���õı���
const float dtx=0.0048;
//-------------------------------------------------------
void complement_filterX(float angle_m_cfx,float gyro_m_cfx)
{
	bias_cfx*=0.0001;			       //��������Ʈ��ͨ�˲���500�ξ�ֵ��0.998 
	bias_cfx+=gyro_m_cfx*0.009;		   //0.002
	angle_dotx=gyro_m_cfx-bias_cfx;		   
	Angle_X=angle_m_cfx*0.02 + (Angle_X+angle_dotx*dtx)*0.98;	
	//���ٶȵ�ͨ�˲���20�ξ�ֵ����100��ÿ����㣬��ͨ5Hz��0.90 0.05
}
//-------------------------------------------------------
//-------------------------------------------------------
float bias_cfy;
float angle_doty; 		//�ⲿ��Ҫ���õı���
const float dty=0.0048;
//-------------------------------------------------------
void complement_filterY(float angle_m_cfy,float gyro_m_cfy)
{
	bias_cfy*=0.0001;			       //��������Ʈ��ͨ�˲���500�ξ�ֵ��0.998 
	bias_cfy+=gyro_m_cfy*0.009;		   //0.002
	angle_doty=gyro_m_cfy-bias_cfy;		   
	Angle_Y=angle_m_cfy*0.02 + (Angle_Y+angle_doty*dty)*0.98;	
	//���ٶȵ�ͨ�˲���20�ξ�ֵ����100��ÿ����㣬��ͨ5Hz��0.90 0.05
}

void Angle_Calcu(void)	
{
	float temp1,temp2;
	/****************************Y����**************************/
		//���ٶ�(�Ƕ�)	
	int16_t gx,gy,gz;	
	int16_t ax,ay,az;
  MPU_Get_Gyroscope(&gx,&gy,&gz);
	MPU_Get_Accelerometer(&ax,&ay,&az);	
	JSDx  = ax;	  //��ȡX����ٶ�
	JSDy  = ay;	  //��ȡY����ٶ�
	JSDz  = az;	  //��ȡZ����ٶ�
	temp1=sqrt((JSDx*JSDx+JSDz*JSDz))/JSDy;
	JSDy=atan(temp1)/3.1415926*180;
	if(JSDy>0) Angle_B=JSDy-89.9;
	if(JSDy<0) Angle_B=JSDy+90.1;
  //������(���ٶ�)
	TLYx = gy;	          //��ֹʱ���ٶ�Y�����Ϊ-30����
	TLYx = (TLYx)/16.384;         //ȥ�����ƫ�ƣ�������ٶ�ֵ,����Ϊ������ 
////	Angle_gy = Angle_gy + TLYy*0.0056;  //���ٶȻ��ֵõ���б�Ƕ�.	
	
	/****************************X����**************************/
		//���ٶ�(�Ƕ�)
	JSDx  = ax;	  //��ȡX����ٶ�
	JSDy  = ay;	  //��ȡY����ٶ�
	JSDz  = az;	  //��ȡZ����ٶ�
	temp2=sqrt((JSDy*JSDy+JSDz*JSDz))/JSDx;
	JSDx=atan(temp2)/3.1415926*180;
	if(JSDx>0) Angle_A=JSDx-87.2;
	if(JSDx<0) Angle_A=JSDx+92.8;
  //������(���ٶ�)
	TLYy = gy;	           //��ֹʱ���ٶ�Y�����Ϊ-30����
	TLYy = -(TLYy)/16.384;         //ȥ�����ƫ�ƣ�������ٶ�ֵ,����Ϊ������ 
////	Angle_gy = Angle_gy + TLYy*0.0056;  //���ٶȻ��ֵõ���б�Ƕ�.	
	
	//-------�����˲�-----------------------
	//����ԭ����ȡ��ǰ��Ǻͼ��ٶȻ����ǲ�ֵ���зŴ�Ȼ����
  //�����ǽ��ٶȵ��Ӻ��ٻ��֣��Ӷ�ʹ��������Ϊ���ٶȻ�õĽǶ�
	//0.5Ϊ�Ŵ������ɵ��ڲ����ȣ�0.005Ϊϵͳ����5ms	
		
	Angle_X = Angle_X + (((Angle_A-Angle_X)*0.5 + TLYy)*0.0054);		//X����
	Angle_Y =Angle_Y + (((Angle_B-Angle_Y)*0.5 + TLYx)*0.0054);	//Y����

}

/******************************************************************
��ע��ͨ�������ǻ��ֱջ����ڵ�ֵ����ٶȼƵ�ֵһ��
	�Ƕ�ֵ�����������ⶨ��ԭ����ٶȼƲ�õĽǶ�������������������Ҫ�Ľ�����
	�������ǲ�Ƕȣ���Ҫ�õ�������ʾ������
*********************************************************************/
