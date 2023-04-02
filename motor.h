#ifndef __MOTOR_H
#define __MOTOR_H

#include "stm32f4xx_hal.h"
#include "main.h"
#include "tim.h"

extern unsigned int RPS[10];
extern unsigned int RPM[10];

void Motor_SPEED(unsigned int channel,int speed);
unsigned int Motor_RPS(unsigned int channel);


#endif /* __MAIN_H */
