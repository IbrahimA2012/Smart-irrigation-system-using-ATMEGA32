/*
 * lcd.c
 *
 *  Created on: Aug 13, 2023
 *      Author: hamada
 */

#include "lcd.h"
#include <avr/delay.h>
#include <avr/io.h>
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"


void LCD_VidSendCMD(u8 Copy_u8CMD)
{
	DIO_VidSetPinValue(LCD_CMD_PORT , RS ,DIO_LOW);

	DIO_VidSetPinValue(LCD_CMD_PORT , RW ,DIO_LOW);

	DIO_VidSetPortValue(LCD_DATA_PORT,Copy_u8CMD);

	DIO_VidSetPinValue(LCD_CMD_PORT ,EN ,DIO_HIGH);
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_CMD_PORT ,EN ,DIO_LOW);
}

void LCD_VidSendChar(u8 Copy_u8Char)
{
	DIO_VidSetPinValue(LCD_CMD_PORT , RS ,DIO_HIGH);

	DIO_VidSetPinValue(LCD_CMD_PORT , RW ,DIO_LOW);

	DIO_VidSetPortValue(LCD_DATA_PORT,Copy_u8Char);

	DIO_VidSetPinValue(LCD_CMD_PORT ,EN ,DIO_HIGH);
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_CMD_PORT ,EN ,DIO_LOW);
}

void LCD_VidInitialize(void)
{
	DIO_VidSetPortDirection(LCD_DATA_PORT,0xff);
	DIO_VidSetPinDirection(LCD_CMD_PORT,RS,DIO_OUT);
	DIO_VidSetPinDirection(LCD_CMD_PORT,RW,DIO_OUT);
	DIO_VidSetPinDirection(LCD_CMD_PORT,EN,DIO_OUT);
	_delay_ms(35);

	LCD_VidSendCMD(FUN_SET);
	_delay_ms(1);

	LCD_VidSendCMD(LCD_ON_OFF);
	_delay_ms(1);

	LCD_VidSendCMD(LCD_CLEAER);
	_delay_ms(2);

}

void LCD_VidSendString(u8 *Copy_u8String)
{
	while(*Copy_u8String)
	{
		LCD_VidSendChar(*Copy_u8String++);
	}
}

void LCD_VidSendLocation(u8 Copy_u8LineNumber ,u8 Copy_u8CharNumber )
{
	switch(Copy_u8LineNumber)
	{
		case LINE_1 :
			LCD_VidSendCMD(0x80+Copy_u8CharNumber);
		break ;
		case LINE_2 :
			LCD_VidSendCMD(0xC0+Copy_u8CharNumber);
		break ;
	}
}


void LCD_VidSendCustomChar(u8 *Copy_u8Char ,u8 Copy_u8CharNumber , u8 Copy_u8LineNumber)
{
	u8 L_counter =0;
	LCD_VidSendCMD(0x40+(Copy_u8CharNumber*8));
	for(L_counter = 0 ; L_counter < 8 ; L_counter++)
	{
		LCD_VidSendChar(Copy_u8Char[L_counter]);
	}

	LCD_VidSendLocation(Copy_u8LineNumber,Copy_u8CharNumber);
	LCD_VidSendChar(Copy_u8CharNumber);
}

void LCD_VidSendNumber(u8 Copy_u8Num)
{
	u8 L_string[3];
	sprintf(&L_string,"%d",Copy_u8Num);
	LCD_VidSendString(L_string);
}

void LCD_VidSendNumberU16(uint16 Copy_u16Num)
{
	u8 L_string[5];
	sprintf(&L_string,"%d",Copy_u16Num);
	LCD_VidSendString(L_string);
}



void LCD_CLEAR(void)
{
	LCD_VidSendCMD(LCD_CLEAER);
	_delay_ms(1);
}


