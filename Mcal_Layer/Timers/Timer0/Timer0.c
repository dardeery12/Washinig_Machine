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
static Std_ReturnType Timer0_Available_flag = E_OK;
/*****************  GLOBAL FUNCTIONS   ***********************/

/*  E_OK  =====> free to use
 *  E_NOK =====> busy cant use */
Std_ReturnType Timer0_Check_Available()
{
	Std_ReturnType Ret = E_NOK;
	if(E_OK == Timer0_Available_flag)
	{
		Ret = E_OK;
	}
	else
	{
		Ret = E_NOK;
	}
	return Ret;
}
void Timer0_Init(void)
{
	/*Enable Global Interrupt  */
	SREG_reg->I =1;
	/* set mode */

	/*set prescaller*/
	PRESCALLER_1024();
	//EXTERNAL_CLCK_SOURCE_RISING_EDGE();
	/*  */
	TIMER0_OFV_INTERRUPT_ENABLE();
	//TIMSK_reg->OCIE0 =1;
	//Timer0_Stop();
}
Std_ReturnType Timer0_Start(void)
{

	Std_ReturnType Ret = E_NOK;
	//EXTERNAL_CLCK_SOURCE_RISING_EDGE();
	PRESCALLER_1024();
	Timer0_Available_flag = E_NOK;
	return Ret;
}
Std_ReturnType Timer0_Stop(void)
{
	tccr0 = 0;
	Std_ReturnType Ret = E_NOK;
	TIMERO_NO_CLCK();
	Timer0_Available_flag = E_OK;
	return Ret;

}

void Timer0_Calculate_Sec(uint8 * Second)
{
	if(61 == Ovf_Counter)
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
void Timer0_Calculate_Min_And_Sec(uint8 * Sec, uint8 * Minuts)
{

	*Sec = Sec_Counter;
	*Minuts = Min_Counter;

}
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	Ovf_Counter++;
	TIMER0_CLEAR_FLAG();
	if(Ovf_Counter >= 30)
	{
		Sec_Counter++;
		Ovf_Counter =0;
		if(Sec_Counter >= 60)
		{
			Sec_Counter = 0;
			Min_Counter++;
			if(Min_Counter >= 60)
			{
				Min_Counter = 0;
			}
		}

	}
}
