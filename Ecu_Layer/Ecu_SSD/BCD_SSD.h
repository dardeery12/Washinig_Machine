/**
 ********************************************************************************
 * @file    BCD_SSD.h
 * @author  Abo Drda
 * @date    Jun 30, 2023
 * @brief   
 ********************************************************************************
 */

#ifndef ECU_LAYER_HEADER_BCD_SSD_H_
#define ECU_LAYER_HEADER_BCD_SSD_H_


/************************************
 * INCLUDES
 ************************************/

#include "../../Mcal_Layer/Mcal_Gpio/Mcal_Gpio_Interface.h"


/**
 * SSD_BCD_cnfg_t ssd1 ={.pins_cnfg[0].port = PORTA , .pins_cnfg[0].pin = GPIO_PIN1 ,
					  .pins_cnfg[1].port = PORTA , .pins_cnfg[1].pin = GPIO_PIN2 ,
		              .pins_cnfg[2].port = PORTA , .pins_cnfg[2].pin = GPIO_PIN3 ,
					  .pins_cnfg[3].port = PORTA , .pins_cnfg[3].pin = GPIO_PIN4 ,
					  .ctrl_pin.port = PORTC, .ctrl_pin.pin = GPIO_PIN7};
 */


/************************************
 * MACROS AND DEFINES
 ************************************/





/************************************
 * TYPEDEFS
 ************************************/
typedef struct
{
	Gpio_pin_config_t   pins_cnfg [4];
	Gpio_pin_config_t   ctrl_pin;

}SSD_BCD_cnfg_t;



/************************************
 * EXPORTED VARIABLES
 ************************************/





/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/



Std_ReturnType SSD_BCD_Inialize(SSD_BCD_cnfg_t * ssd_obj);
Std_ReturnType SSD_BCD_Print_Num(SSD_BCD_cnfg_t * ssd_obj, uint8 Num);
Std_ReturnType SSD_BCD_Print_char(SSD_BCD_cnfg_t * ssd_obj);
Std_ReturnType SSD_BCD_Enable(SSD_BCD_cnfg_t * ssd_obj);
Std_ReturnType SSD_BCD_Disable(SSD_BCD_cnfg_t * ssd_obj);

#endif

