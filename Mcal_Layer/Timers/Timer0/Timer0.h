/*******************************************************************************
 * @file    Timer0.h
 * @author  Abo Drda
 * @date    Sep 2, 2023
 * @brief   
 ******************************************************************************/

#ifndef TIMER0_TIMER0_H_
#define TIMER0_TIMER0_H_

/*****************  Includes ********************************/
<<<<<<< HEAD
#include "Timer0_private.h"
/*****************  ex to use   ***********************/
/* tested and ok
 * Std_ReturnType available_flag =E_NOK;
	Ecu_Init();

	while(1)
	{
		available_flag = Timer0_Check_Available();
		if(E_NOK == available_flag)
		{
			Timer0_Start();
		}
		Timer0_Calculate_Min_And_Sec(&count,&count1);
		Print_Time(&lcd1,1,1,count,count1);
		if((count >= 5) || (count1 >= 5))
		{
			Timer0_Stop();
		}
		}
 * */
=======
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

>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
void Timer0_Init(void);
Std_ReturnType Timer0_Start(void);
Std_ReturnType Timer0_Stop(void);
void Timer0_Calculate_Sec(uint8 * Second);
void Timer0_Calculate_Min_And_Sec(uint8 * Sec, uint8 * Minuts);
Std_ReturnType Timer0_Check_Available();
<<<<<<< HEAD
void Timer0_Reset();
Std_ReturnType Timr0_Time_Out(uint8 min, uint8 sec);
void Timr0_Time_Out_Stop();
=======

>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
#endif

