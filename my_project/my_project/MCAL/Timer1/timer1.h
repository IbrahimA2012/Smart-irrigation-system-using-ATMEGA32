/*
 * timer1.h
 *
 *  Created on: Aug 22, 2023
 *      Author: hamada
 */

#ifndef MCAL_TIMER1_TIMER1_H_
#define MCAL_TIMER1_TIMER1_H_

#include "../../LIB/STD_TYPES.h"

void TMR1_Timer1Normal_Vid(void);
void TMR1_Timer1FPWM_Vid(void);
void TMR1_ICUInit_Vid(void);
void ICU_VidEdgeSelect(u8 Copy_u8EdgeSelect);
uint16 ICU_u16ReadICR(void);
void ICU_VidINT_Disable(void);


#endif /* MCAL_TIMER1_TIMER1_H_ */
