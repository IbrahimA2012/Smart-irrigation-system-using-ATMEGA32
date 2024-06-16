/*
 * adc.c
 *
 *  Created on: Aug 17, 2023
 *      Author: hamada
 */

/**
 * 1- select 2.56v
 * 2- Right
 * 3- Auto
 * 4- Division factor
 * 5- ADC
 */

#include "adc.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include <avr/io.h>

void ADC_VidInit(void)
{
	/*select voltage reference 2.56v*/
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
	/*Right*/
	CLEAR_BIT(ADMUX,ADLAR);
	/*Disable auto trigger*/
	CLEAR_BIT(ADCSRA,ADATE);
	/*Division factor*/
	CLEAR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	/*ADC Enable*/
	SET_BIT(ADCSRA,ADEN);
}

uint16 ADC_u16GetDigitalValue(u8 Copy_CannleNum)
{
	uint16 l_adc_value;
	ADMUX &=0xE0;
	/*select channel num*/
	ADMUX|=Copy_CannleNum;
	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);

	while(!READ_BIT(ADCSRA,ADIF));

	/*flag = 0*/
	SET_BIT(ADCSRA,ADIF);

	l_adc_value = ADC_REG;

return l_adc_value;
}



