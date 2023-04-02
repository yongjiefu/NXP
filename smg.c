#include "smg.h"

int WEI = 1;
unsigned int sumNum[20] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x80};

void HC595_Send(unsigned int data)
{
    unsigned char i;
	
	HAL_GPIO_WritePin(RCK_GPIO_Port,RCK_Pin,GPIO_PIN_RESET);     		//RCLK  = 0     
    for(i=1;i <= 8;i++){
		if(data & 0x80){
			HAL_GPIO_WritePin(SI_GPIO_Port,SI_Pin,GPIO_PIN_SET);		//SER = 1
		}else{
			HAL_GPIO_WritePin(SI_GPIO_Port,SI_Pin,GPIO_PIN_RESET);		//SER = 0
		}
		HAL_GPIO_WritePin(SCK_GPIO_Port,SCK_Pin,GPIO_PIN_SET);			//SRCLK = 1  
				
		HAL_GPIO_WritePin(SCK_GPIO_Port,SCK_Pin,GPIO_PIN_RESET);			//SRCLK = 0 
			
		data <<= 1;
    }  
	HAL_GPIO_WritePin(RCK_GPIO_Port,RCK_Pin,GPIO_PIN_SET); 			//RCLK	= 1
}
void smg_Display(int num)
{
	int value[3];
	value[1] = num / 10;
	value[2] = num % 10;
	
	switch(WEI){
		case 1:
			HAL_GPIO_WritePin(SEG1_GPIO_Port,SEG1_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port,SEG2_Pin,GPIO_PIN_RESET);
			HC595_Send(sumNum[value[1]]);
		break;
		case 2:
			HAL_GPIO_WritePin(SEG1_GPIO_Port,SEG1_Pin,GPIO_PIN_RESET);
			HAL_GPIO_WritePin(SEG2_GPIO_Port,SEG2_Pin,GPIO_PIN_SET);
			HC595_Send(sumNum[value[2]]);
		break;
	}
}
void smg_Mode(int mode)
{
	switch(mode){
		case 0:
		break;
		case 1:
			switch(WEI){
				case 1:
					HAL_GPIO_WritePin(SEG1_GPIO_Port,SEG1_Pin,GPIO_PIN_SET);
					HAL_GPIO_WritePin(SEG2_GPIO_Port,SEG2_Pin,GPIO_PIN_RESET);
					HC595_Send(sumNum[15]);
				break;
				case 2:
					HAL_GPIO_WritePin(SEG1_GPIO_Port,SEG1_Pin,GPIO_PIN_RESET);
					HAL_GPIO_WritePin(SEG2_GPIO_Port,SEG2_Pin,GPIO_PIN_SET);
					HC595_Send(sumNum[15]);
				break;
			}
		break;
	}
}








