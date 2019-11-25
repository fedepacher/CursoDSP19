/*
 * board_ext.h
 *
 *  Created on: Nov 19, 2019
 *      Author: fede_
 */

#include "stdbool.h"
#include "stm32f411xe.h"
#include "main.h"

#ifndef INC_BOARD_EXT_H_
#define INC_BOARD_EXT_H_

typedef enum
{
	BOARD_SW_ID_1 = 0,
	BOARD_SW_ID_2,
	BOARD_SW_ID_3,
	BOARD_SW_ID_4,
	BOARD_SW_ID_TOTAL
}board_swId_enum;

typedef enum
{
	BOARD_LED_ID_VERDE = 0,
	BOARD_LED_ID_NARANJA,
	BOARD_LED_ID_AZUL,
	BOARD_LED_ID_ROJO,
	BOARD_LED_ID_TOTAL
}board_ledId_enum;

typedef struct{
	GPIO_TypeDef *gpio;
	uint16_t pin;
}board_gpioInfo_type;

bool board_getSw(board_swId_enum id);

void board_set_led(board_ledId_enum id);

#endif /* INC_BOARD_EXT_H_ */
