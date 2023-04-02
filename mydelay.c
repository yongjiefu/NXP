#include "mydelay.h"


// Core\Src\delay.c
void HAL_Delay_US(uint32_t Delay_us) 
{

	__HAL_TIM_SetCounter(&htim2, 0);

	__HAL_TIM_ENABLE(&htim2);

	while(__HAL_TIM_GetCounter(&htim2) < Delay_us);
	/* Disable the Peripheral */
	__HAL_TIM_DISABLE(&htim2);
}







