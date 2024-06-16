/*
 * APP.c
 *
 *  Created on: Aug 10, 2023
 *      Author: hamada
 */


#include "APP.h"
#include "avr/io.h"
#include "avr/delay.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/GIE/GIE.h"
#include "../MCAL/Timer0/timer0.h"
#include "../MCAL/DIO/DIO.h"
#include "../FreeRTOSFiles/FreeRTOS.h"
#include "../FreeRTOSFiles/FreeRTOSConfig.h"
#include "../FreeRTOSFiles/task.h"


void task1(void *pvparameters);
void task2(void *pvparameters);
void task3(void *pvparameters);
void task4(void *pvparameters);

int main(void)
{
		DIO_VidSetPinDirection(PORT_A,PIN_0,DIO_OUT);
		DIO_VidSetPinDirection(PORT_A,PIN_1,DIO_OUT);
		DIO_VidSetPinDirection(PORT_A,PIN_2,DIO_OUT);
		DIO_VidSetPinDirection(PORT_A,PIN_3,DIO_OUT);

		xTaskCreate(task1,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL);
		xTaskCreate(task2,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL);
		xTaskCreate(task3,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL);
		xTaskCreate(task4,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL);
		vTaskStartScheduler();



return 0;
}

void task1(void *pvparameters)
{
	while(1)
	{
		DIO_VidTogglePin(PORT_A,PIN_0);
		vTaskDelay(150);
	}
}
void task2(void *pvparameters)
{
	while(1)
	{
		DIO_VidTogglePin(PORT_A,PIN_1);
		vTaskDelay(300);
	}
}
void task3(void *pvparameters)
{
	while(1)
	{
		DIO_VidTogglePin(PORT_A,PIN_2);
		vTaskDelay(500);
	}
}
void task4(void *pvparameters)
{
	while(1)
	{
		DIO_VidTogglePin(PORT_A,PIN_3);
		vTaskDelay(1000);
	}
}
