/*
 * keypad.c
 *
 *  Created on: Aug 14, 2023
 *      Author: hamada
 */

#include "keypad.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/BIT_MATH.h"
#include "avr/io.h"
#include "avr/delay.h"




u8 KPD_U8KEYS[4][4] = KPD_KEYS;

u8 KPD_U8ROW_PINS [4] ={KPD_R1_PIN,KPD_R2_PIN,KPD_R3_PIN,KPD_R4_PIN};
u8 KPD_U8COL_PINS [4] ={KPD_C1_PIN,KPD_C2_PIN,KPD_C3_PIN,KPD_C4_PIN};

void KPD_VidInit(void)
{
	DIO_VidSetPortDirection(KPD_PORT,0x0f);
	DIO_VidSetPortValue(KPD_PORT , 0xff);
}

u8 KPD_U8PressedKey(void)
{
	u8 Local_u8CtrR = 0;
	u8 Local_u8CtrC = 0;
	u8 Local_u8Pressed = 0;
	u8 Local_u8_retVal = KPD_CHECK;
	u8 Local_u8Flag = 0;

	for(Local_u8CtrR = 0; Local_u8CtrR < 4; Local_u8CtrR++)
	{
		DIO_VidSetPinValue(KPD_PORT, Local_u8CtrR, DIO_LOW);
		for(Local_u8CtrC = 0;Local_u8CtrC < 4; Local_u8CtrC++)
		{
			Local_u8Pressed = DIO_8uGetPinValue(KPD_PORT, KPD_U8COL_PINS[Local_u8CtrC]);
			if(Local_u8Pressed == DIO_LOW)
			{
				_delay_ms(20);
				while(Local_u8Pressed == DIO_LOW)
				{
					Local_u8Pressed = DIO_8uGetPinValue(KPD_PORT, KPD_U8COL_PINS[Local_u8CtrC]);
				}
				Local_u8_retVal = KPD_U8KEYS[Local_u8CtrR][Local_u8CtrC];
				Local_u8Flag = 1;
				break;
			}
		}
		DIO_VidSetPinValue(KPD_PORT,KPD_U8ROW_PINS[Local_u8CtrR],DIO_HIGH);
		if(Local_u8Flag == 1)
		{
			break;
		}
	}
	return (Local_u8_retVal);
}







