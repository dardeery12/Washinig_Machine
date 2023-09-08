/*******************************************************************************
 * @file    Maneger.h
 * @author  Abo Drda
 * @date    Aug 7, 2023
 * @brief   
 ******************************************************************************/

#ifndef ECU_LAYER_ECU_MANEGER_MANEGER_H_
#define ECU_LAYER_ECU_MANEGER_MANEGER_H_

/*****************  Includes ********************************/

#include "Ecu_Cnfg.h"

#include "../../Mcal_Layer/Mcal_Maneger/Mcal_Maneger.h"
#include"../Ecu_Initialization/Ecu_Init.h"

/***********************************************************/
#if CHAR_LCD_MODULE_ENABLE   == ENABLE
#include"../Ecu_Char_Lcd/char_lcd.h"
#endif
/***********************************************************/

#if  LED_MODULE_ENABLE  == ENABLE
#include"../Ecu_led/led.h"
#endif
/***********************************************************/
#if BTN_MODULE_ENABLE == ENABLE
#include"../Ecu_Btn/Button.h"
#endif
/***********************************************************/
#if RELAY_MODULE_ENABLE == ENABLE
#include"../Ecu_Relay/relay.h"
#endif
/***********************************************************/
#if MOTOR_MODULE_ENABLE == ENABLE
#include"../Ecu_Dc_Motor/motor_dc.h"
#endif
/***********************************************************/
#if SSD_MODULE_ENABLE == ENABLE
#include"../Ecu_SSD/SSD.h"
#endif
/***********************************************************/
#if SSD_BCD_ENABLE == ENABLE
#include"../Ecu_SSD/BCD_SSD.h"
#endif
/***********************************************************/
/*
#if    == ENABLE
#include
#endif
#if    == ENABLE
#include
#endif
#if    == ENABLE
#include
#endif
#if    == ENABLE
#include
#endif
*/
#endif

