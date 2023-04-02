#ifndef __RS485_H
#define __RS485_H	
		 
#include "main.h"						  
#include "usart.h"
#include "string.h"

//模式控制
#define RS485_TX_EN_0 HAL_GPIO_WritePin(RE_DE_GPIO_Port,RE_DE_Pin,GPIO_PIN_RESET)	//485模式控制.0,接收;1,发送.
#define RS485_TX_EN_1 HAL_GPIO_WritePin(RE_DE_GPIO_Port,RE_DE_Pin,GPIO_PIN_SET)		
  
void RS485_Init(void);
void RS485_Send_Data(unsigned char *Data);

#endif	   





