/*******************************************************************************
 * @file    Timer0_private.h
 * @author  Abo Drda
 * @date    Sep 8, 2023
 * @brief   
 ******************************************************************************/

#ifndef MCAL_LAYER_TIMERS_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_LAYER_TIMERS_TIMER0_TIMER0_PRIVATE_H_

#include "../../Mcal_Common/M_Atmega32_Reg.h"

#define PRESCALLER_1024()     {\
							TCCR0_reg->CS00 =1; \
							TCCR0_reg->CS01 =0; \
							TCCR0_reg->CS02 =1; \
	}
#define EXTERNAL_CLCK_SOURCE_RISING_EDGE()     {\
							TCCR0_reg->CS00 =1; \
							TCCR0_reg->CS01 =1; \
							TCCR0_reg->CS02 =1; \
	}
#define TIMERO_NO_CLCK()     {\
							TCCR0_reg->CS00 =0; \
							TCCR0_reg->CS01 =0; \
							TCCR0_reg->CS02 =0; \
	}
#define TIMER0_OFV_INTERRUPT_ENABLE()      (TIMSK_reg->TOIE0 =1)


#define TIMER0_CLEAR_FLAG()      (TIFR_reg->TOV0 =1)

#endif

