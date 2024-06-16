/*
 * DIO.h
 *
 *  Created on: Aug 10, 2023
 *      Author: hamad
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>


#define PORT_A 	0
#define PORT_B	1
#define PORT_C 	2
#define PORT_D 	3


#define PIN_0	0
#define PIN_1	1
#define PIN_2	2
#define PIN_3	3
#define PIN_4	4
#define PIN_5	5
#define PIN_6	6
#define PIN_7	7


#define DIO_OUT		1
#define DIO_IN		0

#define DIO_HIGH	1
#define DIO_LOW		0





void DIO_VidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction);
void DIO_VidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin , u8 Copy_u8Value);

void DIO_VidSetPortDirection(u8 Copy_u8Port, u8 copy_u8Direction);
void DIO_VidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

u8 	 DIO_8uGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);
void DIO_VidTogglePin(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif /* MCAL_DIO_DIO_H_ */
