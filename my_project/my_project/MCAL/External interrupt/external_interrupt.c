/*
 * external_interrupt.c
 *
 *  Created on: Aug 16, 2023
 *      Author: hamada
 */


#include "external_interrupt.h"
#include "../../LIB/BIT_MATH.h"
#include "avr/interrupt.h"
#include "avr/io.h"
#include "stdio.h"



void (*EXTI_PVidTemp[3])(void) = {NULL , NULL ,NULL};


void INT_Vid_init(void)
{
#if INT==INT_0

#if INT_MODE==INT_LOW_LEVEL
	CLEAR_BIT(MCUCR,ISC00);
	CLEAR_BIT(MCUCR,ISC01);
#elif INT_MODE==INT_LOGICAL_CHANGE
	SET_BIT(MCUCR,ISC00);
	CLEAR_BIT(MCUCR,ISC01);
#elif INT_MODE==INT_FALLING_EDGE
	CLEAR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#elif INT_MODE==INT_RISING_EDGE
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#endif
	SET_BIT(GICR,INT0);

#elif INT==INT_1

#if INT_MODE==INT_LOW_LEVEL
	CLEAR_BIT(MCUCR,ISC10);
	CLEAR_BIT(MCUCR,ISC11);
#elif INT_MODE==INT_LOGICAL_CHANGE
	SET_BIT(MCUCR,ISC10);
	CLEAR_BIT(MCUCR,ISC11);
#elif INT_MODE==INT_FALLING_EDGE
	CLEAR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#elif INT_MODE==INT_RISING_EDGE
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#endif
	SET_BIT(GICR,INT1);

#elif INT==INT_2

#if INT_MODE==INT_FALLING_EDGE
	CLEAR_BIT(MCUCR,ISC2);
#elif INT_MODE==INT_RISING_EDGE
	SET_BIT(MCUCR,ISC2);
#endif
	SET_BIT(GICR,INT2);
#endif
}

void GIE_VidInit(void)
{
#if INT_GIE==ENABLE
	SET_BIT(SREG,I_BIT);
#elif INT_GIE==DISABLE
	CLEAR_BIT(SREG,I_BIT);
#endif
}

void EXTI_VidSetCallBack(u8 Copy_index , void (*copy_ptr)(void))
{
	EXTI_PVidTemp[Copy_index] = copy_ptr;
}

ISR(INT0_vect)
{
	if(EXTI_PVidTemp[0] != NULL)
	{
		EXTI_PVidTemp[0]();
	}
}

ISR(INT1_vect)
{
	if(EXTI_PVidTemp[1] != NULL)
	{
		EXTI_PVidTemp[1]();
	}
}

ISR(INT2_vect)
{
	if(EXTI_PVidTemp[2] != NULL)
	{
		EXTI_PVidTemp[2]();
	}
}



