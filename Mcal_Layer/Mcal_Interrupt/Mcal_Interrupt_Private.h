/**
 ********************************************************************************
 * @file    Mcal_Private.h
 * @author  Abo Drda
 * @date    Jul 29, 2023
 * @brief   
 ********************************************************************************
 */

#ifndef MCAL_LAYER_MCAL_INTERRUPT_MCAL_INTERRUPT_PRIVATE_H_
#define MCAL_LAYER_MCAL_INTERRUPT_MCAL_INTERRUPT_PRIVATE_H_

/*****************  INCLUDES   *******************************/
#include "../Mcal_Common/Mcal_Std.h"
#include "../Mcal_Common/M_Atmega32_Reg.h"


/******************** * MACROS AND DEFINES **********************/
#define INTERRUPT_GLOBAL_ENABLE()       (SREG_reg->I = 1)
#define INTERRUPT_GLOBAL_DISABLE()      (SREG_reg->I = 0)

#define INTERRUPT_EXT_INT0_ENABLE()       (GICR_reg->INT0 = 1)
#define INTERRUPT_EXTERNAL_INT1_ENABLE()  (GICR_reg->INT1 = 1)
#define INTERRUPT_EXTERNAL_INT2_ENABLE()  (GICR_reg->INT2 = 1)

#define INTERRUPT_EXTERNAL_INT0_DISABLE()  (GICR_reg->INT0 = 0)
#define INTERRUPT_EXTERNAL_INT1_DISABLE()  (GICR_reg->INT1 = 0)
#define INTERRUPT_EXTERNAL_INT2_DISABLE()  (GICR_reg->INT2 = 0)

#define INTERRUPT0_CLEAR_FLAGE()  (GIFR_reg->INTF0 = 1)
#define INTERRUPT1_CLEAR_FLAGE()  (GIFR_reg->INTF1 = 1)
#define INTERRUPT2_CLEAR_FLAGE()  (GIFR_reg->INTF2 = 1)

/* interrupt 0 macros to set sense */
#define INTERRUPT0_LOW_LEVEL_ENABLE()      {\
	MCUCR_reg->ISC00 =0;\
	MCUCR_reg->ISC01 =0;\
}
#define INTERRUPT0_LOGICAL_CHANGE_ENABLE() {\
	MCUCR_reg->ISC00 =1;\
	MCUCR_reg->ISC01 =0;\
	}
#define INTERRUPT0_FALLING_EDGE_ENABLE()   {MCUCR_reg->ISC00 =0;\
	MCUCR_reg->ISC01 =1;}
#define INTERRUPT0_RISING_EDGE_ENABLE()    {MCUCR_reg->ISC00 =1;\
	MCUCR_reg->ISC01 =1;}


/* interrupt 1 macros to set sense */
#define INTERRUPT1_LOW_LEVEL_ENABLE()      {MCUCR_reg->ISC10 =0;\
	MCUCR_reg->ISC11 =0;}
#define INTERRUPT1_LOGICAL_CHANGE_ENABLE() {MCUCR_reg->ISC10 =1;\
	MCUCR_reg->ISC11 =0;}
#define INTERRUPT1_FALLING_EDGE_ENABLE()   {MCUCR_reg->ISC10 =0;\
	MCUCR_reg->ISC11 =1;}
#define INTERRUPT1_RISING_EDGE_ENABLE()    {MCUCR_reg->ISC10 =1;\
	MCUCR_reg->ISC11 =1;}


/* interrupt 2 macros to set sense */
#define INTERRUPT2_FALLING_EDGE_ENABLE()   (MCUCSR_reg->ISC2 = 0)
#define INTERRUPT2_RISING_EDGE_ENABLE()    (MCUCSR_reg->ISC2 = 1)


#endif

