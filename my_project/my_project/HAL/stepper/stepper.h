/*
 * stepper.h
 *
 *  Created on: Aug 15, 2023
 *      Author: hamad
 */

#ifndef HAL_STEPPER_STEPPER_H_
#define HAL_STEPPER_STEPPER_H_

#include "../../MCAL/DIO/DIO.h"

#define STEP_PORT 			PORT_C

#define STEP_COIL_BLUE 		PIN_0
#define STEP_COIL_PINK 		PIN_1
#define STEP_COIL_YELLOW 	PIN_2
#define STEP_COIL_ORANGE 	PIN_3

#define STEP_DELAY 			300

void STEP_Init_Vid(void);
void STEP_HCW_Vid(void);//half step clockwise



#endif /* HAL_STEPPER_STEPPER_H_ */
