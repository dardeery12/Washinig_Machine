/********************************************************************************
 * @file    auto_program.c
 * @author  Drd
 * @date    Sep 6, 2023
 * @brief   
 ********************************************************************************/


/*****************  INCLUDES   *******************************/
#include "auto_interface.h"
/***************** EXTERN VARIABLES  *************************/
<<<<<<< HEAD
=======
extern Machine_Mode_t G_Machine_Current_Mode; /* @ref : manual interface.h */
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5

//extern button_t  Mode_Manual_Btn ;
//extern button_t  Mode_Auto_Btn;
//extern button_t  Man_Water_Btn;
//extern button_t  Man_Heater_Btn;
//extern button_t  Man_RotatRight_Btn;
//extern button_t  Man_RotateLeft_Btn;
//extern button_t  Man_Drain_Btn;
//extern button_t  Door_Contact_Btn;
extern button_t  Auto_Start_Btn;
extern Gpio_pin_config_t  R00_WaterEnable;
//extern Gpio_pin_config_t  R01_HeaterEnable;
<<<<<<< HEAD
extern Motor_Cnfg_t  R02_RightMotor ;
//extern Gpio_pin_config_t  R03_LeftMotor;
extern Gpio_pin_config_t  R04_FastEnable;
extern Motor_Cnfg_t       R05_DrainEnable ;
=======
extern Gpio_pin_config_t  R02_RightMotor ;
//extern Gpio_pin_config_t  R03_LeftMotor;
extern Gpio_pin_config_t  R04_FastEnable;
//extern Gpio_pin_config_t  R05_DrainEnable ;
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
//extern Gpio_pin_config_t  Door_Lock_Pin;
//extern Gpio_pin_config_t  Buzzer;
//extern Gpio_pin_config_t  LED ;
extern Gpio_pin_config_t  Water_Level_Pin;
//extern Gpio_pin_config_t  Auto_Water_Temp ;

<<<<<<< HEAD
/*  to run motor the G_Motor_Run_Flag must be = E_OK
 * and to stop motor the G_Motor_Run_Flag must be = E_NOK*/
//extern Std_ReturnType G_Motor_Run_Flag;
//extern Std_ReturnType Timer0_Busy_flag;
extern chr_lcd_4bit_t lcd1;

extern Machine_Mode_t G_Machine_Current_Mode;
=======
extern chr_lcd_4bit_t lcd1;
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
/***************** PRIVATE MACROS AND DEFINES  ****************/
/* washing time as required*/
#define WASHING_TIME_MINUTS         5
/* rinse  time as required */
#define RINSE_TIME_MINUTS           2
/* drain time as required*/
#define DRAIN_TIME_MINUTS           1
/* fast drain time as required*/
#define FAST_DRAIN_TIME_MINUTS      1

/* time that motor should run in rinse time as required*/
<<<<<<< HEAD
#define RINS_MOTOR_TIME             1
/* time that motor should run in wash time as required*/
#define WASH_MOTOR_TIME             1
/* time that motor should run in wash time as required*/
#define DRAIN_MOTOR_TIME            1
=======
#define RINS_MOTOR_TIME             2
/* time that motor should run in wash time as required*/
#define WASH_MOTOR_TIME             2
/* time that motor should run in wash time as required*/
#define DRAIN_MOTOR_TIME            2
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5

/*****************  PRIVATE TYPEDEFS   *************************/

/*****************  STATIC VARIABLES   *************************/

/*****************  GLOBAL VARIABLES   *************************/
<<<<<<< HEAD

button_state_t G_auto_start_btn_stat = BUTTON_RELEASED; /* to save if auto start  btn status*/

logic_t G_water_sensor_val = HIGH; /* to read digital i/p of water sensor
 *to enable or disable water motor*/


Std_ReturnType G_Rinse_Flag_Don   = E_NOK; /* this flag is used to indicate if rinse function  don complelte or not*/
Std_ReturnType G_Washe_Flag_Don   = E_NOK; /* this flag is used to indicate if rinse function  don complelte or not*/
Std_ReturnType G_Drin_Flag_Don  	= E_NOK; /* this flag is used to indicate if rinse function  don complelte or not*/

=======
logic_t G_water_sensor_val = HIGH; /* to read digital i/p of water sensor
 *to enable or disable water motor*/
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
uint8 G_Rinse_Minut_Counter ;  /*  to save rinse time minutes counting */
uint8 G_Rinse_Sec_Counter ;	   /*  to save rinse time minutes counting */

uint8 G_Wash_Minut_Counter ;  /*  to save wash time minutes counting */
uint8 G_Wash_Sec_Counter ;	   /*  to save wash time minutes counting */

uint8 G_Drain_Minut_Counter ;  /*  to save drain time minutes counting */
uint8 G_Drain_Sec_Counter ;	   /*  to save drain time minutes counting */

<<<<<<< HEAD
//Auto_Machine_Status_t G_Auto_Current_stat = RINSE_STATE; /*to know auto current status */
Auto_Machine_Status_t G_auto_current_stat = RINSE_STATE;
=======
Auto_Machine_Status_t G_Auto_Current_stat = ERROR_STAT; /*to know auto current status */
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5

/*****************  STATIC FUNCTION PROTOTYPES   ***************/
static void enable_water(void);
static void disable_water(void);
<<<<<<< HEAD
static Std_ReturnType empty_water(void);
static void read_water_level();
Std_ReturnType water_function();

static void start_motor(void);
static void stop_motor(void);
Std_ReturnType rinse_motor_function();
static Std_ReturnType wash_motor_function();
static Std_ReturnType drain_motor_function();
=======
static void empty_water(void);
static void read_water_level();
static Std_ReturnType water_function();

static void start_motor(void);
static void stop_motor(void);
static Std_ReturnType rinse_motor_function();
static void wash_motor_function();
static void drain_motor_function();
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5

static void fast_speed_enable();
static void fast_speed_disable();

static Std_ReturnType Machine_Rinse();
<<<<<<< HEAD
Std_ReturnType Machine_Washing();
static Std_ReturnType Machine_Drain();


static void drain_motor_Run();
static void drain_motor_stop();

/***********************************************************************/
Std_ReturnType Machine_Rinse_flag_Don   = E_NOK;
Std_ReturnType Machine_Wash_flag_Don    = E_NOK;
Std_ReturnType Machine_Drain_flag_Don   = E_NOK;
Std_ReturnType Machine_Rinse2_flag_Don  = E_NOK;

Auto_Machine_Status_t slect_auto_stat()
{
	static Auto_Machine_Status_t state = RINSE_STATE;
	if(E_OK == Machine_Rinse_flag_Don)
	{
		state = WASHING_STATE;
		Machine_Rinse_flag_Don   = E_NOK;

	}
	else if(E_OK == Machine_Wash_flag_Don)
	{
		state = RINSE_STATE2;
		Machine_Wash_flag_Don    = E_NOK;

	}
	else if(E_OK == Machine_Rinse2_flag_Don)
	{
		state = DRAIN_STATE;
		Machine_Rinse2_flag_Don  = E_NOK;
	}
	else if(E_OK == Machine_Drain_flag_Don)
	{
		state = END_STATE;
		Machine_Rinse_flag_Don   = E_NOK;
		Machine_Wash_flag_Don    = E_NOK;
		Machine_Drain_flag_Don   = E_NOK;
		Machine_Rinse2_flag_Don  = E_NOK;
	}
	else if ((Machine_Rinse_flag_Don == E_NOK) && (Machine_Wash_flag_Don == E_NOK))
	{
		if((Machine_Drain_flag_Don == E_NOK) && (Machine_Rinse2_flag_Don == E_NOK))
		{
			//state = ERROR_STAT;
		}
	}

	return state;
}

/***********************************************************************/
=======
static void Machine_Washing();
static void Machine_Drain();
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5

/*****************  GLOBAL FUNCTIONS   *************************/
Std_ReturnType Machine_Auto_Process()
{
	Std_ReturnType Ret = E_NOK;
<<<<<<< HEAD
	if(G_auto_start_btn_stat == BUTTON_RELEASED)
	{
		button_read_state(&Auto_Start_Btn, &G_auto_start_btn_stat);
	}
	if(BUTTON_PRESSED == G_auto_start_btn_stat)
	{
		//current_stat = slect_auto_stat();
		switch(G_auto_current_stat)
		{
		case RINSE_STATE:
			Machine_Rinse_flag_Don = Machine_Rinse();
			if(Machine_Rinse_flag_Don == E_OK)
			{
				G_auto_current_stat = WASHING_STATE;
			}
			break;
		case WASHING_STATE:
			Machine_Wash_flag_Don = Machine_Washing();
			if(Machine_Wash_flag_Don == E_OK)
			{
				G_auto_current_stat = RINSE_STATE2;
			}
			break;
		case RINSE_STATE2:
			Machine_Rinse2_flag_Don = Machine_Rinse();
			if(E_OK == Machine_Rinse2_flag_Don)
			{
				G_auto_current_stat = DRAIN_STATE;
			}
			break;
		case DRAIN_STATE:
			Machine_Drain_flag_Don = Machine_Drain();
			if(E_OK == Machine_Drain_flag_Don)
			{
				G_auto_current_stat = END_STATE;
			}
			break;
		case END_STATE:
			G_Machine_Current_Mode = ERROR_CHOOSE_MODE;
			break;
		}
	}
	else
	{
		/*Do Nothing*/
	}

	return Ret ;
}


=======
	Std_ReturnType Machine_Rinse_flag   = E_NOK;
	Std_ReturnType Machine_Wash_flag    = E_NOK;
	Std_ReturnType Machine_Drain_flag   = E_NOK;
	Std_ReturnType Machine_Rinse2_flag  = E_NOK;

	button_state_t Loc_auto_Btn_Val = BUTTON_RELEASED;

		button_read_state(&Auto_Start_Btn, &Loc_auto_Btn_Val);
		lcd_4bit_send_num_pos(&lcd1,1,1 ,Loc_auto_Btn_Val);
		if(BUTTON_PRESSED == Loc_auto_Btn_Val)
		{
			switch(G_Auto_Current_stat)
			{
			case  RINSE_STATE :
				lcd_4bit_send_num_pos(&lcd1,1,8 ,G_Auto_Current_stat);
				Machine_Rinse_flag = Machine_Rinse();
				if(E_OK == Machine_Rinse_flag)
				{
					G_Auto_Current_stat = WASHING_STATE;
				}
				else
				{
					G_Auto_Current_stat = RINSE_STATE;
				}
				break;
			case WASHING_STATE  :
				Machine_Washing();
				break;
			case  DRAIN_STATE :
				Machine_Drain();
				break;
			case  RINSE_STATE2 :
				Machine_Rinse();
				break;
			case  END_STATE :
				G_Auto_Current_stat = ERROR_STAT;
				break;
			default   :
				break;
			}
		}
		else
		{
			/*Do Nothing*/
		}

	return Ret ;

}



>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
/**************static function implementation   *************************/

static Std_ReturnType Machine_Rinse()
{
	Std_ReturnType Ret = E_NOK;
<<<<<<< HEAD
	Std_ReturnType Loc_water_flag = E_NOK;  /* remember to change Loc_water_flag to E_NOK*/
	Std_ReturnType Loc_motor_flag = E_NOK;
	//Std_ReturnType Loc_empty_water_flag = E_OK; /* take care about water flag = E_OK*/

	Loc_water_flag = water_function();

	if(E_OK == Loc_water_flag)
	{

		Loc_motor_flag = rinse_motor_function();
	}
	if(E_OK == Loc_motor_flag)
	{
		empty_water();
	}
	if(Loc_motor_flag == E_OK)
	{
		Ret = E_OK;
	}
	/*else
	{
		Ret = E_NOK;
	}*/
	return Ret;
}
Std_ReturnType Machine_Washing()
{
	Std_ReturnType Ret = E_NOK;
	static Std_ReturnType water_flag = E_NOK;
	static Std_ReturnType wash_flag = E_NOK;
	static Std_ReturnType empty_flag = E_OK;
	water_flag = water_function();
	wash_flag = wash_motor_function();
	empty_flag = empty_water();

	if(E_OK == water_flag)
	{
		if(E_OK == wash_flag)
		{
			if(E_OK == empty_flag)
			{
				Ret = E_OK;
			}
		}
	}
	return Ret;
}

static Std_ReturnType Machine_Drain()
{
	Std_ReturnType Ret = E_NOK;
	Std_ReturnType Loc_drain_flag = E_NOK;
	Loc_drain_flag = drain_motor_function();
	if(E_OK == Loc_drain_flag)
	{
		Ret = E_OK;
	}
	return Ret;
=======
	Std_ReturnType Loc_water_flag = E_NOK;
	Std_ReturnType Loc_motor_flag = E_NOK;
	//Std_ReturnType Loc_empty_water_flag = E_OK; /* take care about water flag = E_OK*/
	lcd_4bit_send_num_pos(&lcd1,2,1 ,Loc_water_flag);
	Loc_water_flag = water_function();
	Loc_motor_flag = rinse_motor_function();

	lcd_4bit_send_num_pos(&lcd1,3,1 ,Loc_motor_flag);
	empty_water();

	if(Loc_water_flag && Loc_motor_flag )
	{
		Ret = E_OK;
	}
	else
	{
		Ret = E_NOK;
	}

	return Ret;
}

static void Machine_Washing()
{

	water_function();
	wash_motor_function();
	empty_water();

}

static void Machine_Drain()
{

	drain_motor_function();
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
}

static void read_water_level()
{
	gpio_pin_read(&Water_Level_Pin, &G_water_sensor_val);
}


static void start_motor(void)
{
<<<<<<< HEAD
	Motor_Run(&R02_RightMotor);
}
static void stop_motor(void)
{

	Motor_Stop(&R02_RightMotor);

}

Std_ReturnType rinse_motor_function()
{
	Std_ReturnType Ret = E_NOK;
	start_motor();
	Timer0_Start();
	Timer0_Calculate_Min_And_Sec(&G_Rinse_Sec_Counter, &G_Rinse_Minut_Counter);
	if(G_Rinse_Minut_Counter >= RINS_MOTOR_TIME)
=======
	gpio_pin_write_logic(&R02_RightMotor, HIGH);
}
static void stop_motor(void)
{
	gpio_pin_write_logic(&R02_RightMotor, LOW);
}

static Std_ReturnType rinse_motor_function()
{
	Std_ReturnType Ret = E_NOK;
	start_motor();

	Timer0_Start();
	Timer0_Calculate_Min_And_Sec(&G_Rinse_Sec_Counter, &G_Rinse_Minut_Counter);
	if(RINS_MOTOR_TIME == G_Rinse_Minut_Counter)
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
	{
		stop_motor();
		Timer0_Stop();
		G_Rinse_Minut_Counter = 0;
		G_Rinse_Sec_Counter = 0;
<<<<<<< HEAD
		G_Rinse_Flag_Don   = E_OK;
		Ret = E_OK;
	}
	else
	{
		/* handle error or done */
	}
	return Ret;
}
static Std_ReturnType wash_motor_function()
{
	Std_ReturnType Ret = E_NOK;
	if(E_NOK == G_Washe_Flag_Don)
	{
		start_motor();
		Timer0_Start();
		Timer0_Calculate_Min_And_Sec(&G_Wash_Sec_Counter, &G_Wash_Minut_Counter);
		if(G_Wash_Minut_Counter >= WASH_MOTOR_TIME)
		{

			stop_motor();
			Timer0_Stop();
			G_Wash_Minut_Counter = 0;
			G_Wash_Sec_Counter = 0;
			G_Washe_Flag_Don   = E_OK;
			Ret = E_OK;
		}
		/*else
		{
			Ret = E_NOK;
		}*/
	}
	else
	{
		/* handle error or done */
	}
	return Ret;

}


static Std_ReturnType drain_motor_function()
{
	fast_speed_enable();
	Std_ReturnType Ret = E_NOK;

	/* Drain */
	drain_motor_Run();
	Timer0_Start();
	Timer0_Calculate_Min_And_Sec(&G_Drain_Sec_Counter, &G_Drain_Minut_Counter);
	if(G_Drain_Minut_Counter >= DRAIN_MOTOR_TIME)
	{
		drain_motor_stop();
		Timer0_Stop();
		G_Drain_Minut_Counter = 0;
		G_Drain_Sec_Counter = 0;
		Ret = E_OK;
	}
	/*else
	{
		/* handle error or done */
	//}
	return Ret;

=======
		Ret = E_OK;
	}
	return Ret;
}
static void wash_motor_function()
{

	start_motor();

	Timer0_Start();
	Timer0_Calculate_Min_And_Sec(&G_Wash_Sec_Counter, &G_Wash_Minut_Counter);
	if(WASH_MOTOR_TIME == G_Wash_Minut_Counter)
	{
		stop_motor();
		Timer0_Stop();
		G_Wash_Minut_Counter = 0;
		G_Wash_Sec_Counter   = 0;
	}
}

static void drain_motor_function()
{
	fast_speed_enable();

	Timer0_Start();
	Timer0_Calculate_Min_And_Sec(&G_Drain_Sec_Counter, &G_Drain_Minut_Counter);
	if(DRAIN_MOTOR_TIME == G_Drain_Minut_Counter)
	{
		fast_speed_disable();
		Timer0_Stop();
		G_Drain_Minut_Counter = 0;
		G_Drain_Sec_Counter   = 0;
	}
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
}

static void fast_speed_enable()
{
	gpio_pin_write_logic(&R04_FastEnable, HIGH);
}
static void fast_speed_disable()
{
	gpio_pin_write_logic(&R04_FastEnable, LOW);
}

<<<<<<< HEAD
static Std_ReturnType empty_water(void)
{
	Std_ReturnType Ret = E_OK;
	gpio_pin_write_logic(&R00_WaterEnable, HIGH);
	/* wait  some time for empty water */
	gpio_pin_write_logic(&R00_WaterEnable, LOW);
	return Ret;
}


Std_ReturnType water_function()
=======
static void empty_water(void)
{

	gpio_pin_write_logic(&R00_WaterEnable, HIGH);
	/* wait  some time for empty water */
	gpio_pin_write_logic(&R00_WaterEnable, LOW);

}


static Std_ReturnType water_function()
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
{
	Std_ReturnType Ret = E_NOK;
	read_water_level();
	if(LOW == G_water_sensor_val)
	{
		enable_water();
		Ret = E_NOK;
	}
	else
	{
		disable_water();
		Ret = E_OK;
	}
	return Ret;
}
static void enable_water(void)
{
	gpio_pin_write_logic(&R00_WaterEnable, HIGH);
}
static void disable_water(void)
{
	gpio_pin_write_logic(&R00_WaterEnable, LOW);
}

<<<<<<< HEAD
Std_ReturnType Print_Time(chr_lcd_4bit_t *lcd,uint8 row,uint8 col,uint8 min, uint8 sec)
{
	Std_ReturnType Ret = E_NOK;
	static uint8 sec_flag = 0;
	static uint8 min_flag = 120;  /* min_flag = 120 any number it just for flag*/

	if(sec == 0)
	{
		lcd_4bit_send_string_pos(&lcd1, row, col+3, "00");

	}
	if((sec == 0) && (min == 0))
	{
		lcd_4bit_send_string_pos(&lcd1, row, col, "00:");

	}
	if(sec_flag != sec)
	{
		if(sec<10)
		{
			lcd_4bit_send_num_pos(&lcd1, row, col+4, sec);
		}
		else
		{
			lcd_4bit_send_num_pos(&lcd1, row, col+3, sec);
		}
		sec_flag = sec;
	}
	if(min_flag != min)
	{
		if(min<10)
		{
			lcd_4bit_send_num_pos(&lcd1, row, col+1, min);
		}
		else
		{
			lcd_4bit_send_num_pos(&lcd1, row, col, min);
		}
		min_flag = min;
	}

	return Ret;
}

static void drain_motor_Run()
{
	Motor_Run(&R05_DrainEnable);
}
static void drain_motor_stop()
{
	Motor_Stop(&R05_DrainEnable);
}




=======
////////////////////////////////////////////////////////////////////////////////
Std_ReturnType Print_Time(chr_lcd_4bit_t *lcd,uint8 row,uint8 col,uint8 min, uint8 sec)
{
	Std_ReturnType Ret = E_NOK;

	lcd_4bit_send_string_pos(&lcd1, row, col, "  :  ");
	lcd_4bit_send_num_pos(&lcd1, row, col, min);
	lcd_4bit_send_num_pos(&lcd1, row, col+3, sec);



	return Ret;
}
>>>>>>> 1620340d295595eb636486b3db92cf013d0c5ac5
