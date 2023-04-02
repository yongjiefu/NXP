#ifndef __SMG_H
#define __SMG_H

#include "stm32f4xx_hal.h"
#include "main.h"

extern int WEI;

void HC595_Send(unsigned int data);
void smg_Display(int num);
void smg_Mode(int mode);
	

#endif /* __MAIN_H */
