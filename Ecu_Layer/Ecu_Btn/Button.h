/*******************************************************************************
 * @file    Button.h
 * @author  Abo Drda
 * @date    Jul 29, 2023
 * @brief   
 ******************************************************************************/

#ifndef ECU_LAYER_ECU_BTN_BUTTON_H_
#define ECU_LAYER_ECU_BTN_BUTTON_H_

/*****************  Includes ********************************/
#include "../../Mcal_Layer/Mcal_Gpio/Mcal_Gpio_Interface.h"

/*
button_t  btn1 ={.button_pin.port = PORTD,.button_pin.pin = GPIO_PIN3,
		.button_state = BUTTON_RELEASED,.button_connection = BUTTON_ACTIVE_HIGH};
 */

/*******************************/

typedef enum{
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct{
    Gpio_pin_config_t button_pin;
    button_state_t button_state;
    button_active_t button_connection;
}button_t;




/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
Std_ReturnType button_initialize(const button_t *btn);

Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state);

#endif

