/********************************************************************************
 * @file    program.c
 * @author  Drd
 * @date    Sep 6, 2023
 * @brief   
 ********************************************************************************/


/*****************  INCLUDES   *******************************/
#include "interface.h"
#include "util/delay.h"
<<<<<<< HEAD

/*****************  STATIC FUNCTION PROTOTYPES   ***************/
static Std_ReturnType Manual_Btn_select();
static void man_water_func();
static void man_heater_func();
static void man_drain_func();
static void man_fast_drain_func();
static void man_rotat_right_func();
static void man_rotat_left_func();
static void man_Door_Lock(void);
static void man_error_choose();



=======
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
/***************** EXTERN VARIABLES  *************************/
extern button_t  Mode_Manual_Btn ;
extern button_t  Mode_Auto_Btn;
extern button_t  Man_Water_Btn;
extern button_t  Man_Heater_Btn;
extern button_t  Man_RotatRight_Btn;
extern button_t  Man_RotateLeft_Btn;
extern button_t  Man_Drain_Btn;
extern button_t  Door_Contact_Btn;
extern Gpio_pin_config_t  R00_WaterEnable;
extern Gpio_pin_config_t  R01_HeaterEnable;
extern Gpio_pin_config_t  R02_RightMotor ;
extern Gpio_pin_config_t  R03_LeftMotor;
//extern Gpio_pin_config_t  R04_FastEnable;
extern Gpio_pin_config_t  R05_DrainEnable ;
extern Gpio_pin_config_t  Door_Lock_Pin;
extern Gpio_pin_config_t  Buzzer;
extern Gpio_pin_config_t  LED ;
//extern Gpio_pin_config_t  Water_Level_Pin;
//extern Gpio_pin_config_t  Auto_Water_Temp ;

<<<<<<< HEAD

/*****************  GLOBAL VARIABLES   *************************/
Manual_Btn_Select_t G_Man_Btn_Stat = ERROR_MAN_CHOOSE;/*buttons in manual mode */
=======
/*****************  STATIC FUNCTION PROTOTYPES   ***************/
static Std_ReturnType Manual_Btn_select(Manual_Btn_Select_t * Btn);
static void man_water_func();
static void man_heater_func();
static void man_drain_func();
static void man_fast_drain_func();
static void man_rotat_right_func();
static void man_rotat_left_func();
static void man_Door_Lock(void);
static void clear_lcd_print_comapany(void);


/*****************  GLOBAL VARIABLES   *************************/
Manual_Btn_Select_t G_Man_Btn_Stat = ERROR_CHOOSE;/*buttons in manual mode */
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5

Machine_Mode_t G_Machine_Current_Mode = ERROR_CHOOSE_MODE;/*machine mode manual or automatic */

Std_ReturnType G_Alarm_Notification = E_NOK; /*for any error any function able to make alarm */

<<<<<<< HEAD
/*****************  extern variables   *************************/
=======
/*****************  extern VARIABLES   *************************/
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
extern chr_lcd_4bit_t lcd1;

/*****************  STATIC VARIABLES   *************************/

/*****************   TYPEDEFS   *************************/

/***************** PRIVATE MACROS AND DEFINES  ****************/
<<<<<<< HEAD
/* MAN_ERROR_CHOOSE_TIME if in manual mode and no preesed btn*/
#define MAN_ERROR_CHOOSE_TIME        10
/*****************  global FUNCTIONS   *************************/
=======

/*****************  GLOBAL FUNCTIONS   *************************/
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5

Std_ReturnType Machine_Manual_Init(void)
{
	Std_ReturnType Ret = E_NOK;


	return Ret;
}

Std_ReturnType Machine_Manual_Process(void)
{
	Std_ReturnType Ret = E_NOK;
<<<<<<< HEAD

	Manual_Btn_select();
	switch(G_Man_Btn_Stat)
	{
	case  WATER_BTN :
		man_water_func();
		break;
	case  HEATER_BTN :
		man_heater_func();
		break;
	case  DRAIN_BTN :
		man_drain_func();
		break;
	case  RIGHT_ROTAT_BTN :
		man_rotat_right_func();
		break;
	case  LEFT_ROTAT_BTN :
		man_rotat_left_func();
		break;
	case  DOOR_LOCK :
		man_Door_Lock();
		break;
	case  ERROR_MAN_CHOOSE :
		man_error_choose();
		break;
=======
	Machine_Select_Mode();
	if(MANUAL_MODE == G_Machine_Current_Mode)
	{
		Manual_Btn_select(&G_Man_Btn_Stat);
		if (WATER_BTN == G_Man_Btn_Stat)
		{
			man_water_func();
		}
		else if (HEATER_BTN == G_Man_Btn_Stat)
		{
			man_heater_func();
		}
		else if (DRAIN_BTN == G_Man_Btn_Stat)
		{
			man_drain_func();		}
		else if (RIGHT_ROTAT_BTN == G_Man_Btn_Stat)
		{
			man_rotat_right_func();
		}
		else if (LEFT_ROTAT_BTN == G_Man_Btn_Stat)
		{
			man_rotat_left_func();
		}
		else if (DOOR_LOCK == G_Man_Btn_Stat)
		{
			man_Door_Lock();
		}
		else
		{
			G_Alarm_Notification= E_OK;
		}
	}
	else
	{
		/*Handle Error*/
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
	}

	return Ret;
}
Std_ReturnType Alarm_Error(void)
{
	Std_ReturnType Ret = E_NOK;
	if(E_OK == G_Alarm_Notification)
	{
		gpio_pin_write_logic(&LED, HIGH);
		gpio_pin_write_logic(&Buzzer, HIGH);
	}
	else
	{
		gpio_pin_write_logic(&LED, LOW);
		gpio_pin_write_logic(&Buzzer, LOW);
	}

	return Ret;
}

<<<<<<< HEAD
=======
Std_ReturnType Machine_Lcd()
{
	Std_ReturnType Ret =E_NOK;
	switch (G_Machine_Current_Mode)
	{
	case MANUAL_MODE:
	{
		if (WATER_BTN == G_Man_Btn_Stat)
		{
			lcd_4bit_send_string_pos(&lcd1,1,1,"water");
		}
		else if (HEATER_BTN == G_Man_Btn_Stat)
		{
			lcd_4bit_send_string_pos(&lcd1,1,1,"heater");
		}
		else if (DRAIN_BTN == G_Man_Btn_Stat)
		{
			lcd_4bit_send_string_pos(&lcd1,1,1,"drain");
		}
		else if (RIGHT_ROTAT_BTN == G_Man_Btn_Stat)
		{
			lcd_4bit_send_string_pos(&lcd1,1,1,"right");
		}
		else if (LEFT_ROTAT_BTN == G_Man_Btn_Stat)
		{
			lcd_4bit_send_string_pos(&lcd1,1,1,"left");
		}
		else if (DOOR_LOCK == G_Man_Btn_Stat)
		{
			lcd_4bit_send_string_pos(&lcd1,1,1,"door");
		}
		else
		{
			//G_Alarm_Notification= E_OK;

			clear_lcd_print_comapany();
		}
	}
	break;


	case AUTO_MODE:

		break;
	case STOP_MODE:

		break;

	default:
		break;
	}
	return Ret;
}
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
Std_ReturnType Machine_Select_Mode()
{
	Std_ReturnType ret = E_NOK;
	//	Machine_Mode_t  Loc_btn_val = STOP_MODE;
	button_state_t  Loc_Auto_btn_val = BUTTON_RELEASED;
	button_state_t  Loc_Man_btn_val = BUTTON_RELEASED;
<<<<<<< HEAD
	/* this condition is used to protect system from changing machine mode
	 *  when it is already in other mode*/
	if(G_Machine_Current_Mode == ERROR_CHOOSE_MODE)
	{
		button_read_state(&Mode_Auto_Btn, &Loc_Auto_btn_val);
		button_read_state(&Mode_Manual_Btn, &Loc_Man_btn_val);

		/* this condition is used to protect system from press manual and auto at the same time*/
		if((BUTTON_PRESSED == Loc_Auto_btn_val) && (BUTTON_RELEASED == Loc_Man_btn_val))
		{
			G_Machine_Current_Mode = AUTO_MODE;
			Loc_Man_btn_val = BUTTON_RELEASED;
		}
		else if((BUTTON_PRESSED == Loc_Man_btn_val) && (BUTTON_RELEASED ==  Loc_Auto_btn_val))
		{
			G_Machine_Current_Mode = MANUAL_MODE;
			Loc_Auto_btn_val = BUTTON_RELEASED;
		}
		else if((BUTTON_PRESSED == Loc_Man_btn_val) && (BUTTON_PRESSED == Loc_Auto_btn_val))
		{
			G_Machine_Current_Mode = ERROR_CHOOSE_MODE;

			Loc_Auto_btn_val = BUTTON_PRESSED;
			Loc_Man_btn_val = BUTTON_PRESSED;
		}

		else
		{
			G_Machine_Current_Mode = ERROR_CHOOSE_MODE;
			Loc_Auto_btn_val = BUTTON_RELEASED;
			Loc_Man_btn_val = BUTTON_RELEASED;
		}
=======

	button_read_state(&Mode_Auto_Btn, &Loc_Auto_btn_val);
	button_read_state(&Mode_Manual_Btn, &Loc_Man_btn_val);

	if((BUTTON_PRESSED == Loc_Auto_btn_val) && (BUTTON_RELEASED == Loc_Man_btn_val))
	{
		G_Machine_Current_Mode = AUTO_MODE;
		Loc_Man_btn_val = BUTTON_RELEASED;
	}
	else if((BUTTON_PRESSED == Loc_Man_btn_val) && (BUTTON_RELEASED ==  Loc_Auto_btn_val))
	{
		G_Machine_Current_Mode = MANUAL_MODE;
		Loc_Auto_btn_val = BUTTON_RELEASED;
	}
	else if((BUTTON_PRESSED == Loc_Man_btn_val) && (BUTTON_PRESSED == Loc_Auto_btn_val))
	{
		G_Machine_Current_Mode = ERROR_CHOOSE_MODE;

		Loc_Auto_btn_val = BUTTON_PRESSED;
		Loc_Man_btn_val = BUTTON_PRESSED;
	}

	else
	{
		G_Machine_Current_Mode = STOP_MODE;
		Loc_Auto_btn_val = BUTTON_RELEASED;
		Loc_Man_btn_val = BUTTON_RELEASED;
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
	}
	return ret;
}



/*****************  STATIC FUNCTIONS  implementation *************************/


<<<<<<< HEAD
static Std_ReturnType Manual_Btn_select()
=======
static Std_ReturnType Manual_Btn_select(Manual_Btn_Select_t * Btn)
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
{
	Std_ReturnType Ret = E_NOK;
	button_state_t Loc_Man_Water_Btn_val 	   = BUTTON_RELEASED;
	button_state_t Loc_Man_Heater_Btn_val 	   = BUTTON_RELEASED;
	button_state_t Loc_Man_RotatRight_Btn_val  = BUTTON_RELEASED;
	button_state_t Loc_Man_RotateLeft_Btn_val  = BUTTON_RELEASED;
	button_state_t Loc_Man_Drain_Btn_val       = BUTTON_RELEASED;
	button_state_t Loc_Door_Contact_Btn_val    = BUTTON_RELEASED;

	button_read_state(&Man_Water_Btn, &Loc_Man_Water_Btn_val);
	button_read_state(&Man_Heater_Btn, &Loc_Man_Heater_Btn_val);
	button_read_state(&Man_RotatRight_Btn, &Loc_Man_RotatRight_Btn_val);
	button_read_state(&Man_RotateLeft_Btn, &Loc_Man_RotateLeft_Btn_val);
	button_read_state(&Man_Drain_Btn, &Loc_Man_Drain_Btn_val);
	button_read_state(&Door_Contact_Btn, &Loc_Door_Contact_Btn_val);
	if(BUTTON_PRESSED == Loc_Man_Water_Btn_val)
	{
<<<<<<< HEAD
		G_Man_Btn_Stat = WATER_BTN;
		Ret = E_OK;
		/* protect from other operations*/
=======
		* Btn = WATER_BTN;
		/* protect from other operations*/

>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
		Loc_Man_Heater_Btn_val     = BUTTON_RELEASED;
		Loc_Man_RotatRight_Btn_val = BUTTON_RELEASED;
		Loc_Man_RotateLeft_Btn_val = BUTTON_RELEASED;
		Loc_Man_Drain_Btn_val      = BUTTON_RELEASED;
		Loc_Door_Contact_Btn_val   = BUTTON_RELEASED;
	}
	else if(BUTTON_PRESSED == Loc_Man_Heater_Btn_val)
	{
<<<<<<< HEAD
		G_Man_Btn_Stat = HEATER_BTN;
		Ret = E_OK;
=======
		* Btn = HEATER_BTN;
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
		/* protect from other operations*/
		Loc_Man_Water_Btn_val      = BUTTON_RELEASED;
		Loc_Man_RotatRight_Btn_val = BUTTON_RELEASED;
		Loc_Man_RotateLeft_Btn_val = BUTTON_RELEASED;
		Loc_Man_Drain_Btn_val      = BUTTON_RELEASED;
		Loc_Door_Contact_Btn_val   = BUTTON_RELEASED;
	}
	else if(BUTTON_PRESSED == Loc_Man_RotatRight_Btn_val)
	{
<<<<<<< HEAD
		G_Man_Btn_Stat = RIGHT_ROTAT_BTN;
		Ret = E_OK;
=======
		* Btn = RIGHT_ROTAT_BTN;
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
		/* protect from other operations*/
		Loc_Man_Water_Btn_val      = BUTTON_RELEASED;
		Loc_Man_Heater_Btn_val     = BUTTON_RELEASED;
		Loc_Man_RotateLeft_Btn_val = BUTTON_RELEASED;
		Loc_Man_Drain_Btn_val      = BUTTON_RELEASED;
		Loc_Door_Contact_Btn_val   = BUTTON_RELEASED;
	}
	else if(BUTTON_PRESSED == Loc_Man_RotateLeft_Btn_val)
	{
<<<<<<< HEAD
		G_Man_Btn_Stat = LEFT_ROTAT_BTN;
		Ret = E_OK;
=======
		* Btn = LEFT_ROTAT_BTN;
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
		/* protect from other operations*/
		Loc_Man_Water_Btn_val      = BUTTON_RELEASED;
		Loc_Man_Heater_Btn_val     = BUTTON_RELEASED;
		Loc_Man_RotatRight_Btn_val = BUTTON_RELEASED;
		Loc_Man_Drain_Btn_val      = BUTTON_RELEASED;
		Loc_Door_Contact_Btn_val   = BUTTON_RELEASED;
	}
	else if(BUTTON_PRESSED == Loc_Man_Drain_Btn_val)
	{
<<<<<<< HEAD
		G_Man_Btn_Stat = DRAIN_BTN;
		Ret = E_OK;
=======
		* Btn = DRAIN_BTN;
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
		/* protect from other operations*/
		Loc_Man_Water_Btn_val      = BUTTON_RELEASED;
		Loc_Man_Heater_Btn_val     = BUTTON_RELEASED;
		Loc_Man_RotatRight_Btn_val = BUTTON_RELEASED;
		Loc_Man_RotateLeft_Btn_val = BUTTON_RELEASED;
		Loc_Door_Contact_Btn_val   = BUTTON_RELEASED;
	}
	else if(BUTTON_PRESSED == Loc_Door_Contact_Btn_val)
	{
<<<<<<< HEAD
		G_Man_Btn_Stat = DOOR_LOCK;
		Ret = E_OK;
=======
		* Btn = DOOR_LOCK;
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
		/* protect from other operations*/
		Loc_Man_Water_Btn_val      = BUTTON_RELEASED;
		Loc_Man_Heater_Btn_val	   = BUTTON_RELEASED;
		Loc_Man_RotatRight_Btn_val = BUTTON_RELEASED;
		Loc_Man_RotateLeft_Btn_val = BUTTON_RELEASED;
<<<<<<< HEAD
		Loc_Man_Drain_Btn_val      = BUTTON_RELEASED;
	}
	/*
	else if(Loc_Man_Water_Btn_val && Loc_Man_Heater_Btn_val && Loc_Man_RotatRight_Btn_val)
	{
		if(Loc_Man_RotateLeft_Btn_val && Loc_Man_Drain_Btn_val && Loc_Door_Contact_Btn_val)
		{
			G_Man_Btn_Stat =  ERROR_MAN_CHOOSE;
		}
	}
*/
=======
		Loc_Door_Contact_Btn_val   = BUTTON_RELEASED;
	}
	else
	{
		/*Do Nothing*/
	}

>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5

	return Ret;
}
static void man_water_func()
{
	button_state_t Loc_water_btn_stat = BUTTON_RELEASED;
	button_read_state(&Man_Water_Btn, &Loc_water_btn_stat);

	if(BUTTON_PRESSED == Loc_water_btn_stat)
	{
		gpio_pin_write_logic(&R00_WaterEnable, HIGH);
	}
<<<<<<< HEAD
	else if(BUTTON_RELEASED == Loc_water_btn_stat)
=======
	else
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
	{
		Loc_water_btn_stat = BUTTON_RELEASED;
		gpio_pin_write_logic(&R00_WaterEnable, LOW);
	}
}
static void man_heater_func()
{
	button_state_t Loc_heater_btn_stat = BUTTON_RELEASED;
	button_read_state(&Man_Heater_Btn, &Loc_heater_btn_stat);
	if(BUTTON_PRESSED == Loc_heater_btn_stat)
	{
		gpio_pin_write_logic(&R01_HeaterEnable, HIGH);
	}
	else
	{
		Loc_heater_btn_stat = BUTTON_RELEASED;
		gpio_pin_write_logic(&R01_HeaterEnable, LOW);
	}
}
static void man_drain_func()
{
	button_state_t Loc_drain_btn_stat = BUTTON_RELEASED;
	button_read_state(&Man_Drain_Btn, &Loc_drain_btn_stat);
	if(BUTTON_PRESSED == Loc_drain_btn_stat)
	{
		gpio_pin_write_logic(&R05_DrainEnable, HIGH);
	}
	else
	{
		Loc_drain_btn_stat = BUTTON_RELEASED;
		gpio_pin_write_logic(&R05_DrainEnable, LOW);
	}
}
static void man_rotat_right_func()
{
	button_state_t Loc_rotat_right_btn_stat = BUTTON_RELEASED;
	button_read_state(&Man_RotatRight_Btn, &Loc_rotat_right_btn_stat);
	if(BUTTON_PRESSED == Loc_rotat_right_btn_stat)
	{
		gpio_pin_write_logic(&R02_RightMotor, HIGH);
	}
	else
	{
		Loc_rotat_right_btn_stat = BUTTON_RELEASED;
		gpio_pin_write_logic(&R02_RightMotor, LOW);
	}
}

static void man_rotat_left_func()
{
	button_state_t Loc_rotat_left_btn_stat = BUTTON_RELEASED;
	button_read_state(&Man_RotateLeft_Btn, &Loc_rotat_left_btn_stat);
	if(BUTTON_PRESSED == Loc_rotat_left_btn_stat)
	{
		gpio_pin_write_logic(&R03_LeftMotor, HIGH);
	}
	else
	{
		Loc_rotat_left_btn_stat = BUTTON_RELEASED;
		gpio_pin_write_logic(&R03_LeftMotor, LOW);
	}
}
static void man_Door_Lock()
{
	button_state_t Loc_door_btn_stat = BUTTON_RELEASED;
	button_read_state(&Door_Contact_Btn, &Loc_door_btn_stat);
	if(BUTTON_PRESSED == Loc_door_btn_stat)
	{
		gpio_pin_write_logic(&Door_Lock_Pin, HIGH);
	}
	else
	{
		Loc_door_btn_stat = BUTTON_RELEASED;
		gpio_pin_write_logic(&Door_Lock_Pin, LOW);
	}
}
<<<<<<< HEAD
static void man_error_choose()
{
	Std_ReturnType Loc_time_out = E_NOK;
	Timer0_Start();
	Loc_time_out = Timr0_Time_Out(0,MAN_ERROR_CHOOSE_TIME);
	if(Loc_time_out == E_OK)
	{
		G_Machine_Current_Mode = ERROR_CHOOSE_MODE;
		Timr0_Time_Out_Stop();
	}
=======

static void clear_lcd_print_comapany(void)
{
	uint8 company_name ="Alaqsaa Company";
	lcd_4bit_clear(&lcd1);
	lcd_4bit_send_string_pos(&lcd1, 1,1,company_name);

>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
}
