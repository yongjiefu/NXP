#include "rs485.h"	 

/*******************************************************
�����ܣ�485���ͽ��տ���
�Ρ�������
����ֵ����
********************************************************/  
void RS485_Init(void)
{  	 	
	RS485_TX_EN_0;			//Ĭ��Ϊ����ģʽ	
}

void RS485_Send_Data(unsigned char *Data)
{
	RS485_TX_EN_1;			//����Ϊ����ģʽ
    //HAL_UART_Transmit_IT(&huart5,Data,strlen((char *)Data));
	HAL_UART_Transmit(&huart5,Data,strlen((char *)Data),1000);//����2��������
	RS485_TX_EN_0;			//����Ϊ����ģʽ
}

