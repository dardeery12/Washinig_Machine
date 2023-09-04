/**
 ********************************************************************************
 * @file    btn.c
 * @author  Abdo Drd
 * @date    Jun 22, 2023
 * @brief   
 ********************************************************************************
 */

/************************************ INCLUDES************************************/
#include "../Ecu_Maneger/Maneger.h"
#if BTN_MODULE_ENABLE == ENABLE
#include "Button.h"

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
/**
 *
 * @param btn
 * @return
 */
Std_ReturnType button_initialize(const button_t *btn){
    Std_ReturnType ret = E_OK;
    if(NULL == btn){
        ret = E_NOK;
    }
    else{
        ret = gpio_pin_direction_initialize(&(btn->button_pin), GPIO_PIN_INPOT);
    }
    return ret;
}

/**
 * @brief Read the state of the button
 * @param btn pointer to the button configurations
 * @param btn_state button state @ref button_state_t
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOK) : The function has issue while performing this action
 */
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state){
    Std_ReturnType ret = E_NOK;
    logic_t btn_Logic_Status = LOW;
    Gpio_pin_config_t loc_pin ={.port = btn->button_pin.port, .pin = btn->button_pin.pin};
    if((NULL == btn) || (NULL == btn_state)){
        ret = E_NOK;
    }
    else{
    	gpio_pin_read(&loc_pin, &btn_Logic_Status);
        if(BUTTON_ACTIVE_HIGH == btn->button_connection){
            if(HIGH == btn_Logic_Status){
                *btn_state = BUTTON_PRESSED;
            }
            else{
                *btn_state = BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == btn->button_connection){
            if(HIGH == btn_Logic_Status){
                *btn_state = BUTTON_RELEASED;
            }
            else{
                *btn_state = BUTTON_PRESSED;
            }
        }
        else { /* Nothing */ }
        ret = E_OK;
    }
    return ret;
}

#endif
