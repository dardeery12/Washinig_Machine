/*******************************************************************************
 * @file    Timer0.c
 * @author  Abo Drda
 * @date    Sep 2, 2023
 * @brief   
 ******************************************************************************/

/*****************  Includes ********************************/
#include "Timer0.h"
/***************** private global variables  ************************/
static volatile uint8 Ovf_Counter = 0 ;
static uint8 sec_Counter = 0 ;
static uint8 min_Counter = 0 ;
static Std_ReturnType Timer0_Available_flag = E_OK;


/*****************  macros   ***********************/
#define NUM_OF_OVF_SEC     30


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
	tcnt0 =0x06;
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
	//tccr0 = 0;
	Std_ReturnType Ret = E_NOK;
	TIMERO_NO_CLCK();
	Timer0_Available_flag = E_OK;
	Timer0_Reset();
	return Ret;

}

void Timer0_Reset()
{
	Ovf_Counter = 0;
	sec_Counter = 0;
	min_Counter = 0;
}
void Timer0_Calculate_Sec(uint8 * Second)
{
	if(Ovf_Counter >= NUM_OF_OVF_SEC)
	{
		sec_Counter++;
		*Second = sec_Counter;
		Ovf_Counter = 0;
		if(sec_Counter >= 60)
		{
			sec_Counter = 0;
		}
	}
}

void Timer0_Calculate_Min(uint8 * min)
{
	* min = min_Counter;
	if(sec_Counter >= 59)
	{
		min_Counter++;
		sec_Counter = 0;
	}
}
void Timer0_Calculate_Min_And_Sec(uint8 * Sec, uint8 * Minuts)
{
	Timer0_Calculate_Sec(&sec_Counter);
	Timer0_Calculate_Min(&min_Counter);

	*Minuts = min_Counter;
	* Sec = sec_Counter;
	if(min_Counter >= 60)
	{
		min_Counter = 0;
	}

}
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	Ovf_Counter++;
	tcnt0 =0x06;
	TIMER0_CLEAR_FLAG();
}
