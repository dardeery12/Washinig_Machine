/**
 ********************************************************************************
 * @file    relay.h
 * @author  Abo Drda
 * @date    Jun 23, 2023
 * @brief   
 ********************************************************************************
 */

#ifndef ECU_LAYER_HEADER_RELAY_H_
#define ECU_LAYER_HEADER_RELAY_H_


/************************************
 * INCLUDES
 ************************************/
 
#include "../../Mcal_Layer/Mcal_Gpio/Mcal_Gpio_Interface.h"
 
 
 
 
/************************************
 * MACROS AND DEFINES
 ************************************/





/************************************
 * TYPEDEFS
 ************************************/





/************************************
 * EXPORTED VARIABLES
 ************************************/
typedef enum
{
	RELAY_ON,
	RELAY_OFF
}relay_state_t;


typedef struct
{
	port_index_t port;
	pin_index_t  pin;
	relay_state_t  relay_state;
}relay_cnfg_t;

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/


Std_ReturnType Relay_Inialize(relay_cnfg_t * relay_obj);
Std_ReturnType Relay_Turn_on(relay_cnfg_t * relay_obj);
Std_ReturnType Relay_Turn_off(relay_cnfg_t * relay_obj);

#endif

