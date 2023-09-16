/********************************************************************************
 * @file    Timer1.c
 * @author  Drd
 * @date    Pep 1, 2023
 * @brief   
 ********************************************************************************/
/*****************  INCLUDES   *******************************/

#include "Timer1_Interface.h"
#include "../../Mcal_Gpio/Mcal_Gpio_Interface.h"

/***************** EXTERN VARIABLES  *************************/

/***************** PRIVATE MACROS AND DEFINES  ****************/

/*****************  PRIVATE TYPEDEFS   *************************/

/*****************  STATIC VARIABLES   *************************/

/*****************  GLOBAL VARIABLES   *************************/
uint8 Second_Counter = 0;
uint8 Minute_Counter = 0;
static uint8 Timer1_Ovf_Counter = 0;
/*****************  STATIC FUNCTION PROTOTYPES   ***************/

/*****************  STATIC FUNCTIONS   *************************/

/*****************  GLOBAL FUNCTIONS   *************************/
Gpio_pin_config_t led2 ={PORTA, GPIO_PIN3, GPIO_PIN_OUTPOT};

Std_ReturnType Timer1_Init()
{
	Std_ReturnType Ret = E_NOK;

	  SREG_reg->I = 1;
	  TCCR1A_reg = 0x80;
	  TCCR1B_reg = 0x08;
	  OCR1AH_reg = 0xF4;
	  OCR1AL_reg = 0x23;
	  TIMSK_reg->OCIE1A = 1;
	return Ret;
}
Std_ReturnType Timer1_Start()
{
	Std_ReturnType Ret = E_NOK;

	return Ret;
}
Std_ReturnType Timer1_Stop()
{
	Std_ReturnType Ret = E_NOK;

	return Ret;
}
/*
void __vector_10 (void) __attribute__ ((signal)) ;
void __vector_10 (void)
{
	gpio_pin_toggle(&led2);
	Timer1_Ovf_Counter++;
	Second_Counter++;
	//TIFR_reg->TOV1 = 1;
	if(60 == Timer1_Ovf_Counter)
	{
		Timer1_Ovf_Counter = 0;
		Minute_Counter++;
	}

}

*/
