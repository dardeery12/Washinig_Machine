/**
 ********************************************************************************
 * @file    Mcal_Interrupt_Interface.h
 * @author  Abdo Drd
 * @date    Jul 29, 2023
 * @brief   
 ********************************************************************************
 */

#ifndef MCAL_LAYER_MCAL_INTERRUPT_MCAL_INTERRUPT_INTERFACE_H_
#define MCAL_LAYER_MCAL_INTERRUPT_MCAL_INTERRUPT_INTERFACE_H_

/*****************  INCLUDES   *******************************/
#include "../Mcal_Gpio/Mcal_Gpio_Interface.h"
#include "../Mcal_Common/M_Atmega32_Reg.h"
#include "../Mcal_Common/Mcal_Std.h"
#include "Mcal_Interrupt_Private.h"



/********************** * TYPEDEFS *****************************/
typedef enum
{
	INTERRUPT_EXTERNAL_INT0 =  ZERO_INIT,
	INTERRUPT_EXTERNAL_INT1,
	INTERRUPT_EXTERNAL_INT2
}Interrupt_Num_t;

typedef enum
{
	INTERRUPT_FALLING_EDGE = ZERO_INIT,
	INTERRUPT_RISING_EDGE,
	INTERRUPT_LOGICAL_CHANGE,
	INTERRUPT_LOW_LEVEL
}Interrupt_Sense_t;

typedef struct
{
	void (*INTERRUPT_HANDLER)(void);
	Interrupt_Num_t  Interrupt_Num;
	Interrupt_Sense_t Interrupt_Sense;
}Interrupt_Cnfg_t;


/***************** GLOBAL FUNCTION PROTOTYPES *****************/

Std_ReturnType Interrupt_External_Init(Interrupt_Cnfg_t * Interrupt_Cnfg_obj);
Std_ReturnType Interrupt_External_Dinit(Interrupt_Cnfg_t * Interrupt_Cnfg_obj);
Std_ReturnType Interrupt_Global_Enable(void);
Std_ReturnType Interrupt_Global_Disable(void);


#endif

