#include "rs485.h"	 

/*******************************************************
功　能：485发送接收控制
参　数：无
返回值：无
********************************************************/  
void RS485_Init(void)
{  	 	
	RS485_TX_EN_0;			//默认为接收模式	
}

void RS485_Send_Data(unsigned char *Data)
{
	RS485_TX_EN_1;			//设置为发送模式
    //HAL_UART_Transmit_IT(&huart5,Data,strlen((char *)Data));
	HAL_UART_Transmit(&huart5,Data,strlen((char *)Data),1000);//串口2发送数据
	RS485_TX_EN_0;			//设置为接收模式
}

