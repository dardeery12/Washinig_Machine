/*******************************************************************************
 * @file    motor_dc.h
 * @author  Abo Drda
 * @date    Sep 8, 2023
 * @brief   
 ******************************************************************************/

#ifndef MOTOR_DC_H_
#define MOTOR_DC_H_

/** ex to use
 * Motor_Cnfg_t Motor1 ={.motor_pin_config.port = PORTA, .motor_pin_config.pin = GPIO_PIN0};
   =============> G_Motor_Run_Flag = E_OK;
                  Motor_Init(&Motor1);
 */


/*****************  Includes ********************************/
#include "../../Mcal_Layer/Mcal_Maneger/Mcal_Maneger.h"
/***************** types  ************************/
typedef enum
{
	MOTOR_STOP,
	MOTOR_RUN,
}Motor_Stat_t;
typedef struct
{
	Gpio_pin_config_t motor_pin_config;
	Motor_Stat_t      motor_init_stat :1;
}Motor_Cnfg_t;
/*****************  GLOBAL VARIABLES   ***********************/
/*  to run motor the G_Motor_Run_Flag must be = E_OK
 * and to stop motor the G_Motor_Run_Flag must be = E_NOK*/
//extern Std_ReturnType G_Motor_Run_Flag;

/*****************  GLOBAL FUNCTIONS   ***********************/

Std_ReturnType Motor_Init(Motor_Cnfg_t * motor_obj);
Std_ReturnType Motor_Run(Motor_Cnfg_t * motor_obj);
Std_ReturnType Motor_Stop(Motor_Cnfg_t * motor_obj);
Motor_Stat_t   Motor_Get_Stat(Motor_Cnfg_t * motor_obj);

#endif

