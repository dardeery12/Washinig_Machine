/*******************************************************************************
 * @file    Timer0.h
 * @author  Abo Drda
 * @date    Sep 2, 2023
 * @brief   
 ******************************************************************************/

#ifndef TIMER0_TIMER0_H_
#define TIMER0_TIMER0_H_

/*****************  Includes ********************************/
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
void Timer0_Init(void);
Std_ReturnType Timer0_Start(void);
Std_ReturnType Timer0_Stop(void);
void Timer0_Calculate_Sec(uint8 * Second);
void Timer0_Calculate_Min_And_Sec(uint8 * Sec, uint8 * Minuts);
Std_ReturnType Timer0_Check_Available();
void Timer0_Reset();
#endif

