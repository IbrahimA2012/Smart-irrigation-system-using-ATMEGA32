/*
 * UART.h
 *
 *  Created on: Aug 23, 2023
 *      Author: hamada
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "../../LIB/STD_TYPES.h"




void UART_VidInit(void);
void UART_VidSendChar(u8 Copy_u8Data);
u8 UART_VidReceiveChar(void);
void UART_VidSendString(u8 *Copy_u8Data);

#endif /* MCAL_UART_UART_H_ */
