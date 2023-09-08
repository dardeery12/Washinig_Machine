/*******************************************************************************
 * @file    interface.h
 * @author  Abo Drda
 * @date    Sep 6, 2023
 * @brief   
 ******************************************************************************/

#ifndef MACHINE_MANUAL_INTERFACE_H_
#define MACHINE_MANUAL_INTERFACE_H_

/*****************  Includes ********************************/
#include "../../Ecu_Layer/Ecu_Maneger/Maneger.h"

/***************** EXTERN VARIABLES  ************************/


/*****************   TYPEDEFS   *************************/

typedef enum
{
	AUTO_MODE,
	MANUAL_MODE,
	STOP_MODE,
	ERROR_CHOOSE_MODE
}Machine_Mode_t;

typedef enum
{
	WATER_BTN,
	HEATER_BTN,
	DRAIN_BTN,
	RIGHT_ROTAT_BTN,
	LEFT_ROTAT_BTN,
	DOOR_LOCK,
	ERROR_CHOOSE,
}Manual_Btn_Select_t;
/*****************  GLOBAL VARIABLES   ***********************/
/*****************  global function   ***********************/
Std_ReturnType Machine_Manual_Init(void);
Std_ReturnType Machine_Manual_Process(void);
Std_ReturnType Alarm_Error(void);
Std_ReturnType Machine_Lcd();
Std_ReturnType Machine_Select_Mode();

#endif

