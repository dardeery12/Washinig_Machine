/**
 ********************************************************************************
 * @file    Mcal_Gpio_Interface.h
 * @author  Abdo Drd
 * @date    Jul 29, 2023
 * @brief   
 ********************************************************************************
 */

#ifndef MCAL_LAYER_MCAL_GPIO_MCAL_GPIO_INTERFACE_H_
#define MCAL_LAYER_MCAL_GPIO_MCAL_GPIO_INTERFACE_H_

/*****************  INCLUDES   *******************************/
#include "Mcal_Gpio_Cnfg.h"
#include "../Mcal_Common/Mcal_Std.h"


/* Section: Data Type Declarations */

typedef enum {
	PORTA = 0x39,
	PORTB = 0x36,
	PORTC = 0x33,
	PORTD = 0x30,
}port_index_t;

typedef enum{
	GPIO_PIN0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7
}pin_index_t;

typedef enum{
	GPIO_PIN_OUTPOT,
	GPIO_PIN_INPOT
}direction_t;

typedef enum{
	LOW = 0,
	HIGH
}logic_t;

typedef struct {
	port_index_t   port ;           /* @ref port_index_t */
	pin_index_t    pin : 3;         /* @ref pin_index_t */
	direction_t    direction : 1;   /* @ref direction_index_t */
	logic_t        logic : 1;       /* @ref logic */
}Gpio_pin_config_t;


Std_ReturnType gpio_pin_direction_initialize(const Gpio_pin_config_t * pin_cnfg, direction_t dir);
Std_ReturnType gpio_pin_get_direction_status(const Gpio_pin_config_t * pin_cnfg, logic_t * logic);
Std_ReturnType gpio_pin_write_logic(const Gpio_pin_config_t * pin_cnfg,  logic_t logic);
Std_ReturnType gpio_pin_read(const Gpio_pin_config_t * pin_cnfg ,logic_t * logic);
Std_ReturnType gpio_pin_toggle(const Gpio_pin_config_t * pin_cnfg);
Std_ReturnType gpio_pin_initialize(const Gpio_pin_config_t * pin_cnfg);
Std_ReturnType gpio_pin_get_status( Gpio_pin_config_t * pin_cnfg);


Std_ReturnType gpio_port_direction_initialize(port_index_t port, direction_t direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status);
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port);


#endif

