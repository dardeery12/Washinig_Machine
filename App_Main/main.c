
#include "App_Main.h"
void Machine_Sysytem(void);
extern chr_lcd_4bit_t lcd1;
Machine_Mode_t Machine_Current_Mode = STOP_MODE;
int main(void)
{
	Ecu_Init();
	Machine_Init();



	while(1)
	{
		Machine_Sysytem();
		//Machine_Rinse();


	}
}

void Machine_Sysytem(void)
{

	 Machine_Select_Mode(&Machine_Current_Mode);

	switch (Machine_Current_Mode)
	{
	case AUTO_MODE:
	{
		lcd_4bit_send_string_pos(&lcd1,1,1,"AUTO_MODE");
		Machine_Auto_Function();
		break;
	}
	case 	MANUAL_MODE:
	{
		Machine_Manual_Function();
		lcd_4bit_send_string_pos(&lcd1,1,1,"MANUAL_MODE");
		break;
	}
	case ERROR_CHOOSE_MODE:
		{
			lcd_4bit_send_string_pos(&lcd1,1,1,"ERROR_CHOOSE_MODE");
			break;
		}
	case STOP_MODE:
	{
		lcd_4bit_send_string_pos(&lcd1,1,1,"STOP_MODE");
		break;
	}
	}
}
