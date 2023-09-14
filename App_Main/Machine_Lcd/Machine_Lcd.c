/********************************************************************************
 * @file    Machine_Lcd.c
 * @author  Drd
 * @date    Sep 13, 2023
 * @brief   
 ********************************************************************************/


/*****************  INCLUDES   *******************************/
#include "Machine_Lcd.h"
/***************** EXTERN VARIABLES  *************************/

/***************** static functions  ****************/
static void clear_lcd_lin_num(uint8 line_num);
static void lcd_auto_update();
static void lcd_manual_update();

static void lcd_rinse_stat_func();
static void lcd_wash_stat_func();
static void lcd_rinse2_stat_func();
static void lcd_drain_stat_func();
static void lcd_end_stat_func();

/*****************  PRIVATE TYPEDEFS   *************************/

/*****************  extern VARIABLES   *************************/
extern chr_lcd_4bit_t lcd1;
extern Machine_Mode_t G_Machine_Current_Mode;
extern Auto_Machine_Status_t G_auto_current_stat;

extern uint8 G_Rinse_Minut_Counter ;  /*  @re auto_program.c */
extern uint8 G_Rinse_Sec_Counter ;	  /*  @re auto_program.c */

extern uint8 G_Wash_Minut_Counter ;   /*  @re auto_program.c */
extern uint8 G_Wash_Sec_Counter ;	   /*  @re auto_program.c */

extern uint8 G_Drain_Minut_Counter ;  /*  @re auto_program.c */
extern uint8 G_Drain_Sec_Counter ;	  /*  @re auto_program.c */
/*****************  GLOBAL VARIABLES   *************************/

/*****************  STATIC FUNCTION PROTOTYPES   ***************/

/*****************  STATIC FUNCTIONS   *************************/

/*****************  GLOBAL FUNCTIONS   *************************/
void Machine_Lcd_Init(void)
{
	uint8 welcom[] = "  Welcome To Alaqsa ";
	uint8 mode[] = "    Choose Mode";
	uint8 select[] = "Auto        Manual";
	lcd_4bit_send_string_pos(&lcd1, 1, 1, welcom);
	lcd_4bit_send_string_pos(&lcd1, 3, 1, mode);
	lcd_4bit_send_string_pos(&lcd1, 4, 1, select);

}


void Machine_Lcd_Updat(void)
{

	switch(G_Machine_Current_Mode)
	{
	case AUTO_MODE:
		lcd_auto_update();
		break;
	case MANUAL_MODE:
		lcd_manual_update();
		break;
	case ERROR_CHOOSE_MODE:
		break;

	}
}



static void clear_lcd_lin_num(uint8 line_num)
{
	uint8 line[4][20] = {"              	      ", "  	                  ",
			"               	     ", "            	        " };
	lcd_4bit_send_string_pos(&lcd1,line_num,1, line[line_num-1]);
}

static void lcd_auto_update()
{
	uint8 Loc_auto_update_flag = 155;
	static uint8 Loc_first_time_flag = 0;

	uint8 press[] = "Press Auto Start Btn";
	uint8 press2[] = "       To Run";
	if(Loc_first_time_flag == 0)
	{
		clear_lcd_lin_num(2);
		clear_lcd_lin_num(3);
		clear_lcd_lin_num(4);
		lcd_4bit_send_string_pos(&lcd1, 2, 1, press);
		lcd_4bit_send_string_pos(&lcd1, 3, 1, press2);
		Loc_first_time_flag = 5;
	}
	if(Loc_auto_update_flag != G_auto_current_stat)
	{

		switch(G_auto_current_stat)
		{
		case RINSE_STATE:
			lcd_rinse_stat_func();
			break;
		case WASHING_STATE:
			lcd_wash_stat_func();
			break;
		case RINSE_STATE2:
			lcd_rinse2_stat_func();
			break;
		case DRAIN_STATE:
			lcd_drain_stat_func();
			break;
		case END_STATE:
			lcd_end_stat_func();
			break;
		}
		Loc_auto_update_flag = G_auto_current_stat;
	}
}
static void lcd_manual_update()
{
	uint8 Loc_man_update_flag = 155;
	if(Loc_man_update_flag != G_auto_current_stat)
	{
		switch(G_auto_current_stat)
		{
		case RINSE_STATE:
			break;
		case WASHING_STATE:
			break;
		case RINSE_STATE2:
			break;
		case DRAIN_STATE:
			break;
		case END_STATE:
			break;
		}
		Loc_man_update_flag = G_auto_current_stat;
	}
}

static void lcd_rinse_stat_func()
{
	static uint8 Loc_first_flag = 0;
	if(Loc_first_flag == 0)
	{
		uint8 mode[] = "Rinse";
		clear_lcd_lin_num(3);
		clear_lcd_lin_num(4);
		lcd_4bit_send_string_pos(&lcd1, 3,15,mode);
		Loc_first_flag = 2;
	}
	Print_Time(&lcd1, 4,15, G_Rinse_Minut_Counter, G_Rinse_Sec_Counter);
}
static void lcd_wash_stat_func()
{
	static uint8 Loc_first_flag = 0;
	if(Loc_first_flag == 0)
	{
		uint8 mode[] = "Wash";
		clear_lcd_lin_num(3);
		clear_lcd_lin_num(4);
		lcd_4bit_send_string_pos(&lcd1, 3,15,mode);
		Loc_first_flag = 9;
	}
	Print_Time(&lcd1, 4,15,G_Wash_Minut_Counter,G_Wash_Sec_Counter);
}
static void lcd_rinse2_stat_func()
{
	static uint8 Loc_first_flag = 0;
	if(Loc_first_flag == 0)
	{
		uint8 mode[] = "Rinse2";
		clear_lcd_lin_num(3);
		clear_lcd_lin_num(4);
		lcd_4bit_send_string_pos(&lcd1, 3,15,mode);
		Loc_first_flag = 66;
	}
	Print_Time(&lcd1, 4,15,G_Rinse_Minut_Counter,G_Rinse_Sec_Counter);
}
static void lcd_drain_stat_func()
{
	static uint8 Loc_first_flag = 0;
	if(Loc_first_flag == 0)
	{
		uint8 mode[] = "Drain";
		clear_lcd_lin_num(3);
		clear_lcd_lin_num(4);
		lcd_4bit_send_string_pos(&lcd1, 3,15,mode);
		Loc_first_flag = 22;
	}
	Print_Time(&lcd1, 4, 15, G_Drain_Minut_Counter, G_Drain_Sec_Counter);
}
static void lcd_end_stat_func()
{
	static uint8 Loc_first_flag = 0;
	if(Loc_first_flag == 0)
	{
		uint8 mode[] = "     End!!";
		clear_lcd_lin_num(3);
		clear_lcd_lin_num(4);
		lcd_4bit_send_string_pos(&lcd1, 3,1,mode);
		Loc_first_flag = 88;
	}
}

