/*
 * LM35.h
 *
 *  Created on: Sep 2, 2023
 *      Author: hamada
 */

#ifndef HAL_LM35_LM35_H_
#define HAL_LM35_LM35_H_

#include "../../LIB/STD_TYPES.h"

#define CHANNEL_0 	0
#define CHANNEL_1	1
#define CHANNEL_2	2
#define CHANNEL_3	3
#define CHANNEL_4	4
#define CHANNEL_5	5
#define CHANNEL_6	6
#define CHANNEL_7	7

uint16 LM35_Read_Temp(u8 Copy_Channel);


#endif /* HAL_LM35_LM35_H_ */
