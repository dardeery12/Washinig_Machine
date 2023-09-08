/**
 ********************************************************************************
 * @file    led.c
 * @author  Abdo Drd
 * @date    22/6/2023
 * @brief
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "../Ecu_Maneger/Maneger.h"

#if LED_MODULE_ENABLE == ENABLE
#include "led.h"
#define Delay_ms(x)        _delay_ms(x)

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
/**
 *
 * @param led
 * @return
 */
Std_ReturnType led_inialize(led_t * led)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == led)
	{
		ret = E_NOK;
	}
	else
	{
		Gpio_pin_config_t  led_pin ={.port = led->port, .pin = led->pin,
				.direction = GPIO_PIN_OUTPOT, .logic = led->status};
		gpio_pin_initialize(&led_pin);
		ret = E_OK;
	}

	return ret;
}
/**
 *
 * @param led
 * @return
 */
Std_ReturnType led_turn_on(led_t * led)
{
	Std_ReturnType ret = E_NOK;

	Gpio_pin_config_t  loc_pin = {.port = led->port,
			.pin = led->pin, .logic = HIGH};
	if(NULL == led)
	{
		ret = E_NOK;
	}
	else
	{
		gpio_pin_write_logic(&loc_pin, HIGH);

		ret = E_OK;
	}

	return ret;
}
/**
 *
 * @param led
 * @return
 */
Std_ReturnType led_turn_off(led_t * led)
{
	Std_ReturnType ret = E_NOK;

	Gpio_pin_config_t  loc_pin = {.port = led->port,
			.pin = led->pin, .logic = LOW};
	if(NULL == led)
	{
		ret = E_NOK;
	}
	else
	{
		gpio_pin_write_logic(&loc_pin, LOW);

		ret = E_OK;
	}

	return ret;
}
/**
 *
 * @param led
 * @return
 */
Std_ReturnType led_toggle(led_t * led)
{
	Std_ReturnType ret = E_NOK;

	Gpio_pin_config_t  loc_pin = {.port = led->port,
			.pin = led->pin, .logic = LOW};
	if(NULL == led)
	{
		ret = E_NOK;
	}
	else
	{
		gpio_pin_toggle(&loc_pin);

		ret = E_OK;
	}

	return ret;
}

Std_ReturnType led_blinking(led_t * led)
{
	Std_ReturnType ret = E_NOK;
	uint8 Loc_Counter = ZERO_INIT;
	if(NULL == led)
	{
		ret = E_NOK;
	}
	else
	{
		for(Loc_Counter = 0; Loc_Counter < 20; ++Loc_Counter)
		{
			gpio_pin_toggle(led);
			Delay_ms(50);
		}
		ret = E_OK;
	}

	return ret;
}

Std_ReturnType led_Toggle(led_t * led)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == led)
	{
		ret = E_NOK;
	}
	else
	{
		gpio_pin_toggle(led);

		ret = E_OK;
	}

	return ret;
}
#endif
