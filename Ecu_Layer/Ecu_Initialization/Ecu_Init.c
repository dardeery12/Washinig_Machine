/********************************************************************************
 * @file    Ecu_Init.c
 * @author  Drd
 * @date    Sep 2, 2023
 * @brief   
 ********************************************************************************/
/*****************  INCLUDES   *******************************/

#include "Ecu_Init.h"
led_t Led1 = {.port = PORTB,
		.pin = GPIO_PIN0,
		.status = LED_OFF
};

/*****************  GLOBAL FUNCTIONS   *************************/
chr_lcd_4bit_t lcd1 ={
		.lcd_rs.port = PORTA, .lcd_rs.pin = 0,
		.lcd_en.port = PORTA, .lcd_en.pin = 2,
		.lcd_data[0].port = PORTA,
		.lcd_data[1].port = PORTA,
		.lcd_data[2].port = PORTA,
		.lcd_data[3].port = PORTA,
		.lcd_data[0].pin = 3,
		.lcd_data[1].pin = 4,
		.lcd_data[2].pin = 5,
		.lcd_data[3].pin = 6, };

Std_ReturnType Ecu_Init()
{
	Std_ReturnType Ret =E_NOK;
	lcd_4bit_intialize(&lcd1);
	Timer0_Init();

	return Ret;
}
void Print_time_Lcd(void)
{
	static uint8 sec = 0x00;
	static uint8 minuts = 0x00;
	/*
	lcd_4bit_send_string_pos(&lcd1, 1,1,"00");
	lcd_4bit_send_char_data_pos(&lcd1, 1, 3, ':');
	lcd_4bit_send_string_pos(&lcd1, 1,4,"00");
*/
	Timer0_Calculate_Min_And_Sec(&sec, &minuts);
	lcd_4bit_send_char_data_pos(&lcd1, 1, 3, ':');
	lcd_4bit_send_num_pos(&lcd1, 1,4,sec);
	lcd_4bit_send_num_pos(&lcd1, 1,1,minuts);
}

