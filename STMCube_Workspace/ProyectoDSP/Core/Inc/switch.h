/*
 * key.h
 *
 *  Created on: Nov 15, 2019
 *      Author: fede_
 */

#ifndef SRC_SWITCH_H_
#define SRC_SWITCH_H_

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
extern "C" {
#endif


/*==================[external functions definition]==========================*/
#include "board_ext.h"


void SW_Init(void);
int16_t SW_Status(void);
//void SW_DeInit(board_swId_enum id);
/*bool key_getPressEv(board_swId_enum id);
void key_periodicTask(void);*/


/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif

#endif /* SRC_SWITCH_H_ */
