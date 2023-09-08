/**
 ********************************************************************************
 * @file    Mcal_Std.h
 * @author  Abo Drda
 * @date    Jul 29, 2023
 * @brief   
 ********************************************************************************
 */

#ifndef MCAL_LAYER_MCAL_COMMON_MCAL_STD_H_
#define MCAL_LAYER_MCAL_COMMON_MCAL_STD_H_

/*****************  INCLUDES   *******************************/

#include <stdio.h>
#include <stdlib.h>
#include "util/delay.h"

#define ACCESS_REG(REG)                 (*(volatile uint8 * )(REG))
#define SET_BIT(REG, BIT_NUM)           (REG |=(1<<(BIT_NUM)))
#define CLEAR_BIT(REG, BIT_NUM)         (REG &=~(1<<BIT_NUM))
#define TOGGLE_BIT(REG, BIT_NUM)        (REG ^=(1<<BIT_NUM))
#define READ_BIT(REG, BIT_NUM)          ((REG >>BIT_NUM)&(0X01))

#define SET_REG(REG)                    (ACCESS_REG(REG) = 0XFF)
#define CLEAR_REG(REG)                  (ACCESS_REG(REG) = 0X00)


/* Section: Data Type Declarations */

typedef   unsigned char              uint8;
typedef   signed char                suint8;
typedef   unsigned short             uint16;
typedef   signed short               sint16;
typedef   unsigned int               uint32;
typedef   signed int                 suint32;

typedef   uint8                Std_ReturnType;

/* Section: Macro Declarations */
#define E_OK                 (Std_ReturnType)0x00
#define E_NOK                (Std_ReturnType)0x01

#define ZERO_INIT            (uint8)0x00



					/*****************  PRIVATE TYPEDEFS   ***********************/


#endif

