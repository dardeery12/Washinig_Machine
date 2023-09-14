



#include "App_Main.h"
#include <util/delay.h>
#include "../machine/auto/auto_interface.h"
#include "Machine_Lcd/Machine_Lcd.h"

extern Machine_Mode_t G_Machine_Current_Mode;


int main(void)
{

	Ecu_Init();
	Machine_Lcd_Init();
	while(1)
	{


		Machine_Process_function();
		Machine_Lcd_Updat();
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



