/**
 ********************************************************************************
 * @file    BCD_SSD.c
 * @author  Abdo Drd
 * @date    Jun 30, 2023
 * @brief   
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "../Ecu_Maneger/Maneger.h"
#if BCD_MODULE_ENABLE == ENABLE
#include"BCD_SSD.h"


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
static Gpio_pin_config_t  PIN_CONTROL ;


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

Std_ReturnType SSD_BCD_Inialize(SSD_BCD_cnfg_t * ssd_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == ssd_obj)
	{
		ret = E_NOK;
	}
	else
	{
		ret = gpio_pin_direction_initialize(&(ssd_obj->pins_cnfg[0]), GPIO_PIN_OUTPOT);
		ret = gpio_pin_direction_initialize(&(ssd_obj->pins_cnfg[1]), GPIO_PIN_OUTPOT);
		ret = gpio_pin_direction_initialize(&(ssd_obj->pins_cnfg[2]), GPIO_PIN_OUTPOT);
		ret = gpio_pin_direction_initialize(&(ssd_obj->pins_cnfg[3]), GPIO_PIN_OUTPOT);

		ret = gpio_pin_direction_initialize(&(ssd_obj->ctrl_pin), GPIO_PIN_OUTPOT);
	}

	return ret;
}
Std_ReturnType SSD_BCD_Print_Num(SSD_BCD_cnfg_t * ssd_obj, uint8 Num)
{
	Std_ReturnType ret = E_NOK;
	if((NULL == ssd_obj) || ( Num > 9) || (Num < 0 ))
	{
		ret = E_NOK;
	}
	else
	{
		gpio_pin_write_logic(&(ssd_obj->pins_cnfg[0]), (Num >> 0) & (0x01));
		gpio_pin_write_logic(&(ssd_obj->pins_cnfg[1]), (Num >> 1) & (0x01));
		gpio_pin_write_logic(&(ssd_obj->pins_cnfg[2]), (Num >> 2) & (0x01));
		gpio_pin_write_logic(&(ssd_obj->pins_cnfg[3]), (Num >> 3) & (0x01));
		ret = E_OK;
	}

	return ret;
}
Std_ReturnType SSD_BCD_Print_char(SSD_BCD_cnfg_t * ssd_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == ssd_obj)
	{
		ret = E_NOK;
	}
	else
	{


		ret = E_OK;
	}

	return ret;
}

Std_ReturnType SSD_BCD_Enable(SSD_BCD_cnfg_t * ssd_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == ssd_obj)
	{
		ret = E_NOK;
	}
	else
	{
		PIN_CONTROL =ssd_obj->ctrl_pin;

		gpio_pin_write_logic(&PIN_CONTROL, HIGH);
		ret = E_OK;
	}

	return ret;
}
Std_ReturnType SSD_BCD_Disable(SSD_BCD_cnfg_t * ssd_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == ssd_obj)
	{
		ret = E_NOK;
	}
	else
	{
		PIN_CONTROL = ssd_obj->ctrl_pin;
		gpio_pin_write_logic(&PIN_CONTROL, LOW);
		ret = E_OK;
	}

	return ret;
}
#endif
