/*
 * timer0.h
 *
 *  Created on: Aug 20, 2023
 *      Author: hamada
 */

#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_


#define TMR0_MODE_OVF	0
#define TMR0_MODE_CTC	1



void TMR0_Timer0InitOVF_Vid(void);
void TMR0_Timer0SetCallBackOVF(void (*Copy_u8TimerOVF) (void));
void TMR0_Timer0InitCTC_Vid(uint16 Copy_u8Time_ms);
void TMR0_Timer0SetCallBackCTC(void (*Copy_u8TimerCTC) (void));

void TIMER0_VidTimer0FPWMInit(void);

#endif /* MCAL_TIMER0_TIMER0_H_ */
