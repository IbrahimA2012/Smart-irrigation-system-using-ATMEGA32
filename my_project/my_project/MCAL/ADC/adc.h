/*
 * adc.h
 *
 *  Created on: Aug 17, 2023
 *      Author: hamada
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "../../LIB/STD_TYPES.h"


#define CHANNEL_0 	0
#define CHANNEL_1	1
#define CHANNEL_2	2
#define CHANNEL_3	3
#define CHANNEL_4	4
#define CHANNEL_5	5
#define CHANNEL_6	6
#define CHANNEL_7	7


#define ADC_REG 	*((volatile uint16*)0x24)







void ADC_VidInit(void);
uint16 ADC_u16GetDigitalValue(u8 Copy_CannleNum);





#endif /* MCAL_ADC_ADC_H_ */
