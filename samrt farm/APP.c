#include "APP.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/lcd.h"
#include "../HAL/Soil_Moisture_Sensor/Soil_Moisture_Sensor.h"
#include "../HAL/LDR/LDR.h"
#include "../HAL/LM35/LM35.h"
#include "../MCAL/UART/UART.h"
#include <avr/io.h>
#include <avr/delay.h>


uint16 soil_1_value = 0 , soil_2_value = 0;
uint16 temp_value = 0 ;
uint16 ldr_value = 0 ;
u8 leds_state =0 ,pump1_state =0 ,pump2_state =0 , fan_state =0;
u8 sw_pump1_state =0 ,sw_pump2_state =0 , sw_fan_state =0;
int main(void)
{

	UART_VidInit();
   	LCD_VidInitialize();
   	LCD_VidSendLocation(LINE_1,0);
   	LCD_VidSendString("Temp|soil1|soil2"); 		// Temp|soil1|soil2
   												// 45 C|45%  |87%
	DIO_VidSetPinDirection(PORT_B,PIN_0,DIO_OUT);
	DIO_VidSetPinDirection(PORT_B,PIN_1,DIO_OUT);
	DIO_VidSetPinDirection(PORT_B,PIN_2,DIO_OUT); //fan
	DIO_VidSetPinDirection(PORT_B,PIN_3,DIO_OUT);
	DIO_VidSetPinDirection(PORT_B,PIN_4,DIO_OUT);

	DIO_VidSetPinDirection(PORT_D,PIN_3,DIO_IN);
	DIO_VidSetPinDirection(PORT_D,PIN_4,DIO_IN);
	DIO_VidSetPinDirection(PORT_D,PIN_5,DIO_IN);
	DIO_VidSetPinDirection(PORT_D,PIN_6,DIO_IN);
	DIO_VidSetPinDirection(PORT_D,PIN_7,DIO_IN);

	DIO_VidSetPinValue(PORT_D,PIN_3,DIO_HIGH);
	DIO_VidSetPinValue(PORT_D,PIN_4,DIO_HIGH);
	DIO_VidSetPinValue(PORT_D,PIN_5,DIO_HIGH);
	DIO_VidSetPinValue(PORT_D,PIN_6,DIO_HIGH);
	DIO_VidSetPinValue(PORT_D,PIN_7,DIO_HIGH);

	DIO_VidSetPinValue(PORT_B,PIN_0,DIO_LOW);
	DIO_VidSetPinValue(PORT_B,PIN_1,DIO_LOW);
	_delay_ms(100);

    while (1)
    {
    	soil_1_value = Siol_Moisture_value(CHANNEL_0);
    	soil_2_value = Siol_Moisture_value(CHANNEL_1);
    	temp_value = LM35_Read_Temp(CHANNEL_2);
    	ldr_value = LDR_ReadValue(CHANNEL_3);
    	LCD_VidSendLocation(LINE_2,0);
    	LCD_VidSendNumber(temp_value);
    	LCD_VidSendString(" C|");
    	LCD_VidSendLocation(LINE_2,5);
		LCD_VidSendNumber(soil_1_value);
		LCD_VidSendString("%  |");
		LCD_VidSendLocation(LINE_2,11);
		LCD_VidSendNumber(soil_2_value);
		LCD_VidSendChar('%');
		/*LEDs Control*/
		leds_control();
		/*Pump 1 Control*/
		pump1_control();
		/*Pump 2 Control*/
		pump2_control();
		/*Fan Control*/
		fan_control();

    }



    return 0;
}


void pump1_control(void)
{
	if((soil_1_value < 20) && (pump1_state==0))
	{
		DIO_VidSetPinValue(PORT_B,PIN_3,DIO_HIGH);
		pump1_state =1;
		UART_VidSendString("Pump 1 ON\r");
	}
	if((soil_1_value > 20 )&&( pump1_state==1))
	{
		DIO_VidSetPinValue(PORT_B,PIN_3,DIO_LOW);
		UART_VidSendString("Pump 1 OFF\r");
		pump1_state =0;
	}
	if(DIO_8uGetPinValue(PORT_D,PIN_6) == 0 && sw_pump1_state ==0)
	{
		 DIO_VidSetPinValue(PORT_B,PIN_3,DIO_HIGH);
		 sw_pump1_state =1;
		 UART_VidSendString("Pump 1 ON\r");
	}
	if(DIO_8uGetPinValue(PORT_D,PIN_6) == 1 && sw_pump1_state==1 && soil_1_value > 20)
	{
		DIO_VidSetPinValue(PORT_B,PIN_3,DIO_LOW);
		sw_pump1_state =0;
		UART_VidSendString("Pump 1 OFF\r");
	}

}
void pump2_control(void)
{
	if((soil_2_value < 20) &&(pump2_state==0))
		{
			DIO_VidSetPinValue(PORT_B,PIN_4,DIO_HIGH);
			pump2_state =1;
			UART_VidSendString("Pump 2 ON\r");
		}
		if((soil_2_value > 20) &&(pump2_state==1))
		{
			DIO_VidSetPinValue(PORT_B,PIN_4,DIO_LOW);
			pump2_state =0;
			UART_VidSendString("Pump 2 OFF\r");
		}

		if(DIO_8uGetPinValue(PORT_D,PIN_7) == 0 && sw_pump2_state ==0)
		{
			DIO_VidSetPinValue(PORT_B,PIN_4,DIO_HIGH);
			 sw_pump2_state =1;
			 UART_VidSendString("Pump 2 ON\r");
		}
		if(DIO_8uGetPinValue(PORT_D,PIN_7) == 1 && sw_pump2_state==1 && soil_2_value > 20)
		{
			DIO_VidSetPinValue(PORT_B,PIN_4,DIO_LOW);
			sw_pump2_state =0;
			UART_VidSendString("Pump 2 OFF\r");
		}
}
void fan_control(void)
{
	if(temp_value > 27 && fan_state==0)
	{
		DIO_VidSetPinValue(PORT_B,PIN_2,DIO_HIGH);
		fan_state =1;
		UART_VidSendString("Fan ON\r");
	}
	if(temp_value < 27&& fan_state==1)
	{
		DIO_VidSetPinValue(PORT_B,PIN_2,DIO_LOW);
		fan_state =0;
		UART_VidSendString("Fan OFF\r");
	}

	if(DIO_8uGetPinValue(PORT_D,PIN_5) == 0 && sw_fan_state ==0)
	{
		DIO_VidSetPinValue(PORT_B,PIN_2,DIO_HIGH);
		sw_fan_state =1;
		UART_VidSendString("Fan ON\r");
	}
	if(DIO_8uGetPinValue(PORT_D,PIN_5) == 1 && sw_fan_state==1 && temp_value<27)
	{
		DIO_VidSetPinValue(PORT_B,PIN_2,DIO_LOW);
		sw_fan_state =0;
		UART_VidSendString("Fan OFF\r");
	}
}
void leds_control(void)
{
	if(ldr_value < 600 && leds_state==0)
	{
		DIO_VidSetPinValue(PORT_B,PIN_0,DIO_HIGH);
		DIO_VidSetPinValue(PORT_B,PIN_1,DIO_HIGH);
		leds_state =1;
		UART_VidSendString("LEDs ON\r");
	}
	if(ldr_value > 600 && leds_state==1)
	{
		DIO_VidSetPinValue(PORT_B,PIN_0,DIO_LOW);
		DIO_VidSetPinValue(PORT_B,PIN_1,DIO_LOW);
		UART_VidSendString("LEDs OFF\r");
		leds_state =0;
	}
}

