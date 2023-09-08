/**
 ********************************************************************************
 * @file    keypad.c
 * @author  Abdo Drd
 * @date    Jul 12, 2023
 * @brief   
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/

#include"keypad.h"


#define Delay_ms(x)        _delay_ms(x)
/************************************
 * GLOBAL VARIABLES
 ************************************/

static const uint8 Btn_val [KEYPAD_ROW][KEYPAD_COL] = {
		{'7' , '8' , '9' , '/'},
		{'4' , '5' , '6' , '*'},
		{'1' , '2' , '3' , '-'},
		{'#' , '0' , '=' , '+'},
};
/************************************
 * GLOBAL FUNCTIONS
 ************************************/


Std_ReturnType Keypad_Initialize( Kypad_cnfg_t * keypad_obj)
{
	Std_ReturnType ret = E_NOK;
	uint8 Loc_Row_counter = ZERO_INIT, Loc_Col_counter = ZERO_INIT;
	if(NULL == keypad_obj)
	{
		ret = E_NOK;
	}
	else
	{
		for(Loc_Row_counter = 0; Loc_Row_counter < KEYPAD_ROW; ++Loc_Row_counter)
		{
			keypad_obj->Row[Loc_Row_counter].logic = LOW;
			keypad_obj->Row[Loc_Row_counter].direction = GPIO_PIN_OUTPOT;
			ret = gpio_pin_initialize(&(keypad_obj->Row[Loc_Row_counter]));
		}
		for(Loc_Col_counter = 0; Loc_Col_counter < KEYPAD_COL; ++Loc_Col_counter)
		{
			ret = gpio_pin_direction_initialize(&(keypad_obj->Col[Loc_Col_counter]), GPIO_PIN_INPOT);
		}
		ret = E_OK;
	}

	return ret ;
}
Std_ReturnType Keypad_Scane(const Kypad_cnfg_t * keypad_obj, uint8 * value)
{
	Std_ReturnType ret = E_NOK;
	uint8 Loc_Col_value =ZERO_INIT;
	uint8 Loc_Row_counter = ZERO_INIT, Loc_Col_counter = ZERO_INIT, Loc_counter = ZERO_INIT;
	if(NULL == keypad_obj)
	{
		ret = E_NOK;
	}
	else
	{
		for(Loc_Row_counter = 0; Loc_Row_counter < KEYPAD_ROW; ++Loc_Row_counter)
		{
			for(Loc_counter = 0; Loc_counter < KEYPAD_ROW; ++Loc_counter)
			{
				gpio_pin_write_logic(&(keypad_obj->Row[Loc_counter]), LOW);
			}
			gpio_pin_write_logic(&(keypad_obj->Row[Loc_Row_counter]), HIGH);
			Delay_ms(10);
			for(Loc_Col_counter = 0; Loc_Col_counter < KEYPAD_COL; ++Loc_Col_counter)
			{
				ret = gpio_pin_read(&(keypad_obj->Col[Loc_Col_counter]), &Loc_Col_value);
				if(HIGH == Loc_Col_value)
				{
					Delay_ms(10);
					if(HIGH == Loc_Col_value)
					{
						*value = Btn_val [Loc_Row_counter][Loc_Col_counter];
					}
				}
			}
		}
		ret = E_OK;
	}
	return ret ;
}






