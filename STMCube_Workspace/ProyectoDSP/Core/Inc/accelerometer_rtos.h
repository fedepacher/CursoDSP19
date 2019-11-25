/*
 * accelerometer_rtos.h
 *
 *  Created on: Nov 20, 2019
 *      Author: fede_
 */

#ifndef INC_ACCELEROMETER_RTOS_H_
#define INC_ACCELEROMETER_RTOS_H_
//#include "C:\Users\fede_\STM32CubeIDE\workspace_1.1.0\ProyectoDSP1\Drivers\BSP\STM32F411E-Discovery\stm32f411e_discovery_accelerometer.h"
#include "stm32f411e_discovery_accelerometer.h"
#include "cmsis_os2.h"
#include "main.h"
//#include "ProyectoDSP1/Drivers/BSP/STM32F411E-Discovery/stm32f411e_discovery_accelerometer.h"

int8_t Accelerometer_RTOS_Init();
int Init_MsgQueue (void);
void Thread_MsgQueue_Read_Acc (void *argument);         // thread function 1
void Thread_MsgQueue_Write_Acc (void *argument);         // thread function 2

void AccelerometerTask(void *argument);
#endif /* INC_ACCELEROMETER_RTOS_H_ */
