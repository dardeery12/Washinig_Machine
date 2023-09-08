/**
 ********************************************************************************
 * @file    M_Atmega32_Reg.h
 * @author  Abo Drda
 * @date    Jul 29, 2023
 * @brief   
 ********************************************************************************
 */

#ifndef MCAL_LAYER_MCAL_COMMON_M_ATMEGA32_REG_H_
#define MCAL_LAYER_MCAL_COMMON_M_ATMEGA32_REG_H_

/*****************  INCLUDES   *******************************/
#include "Mcal_Std.h"

/*****************  TYPEDEFS   *************************/

typedef struct
{
	uint8 PIN0    			 : 1;
	uint8 PIN1   			 : 1;
	uint8 PIN2				 : 1;
	uint8 PIN3    			 : 1;
	uint8 PIN4   			 : 1;
	uint8 PIN5    			 : 1;
	uint8 PIN6   			 : 1;
	uint8 PIN7     			 : 1;
}PORTA_reg_t;

typedef struct
{
	uint8 IVCE    			 : 1;
	uint8 IVSEL   			 : 1;
	uint8 RESERVED			 : 3;
	uint8 INT2    			 : 1;
	uint8 INT0   			 : 1;
	uint8 INT1    			 : 1;
}GICR_reg_t;


typedef struct
{
	uint8 RSERVED    		 : 5;
	uint8 INTF2    			 : 1;
	uint8 INTF0   			 : 1;
	uint8 INTF1     		 : 1;
}GIFR_reg_t;
typedef struct
{
	uint8 ISC00    			 : 1;
	uint8 ISC01   			 : 1;
	uint8 ISC10				 : 1;
	uint8 ISC11    			 : 1;
	uint8 SM0   			 : 1;
	uint8 SM1    			 : 1;
	uint8 SM2   			 : 1;
	uint8 SE     			 : 1;
}MCUCR_reg_t;

typedef struct
{
	uint8 PORF    			 : 1;
	uint8 EXTRF   			 : 1;
	uint8 BORF				 : 1;
	uint8 WDRF    			 : 1;
	uint8 JTRF   			 : 1;
	uint8 RSERVED    		 : 1;
	uint8 ISC2   			 : 1;
	uint8 JTD     			 : 1;
} MCUCSR_reg_t;

typedef struct
{
	uint8 C    			 : 1;
	uint8 Z   			 : 1;
	uint8 N				 : 1;
	uint8 V    			 : 1;
	uint8 S   			 : 1;
	uint8 H    			 : 1;
	uint8 T   			 : 1;
	uint8 I     		 : 1;
} SREG_reg_t;
/*************************************************************/
/**Timers Registers **/
#define  TCNT0_reg   *(volatile uint8 *)0x52
typedef struct
{
	uint8 TOIE0    			 : 1;
	uint8 OCIE0   			 : 1;
	uint8 TOIE1				 : 1;
	uint8 OCIE1B    		 : 1;
	uint8 OCIE1A   			 : 1;
	uint8 TICIE1    		 : 1;
	uint8 TOIE2   			 : 1;
	uint8 OCIE2     		 : 1;
}TIMSK_reg_t;

typedef struct
{
	uint8 TOV0    			 : 1;
	uint8 OCF0   			 : 1;
	uint8 TOV1				 : 1;
	uint8 OCF1B    			 : 1;
	uint8 OCF1A   			 : 1;
	uint8 ICF1    			 : 1;
	uint8 TOV2   			 : 1;
	uint8 OCF2      		 : 1;
} TIFR_reg_t;

typedef struct
{
	uint8 TWIE    			 : 1;
	uint8 RESERVED   		 : 1;
	uint8 TWEN				 : 1;
	uint8 TWWC    			 : 1;
	uint8 TWSTO   			 : 1;
	uint8 TWSTA    			 : 1;
	uint8 TWEA   			 : 1;
	uint8 TWINT      		 : 1;
}TWCR_reg_t ;

typedef struct
{
	uint8 CS00    			 : 1;
	uint8 CS01   			 : 1;
	uint8 CS02				 : 1;
	uint8 WGM01    			 : 1;
	uint8 COM00   			 : 1;
	uint8 COM01    			 : 1;
	uint8 WGM00   			 : 1;
	uint8 FOC0      		 : 1;
}TCCR0_reg_t ;


/*************************************************************/
//#define SREG         *(volatile uint8 *)0x5F
/*****************  MACROS AND DEFINES  ***********************/

#define GICR_reg      ((volatile GICR_reg_t*)0x5B)
#define PORTA_reg     ((volatile PORTA_reg_t*)0x3B)
#define GIFR_reg      ((volatile GIFR_reg_t*)0x5A)
#define MCUCR_reg     ((volatile MCUCR_reg_t*)0x55)

#define MCUCSR_reg    ((volatile MCUCSR_reg_t*)0x54)
/*TIMERS */
#define TCCR0_reg      ((volatile TCCR0_reg_t*)0x53)
#define TWCR_reg       ((volatile TWCR_reg_t*)0x56)
#define TIFR_reg       ((volatile TIFR_reg_t*)0x58)
#define	TIMSK_reg 	   ((volatile TIMSK_reg_t *)0x59)
#define SREG_reg       ((volatile SREG_reg_t*)0x5F)


#define TCCR1A_reg 	 *(volatile uint8 *)0x4F
#define TCCR1B_reg 	 *(volatile uint8 *)0x4E
#define OCR1AH_reg 	 *(volatile uint8 *)0x4D
#define OCR1AL_reg	 *(volatile uint8 *)0x4A

#define tccr0	 *(volatile uint8 *)0x53

#endif

