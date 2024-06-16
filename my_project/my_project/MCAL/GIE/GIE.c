/*
 * GIE.c
 *
 *  Created on: Aug 20, 2023
 *      Author: hamada
 */

#include "GIE.h"

#include "../../LIB/BIT_MATH.h"
#include "avr/io.h"

void GIE_VidEnable(void)
{
	SET_BIT(SREG,7);
}
void GIE_VidDisable(void)
{
	CLEAR_BIT(SREG,7);
}


