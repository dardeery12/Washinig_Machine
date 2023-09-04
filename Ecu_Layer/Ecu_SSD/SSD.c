/**
 ********************************************************************************
 * @file    7sement.c
 * @author  Abdo Drd
 * @date    Jun 23, 2023
 * @brief   
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "../Ecu_Maneger/Maneger.h"
#if SSD_MODULE_ENABLE == ENABLE

#include "../../Mcal_Layer/Mcal_Gpio/Mcal_Gpio_Interface.h"
#include "../../Mcal_Layer/Mcal_Common/Mcal_Std.h"
#include "SSD.h"
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

/* common  cathode */
static const uint8 SSD_Pattern[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92, 0x82,0xF8,0x80,0x90};


/************************************
 * GLOBAL VARIABLES
 ************************************/



/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

static Gpio_pin_config_t PIN_CONTROL ;

/************************************
 * STATIC FUNCTIONS
 ************************************/



/************************************
 * GLOBAL FUNCTIONS
 ************************************/
Std_ReturnType SSD_Inialize(SSD_cnfg_t * ssd_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == ssd_obj)
	{
		ret = E_NOK;
	}
	else
	{
		uint8 Loc_Counter =1 ;
		for(Loc_Counter = 1; Loc_Counter < 9; ++Loc_Counter)
		{
			ssd_obj->pin.pin = Loc_Counter;
			gpio_pin_direction_initialize(&(ssd_obj->pin), GPIO_PIN_OUTPOT);

		}

		gpio_pin_direction_initialize(&(ssd_obj->ctrl_pin), GPIO_PIN_OUTPOT);

		ret = E_OK;
	}

	return ret;
}
Std_ReturnType SSD_Print_Num(SSD_cnfg_t * ssd_obj, uint8 Num)
{
	Std_ReturnType ret = E_NOK;
	if((NULL == ssd_obj) || (Num >9) || (Num < 0))
	{
		ret = E_NOK;
	}
	else
	{

		if(COMMON_ANODE == ssd_obj->ssd_type )
		{
			gpio_port_write_logic(ssd_obj->pin.port, SSD_Pattern[Num] << 1 );
		}
		else if(COMMON_CATHOD == ssd_obj->ssd_type )
		{
			gpio_port_write_logic(ssd_obj->pin.port, (~SSD_Pattern[Num]) << 1);
		}
		else
		{
			ret = E_NOK;
		}

		ret = E_OK;

	}

	return ret;
}

Std_ReturnType SSD_Enable(SSD_cnfg_t * ssd_obj)
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
Std_ReturnType SSD_Disable(SSD_cnfg_t * ssd_obj)
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

Std_ReturnType SSD_2Digit_Inialize(SSD_2Digit_t * ssd_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == ssd_obj)
	{
		ret = E_NOK;
	}
	else
	{
		SSD_Inialize(&(ssd_obj->SSD[0]));
		SSD_Inialize(&(ssd_obj->SSD[1]));
	}

	return ret;
}

Std_ReturnType SSD_Print_2Digit(SSD_2Digit_t * ssd_obj, uint8 Num)
{
	Std_ReturnType ret = E_NOK;
	uint8 Loc_Num1 = Num  % 10;
	uint8 Loc_Num2 = Num  / 10;
	if(NULL == ssd_obj)
	{
		ret = E_NOK;
	}
	else
	{
		SSD_Enable(&(ssd_obj->SSD[0]));
		SSD_Print_Num(&(ssd_obj->SSD[0]), Loc_Num1);
		_delay_ms(10);
		SSD_Disable(&(ssd_obj->SSD[0]));

		SSD_Enable(&(ssd_obj->SSD[1]));
		SSD_Print_Num(&(ssd_obj->SSD[1]), Loc_Num2);
		_delay_ms(10);
		SSD_Disable(&(ssd_obj->SSD[1]));

	}

	return ret;
}
#endif
