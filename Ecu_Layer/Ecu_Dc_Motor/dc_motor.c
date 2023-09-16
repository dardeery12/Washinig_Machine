/**
 ********************************************************************************
 * @file    dc_motor.c
 * @author  Abdo Drd
 * @date    Jun 23, 2023
 * @brief   
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "../Ecu_Maneger/Maneger.h"
#if MOTOR_MODULE_ENABLE == ENABLE
#include "dc_motor.h"

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
/**
 *
 * @param motor_obj
 * @return
 */
Std_ReturnType  Dc_Motor_Inialize(motor_cnfg_t * motor_obj)
{
	Std_ReturnType ret = E_NOK;
	/*pin0 */
	Gpio_pin_config_t  locDc_motor_Pin0 = {.port = motor_obj->dc_pin[0].port,
			.pin = motor_obj->dc_pin[0].pin,.direction = GPIO_PIN_OUTPOT, .logic = LOW};
	/*pin1 */
	Gpio_pin_config_t  locDc_motor_Pin1 = {.port = motor_obj->dc_pin[1].port,
			.pin = motor_obj->dc_pin[1].pin,.direction = GPIO_PIN_OUTPOT, .logic = LOW};
	if(NULL == motor_obj)
	{
		ret = E_NOK;
	}
	else
	{
		ret = gpio_pin_initialize(&locDc_motor_Pin0);
		ret = gpio_pin_initialize(&locDc_motor_Pin1);
		ret = E_OK;
	}

	return ret;
}
/**
 *
 * @param motor_obj
 * @return
 */
Std_ReturnType  Dc_Motor_Forward(motor_cnfg_t * motor_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == motor_obj)
	{

		ret = E_NOK;
	}
	else
	{
		gpio_pin_write_logic(&(motor_obj->dc_pin[0]), HIGH);
		gpio_pin_write_logic(&(motor_obj->dc_pin[1]), LOW);
		ret = E_OK;
	}

	return ret;
}
Std_ReturnType  Dc_Motor_Backward(motor_cnfg_t * motor_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == motor_obj)
	{
		ret = E_NOK;
	}
	else
	{
		gpio_pin_write_logic(&(motor_obj->dc_pin[0]), LOW);
		gpio_pin_write_logic(&(motor_obj->dc_pin[1]), HIGH);
		ret = E_OK;
	}

	return ret;
}
/**
 *
 * @param motor_obj
 * @return
 */
Std_ReturnType  Dc_Motor_Stop(motor_cnfg_t * motor_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == motor_obj)
	{
		ret = E_NOK;
	}
	else
	{
		gpio_pin_write_logic(&(motor_obj->dc_pin[0]), LOW);
		gpio_pin_write_logic(&(motor_obj->dc_pin[1]), LOW);
		ret = E_OK;
	}

	return ret;
}

#endif
