
#include "App_Main.h"

//extern chr_lcd_4bit_t lcd1;
//extern Manual_Btn_Select_t G_Man_Btn_Stat;
int main(void)
{
	Ecu_Init();

	while(1)
	{
		Machine_Manual_Process();
		//lcd_4bit_send_num_pos(&lcd1, 1, 1, G_Man_Btn_Stat);
		 Machine_Lcd();
	}
}
