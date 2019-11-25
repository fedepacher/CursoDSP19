/*
 * key.c
 *
 *  Created on: Nov 13, 2019
 *      Author: fede_
 */
#include <key_rtos.h>


/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define FLAGS_INT_SW 0x00000001U
#define MSGQUEUE_OBJECTS 16                     // number of Message Queue Objects
/* USER CODE END PD */

/*typedef struct {                                // object data type
  uint8_t Buf[32];
  uint8_t Idx;
} MSGQUEUE_OBJ_t;*/



/* USER CODE BEGIN PV */
osEventFlagsId_t evt_id;
osThreadId_t tid_Thread_EventReceiver;          // thread id 1
osMessageQueueId_t mid_MsgQueue;                // message queue id
osThreadId_t tid_Thread_MsgQueue;              // thread id 1
/* USER CODE END PV */

int Init_Events (void)
{
	//BSP_Init();
	SW_Init();
	evt_id = osEventFlagsNew(NULL);
	if (evt_id == NULL) {
		; // Event Flags object not created, handle failure
	}

	/*const osThreadAttr_t eventTask_attributes = {
			.name = "EventTask",
			.priority = (osPriority_t) osPriorityNormal,
			.stack_size = 4096
	};*/
	tid_Thread_EventReceiver = osThreadNew(Thread_EventReceiver_Key, NULL, NULL);//&eventTask_attributes);
	if (tid_Thread_EventReceiver == NULL) {
		return(-1);
	}

	/*const osThreadAttr_t queueTask_attributes = {
			.name = "QueueTask",
			.priority = (osPriority_t) osPriorityNormal,
			.stack_size = 4096
	};*/
/*	mid_MsgQueue = osMessageQueueNew(MSGQUEUE_OBJECTS, sizeof(board_gpioInfo_type), NULL);
	if (mid_MsgQueue == NULL) {
		return(-1); // Message Queue object not created, handle failure
	}

	tid_Thread_MsgQueue = osThreadNew(Thread_MsgQueue_Key, NULL, NULL);
	if (tid_Thread_MsgQueue == NULL) {
		return(-1);
	}*/
	return(0);
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	osEventFlagsSet(evt_id, FLAGS_INT_SW);
	//osThreadYield();                            // suspend thread

}



void Thread_EventReceiver_Key (void *argument) {
  uint32_t flags;
  //board_gpioInfo_type msg;
  //int32_t id;

  while (1) {
    flags = osEventFlagsWait(evt_id, FLAGS_INT_SW, osFlagsWaitAny, osWaitForever);
    //	osDelay(250);//mando a dormir 50 msg para evitar rebote
    if(flags == FLAGS_INT_SW)//&& PULSADOR_Pin == GPIO_PIN_SET)
    {
    	int16_t sw = SW_Status();
    	osDelay(250);
    	if(sw < BOARD_SW_ID_TOTAL)
    	{
    		board_set_led(sw);
    		//osDelay(250);
    		SW_Init();
    	}

    	//HAL_GPIO_TogglePin(GPIOD, LD4_Pin);



    	//pongo mensaje de activacion de pulsador en la queue
    	//id = BSP_Sw_IT_Handler();


    	osEventFlagsClear(evt_id, FLAGS_INT_SW);	//limpio flag de evento
    	//osMessageQueuePut(mid_MsgQueue, &id, 0U, 0U);
    	osThreadYield();
    }
    //handle event
  }
}

/*void Thread_MsgQueue_Key (void *argument) {

	int16_t id;
	osStatus_t status;

  while (1) {
    // Insert thread code here...
    status = osMessageQueueGet(mid_MsgQueue, &id, NULL, 0U);   // wait for message
    if (status == osOK) {
    	// process data
    	if (id == BOARD_SW_ID)
    	{
    		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
    	   	osDelay(100);
    	   	BSP_Sw_DeInit(id);
    	}
    }
  }
}*/
