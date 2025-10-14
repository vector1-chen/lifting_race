#ifndef __STEP_MOTOR_H__
#define __STEP_MOTOR_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"

/* Exported types -------   -----------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes --------------------------------------------*/
void step_motor_init(void);

void step_motor_run(uint16_t angle, uint16_t t_us, uint8_t dir);
/* Private defines -----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __STEP_MOTOR_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/