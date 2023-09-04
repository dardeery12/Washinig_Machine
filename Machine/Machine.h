/*******************************************************************************
 * @file    Machine.h
 * @author  Abo Drda
 * @date    Sep 3, 2023
 * @brief   
 ******************************************************************************/

#ifndef MACHINE_MACHINE_H_
#define MACHINE_MACHINE_H_

/*****************  Includes ********************************/

#include "../Ecu_Layer/Ecu_Maneger/Maneger.h"

/***************** types  ************************/
typedef enum
{
	AUTO_MODE,
	MANUAL_MODE,
	STOP_MODE,
	ERROR_CHOOSE_MODE
}Machine_Mode_t;

typedef enum
{
	RINSE_STATE,
	WASHING_STATE,
	DRAIN_STATE,
	RINSE_STATE2,
	END_STATE
}Auto_Machine_Status_t;
/*****************  GLOBAL VARIABLES   ***********************/

/*****************  GLOBAL FUNCTIONS   ***********************/
void Machine_Init();
Std_ReturnType Machine_Auto_Function();
Std_ReturnType Machine_Manual_Function();
Std_ReturnType Machine_Select_Mode(Machine_Mode_t *machine_mode);

#endif

