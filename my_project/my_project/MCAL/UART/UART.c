/*
 * UART.c
 *
 *  Created on: Aug 23, 2023
 *      Author: hamada
 */

#include <avr/io.h>
#include "UART.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void UART_VidInit(void)
{
	uint16 Local_u16Bud_Rate = 51;
	u8 Local_u8UCSRC = 0b10000000;

	UBRRL =(u8)Local_u16Bud_Rate;
	UBRRH =(u8)(Local_u16Bud_Rate>>8);
	/*Normal speed*/
	CLEAR_BIT(UCSRA,U2X);
	/*Disable multi-processor*/
	CLEAR_BIT(UCSRA,MPCM);
	/*Enable Tx , Rx*/
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	/*8 Bits Data*/
	SET_BIT(Local_u8UCSRC,UCSZ1);
	SET_BIT(Local_u8UCSRC,UCSZ0);
	CLEAR_BIT(UCSRB,UCSZ2);

	/*Asynchronous mode*/
	CLEAR_BIT(Local_u8UCSRC,UMSEL);
	/*Disable parity*/
	CLEAR_BIT(Local_u8UCSRC,UPM0);
	CLEAR_BIT(Local_u8UCSRC,UPM1);
	/*2 stop bits*/
	SET_BIT(Local_u8UCSRC,USBS);

	UCSRC =Local_u8UCSRC;
}

void UART_VidSendChar(u8 Copy_u8Data)
{
	while(READ_BIT(UCSRA,UDRE)==0);
	UDR = Copy_u8Data;
}

u8 UART_VidReceiveChar(void)
{
	while(READ_BIT(UCSRA,RXC)==0);
	return UDR;
}

void UART_VidSendString(u8 *Copy_u8Data)
{
	while(READ_BIT(UCSRA,UDRE)==0);
	while(*Copy_u8Data !='\0')
	{
		UART_VidSendChar(*Copy_u8Data++);
	}
}
