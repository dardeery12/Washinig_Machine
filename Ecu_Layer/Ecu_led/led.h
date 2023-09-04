/**
 ********************************************************************************
 * @file    led.h
 * @author  abdo drd
 * @date    22/6/2023
 * @brief
 ********************************************************************************
 */

#ifndef _LED_H_
#define _LED_H_



/************************************
 * INCLUDES
 ************************************/

#include "../../Mcal_Layer/Mcal_Gpio/Mcal_Gpio_Interface.h"


/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/


typedef enum{
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct{
	port_index_t port;
    pin_index_t pin : 3;
    led_status_t status : 1;
}led_t;
/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

Std_ReturnType led_inialize(led_t * led);
Std_ReturnType led_turn_on(led_t * led);
Std_ReturnType led_turn_off(led_t * led);
Std_ReturnType led_Toggle(led_t * led);
Std_ReturnType led_blinking(led_t * led);

#endif
