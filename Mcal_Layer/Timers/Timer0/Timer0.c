/*******************************************************************************
 * @file    Timer0.c
 * @author  Abo Drda
 * @date    Sep 2, 2023
 * @brief   
 ******************************************************************************/

/*****************  Includes ********************************/
#include "Timer0.h"
<<<<<<< HEAD
/***************** private global variables  ************************/
static volatile uint8 Ovf_Counter = 0 ;
static uint8 sec_Counter = 0 ;
static uint8 min_Counter = 0 ;
static Std_ReturnType Timer0_Available_flag = E_OK;


/*****************  macros   ***********************/
#define NUM_OF_OVF_SEC     30


=======
/***************** static function  ************************/
volatile uint8 Ovf_Counter =0 ;
volatile uint8 Sec_Counter =0 ;
volatile uint8 Min_Counter =0 ;
/*****************  GLOBAL VARIABLES   ***********************/
Std_ReturnType Timer0_Busy_flag = E_OK;
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
/*****************  GLOBAL FUNCTIONS   ***********************/

/*  E_OK  =====> free to use
 *  E_NOK =====> busy cant use */
Std_ReturnType Timer0_Check_Available()
{
	Std_ReturnType Ret = E_NOK;
<<<<<<< HEAD
	if(E_OK == Timer0_Available_flag)
=======
	if(E_OK == Timer0_Busy_flag)
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
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
<<<<<<< HEAD
	//EXTERNAL_CLCK_SOURCE_RISING_EDGE();
=======

>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
	/*  */
	TIMER0_OFV_INTERRUPT_ENABLE();
	//TIMSK_reg->OCIE0 =1;
	//Timer0_Stop();
<<<<<<< HEAD
	tcnt0 =0x06;
}
Std_ReturnType Timer0_Start(void)
{
	Std_ReturnType Ret = E_NOK;
	//EXTERNAL_CLCK_SOURCE_RISING_EDGE();
	PRESCALLER_1024();
	Timer0_Available_flag = E_NOK;
=======
}
Std_ReturnType Timer0_Start(void)
{

	Std_ReturnType Ret = E_NOK;
	PRESCALLER_1024();
	Timer0_Busy_flag = E_NOK;
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
	return Ret;
}
Std_ReturnType Timer0_Stop(void)
{
<<<<<<< HEAD
	//tccr0 = 0;
	Std_ReturnType Ret = E_NOK;
	TIMERO_NO_CLCK();
	Timer0_Available_flag = E_OK;
	Timer0_Reset();
=======
	tccr0 = 0;
	Std_ReturnType Ret = E_NOK;
	TIMERO_NO_CLCK();
	Timer0_Busy_flag = E_OK;
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
	return Ret;

}

<<<<<<< HEAD
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


Std_ReturnType Timr0_Time_Out(uint8 min, uint8 sec)
{
	Std_ReturnType Ret = E_NOK;
	static uint8 Loc_min = 0;
	static uint8 Loc_sec = 0;
	//Timer0_Reset();
	//Timer0_Start();
	Timer0_Calculate_Min_And_Sec(&Loc_sec, &Loc_min);
	if((min == Loc_min) && (sec == Loc_sec))
	{
		Timer0_Stop();
		Loc_min = 0;
		Loc_sec = 0;
		Ret = E_OK;
	}
	return Ret;
}
void Timr0_Time_Out_Stop()
{
	Timer0_Stop();
=======
void Timer0_Calculate_Sec(uint8 * Second)
{
	Timer0_Busy_flag = E_NOK;
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
void Timer0_Calculate_Min_And_Sec(uint8 * Sec, uint8 * Minuts)
{
	//static uint8 Loc_sec =0;
	Timer0_Busy_flag = E_NOK;
	//Timer0_Calculate_Sec(&Loc_sec);
	*Sec = Sec_Counter;
	//if(Loc_sec == 60)
	{
		//Loc_sec = 0;
		//Min_Counter++;
		*Minuts = Min_Counter;
	}
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
}
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	Ovf_Counter++;
<<<<<<< HEAD
	tcnt0 =0x06;
	TIMER0_CLEAR_FLAG();
=======
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
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
}
