/**
 ********************************************************************************
 * @file    dc_motor.h
 * @author  Abo Drda
 * @date    Jun 23, 2023
 * @brief   
 ********************************************************************************
 */

#ifndef ECU_LAYER_HEADER_DC_MOTOR_H_
#define ECU_LAYER_HEADER_DC_MOTOR_H_


/************************************
 * INCLUDES
 ************************************/

 #include "../../Mcal_Layer/Mcal_Gpio/Mcal_Gpio_Interface.h"

 
/************************************
 *                example
 
motor_cnfg_t  Dc_motor1 = {.dc_pin[0].port = PORTC, .dc_pin[0].pin = GPIO_PIN0,
		.dc_pin[0].logic = LOW,
		.dc_pin[1].port = PORTC, .dc_pin[1].pin = GPIO_PIN1,
		.dc_pin[1].logic = LOW};
motor_cnfg_t  Dc_motor2 = {.dc_pin[0].port = PORTC, .dc_pin[0].pin = GPIO_PIN2,
		.dc_pin[0].logic = LOW,
		.dc_pin[1].port = PORTC, .dc_pin[1].pin = GPIO_PIN3,
		.dc_pin[1].logic = LOW};
 ************************************/
 
/************************************
 * MACROS AND DEFINES
 ************************************/





/************************************
 * TYPEDEFS
 ************************************/



typedef enum{
	MOTOR_ON,
	MOTOR_OFF
}motor_state_t;

typedef struct
{
	Gpio_pin_config_t    dc_pin[2];
}motor_cnfg_t;

/************************************
 * EXPORTED VARIABLES
 ************************************/





/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

Std_ReturnType  Dc_Motor_Inialize(motor_cnfg_t * motor_obj);
Std_ReturnType  Dc_Motor_Forward(motor_cnfg_t * motor_obj);
Std_ReturnType  Dc_Motor_Backward(motor_cnfg_t * motor_obj);
Std_ReturnType  Dc_Motor_Stop(motor_cnfg_t * motor_obj);


#endif

