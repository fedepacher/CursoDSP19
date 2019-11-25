/*
 * key.c
 *
 *  Created on: Nov 15, 2019
 *      Author: fede_
 */

/*==================[inclusions]=============================================*/

#include "switch.h"

/*==================[macros and definitions]=================================*/


/*==================[internal data declaration]==============================*/

/*SW_DrvTypeDef SwitchDvr =
{
	SW_Init,
	SW_IT_Handler,
	SW_DeInit,
};*/



static bool eventSW[BOARD_SW_ID_TOTAL];

void SW_Init(void)
{
    int32_t i;

    for (i = 0 ; i < BOARD_SW_ID_TOTAL ; i++)
    {
        eventSW[i] = 0;
    }
}

int16_t SW_Status()
{
	int16_t result = BOARD_SW_ID_TOTAL;
	int i = 0;
	 for (i = 0 ; i < BOARD_SW_ID_TOTAL ; i++)
	 {
		 if (board_getSw(i))
		 {
			 eventSW[i] = 1;
			 result = i;
		 }
	 }
	 return result;
}

/*void SW_DeInit(board_swId_enum id)
{
	if (eventSW[id])
	{
		eventSW[id] = 0;
	}
}*/



/*bool key_getPressEv(board_swId_enum id)
{
    bool ret = false;

    if (eventSW[id])
    {
        eventSW[id] = 0;
        ret = true;
    }

    return ret;
}

void key_periodicTask(void)
{
    int16_t i;

    for (i = 0 ; i < BOARD_SW_ID_TOTAL ; i++)
    {
        switch (estSW[i])
        {
            case ESPERANDO_ACTIVACION:
                if (BSP_getSw(i))
                {
                    eventSW[i] = 1;
                    estSW[i] = ESPERANDO_DESACTIVACION;
                }
                break;

            case ESPERANDO_DESACTIVACION:
                if (!BSP_getSw(i))
                {
                    estSW[i] = ESPERANDO_ACTIVACION;
                }
                break;

            default:
                estSW[i] = ESPERANDO_ACTIVACION;
                break;
        }
    }
}*/
