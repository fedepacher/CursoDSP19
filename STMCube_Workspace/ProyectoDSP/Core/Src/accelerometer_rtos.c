/*
 * accelerometer_rtos.c
 *
 *  Created on: Nov 20, 2019
 *      Author: fede_
 */
#include "accelerometer_rtos.h"

#define MSGQUEUE_OBJECTS 16                     // number of Message Queue Objects

typedef struct {                                // object data type
  uint8_t Buf[3];
} MSGQUEUE_OBJ_t;

osMessageQueueId_t mid_MsgQueue;                // message queue id
osThreadId_t tid_Thread_MsgQueue1;              // thread id 1
osThreadId_t tid_Thread_MsgQueue2;              // thread id 2
osThreadId_t accelerometerTaskHandle;


int8_t Accelerometer_RTOS_Init()
{
	uint8_t acc_status = ACCELERO_ERROR;
	acc_status = BSP_ACCELERO_Init();
	if(acc_status == ACCELERO_ERROR){
		return acc_status;
	}
	if(acc_status == ACCELERO_OK){
		//Init_MsgQueue();

		const osThreadAttr_t accelerometerTask_attributes = {
		    .name = "defaultTask",
		    .priority = (osPriority_t) osPriorityNormal,
		    .stack_size = 4096
		  };
		accelerometerTaskHandle = osThreadNew(AccelerometerTask, NULL, &accelerometerTask_attributes);

		return acc_status;
	}

	return acc_status;
}

int Init_MsgQueue (void) {

  mid_MsgQueue = osMessageQueueNew(MSGQUEUE_OBJECTS, sizeof(MSGQUEUE_OBJ_t), NULL);
  if (mid_MsgQueue == NULL) {
    ; // Message Queue object not created, handle failure
  }

  tid_Thread_MsgQueue1 = osThreadNew(Thread_MsgQueue_Read_Acc, NULL, NULL);
  if (tid_Thread_MsgQueue1 == NULL) {
    return(-1);
  }
  tid_Thread_MsgQueue2 = osThreadNew(Thread_MsgQueue_Write_Acc, NULL, NULL);
  if (tid_Thread_MsgQueue2 == NULL) {
    return(-1);
  }

  return(0);
}


void Thread_MsgQueue_Read_Acc (void *argument) {
  MSGQUEUE_OBJ_t msg;
  int16_t *pDataXYZ;
  while (1) {
    // Insert thread code here...
	  BSP_ACCELERO_GetXYZ(pDataXYZ);

	 int i = 0;
	 for(i = 0; i < sizeof(msg.Buf); i++){
		 msg.Buf[i] = pDataXYZ[i];                                         // do some work...
	 }

    osMessageQueuePut(mid_MsgQueue, &msg, 0U, 0U);
    osThreadYield();                                            // suspend thread
  }
}

void Thread_MsgQueue_Write_Acc (void *argument) {
  MSGQUEUE_OBJ_t msg;
  osStatus_t status;

  while (1)
  {
    // Insert thread code here...
    status = osMessageQueueGet(mid_MsgQueue, &msg, NULL, 0U);   // wait for message
    if (status == osOK)
    {
    	// process data
    	    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
    	   	osDelay(100);
    }
  }
}

void AccelerometerTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */

  for(;;)
  {

	  HAL_GPIO_TogglePin(GPIOD, LD6_Pin);
	 // printf("Cuenta: %ld \n", contador);

	  /*char txData[50]= "";
	  sprintf(txData, "%d\n\r", contador);
	  HAL_UART_Transmit(&huart2, (uint8_t *) txData, sizeof(txData),1000);*/
	  osDelay(500);
  }
  /* USER CODE END 5 */
}
