#include "motor.h"

unsigned int RPS[10];
unsigned int RPM[10];

void Motor_SPEED(unsigned int channel,int speed)
{	
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	
	switch(channel){
		case 1:	//��ǰ				
			if(speed < 0){
				speed *= -1;
				TIM1->CCR1 = 0;
				TIM1->CCR2 = speed;
			}else{
				TIM1->CCR1 = speed;
				TIM1->CCR2 = 0;
			}		
		break;
		case 2:	//���
		break;
		case 3:	//��ǰ
		break;
		case 4:	//�Һ�
		break;
	}
}
unsigned int Motor_RPS(unsigned int channel)
{
	switch(channel){
		case 1:	//��ǰ
			
		break;
		case 2:	//���
		break;
		case 3:	//��ǰ
		break;
		case 4:	//�Һ�
		break;
	}	
	return 0;
}






