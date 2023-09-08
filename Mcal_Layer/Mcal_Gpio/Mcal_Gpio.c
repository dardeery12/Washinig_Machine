/**
 ********************************************************************************
 * @file    Mcal_Gpio.c
 * @author  Drd
 * @date    Jul 29, 2023
 * @brief   
 ********************************************************************************
 */

/*****************  INCLUDES   *******************************/
#include "../Mcal_Maneger/Mcal_Maneger.h"
#if   GPIO_MODULE_ACTIVE == ENABLE
#include"Mcal_Gpio_Interface.h"
Std_ReturnType gpio_pin_direction_initialize(const Gpio_pin_config_t * pin_cnfg, direction_t dir) {
	Std_ReturnType ret = E_NOK;
	if (NULL == pin_cnfg) {
		ret = E_NOK;
	} else {
		switch (dir) {
		case GPIO_PIN_OUTPOT:
			SET_BIT(ACCESS_REG((pin_cnfg->port) + 1), pin_cnfg->pin);
			break;
		case GPIO_PIN_INPOT:
			CLEAR_BIT(ACCESS_REG((pin_cnfg->port) + 1), pin_cnfg->pin);
			break;

		default:
			ret = E_NOK;
		}

	}
	return ret;
}
/**
 *
 * @param pin_cnfg
 * @param logic
 * @return
 */
Std_ReturnType gpio_pin_get_direction_status(const Gpio_pin_config_t * pin_cnfg, logic_t * logic) {
	Std_ReturnType ret = E_OK;
	if ((NULL == pin_cnfg) || (NULL == logic)) {
		ret = E_NOK;
	} else {
		*logic = READ_BIT(ACCESS_REG((pin_cnfg->port) + 1), pin_cnfg->pin);

	}
	return ret;
}
/**
 *
 * @param pin_cnfg
 * @param logic
 * @return
 */
Std_ReturnType gpio_pin_write_logic(const Gpio_pin_config_t * pin_cnfg, logic_t logic) {
	Std_ReturnType ret = E_OK;
	if (NULL == pin_cnfg) {
		ret = E_NOK;
	} else {
		switch (logic) {
		case HIGH:
			SET_BIT(ACCESS_REG((pin_cnfg->port) + 2), pin_cnfg->pin);
			break;
		case LOW:
			CLEAR_BIT(ACCESS_REG((pin_cnfg->port) + 2), pin_cnfg->pin);
			break;

		default:
			ret = E_NOK;
		}
	}
	return ret;
}
/**
 *
 * @param pin_cnfg
 * @param logic
 * @return
 */
Std_ReturnType gpio_pin_read(const Gpio_pin_config_t * pin_cnfg, logic_t * logic) {
	Std_ReturnType ret = E_OK;
	if ((NULL == pin_cnfg) || (NULL == logic)) {
		ret = E_NOK;
	} else {
		*logic = READ_BIT(ACCESS_REG(pin_cnfg->port), pin_cnfg->pin);

	}
	return ret;
}
/**
 *
 * @param pin_cnfg
 * @return
 */
Std_ReturnType gpio_pin_toggle(const Gpio_pin_config_t * pin_cnfg) {
	Std_ReturnType ret = E_OK;
	if (NULL == pin_cnfg) {
		ret = E_NOK;
	} else {
		TOGGLE_BIT(ACCESS_REG((pin_cnfg->port) + 2), pin_cnfg->pin);
	}
	return ret;
}

/**
 *
 * @param pin_cnfg
 * @return
 */
Std_ReturnType gpio_pin_initialize(const Gpio_pin_config_t * pin_cnfg) {
	Std_ReturnType ret = E_OK;
	if (NULL == pin_cnfg) {
		ret = E_NOK;
	} else {
		ret = gpio_pin_direction_initialize(pin_cnfg, pin_cnfg->direction);
		ret = gpio_pin_write_logic(pin_cnfg, pin_cnfg->logic);

	}
	return ret;
}
/**
 *
 * @param port
 * @param direction
 * @return
 */
Std_ReturnType gpio_port_direction_initialize(port_index_t port, direction_t direction) {
	Std_ReturnType ret = E_OK;
	switch (direction) {
	case GPIO_PIN_OUTPOT:
		SET_REG(port+1);
		break;
	case GPIO_PIN_INPOT:
		CLEAR_REG(port+1);
		break;
	default:
		ret = E_NOK;

	}
	return ret;
}

/**
 *
 * @param port
 * @param direction_status
 * @return
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status)
{
	Std_ReturnType ret = E_OK;

	return ret;
}

/**
 *
 * @param port
 * @param logic
 * @return
 */
Std_ReturnType gpio_port_write_logic(port_index_t port, logic_t logic)
		{
	Std_ReturnType ret = E_NOK;
	if((port == PORTA) ||(port == PORTB) ||(port == PORTC) ||(port == PORTD)  )
	{
		if((logic >255) || (logic < 0))
		{
			ret = E_NOK;
		}
		else
		{
			ACCESS_REG(port +2) = logic;

			ret = E_OK;
		}

	}
	else
	{
		ret = E_NOK;
	}

	return ret;
		}
/**
 *
 * @param port
 * @param logic
 * @return
 */
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic)
{
	Std_ReturnType ret = E_OK;

	return ret;
}
/**
 *
 * @param port
 * @return
 */
Std_ReturnType gpio_port_toggle_logic(port_index_t port)
{
	Std_ReturnType ret = E_OK;

	return ret;
}


#endif
