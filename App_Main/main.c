#define F_CPU         8000000UL
#include "App_Main.h"

Std_ReturnType busyFlag = E_OK;
extern chr_lcd_4bit_t lcd1;
extern Machine_Mode_t G_Machine_Current_Mode;



#include <util/delay.h>
//extern Manual_Btn_Select_t G_Man_Btn_Stat;
int main(void)
{
	static uint8 min;
	static uint8 sec;
	static uint8 min1;
	static uint8 sec1;
	Ecu_Init();
	Timer0_Stop();
	//Timer0_Start();
	while(1)
	{
		Machine_Process_function();
		Machine_Lcd();
	}
}



void Machine_Process_function(void)
{
	Machine_Select_Mode();
	switch(G_Machine_Current_Mode)
	{
	case AUTO_MODE:
		Machine_Auto_Process();
		break;
	case MANUAL_MODE:
		Machine_Manual_Process();
		break;
	case STOP_MODE:
		//Machine_Auto_Process();
		break;
	case ERROR_CHOOSE_MODE:
		//Machine_Auto_Process();
		break;

	}
}
















//Machine_Auto_Function();
//Machine_Manual_Process();
//lcd_4bit_send_num_pos(&lcd1, 1, 1, G_Man_Btn_Stat);
//Machine_Lcd();
/*
 * 		Timer0_Calculate_Min_And_Sec(&sec1, &min1);
		Print_Time(&lcd1, 2, 1, min1, sec1);
		if(sec == 7)
		{
			sec1 =0;
			tccr0 =0;
			Timer0_Stop();
			lcd_4bit_send_string_pos(&lcd1, 4, 1, "stop");
		}
		//_delay_ms(5000);
 * */



