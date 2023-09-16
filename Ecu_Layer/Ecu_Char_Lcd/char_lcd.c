/**
 ********************************************************************************
 * @file    char_lcd.c
 * @author  Abdo Drd
 * @date    Jul 7, 2023
 * @brief   
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "../Ecu_Maneger/Maneger.h"
#if CHAR_LCD_MODULE_ENABLE   == ENABLE
#include "char_lcd.h"

#define Delay_ms(x)        _delay_ms(x)
/************************************
 * EXTERN VARIABLES
 ************************************/

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/
static Std_ReturnType lcd_4bit_send_command(const chr_lcd_4bit_t *lcd, uint8 command);
static Std_ReturnType lcd_8bit_send_command(const chr_lcd_8bit_t *lcd, uint8 command);
/************************************
 * GLOBAL VARIABLES
 ************************************/



/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

static Std_ReturnType lcd_send_4bits(const chr_lcd_4bit_t *lcd, uint8 _data_command);
static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit_t *lcd);
static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd, uint8 row, uint8 coulmn);
static Std_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit_t *lcd);
static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_t *lcd, uint8 row, uint8 coulmn);



/************************************
 * GLOBAL FUNCTIONS
 ************************************/


/**
 *
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_4bit_intialize(const chr_lcd_4bit_t *lcd){
	Std_ReturnType ret = E_OK;
	uint8 Loc_counter = 0;
	uint8 string1[] = {"Lcd inializing....."};
	uint8 string2 []= {"Lcd inialized....."};
	uint8 string3 []= {"Lcd Is Ready......"};
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		ret = gpio_pin_direction_initialize(&(lcd->lcd_rs), GPIO_PIN_OUTPOT);
		ret = gpio_pin_direction_initialize(&(lcd->lcd_en), GPIO_PIN_OUTPOT);
		for(Loc_counter = 0; Loc_counter < 4; ++Loc_counter)
		{
			ret = gpio_pin_direction_initialize(&(lcd->lcd_data[Loc_counter]), GPIO_PIN_OUTPOT);
		}

		Delay_ms(20);
		ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
		Delay_ms(5);
		ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
		Delay_ms(150);
		ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);

		ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
		ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
		ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
		ret = lcd_4bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
		ret = lcd_4bit_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
		ret = lcd_4bit_send_command(lcd, 0x80);

<<<<<<< HEAD
		//ret = lcd_4bit_send_string(lcd, &string1);
		Delay_ms(150);
		//ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);

		//ret = lcd_4bit_send_string(lcd, &string2);
		Delay_ms(150);
		//ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);

		//ret = lcd_4bit_send_string(lcd, &string3);
		Delay_ms(150);
		//ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
=======
		ret = lcd_4bit_send_string(lcd, &string1);
		Delay_ms(150);
		ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);

		ret = lcd_4bit_send_string(lcd, &string2);
		Delay_ms(150);
		ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);

		ret = lcd_4bit_send_string(lcd, &string3);
		Delay_ms(150);
		ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
	}
	return ret;
}

/**
 *
 * @param lcd
 * @param command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_4bit_send_command(const chr_lcd_4bit_t *lcd, uint8 command){
	Std_ReturnType ret = E_OK;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		/* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
		/* Write Logic (0) to the "Register Select" Pin to select the "Instruction Register"  */
		ret = gpio_pin_write_logic(&(lcd->lcd_rs), LOW);
		/* Send the Command through the (4-Pins" Data lines */
		ret = lcd_send_4bits(lcd, command >> 4);
		/* Send the Enable Signal on the "E" Pin */
		ret = lcd_4bit_send_enable_signal(lcd);
		/* Send the Command through the (4-Pins" Data lines */
		ret = lcd_send_4bits(lcd, command);
		/* Send the Enable Signal on the "E" Pin */
		ret = lcd_4bit_send_enable_signal(lcd);
	}
	return ret;
}

/**
 *
 * @param lcd Pointer to the LCD configurations
 * @param data The data that we need to send to the LCD
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_4bit_send_char_data(const chr_lcd_4bit_t *lcd, uint8 data){
	Std_ReturnType ret = E_OK;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		/* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
		/* Write Logic (1) to the "Register Select" Pin to select the "Data Register"  */
		ret = gpio_pin_write_logic(&(lcd->lcd_rs), HIGH);
		/* Send the Data through the (4-Pins" Data lines */
		ret = lcd_send_4bits(lcd, data >> 4);
		/* Send the Enable Signal on the "E" Pin */
		ret = lcd_4bit_send_enable_signal(lcd);
		/* Send the Data through the (4-Pins" Data lines */
		ret = lcd_send_4bits(lcd, data);
		/* Send the Enable Signal on the "E" Pin */
		ret = lcd_4bit_send_enable_signal(lcd);
	}
	return ret;
}

/**
 *
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_4bit_send_char_data_pos(const chr_lcd_4bit_t *lcd,uint8 row, uint8 column, uint8 data){
	Std_ReturnType ret = E_OK;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		ret = lcd_4bit_set_cursor(lcd, row, column);
		ret = lcd_4bit_send_char_data(lcd, data);
	}
	return ret;
}

/**
 *
 * @param lcd
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_4bit_send_string(const chr_lcd_4bit_t *lcd, uint8 *str){
	Std_ReturnType ret = E_OK;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		while(*str){
			ret = lcd_4bit_send_char_data(lcd, *str++);
		}
	}
	return ret;
}

/**
 *
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_4bit_send_string_pos(const chr_lcd_4bit_t *lcd, uint8 row, uint8 column, uint8 *str){
	Std_ReturnType ret = E_OK;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		ret = lcd_4bit_set_cursor(lcd, row, column);
		while(*str){
			ret = lcd_4bit_send_char_data(lcd, *str++);
		}
	}
	return ret;
}

/**
 *
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit_t *lcd, uint8 row, uint8 column,
		const uint8 _chr[], uint8 mem_pos){
	Std_ReturnType ret = E_OK;
	uint8 lcd_counter = ZERO_INIT;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		ret = lcd_4bit_send_command(lcd, (_LCD_CGRAM_START+(mem_pos*8)));
		for(lcd_counter=0; lcd_counter<=7; ++lcd_counter){
			ret = lcd_4bit_send_char_data(lcd, _chr[lcd_counter]);
		}
		ret = lcd_4bit_send_char_data_pos(lcd, row, column, mem_pos);
	}
	return ret;
}

Std_ReturnType lcd_4bit_clear(const chr_lcd_4bit_t *lcd)
{
<<<<<<< HEAD
	Std_ReturnType Ret = E_OK;
	lcd_4bit_send_command(lcd, _LCD_CLEAR);
	return Ret;
=======
	lcd_4bit_send_command(lcd, _LCD_CLEAR);

>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
}

/**
 *
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_8bit_intialize(const chr_lcd_8bit_t *lcd){
	Std_ReturnType ret = E_OK;
	uint8 l_data_pins_counter = ZERO_INIT;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		ret = gpio_pin_initialize(&(lcd->lcd_rs));
		ret = gpio_pin_initialize(&(lcd->lcd_en));
		for(l_data_pins_counter=ZERO_INIT; l_data_pins_counter<8; l_data_pins_counter++){
			ret = gpio_pin_initialize(&(lcd->lcd_data[l_data_pins_counter]));
		}
		Delay_ms(20);
		ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
		Delay_ms(5);
		ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
		Delay_ms(150);
		ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);

		ret = lcd_8bit_send_command(lcd, _LCD_CLEAR);
		ret = lcd_8bit_send_command(lcd, _LCD_RETURN_HOME);
		ret = lcd_8bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
		ret = lcd_8bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
		ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
		ret = lcd_8bit_send_command(lcd, 0x80);
	}
	return ret;
}

/**
 *
 * @param lcd
 * @param command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_8bit_send_command(const chr_lcd_8bit_t *lcd, uint8 command){
	Std_ReturnType ret = E_OK;
	uint8 l_pin_counter = ZERO_INIT;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		/* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
		/* Write Logic (0) to the "Register Select" Pin to select the "Instruction Register"  */
		ret = gpio_pin_write_logic(&(lcd->lcd_rs), LOW);
		/* Send the Command through the (8-Pins" Data lines */
		for(l_pin_counter=0; l_pin_counter<8; ++l_pin_counter){
			ret = gpio_pin_write_logic(&(lcd->lcd_data[l_pin_counter]), (command >> l_pin_counter) & (uint8)0x01);
		}
		/* Send the Enable Signal on the "E" Pin */
		ret = lcd_8bit_send_enable_signal(lcd);
	}
	return ret;
}

/**
 *
 * @param lcd
 * @param data
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_8bit_send_char_data(const chr_lcd_8bit_t *lcd, uint8 data){
	Std_ReturnType ret = E_OK;
	uint8 l_pin_counter = ZERO_INIT;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		/* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
		/* Write Logic (1) to the "Register Select" Pin to select the "Data Register"  */
		ret = gpio_pin_write_logic(&(lcd->lcd_rs), HIGH);
		/* Send the Data through the (8-Pins" Data lines */
		for(l_pin_counter=0; l_pin_counter<8; ++l_pin_counter){
			ret = gpio_pin_write_logic(&(lcd->lcd_data[l_pin_counter]), (data >> l_pin_counter) & (uint8)0x01);
		}
		/* Send the Enable Signal on the "E" Pin */
		ret = lcd_8bit_send_enable_signal(lcd);
	}
	return ret;
}

/**
 *
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_8bit_send_char_data_pos(const chr_lcd_8bit_t *lcd,uint8 row, uint8 column, uint8 data){
	Std_ReturnType ret = E_OK;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		ret = lcd_8bit_set_cursor(lcd, row, column);
		ret = lcd_8bit_send_char_data(lcd, data);
	}
	return ret;
}

/**
 *
 * @param lcd
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_8bit_send_string(const chr_lcd_8bit_t *lcd, uint8 *str){
	Std_ReturnType ret = E_OK;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		while(*str){
			ret = lcd_8bit_send_char_data(lcd, *str++);
		}
	}
	return ret;
}

/**
 *
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_8bit_send_string_pos(const chr_lcd_8bit_t *lcd, uint8 row, uint8 column, uint8 *str){
	Std_ReturnType ret = E_OK;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		ret = lcd_8bit_set_cursor(lcd, row, column);
		ret = lcd_8bit_send_string(lcd, str);
	}
	return ret;
}

/**
 *
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_8bit_send_custom_char(const chr_lcd_8bit_t *lcd, uint8 row, uint8 column,
		const uint8 _chr[], uint8 mem_pos){
	Std_ReturnType ret = E_OK;
	uint8 lcd_counter = ZERO_INIT;
	if(NULL == lcd){
		ret = E_NOK;
	}
	else{
		ret = lcd_8bit_send_command(lcd, (_LCD_CGRAM_START+(mem_pos*8)));
		for(lcd_counter=0; lcd_counter<=7; ++lcd_counter){
			ret = lcd_8bit_send_char_data(lcd, _chr[lcd_counter]);
		}
		ret = lcd_8bit_send_char_data_pos(lcd, row, column, mem_pos);
	}
	return ret;
}

/* * STATIC FUNCTIONS
 ************************************/

/**
 *
 * @param lcd
 * @param _data_command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType lcd_send_4bits(const chr_lcd_4bit_t *lcd, uint8 _data_command){
	Std_ReturnType ret = E_OK;
	ret = gpio_pin_write_logic(&(lcd->lcd_data[0]), (_data_command >> 0) & (uint8)0x01);
	ret = gpio_pin_write_logic(&(lcd->lcd_data[1]), (_data_command >> 1) & (uint8)0x01);
	ret = gpio_pin_write_logic(&(lcd->lcd_data[2]), (_data_command >> 2) & (uint8)0x01);
	ret = gpio_pin_write_logic(&(lcd->lcd_data[3]), (_data_command >> 3) & (uint8)0x01);
	return ret;
}

/**
 *
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit_t *lcd){
	Std_ReturnType ret = E_OK;
	ret = gpio_pin_write_logic(&(lcd->lcd_en), HIGH);
	Delay_ms(5);
	ret = gpio_pin_write_logic(&(lcd->lcd_en), LOW);
	return ret;
}

/**
 *
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit_t *lcd){
	Std_ReturnType ret = E_OK;
	ret = gpio_pin_write_logic(&(lcd->lcd_en), HIGH);
	Delay_ms(5);
	ret = gpio_pin_write_logic(&(lcd->lcd_en), LOW);
	return ret;
}

/**
 *
 * @param lcd Pointer to the LCD configuration parameters defined by the user
 * @param row Which row you need to print your character
 * @param coulmn Which column you need to print your character
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_t *lcd, uint8 row, uint8 coulmn){
	Std_ReturnType ret = E_OK;
	coulmn--;
	switch(row){
	case ROW1 : ret = lcd_8bit_send_command(lcd, (0x80 + coulmn)); break; /* 0x00 -> Decimal : 0  */
	case ROW2 : ret = lcd_8bit_send_command(lcd, (0xc0 + coulmn)); break; /* 0x40 -> Decimal : 64 */
	case ROW3 : ret = lcd_8bit_send_command(lcd, (0x94 + coulmn)); break; /* 0x14 -> Decimal : 20 */
	case ROW4 : ret = lcd_8bit_send_command(lcd, (0xd4 + coulmn)); break; /* 0x54 -> Decimal : 84 */
	default : ;
	}
	return ret;
}

/**
 *
 * @param lcd
 * @param row
 * @param coulmn
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd, uint8 row, uint8 coulmn){
	Std_ReturnType ret = E_OK;
	coulmn--;
	switch(row){
<<<<<<< HEAD
	case ROW1 : ret = lcd_4bit_send_command(lcd, (0x80 + coulmn));break;
	case ROW2 : ret = lcd_4bit_send_command(lcd, (0xC0 + coulmn));break;
	case ROW3 : ret = lcd_4bit_send_command(lcd, (0x94 + coulmn));break;
	case ROW4 : ret = lcd_4bit_send_command(lcd, (0xD4 + coulmn));break;
=======
	case ROW1 : ret = lcd_4bit_send_command(lcd, (0x80 + coulmn)); break;
	case ROW2 : ret = lcd_4bit_send_command(lcd, (0xc0 + coulmn)); break;
	case ROW3 : ret = lcd_4bit_send_command(lcd, (0x94 + coulmn)); break;
	case ROW4 : ret = lcd_4bit_send_command(lcd, (0xd4 + coulmn)); break;
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
	default : ;
	}
	return ret;
}


Std_ReturnType lcd_4bit_send_num_pos(chr_lcd_4bit_t *lcd, uint8 row, uint8 column,  uint8 num)
{
	Std_ReturnType ret = E_NOK;

	char s[4];
	sprintf(s,"%d",num);
	lcd_4bit_send_string_pos(lcd, row, column, s);
	return ret;
}
#endif
