/*******************************************************************************
 * @file    auto_interface.h
 * @author  Abo Drda
 * @date    Sep 6, 2023
 * @brief   
 ******************************************************************************/

#ifndef MACHINE_AUTO_AUTO_INTERFACE_H_
#define MACHINE_AUTO_AUTO_INTERFACE_H_

/*****************  Includes ********************************/
#include "../../Ecu_Layer/Ecu_Maneger/Maneger.h"
#include "../manual/interface.h"


/***************** types  ************************/
typedef enum
{
	RINSE_STATE,
	WASHING_STATE,
	DRAIN_STATE,
	RINSE_STATE2,
	END_STATE,
	ERROR_STAT,
}Auto_Machine_Status_t;

/***************** EXTERN VARIABLES  ************************/

/*****************  GLOBAL VARIABLES   ***********************/

/*****************  GLOBAL FUNCTIONS   ***********************/
Std_ReturnType Machine_Auto_Process();
Std_ReturnType Print_Time(chr_lcd_4bit_t *lcd,uint8 row,uint8 col,uint8 min, uint8 sec);
#endif

