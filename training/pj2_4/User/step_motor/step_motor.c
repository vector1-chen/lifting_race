#include "step_motor.h"
#include "gpio.h" 
/**
 * @brief  步进电机按指定参数转动控制函数
 * @param  direction 转动方向：1-顺时针，0-逆时针
 * @param  angle     转动角度，单位：度（°）
 * @param  speed     转动速度，单位：度/秒（°/s）
 * @note   假设步进电机步距角为1.8°，细分倍数由宏MICROSREP定义
 * @note   使用PA8作为使能引脚（低电平有效）
 * @note   使用PA9作为方向引脚（高电平顺时针，低电平逆时针）
 * @note   使用PA10作为脉冲引脚
 * @retval None
 */
void Stepper_Motor_Control(int8_t direction, float angle, float speed){
  // 使能步进电机驱动器（低电平有效）
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
  
  // 设置转动方向
  if (direction == 1) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET); // 顺时针
  } else if (direction == 0) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET); // 逆时针
  } else {
    return; // 无效方向参数，直接返回
  }
  
  // 计算需要的脉冲步数
  // 步距角1.8°，经过细分后每步角度为1.8°/MICROSREP
  uint32_t steps = (uint32_t)(angle / (1.8 / MICROSREP));
  
  // 计算脉冲间隔时间（毫秒）
  // speed是度/秒，转换为每步所需时间（毫秒）
  // 每步角度：1.8/MICROSREP度，每步时间：(1.8/MICROSREP)/speed秒 = 1800/(MICROSREP*speed)毫秒
  // 由于是高低电平各占一半时间，所以延时时间为总时间的一半
  uint32_t delay = (uint32_t)(1800 / (2 * speed * MICROSREP));
  
  // 发送脉冲序列
  for (uint32_t i = 0; i < steps; i++) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);   // 脉冲高电平
    HAL_Delay(delay);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET); // 脉冲低电平
    HAL_Delay(delay);
  }
}