#ifndef STEP_MOTOR_H
#define STEP_MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include <stdint.h>

/* Defines */
#define MICROSREP 4 // 细分倍数，例如4表示1/4细分

/* Typedefs */

/* Function prototypes */
void Stepper_Motor_Control(int8_t direction, float angle, float speed);

#ifdef __cplusplus
}
#endif

#endif /* STEP_MOTOR_H */