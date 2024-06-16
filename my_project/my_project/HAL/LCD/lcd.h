/*
 * lcd.h
 *
 *  Created on: Aug 13, 2023
 *      Author: hamada
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "../../LIB/STD_TYPES.h"

#define LCD_DATA_PORT 		PORT_A
#define LCD_CMD_PORT 		PORT_B

#define RS 	PIN_5
#define RW 	PIN_6
#define EN 	PIN_7

#define FUN_SET 	0b00111000
#define LCD_ON_OFF 	0b00001111
#define LCD_CLEAER  0b00000001

#define LINE_1 	0
#define LINE_2 	1




void LCD_VidSendCMD(u8 Copy_u8CMD);
void LCD_VidSendChar(u8 Copy_u8Char);

void LCD_VidSendNumber(u8 Copy_u8Num);

void LCD_VidInitialize(void);

void LCD_VidSendString(u8 *Copy_u8String);

void LCD_VidSendLocation(u8 Copy_u8LineNumber ,u8 Copy_u8CharNumber );

void LCD_VidSendCustomChar(u8 *Copy_u8Char ,u8 Copy_u8CharNumber , u8 Copy_u8LineNumber);
void LCD_CLEAR(void);

void LCD_VidSendNumberU16(uint16 Copy_u16Num);

#endif /* HAL_LCD_LCD_H_ */
