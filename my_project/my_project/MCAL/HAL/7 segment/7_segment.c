/*
 * 7_segment.c
 *
 *  Created on: Aug 11, 2023
 *      Author: hamada
 */

#include "7_segment.h"

 u8 arr_number[] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};


void Segment_VidWriteNumber(u8 Copy_u8Port , u8 Copy_u8Number)
{
	DIO_VidSetPortDirection(Copy_u8Port , 0xff);
	DIO_VidSetPortValue(Copy_u8Port , arr_number[Copy_u8Number]);
}



