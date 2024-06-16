/*
 * LM35.c
 *
 *  Created on: Sep 2, 2023
 *      Author: hamada
 */


#include "LM35.h"
#include "../../MCAL/ADC/adc.h"



uint16 LM35_Read_Temp(u8 Copy_Channel)
{
	uint16 adc_value;

	ADC_VidInit();

	adc_value = ADC_u16GetDigitalValue(Copy_Channel);

	uint16 analog_voltage = adc_value *4.88f; /*(Vref)5000mV / (2^n n:resolution) 1024(10bit) = 4.88*/

	float temperature_celsius = analog_voltage / 10.0; /*the output of lm35 in mV -> 10mV/degree*/

	return (uint16)temperature_celsius;
}
