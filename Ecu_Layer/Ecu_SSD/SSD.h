/**
 ********************************************************************************
 * @file    7sement.h
 * @author  Abo Drda
 * @date    Jun 23, 2023
 * @brief   
 ********************************************************************************
 */

#ifndef ECU_LAYER_HEADER_7SEMENT_H_
#define ECU_LAYER_HEADER_7SEMENT_H_


/************************************
 * INCLUDES
 ************************************/
 
 
#include "../../Mcal_Layer/Mcal_Gpio/Mcal_Gpio_Interface.h"
 #include"SSD_cnfg.h"
 
 
/************************************
 * MACROS AND DEFINES
 ************************************/





/************************************
 * TYPEDEFS
 ************************************/

typedef enum
{
	COMMON_CATHOD,
	COMMON_ANODE
}SSD_type_t;

typedef struct
{

	Gpio_pin_config_t   pin;
	SSD_type_t     ssd_type;
	Gpio_pin_config_t   ctrl_pin;
}SSD_cnfg_t;

typedef struct
{
	SSD_cnfg_t  SSD[2];
}SSD_2Digit_t;

/************************************
 * EXPORTED VARIABLES
 ************************************/





/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

Std_ReturnType SSD_Inialize(SSD_cnfg_t * ssd_obj);
Std_ReturnType SSD_Print_Num(SSD_cnfg_t * ssd_obj, uint8 Num);
Std_ReturnType SSD_Disable(SSD_cnfg_t * ssd_obj);
Std_ReturnType SSD_Enable(SSD_cnfg_t * ssd_obj);

Std_ReturnType SSD_Print_2Digit(SSD_2Digit_t * ssd_obj, uint8 Num);
Std_ReturnType SSD_2Digit_Inialize(SSD_2Digit_t * ssd_obj);


#endif

