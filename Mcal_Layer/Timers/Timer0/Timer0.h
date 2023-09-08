/*******************************************************************************
 * @file    Timer0.h
 * @author  Abo Drda
 * @date    Sep 2, 2023
 * @brief   
 ******************************************************************************/

#ifndef TIMER0_TIMER0_H_
#define TIMER0_TIMER0_H_

/*****************  Includes ********************************/
#include "../../Mcal_Common/M_Atmega32_Reg.h"

#define PRESCALLER_1024()     {\
							TCCR0_reg->CS00 =1; \
							TCCR0_reg->CS01 =0; \
							TCCR0_reg->CS02 =1; \
	}
#define TIMERO_NO_CLCK()     {\
							TCCR0_reg->CS00 =0; \
							TCCR0_reg->CS01 =0; \
							TCCR0_reg->CS02 =0; \
	}
#define TIMER0_OFV_INTERRUPT_ENABLE()      (TIMSK_reg->TOIE0 =1)


#define TIMER0_CLEAR_FLAG()      (TIFR_reg->TOV0 =1)
/*****************  GLOBAL FUNCTIONS   ***********************/

void Timer0_Init(void);
Std_ReturnType Timer0_Start(void);
Std_ReturnType Timer0_Stop(void);
void Timer0_Calculate_Sec(uint8 * Second);
void Timer0_Calculate_Min_And_Sec(uint8 * Sec, uint8 * Minuts);
Std_ReturnType Timer0_Check_Available();

#endif

