/********************************************************************************
 * @file    motor_dc.c
 * @author  Drd
 * @date    Sep 8, 2023
 * @brief   
 ********************************************************************************/


/*****************  INCLUDES   *******************************/
#include "../Ecu_Maneger/Maneger.h"
#if MOTOR_MODULE_ENABLE == ENABLE
#include "motor_dc.h"
 #include "../../Mcal_Layer/Mcal_Gpio/Mcal_Gpio_Interface.h"


/***************** EXTERN VARIABLES  *************************/

/***************** PRIVATE MACROS AND DEFINES  ****************/

/*****************  PRIVATE TYPEDEFS   *************************/

/*****************  STATIC VARIABLES   *************************/

/*****************  GLOBAL VARIABLES   *************************/
//Std_ReturnType G_Motor_Run_Flag = E_NOK;
/*****************  STATIC FUNCTION PROTOTYPES   ***************/

/*****************  STATIC FUNCTIONS   *************************/

/*****************  GLOBAL FUNCTIONS   *************************/
Std_ReturnType Motor_Init(Motor_Cnfg_t * motor_obj)
{
	Std_ReturnType Ret = E_OK;
	gpio_pin_direction_initialize(&(motor_obj->motor_pin_config), GPIO_PIN_OUTPOT);

	return Ret;
}
Std_ReturnType Motor_Run(Motor_Cnfg_t * motor_obj)
{
	Std_ReturnType Ret = E_OK;
	gpio_pin_write_logic(&(motor_obj->motor_pin_config), HIGH);
	return Ret;
}
Std_ReturnType Motor_Stop(Motor_Cnfg_t * motor_obj)
{
	Std_ReturnType Ret = E_OK;
		gpio_pin_write_logic(&(motor_obj->motor_pin_config),LOW);

	return Ret;
}
Motor_Stat_t  Motor_Get_Stat(Motor_Cnfg_t * motor_obj)
{
	Motor_Stat_t  Ret = MOTOR_RUN;
	Std_ReturnType  stat = E_NOK;
	stat = gpio_pin_get_status(&(motor_obj->motor_pin_config));
	if(stat == E_NOK)
	{
		   Ret = MOTOR_RUN;
	}
	else
	{
		 Ret = MOTOR_STOP;
	}
	return Ret;
}
#endif
