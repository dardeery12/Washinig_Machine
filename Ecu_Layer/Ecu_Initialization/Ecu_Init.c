/********************************************************************************
 * @file    Ecu_Init.c
 * @author  Drd
 * @date    Sep 2, 2023
 * @brief   
 ********************************************************************************/
/*****************  INCLUDES   *******************************/

#include "Ecu_Init.h"
/***************** pin configuration  ****************/
/*******************************************************************************/
/* Manual_Mode_Pin  To Read Manual Mode BTN   */
button_t  Mode_Manual_Btn ={.button_pin.port = PORTC,.button_pin.pin = GPIO_PIN1,
		.button_state = BUTTON_RELEASED,.button_connection = BUTTON_ACTIVE_LOW};

/*******************************************************************************/
/* Man_Water_Btn  To Read Auto Mode BTN   */
button_t  Man_Water_Btn ={.button_pin.port = PORTC,.button_pin.pin = GPIO_PIN3,
		.button_state = BUTTON_RELEASED,.button_connection = BUTTON_ACTIVE_LOW};
/*******************************************************************************/
/* Man_Heater_Btn  To Read Auto Mode BTN   */
button_t  Man_Heater_Btn ={.button_pin.port = PORTC,.button_pin.pin = GPIO_PIN4,
		.button_state = BUTTON_RELEASED,.button_connection = BUTTON_ACTIVE_LOW};
/*******************************************************************************/
/* Manual_Mode_Pin  To Read Auto Mode BTN   */
button_t  Man_RotatRight_Btn ={.button_pin.port = PORTC,.button_pin.pin = GPIO_PIN5,
		.button_state = BUTTON_RELEASED,.button_connection = BUTTON_ACTIVE_LOW};
/*******************************************************************************/
/* Man_RotateLeft_Btn  To Read Auto Mode BTN   */
button_t  Man_RotateLeft_Btn ={.button_pin.port = PORTC,.button_pin.pin = GPIO_PIN6,
		.button_state = BUTTON_RELEASED,.button_connection = BUTTON_ACTIVE_LOW};
/*******************************************************************************/
/* Man_Drain_Btn  To Read Auto Mode BTN   */
button_t  Man_Drain_Btn ={.button_pin.port = PORTC,.button_pin.pin = GPIO_PIN7,
		.button_state = BUTTON_RELEASED,.button_connection = BUTTON_ACTIVE_LOW};

/*******************************************************************************/
/* Man_Drain_Btn  To Read Auto Mode BTN   */
button_t  Door_Contact_Btn ={.button_pin.port = PORTD,.button_pin.pin = GPIO_PIN1,
		.button_state = BUTTON_RELEASED,.button_connection = BUTTON_ACTIVE_LOW};
/* Water_Pin   To Enable Water Fill  */
Gpio_pin_config_t  R00_WaterEnable = {.port = PORTB, .pin = GPIO_PIN4,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
/*******************************************************************************/
/* Heater_Pin  To Enable Heater */
Gpio_pin_config_t  R01_HeaterEnable = {.port = PORTB, .pin = GPIO_PIN5,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
/*******************************************************************************/
/* Rotate_Right_Pin  To Enable Rotate Right */
<<<<<<< HEAD
Motor_Cnfg_t  R02_RightMotor = {.motor_pin_config.port = PORTB, .motor_pin_config.pin = GPIO_PIN6};

/*******************************************************************************/
/* Rotate_Left_Pin  To Enable Rotate Left */
Motor_Cnfg_t  R03_LeftMotor = {.motor_pin_config.port = PORTB, .motor_pin_config.pin = GPIO_PIN7};
=======
Gpio_pin_config_t  R02_RightMotor = {.port = PORTB, .pin = GPIO_PIN6,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};

/*******************************************************************************/
/* Rotate_Left_Pin  To Enable Rotate Left */
Gpio_pin_config_t  R03_LeftMotor = {.port = PORTB, .pin = GPIO_PIN7,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
/*******************************************************************************/
/* Drain_Pin  To Enable Drain  */
Gpio_pin_config_t  R04_FastEnable = {.port = PORTD, .pin = GPIO_PIN7,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
/*******************************************************************************/
/* Drain_Pin  To Enable Drain  */
<<<<<<< HEAD

Motor_Cnfg_t  R05_DrainEnable = {.motor_pin_config.port = PORTD, .motor_pin_config.pin = GPIO_PIN4};
=======
Gpio_pin_config_t  R05_DrainEnable = {.port = PORTD, .pin = GPIO_PIN4,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
/*******************************************************************************/
/* Man_Drain_Btn  To Read Auto Mode BTN   */
Gpio_pin_config_t  Door_Lock_Pin ={.port = PORTB, .pin = GPIO_PIN3,
		.direction = GPIO_PIN_OUTPOT };

//Machine_Mode_t  machine_state_mode = STOP_MODE;
/*****************  STATIC VARIABLES   *************************/
/* Buzzer_Pin  To Alarm   */
Gpio_pin_config_t  Buzzer = {.port = PORTD, .pin = GPIO_PIN6,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
/*******************************************************************************/
/* Led_Pin  To Alarm   */
Gpio_pin_config_t  LED = {.port = PORTD, .pin = GPIO_PIN5,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
/*******************************************************************************/
/* Water_Level_Pin  To Read Water Level Sensor   */
Gpio_pin_config_t  Water_Level_Pin = {.port = PORTC, .pin = GPIO_PIN0,
		.direction = GPIO_PIN_INPOT };

/*******************************************************************************/
/* Man_Drain_Btn  To Read Auto Mode BTN   */
Gpio_pin_config_t  Auto_Water_Temp = {.port = PORTD, .pin = GPIO_PIN0,
		.direction = GPIO_PIN_INPOT };
/*******************************************************************************/
/* Man_Drain_Btn  To Read Auto Mode BTN   */
button_t  Auto_Start_Btn ={.button_pin.port = PORTB,.button_pin.pin = GPIO_PIN0,
		.button_state = BUTTON_RELEASED,.button_connection = BUTTON_ACTIVE_LOW};
/*******************************************************************************/
/* Mode_Auto_Btn  To Read Auto Mode BTN   */
button_t  Mode_Auto_Btn ={.button_pin.port = PORTC,.button_pin.pin = GPIO_PIN2,
		.button_state = BUTTON_RELEASED,.button_connection = BUTTON_ACTIVE_LOW};


led_t Led1 = {.port = PORTB,
		.pin = GPIO_PIN0,
		.status = LED_OFF
};

/*****************  GLOBAL FUNCTIONS   *************************/
chr_lcd_4bit_t lcd1 ={
<<<<<<< HEAD
		.lcd_rs.port = PORTA, .lcd_rs.pin = 1,
=======
		.lcd_rs.port = PORTA, .lcd_rs.pin = 0,
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
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

	gpio_pin_initialize(&R00_WaterEnable);
	gpio_pin_initialize(&R01_HeaterEnable);
<<<<<<< HEAD

	gpio_pin_initialize(&R04_FastEnable);
=======
	gpio_pin_initialize(&R02_RightMotor);
	gpio_pin_initialize(&R03_LeftMotor);
	gpio_pin_initialize(&R04_FastEnable);
	gpio_pin_initialize(&R05_DrainEnable);
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
	gpio_pin_initialize(&Door_Lock_Pin);
	gpio_pin_initialize(&Buzzer);
	gpio_pin_initialize(&LED);
	gpio_pin_initialize(&Water_Level_Pin);
	gpio_pin_initialize(&Auto_Water_Temp);

	button_initialize(&Mode_Manual_Btn);
	button_initialize(&Man_Water_Btn);
	button_initialize(&Man_Heater_Btn);
	button_initialize(&Man_RotatRight_Btn);
	button_initialize(&Man_RotateLeft_Btn);
	button_initialize(&Man_Drain_Btn);
	button_initialize(&Door_Contact_Btn);
	button_initialize(&Auto_Start_Btn);
	button_initialize(&Mode_Auto_Btn);

	lcd_4bit_intialize(&lcd1);
	Timer0_Init();
<<<<<<< HEAD
	Timer0_Stop();

	Motor_Init(&R02_RightMotor);
	Motor_Init(&R03_LeftMotor);
	Motor_Init(&R05_DrainEnable);
=======



>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
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

