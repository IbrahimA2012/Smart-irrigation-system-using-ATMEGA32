/*
 * LDR.c
 *
 *  Created on: Sep 2, 2023
 *      Author: hamada
 */

#include "../../MCAL/ADC/adc.h"



uint16 LDR_ReadValue(u8 Copy_Channel)
{
	uint16 adc_value ;

	ADC_VidInit();
	adc_value = ADC_u16GetDigitalValue(Copy_Channel);

	return adc_value;
}
