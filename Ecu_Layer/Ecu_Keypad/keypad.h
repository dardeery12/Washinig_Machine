/**
 ********************************************************************************
 * @file    keypad.h
 * @author  Abo Drda
 * @date    Jul 12, 2023
 * @brief   
 ********************************************************************************
 */

#ifndef ECU_LAYER_HEADER_KEYPAD_H_
#define ECU_LAYER_HEADER_KEYPAD_H_


/************************************
 * INCLUDES
 ************************************/
 
#include "../../Mcal_Layer/Mcal_Gpio/Mcal_Gpio_Interface.h"
 
 
/************************************
 * MACROS AND DEFINES
 ************************************/

#define KEYPAD_ROW       4
#define KEYPAD_COL       4



/************************************
 * TYPEDEFS
 ************************************/

typedef struct
{
	Gpio_pin_config_t  Row[KEYPAD_ROW];
	Gpio_pin_config_t  Col[KEYPAD_COL];
}Kypad_cnfg_t;




/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
Std_ReturnType Keypad_Initialize( Kypad_cnfg_t * keypad_obj);
Std_ReturnType Keypad_Scane(const Kypad_cnfg_t * keypad_obj, uint8 * value);

#endif

