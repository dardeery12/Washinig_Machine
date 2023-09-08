/*******************************************************************************
 * @file    Mcal_Maneger.h
 * @author  Abo Drda
 * @date    Jul 29, 2023
 * @brief   
 ******************************************************************************/

#ifndef MCAL_LAYER_MCAL_MANEGER_MCAL_MANEGER_H_
#define MCAL_LAYER_MCAL_MANEGER_MCAL_MANEGER_H_

/*****************  Includes ********************************/
#include "Mcal_Cnfg.h"

#if   GPIO_MODULE_ACTIVE == ENABLE
#include"../Mcal_Gpio/Mcal_Gpio_Interface.h"
#endif
#if   EXT_INTERRUPT_ACTIVE == ENABLE
#include "../Mcal_Interrupt/Mcal_Interrupt_Interface.h"
#endif

#if TIMER0_ACTIVE   == ENABLE
#include "../Timers/Timer0/Timer0.h"
#endif
/*
 * #if    == ENABLE
#include
#endif
#if    == ENABLE
#include
#endif
*/


#endif

