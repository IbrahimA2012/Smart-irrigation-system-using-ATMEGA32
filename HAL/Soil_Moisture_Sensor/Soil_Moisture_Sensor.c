/*
 * Soil_Moisture_Sensor.c
 *
 *  Created on: Sep 1, 2023
 *      Author: hamada
 */

#include "Soil_Moisture_Sensor.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/ADC/adc.h"

uint16 adc_value =0;
uint16 moisture_value =0;

uint16 Siol_Moisture_value(u8 CHANNEL)
{
	ADC_VidInit();
	adc_value = ADC_u16GetDigitalValue(CHANNEL);
	moisture_value = ((adc_value*5/1023.00)/5)*100; //moisture_value = 100-(adc_value*100/1023);
	return moisture_value;
}
