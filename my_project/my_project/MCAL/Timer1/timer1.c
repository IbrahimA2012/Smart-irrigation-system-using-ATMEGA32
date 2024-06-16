/*
 * timer1.c
 *
 *  Created on: Aug 22, 2023
 *      Author: hamada
 */


#include <avr/interrupt.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "timer1.h"
#include "stdio.h"


static void(*TIMER1_PFICU)(void);


void TMR1_Timer1Normal_Vid(void)//timer1 input capture unit
{
	/* fast PWM */
	CLEAR_BIT(TCCR1A, WGM10);
	CLEAR_BIT(TCCR1A, WGM11);
	CLEAR_BIT(TCCR1B, WGM12);
	CLEAR_BIT(TCCR1B, WGM13);

	/* CLK/8 */
	CLEAR_BIT(TCCR1B, CS10);//preScalar = 8
	SET_BIT(TCCR1B, CS11);
	CLEAR_BIT(TCCR1B, CS12);
}
void TMR1_Timer1FPWM_Vid(void)//timer1 fast PWM
{
	/* fast PWM */
	CLEAR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);

	/* clear OCR1A */
	CLEAR_BIT(TCCR1A, COM1A0);
	SET_BIT(TCCR1A, COM1A1);

	/*Time OVF*/
	ICR1 = 19999;//time overflow = 20ms --> 20000us

	/* CLK/8 */
	CLEAR_BIT(TCCR1B, CS10);//preScalar = 8
	SET_BIT(TCCR1B, CS11);
	CLEAR_BIT(TCCR1B, CS12);

}

void TMR1_ICUInit_Vid(void)
{
	SET_BIT(TCCR1B, ICES1);//rising edge
	SET_BIT(TIMSK, TICIE1);//ICU_INT Enable
}

void ICU_VidEdgeSelect(u8 Copy_u8EdgeSelect)
{
	switch(Copy_u8EdgeSelect)
	{
		case 0 : CLEAR_BIT(TCCR1B, ICES1);break;
		case 1 : SET_BIT(TCCR1B, ICES1);break;
	}
}

uint16 ICU_u16ReadICR(void)
{
	return ICR1;
}

void ICU_VidINT_Disable(void)
{
	CLEAR_BIT(TIMSK, TICIE1);
}

void ICU_VID_SetCallBack(void(*Copy_PFCallBack)(void))
{
	TIMER1_PFICU = Copy_PFCallBack;
}

ISR(TIMER1_CAPT_vect)
{
	if(TIMER1_PFICU != NULL)
	{
		TIMER1_PFICU();
	}
}
