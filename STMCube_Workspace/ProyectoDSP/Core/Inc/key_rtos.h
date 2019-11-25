/*
 * key.h
 *
 *  Created on: Nov 13, 2019
 *      Author: fede_
 */

#ifndef SRC_KEY_H_
#define SRC_KEY_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "board_ext.h"

/* Exported functions prototypes ---------------------------------------------*/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
int Init_Events (void);
void Thread_EventReceiver_Key (void *argument);
void Thread_MsgQueue_Key(void *argument);         // thread function 1


#endif /* SRC_KEY_H_ */
