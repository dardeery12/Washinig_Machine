/**
 ********************************************************************************
 * @file    char_lcd.h
 * @author  Abo Drd
 * @date    Jul 7, 2023
 * @brief   
 ********************************************************************************
 */

#ifndef ECU_LAYER_HEADER_CHAR_LCD_H_
#define ECU_LAYER_HEADER_CHAR_LCD_H_


/** Example
 * chr_lcd_4bit_t lcd1 ={.lcd_rs.port = PORTA,
			.lcd_en.port = PORTA,
			.lcd_data[0].port = PORTA,
			.lcd_data[1].port = PORTA,
			.lcd_data[2].port = PORTA,
			.lcd_data[3].port = PORTA,
			.lcd_rs.pin = 0,
			.lcd_en.pin = 1,
			.lcd_data[0].pin = 2,
			.lcd_data[1].pin = 3,
			.lcd_data[2].pin = 4,
			.lcd_data[3].pin = 5, };

	chr_lcd_8bit_t lcd2 ={
			.lcd_rs.port = PORTD,
			.lcd_en.port = PORTD,
			.lcd_data[0].port = PORTC,
			.lcd_data[1].port = PORTC,
			.lcd_data[2].port = PORTC,
			.lcd_data[3].port = PORTC,
			.lcd_data[4].port = PORTC,
			.lcd_data[5].port = PORTC,
			.lcd_data[6].port = PORTC,
			.lcd_data[7].port = PORTC,
			.lcd_rs.pin = 0,
			.lcd_en.pin = 1,
			.lcd_data[0].pin = 0,
			.lcd_data[1].pin = 1,
			.lcd_data[2].pin = 2,
			.lcd_data[3].pin = 3,
			.lcd_data[4].pin = 4,
			.lcd_data[5].pin = 5,
			.lcd_data[6].pin = 6,
			.lcd_data[7].pin = 7,
	};

	lcd_4bit_intialize(&lcd1);
	lcd_8bit_intialize(&lcd2);

	lcd_4bit_send_string(&lcd1, "Welcome Lcd 1");


	lcd_8bit_send_string(&lcd2, "Welcome Lcd 2");
 *
 *
 */


/************************************
 * INCLUDES
 ************************************/
#include "../../Mcal_Layer/Mcal_Gpio/Mcal_Gpio_Interface.h"
#include "../../Mcal_Layer/Mcal_Common/Mcal_Std.h"
 
 
 
 
 
/************************************
 * MACROS AND DEFINES
 ************************************/


#define _LCD_CLEAR                      0X01
#define _LCD_RETURN_HOME                0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF   0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON    0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON    0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT     0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT    0x14
#define _LCD_DISPLAY_SHIFT_LEFT         0x18
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE           0x38
#define _LCD_4BIT_MODE_2_LINE           0x28

#define _LCD_CGRAM_START                0x40
#define _LCD_DDRAM_START                0x80

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4



/************************************
 * TYPEDEFS
 ************************************/


typedef struct{
    Gpio_pin_config_t lcd_rs;
    Gpio_pin_config_t lcd_en;
    Gpio_pin_config_t lcd_data[4];
}chr_lcd_4bit_t;

typedef struct{
    Gpio_pin_config_t lcd_rs;
    Gpio_pin_config_t lcd_en;
    Gpio_pin_config_t lcd_data[8];
}chr_lcd_8bit_t;



/************************************
 * EXPORTED VARIABLES
 ************************************/





/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
Std_ReturnType lcd_4bit_intialize(const chr_lcd_4bit_t *lcd);
Std_ReturnType lcd_4bit_send_char_data(const chr_lcd_4bit_t *lcd, uint8 data);
Std_ReturnType lcd_4bit_send_char_data_pos(const chr_lcd_4bit_t *lcd,uint8 row, uint8 column, uint8 data);
Std_ReturnType lcd_4bit_send_string(const chr_lcd_4bit_t *lcd, uint8 *str);
Std_ReturnType lcd_4bit_send_string_pos(const chr_lcd_4bit_t *lcd, uint8 row, uint8 column, uint8 *str);
Std_ReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit_t *lcd, uint8 row, uint8 column,
                                         const uint8 _chr[], uint8 mem_pos);
Std_ReturnType lcd_4bit_clear(const chr_lcd_4bit_t *lcd);

Std_ReturnType lcd_8bit_intialize(const chr_lcd_8bit_t *lcd);
Std_ReturnType lcd_8bit_send_char_data(const chr_lcd_8bit_t *lcd, uint8 data);
Std_ReturnType lcd_8bit_send_char_data_pos(const chr_lcd_8bit_t *lcd,uint8 row, uint8 column, uint8 data);
Std_ReturnType lcd_8bit_send_string(const chr_lcd_8bit_t *lcd, uint8 *str);
Std_ReturnType lcd_8bit_send_string_pos(const chr_lcd_8bit_t *lcd, uint8 row, uint8 column, uint8 *str);
Std_ReturnType lcd_8bit_send_custom_char(const chr_lcd_8bit_t *lcd, uint8 row, uint8 column,
                                         const uint8 _chr[], uint8 mem_pos);


Std_ReturnType lcd_4bit_send_num_pos(chr_lcd_4bit_t *lcd, uint8 row, uint8 column,  uint8 num);


#endif

