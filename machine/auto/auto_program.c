/********************************************************************************
 * @file    auto_program.c
 * @author  Drd
 * @date    Sep 6, 2023
 * @brief   
 ********************************************************************************/


/*****************  INCLUDES   *******************************/
#include "auto_interface.h"
/***************** EXTERN VARIABLES  *************************/
extern Machine_Mode_t G_Machine_Current_Mode; /* @ref : manual interface.h */

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
extern Gpio_pin_config_t  R02_RightMotor ;
//extern Gpio_pin_config_t  R03_LeftMotor;
extern Gpio_pin_config_t  R04_FastEnable;
//extern Gpio_pin_config_t  R05_DrainEnable ;
//extern Gpio_pin_config_t  Door_Lock_Pin;
//extern Gpio_pin_config_t  Buzzer;
//extern Gpio_pin_config_t  LED ;
extern Gpio_pin_config_t  Water_Level_Pin;
//extern Gpio_pin_config_t  Auto_Water_Temp ;

extern chr_lcd_4bit_t lcd1;
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
#define RINS_MOTOR_TIME             2
/* time that motor should run in wash time as required*/
#define WASH_MOTOR_TIME             2
/* time that motor should run in wash time as required*/
#define DRAIN_MOTOR_TIME            2

/*****************  PRIVATE TYPEDEFS   *************************/

/*****************  STATIC VARIABLES   *************************/

/*****************  GLOBAL VARIABLES   *************************/
logic_t G_water_sensor_val = HIGH; /* to read digital i/p of water sensor
 *to enable or disable water motor*/
uint8 G_Rinse_Minut_Counter ;  /*  to save rinse time minutes counting */
uint8 G_Rinse_Sec_Counter ;	   /*  to save rinse time minutes counting */

uint8 G_Wash_Minut_Counter ;  /*  to save wash time minutes counting */
uint8 G_Wash_Sec_Counter ;	   /*  to save wash time minutes counting */

uint8 G_Drain_Minut_Counter ;  /*  to save drain time minutes counting */
uint8 G_Drain_Sec_Counter ;	   /*  to save drain time minutes counting */

Auto_Machine_Status_t G_Auto_Current_stat = ERROR_STAT; /*to know auto current status */

/*****************  STATIC FUNCTION PROTOTYPES   ***************/
static void enable_water(void);
static void disable_water(void);
static void empty_water(void);
static void read_water_level();
static Std_ReturnType water_function();

static void start_motor(void);
static void stop_motor(void);
static Std_ReturnType rinse_motor_function();
static void wash_motor_function();
static void drain_motor_function();

static void fast_speed_enable();
static void fast_speed_disable();

static Std_ReturnType Machine_Rinse();
static void Machine_Washing();
static void Machine_Drain();

/*****************  GLOBAL FUNCTIONS   *************************/
Std_ReturnType Machine_Auto_Process()
{
	Std_ReturnType Ret = E_NOK;
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



/**************static function implementation   *************************/

static Std_ReturnType Machine_Rinse()
{
	Std_ReturnType Ret = E_NOK;
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
}

static void read_water_level()
{
	gpio_pin_read(&Water_Level_Pin, &G_water_sensor_val);
}


static void start_motor(void)
{
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
	{
		stop_motor();
		Timer0_Stop();
		G_Rinse_Minut_Counter = 0;
		G_Rinse_Sec_Counter = 0;
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
}

static void fast_speed_enable()
{
	gpio_pin_write_logic(&R04_FastEnable, HIGH);
}
static void fast_speed_disable()
{
	gpio_pin_write_logic(&R04_FastEnable, LOW);
}

static void empty_water(void)
{

	gpio_pin_write_logic(&R00_WaterEnable, HIGH);
	/* wait  some time for empty water */
	gpio_pin_write_logic(&R00_WaterEnable, LOW);

}


static Std_ReturnType water_function()
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

////////////////////////////////////////////////////////////////////////////////
Std_ReturnType Print_Time(chr_lcd_4bit_t *lcd,uint8 row,uint8 col,uint8 min, uint8 sec)
{
	Std_ReturnType Ret = E_NOK;

	lcd_4bit_send_string_pos(&lcd1, row, col, "  :  ");
	lcd_4bit_send_num_pos(&lcd1, row, col, min);
	lcd_4bit_send_num_pos(&lcd1, row, col+3, sec);



	return Ret;
}
