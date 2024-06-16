/*
 * stepper.c
 *
 *  Created on: Aug 15, 2023
 *      Author: hamada
 */

#include "stepper.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "avr/delay.h"
#include "avr/io.h"



void STEP_Init_Vid(void)
{
	DIO_VidSetPinDirection(STEP_PORT,STEP_COIL_BLUE, DIO_OUT);
	DIO_VidSetPinDirection(STEP_PORT,STEP_COIL_ORANGE, DIO_OUT);
	DIO_VidSetPinDirection(STEP_PORT,STEP_COIL_PINK, DIO_OUT);
	DIO_VidSetPinDirection(STEP_PORT,STEP_COIL_YELLOW, DIO_OUT);
	DIO_VidSetPinValue(STEP_PORT,STEP_COIL_BLUE,DIO_OUT);
	DIO_VidSetPinValue(STEP_PORT,STEP_COIL_ORANGE, DIO_LOW);
	DIO_VidSetPinValue(STEP_PORT,STEP_COIL_PINK, DIO_LOW);
	DIO_VidSetPinValue(STEP_PORT,STEP_COIL_YELLOW, DIO_LOW);

}

void STEP_HCW_Vid(void)
{
	DIO_VidSetPinValue(STEP_PORT, STEP_COIL_BLUE, DIO_HIGH);
	DIO_VidSetPinValue(STEP_PORT, STEP_COIL_ORANGE, DIO_HIGH);
	_delay_ms(STEP_DELAY);
	DIO_VidSetPinValue(STEP_PORT, STEP_COIL_ORANGE, DIO_LOW);
	_delay_ms(STEP_DELAY);
	DIO_VidSetPinValue(STEP_PORT, STEP_COIL_PINK, DIO_HIGH);
	_delay_ms(STEP_DELAY);
	DIO_VidSetPinValue(STEP_PORT, STEP_COIL_BLUE, DIO_LOW);
	_delay_ms(STEP_DELAY);
	DIO_VidSetPinValue(STEP_PORT, STEP_COIL_YELLOW, DIO_HIGH);
	_delay_ms(STEP_DELAY);
	DIO_VidSetPinValue(STEP_PORT, STEP_COIL_PINK, DIO_LOW);
	_delay_ms(STEP_DELAY);
	DIO_VidSetPinValue(STEP_PORT, STEP_COIL_ORANGE, DIO_HIGH);
	_delay_ms(STEP_DELAY);
	DIO_VidSetPinValue(STEP_PORT, STEP_COIL_YELLOW, DIO_LOW);
	_delay_ms(STEP_DELAY);
}
