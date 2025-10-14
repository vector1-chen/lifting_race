#include "delay_us.h"

void delay_us_init(void)
{
    HAL_TIM_Base_Start(&htim1);
}

void delay_us(uint32_t us)
{
    __HAL_TIM_SET_COUNTER(&htim1, 0);  // set the counter value to 0
    while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}