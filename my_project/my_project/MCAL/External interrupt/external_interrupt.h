/*
 * external_interrupt.h
 *
 *  Created on: Aug 16, 2023
 *      Author: hamad
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_

#include "../../LIB/STD_TYPES.h"

#define INT_LOW_LEVEL 			0
#define INT_LOGICAL_CHANGE 		1
#define INT_FALLING_EDGE 		2
#define INT_RISING_EDGE		 	3

#define ENABLE		0
#define DISABLE		1

#define INT_0 		0
#define INT_1		1
#define INT_2		2

#define I_BIT		7



/*********************************************/
/* select mode
 * 1- INT_LOW_LEVEL
 * 2- INT_LOGICAL_CHANGE
 * 3- INT_FALLING_EDGE
 * 4- INT_RISING_EDGE
 */
/*********************************************/
#define INT_MODE 		INT_RISING_EDGE
/*********************************************/
/* general interrupt
 *  1- ENABLE
 *  2- DISABLE
 */
/*********************************************/
#define INT_GIE			ENABLE
/*********************************************/
/*  interrupt peripheral
 *  1- INT_0
 *  2- INT_1
 *  3- INT_2
 *  4- INT_4
 */
/*********************************************/
#define INT 	INT_0


void INT_Vid_init(void);
void GIE_VidInit(void);

void EXTI_VidSetCallBack(u8 Copy_index ,void (*copy_ptr)(void));


#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_ */
