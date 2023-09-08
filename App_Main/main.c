
#include "App_Main.h"
#include <util/delay.h>
#define F_CPU         8000000UL
Std_ReturnType busyFlag = E_OK;
extern chr_lcd_4bit_t lcd1;
extern Machine_Mode_t G_Machine_Current_Mode;

extern uint8 G_Rinse_Minut_Counter ;  /*  to save rinse time minutes counting */
extern uint8 G_Rinse_Sec_Counter ;
void auto_f();
int main(void)
{
	uint8 count =0;
	uint8 count1 =0;
	Std_ReturnType test_flag =E_NOK;

	Ecu_Init();


	while(1)
	{

		test_flag = Machine_Auto_Process();
		lcd_4bit_send_num_pos(&lcd1,1,1,test_flag);
		//_delay_ms(5000);
		//Machine_Rinse();
		//Machine_Process_function();
		//Machine_Lcd();
	}
}
uint8 mod = 0;
void auto_f()
{
	Std_ReturnType rins_flag =E_NOK;
	Std_ReturnType wash_flag =E_NOK;
	Std_ReturnType rins2_flag =E_NOK;
	Std_ReturnType drain_flag =E_NOK;


	switch(mod)
	{
	case 0:
		rins_flag = E_OK;
		lcd_4bit_send_string_pos(&lcd1,1,1,"rins");
		_delay_ms(500);
		mod =1;
		break;
	case 1:
		lcd_4bit_send_string_pos(&lcd1,1,1,"wash");
		_delay_ms(500);
				mod =2;
		break;
	case 2:
		lcd_4bit_send_string_pos(&lcd1,1,1,"rins2");
		_delay_ms(500);
				mod =3;
		break;
	case 3:
		lcd_4bit_send_string_pos(&lcd1,1,1,"drain");
		_delay_ms(500);
				mod =4;
		break;
	case 4:
		lcd_4bit_send_string_pos(&lcd1,1,1,"end");
		_delay_ms(500);
				mod =0;
		break;
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



