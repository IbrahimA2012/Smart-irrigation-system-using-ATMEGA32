/*
 * servo.c
 *
 *  Created on: Aug 21, 2023
 *      Author: hamada
 */
#include "servo.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void Timer1_VidTimer1FPWM(void)
{
	/* Fast PWM */
	CLEAR_BIT(TCCR1A,WGM01);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	/**/
	CLEAR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);

	/*Time OVF*/
	ICR1=19999;

	/*CLK / 8 */
	CLEAR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);


}


void Servo_VidServoAngle(u8 Copy_u8Angle)
{
	/*
	if(Copy_u8Angle ==0)
	{
		OCR1A =1000;
	}
	else if(Copy_u8Angle ==90)
	{
		OCR1A =1500;
	}
	else if(Copy_u8Angle ==180)
	{
		OCR1A =2000;
	}
	*/
	OCR1A = ((50*Copy_u8Angle)+8991)/9;
}



