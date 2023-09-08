/*******************************************************************************
 * @file    Timer1_Interface.h
 * @author  Abo Drda
 * @date    Sep 1, 2023
 * @brief   
 ******************************************************************************/

#ifndef MCAL_LAYER_TIMERS_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_LAYER_TIMERS_TIMER1_TIMER1_INTERFACE_H_

/*****************  Includes ********************************/
#include "../../Mcal_Common/M_Atmega32_Reg.h"
#include "../../Mcal_Common/Mcal_Std.h"
#include "Timer1_Private.h"
/***************** EXTERN VARIABLES  ************************/

/*****************  GLOBAL VARIABLES   ***********************/

/*****************  GLOBAL FUNCTIONS   ***********************/
Std_ReturnType Timer1_Init();
Std_ReturnType Timer1_Start();
Std_ReturnType Timer1_Stop();
#endif

