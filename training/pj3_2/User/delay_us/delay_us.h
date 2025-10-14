#ifndef __DELAY_US_H__
#define __DELAY_US_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
#include "tim.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes --------------------------------------------*/
/**
 * @brief  Initialize delay functions
 * @param  None
 * @retval None
 */
void delay_us_init(void);

/**
 * @brief  Delay for specified microseconds
 * @param  us: Number of microseconds to delay
 * @retval None
 */
void delay_us(uint32_t us);


/* Private defines -----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __DELAY_US_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/