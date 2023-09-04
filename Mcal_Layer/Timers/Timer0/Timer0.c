/*******************************************************************************
 * @file    Timer0.c
 * @author  Abo Drda
 * @date    Sep 2, 2023
 * @brief   
 ******************************************************************************/

/*****************  Includes ********************************/
#include "Timer0.h"
/***************** static function  ************************/
volatile uint8 Ovf_Counter =0 ;
volatile uint8 Sec_Counter =0 ;
volatile uint8 Min_Counter =0 ;
/*****************  GLOBAL VARIABLES   ***********************/

/*****************  GLOBAL FUNCTIONS   ***********************/
void Timer0_Init(void)
{
	/*Enable Global Interrupt  */
	SREG_reg->I =1;
	/* set mode */

	/*set prescaller*/
	PRESCALLER_1024();

	/*  */
	TIMER0_OFV_INTERRUPT_ENABLE();

	Timer0_Stop();
}
void Timer0_Start(void)
{
	PRESCALLER_1024();
}
void Timer0_Stop(void)
{
	TIMERO_NO_CLCK();
}

Std_ReturnType Timer0_Calculate_Sec(uint8 * Second)
{
	if(31 == Ovf_Counter)
	{
		Sec_Counter++;
		(*Second) = Sec_Counter;
		Ovf_Counter = 0;

		if(Sec_Counter == 60)
		{
			Sec_Counter = 0;
		}

	}

}
Std_ReturnType Timer0_Calculate_Min_And_Sec(uint8 * Sec, uint8 * Minuts)
{
	Std_ReturnType Ret = E_NOK;
	static uint8 Loc_sec =0;
	Timer0_Calculate_Sec(&Loc_sec);
	*Sec = Loc_sec;
	if(Loc_sec == 60)
	{
		Loc_sec = 0;
		Min_Counter++;
		*Minuts = Min_Counter;
	}

return Ret;
}
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	Ovf_Counter++;
	TIMER0_CLEAR_FLAG();
}
