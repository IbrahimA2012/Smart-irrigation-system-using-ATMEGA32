/*
 * LDR.h
 *
 *  Created on: Sep 2, 2023
 *      Author: hamad
 */

#ifndef HAL_LDR_LDR_H_
#define HAL_LDR_LDR_H_

#include "../../LIB/STD_TYPES.h"

#define CHANNEL_0 	0
#define CHANNEL_1	1
#define CHANNEL_2	2
#define CHANNEL_3	3
#define CHANNEL_4	4
#define CHANNEL_5	5
#define CHANNEL_6	6
#define CHANNEL_7	7

uint16 LDR_ReadValue(u8 Copy_Channel);


#endif /* HAL_LDR_LDR_H_ */
