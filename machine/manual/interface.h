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
<<<<<<< HEAD
=======
	STOP_MODE,
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
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
<<<<<<< HEAD
	ERROR_MAN_CHOOSE,
=======
	ERROR_CHOOSE,
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
}Manual_Btn_Select_t;
/*****************  GLOBAL VARIABLES   ***********************/
/*****************  global function   ***********************/
Std_ReturnType Machine_Manual_Init(void);
Std_ReturnType Machine_Manual_Process(void);
Std_ReturnType Alarm_Error(void);
Std_ReturnType Machine_Lcd();
Std_ReturnType Machine_Select_Mode();

#endif

