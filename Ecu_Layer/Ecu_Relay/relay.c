/**
 ********************************************************************************
 * @file    relay.c
 * @author  Abdo Drd
 * @date    Jun 23, 2023
 * @brief   
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "../Ecu_Maneger/Maneger.h"
#if RELAY_MODULE_ENABLE == ENABLE

#include "relay.h"


/************************************
 * EXTERN VARIABLES
 ************************************/

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/




/************************************
 * PRIVATE TYPEDEFS
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/



/************************************
 * GLOBAL VARIABLES
 ************************************/



/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/



/************************************
 * STATIC FUNCTIONS
 ************************************/



/************************************
 * GLOBAL FUNCTIONS
 ************************************/
Std_ReturnType Relay_Inialize(relay_cnfg_t * relay_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == relay_obj)
	{
		ret = E_NOK;
	}
	else
	{
		Gpio_pin_config_t  Loc_Relay  ={.port = relay_obj->port, .pin = relay_obj->pin,
				.direction = GPIO_PIN_OUTPOT, .logic = relay_obj->relay_state};
		gpio_pin_initialize(&Loc_Relay);
		ret = E_OK;
	}

	return ret;
}
Std_ReturnType Relay_Turn_on(relay_cnfg_t * relay_obj)
{
	Std_ReturnType ret = E_NOK;

	Gpio_pin_config_t  loc_Relay = {.port = relay_obj->port,
							   .pin = relay_obj->pin};
	if(NULL == relay_obj)
	{
		ret = E_NOK;
	}
	else
	{
		gpio_pin_write_logic(&loc_Relay, HIGH);

		ret = E_OK;
	}

	return ret;
}
Std_ReturnType Relay_Turn_off(relay_cnfg_t * relay_obj)
{
	Std_ReturnType ret = E_NOK;

	Gpio_pin_config_t  loc_Relay = {.port = relay_obj->port,
			.pin = relay_obj->pin};
	if(NULL == relay_obj)
	{
		ret = E_NOK;
	}
	else
	{
		gpio_pin_write_logic(&loc_Relay, LOW);

		ret = E_OK;
	}

	return ret;
}
#endif
