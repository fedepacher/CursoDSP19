/*
 * board_ext.c
 *
 *  Created on: Nov 19, 2019
 *      Author: fede_
 */
#include "board_ext.h"


static const board_gpioInfo_type board_gpioSw[] =
{
		{PULSADOR0_GPIO_Port, PULSADOR0_Pin},
		{PULSADOR1_GPIO_Port, PULSADOR1_Pin},
		{PULSADOR2_GPIO_Port, PULSADOR2_Pin},
		{PULSADOR3_GPIO_Port, PULSADOR3_Pin},
};
static const board_gpioInfo_type board_leds[] =
{
		{LD4_GPIO_Port, LD4_Pin},
		{LD3_GPIO_Port, LD3_Pin},
		{LD5_GPIO_Port, LD5_Pin},
		{LD6_GPIO_Port, LD6_Pin},
};

bool board_getSw(board_swId_enum id)
{
	return HAL_GPIO_ReadPin(board_gpioSw[id].gpio, board_gpioSw[id].pin);

}


void board_set_led(board_ledId_enum id)
{
	HAL_GPIO_TogglePin(board_leds[id].gpio, board_leds[id].pin);
}
