#include "step_motor.h"
#include "delay_us.h"

void step_motor_init(void){
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
}

void step_motor_run(uint16_t angle, uint16_t t_us, uint8_t dir){
    if(dir == 0){
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
    }else if(dir == 1){
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
    }
    for(uint16_t i=0; i<(uint16_t)(angle*4.0/1.8); i++){
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
        delay_us(t_us);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
        delay_us(t_us);
    }
}