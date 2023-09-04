/********************************************************************************
 * @file    Machine.c
 * @author  Drd
 * @date    Sep 3, 2023
 * @brief   
 ********************************************************************************/


/*****************  INCLUDES   *******************************/
#include "Machine.h"
/***************** EXTERN VARIABLES  *************************/

/***************** PRIVATE MACROS AND DEFINES  ****************/
#define WASHING_TIME_MINUTS         4U
#define RINSE_TIME_MINUTS           2U
#define DRAIN_TIME_MINUTS           1U
/*****************  global variables    *************************/
Auto_Machine_Status_t auto_machine_current_state = RINSE_STATE;
Machine_Mode_t  machine_state_mode = STOP_MODE;
/*****************  STATIC VARIABLES   *************************/
/* Water_Pin   To Enable Water Fill  */
static Gpio_pin_config_t  Water_Pin = {.port = PORTB, .pin = GPIO_PIN4,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
/*******************************************************************************/
/* Heater_Pin  To Enable Heater */
static Gpio_pin_config_t  Heater_Pin = {.port = PORTB, .pin = GPIO_PIN5,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
/*******************************************************************************/
/* Rotate_Right_Pin  To Enable Rotate Right */
static Gpio_pin_config_t  Rotate_Right_Pin = {.port = PORTB, .pin = GPIO_PIN6,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};

/*******************************************************************************/
/* Rotate_Left_Pin  To Enable Rotate Left */
static Gpio_pin_config_t  Rotate_Left_Pin = {.port = PORTB, .pin = GPIO_PIN7,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
/*******************************************************************************/
/* Drain_Pin  To Enable Drain  */
static Gpio_pin_config_t  Drain_Pin = {.port = PORTC, .pin = GPIO_PIN7,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
/*******************************************************************************/
/* Buzzer_Pin  To Alarm   */
static Gpio_pin_config_t  Buzzer_Pin = {.port = PORTC, .pin = GPIO_PIN6,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
/*******************************************************************************/
/* Led_Pin  To Alarm   */
static Gpio_pin_config_t  Led_Pin = {.port = PORTC, .pin = GPIO_PIN5,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
/*******************************************************************************/
/* Water_Level_Pin  To Read Water Level Sensor   */
static Gpio_pin_config_t  Water_Level_Pin = {.port = PORTD, .pin = GPIO_PIN0,
		.direction = GPIO_PIN_INPOT };

/*******************************************************************************/
/* Manual_Mode_Pin  To Read Manual Mode BTN   */
static button_t  Manual_Mode_Btn ={.button_pin.port = PORTC,.button_pin.pin = GPIO_PIN1,
		.button_state = BUTTON_RELEASED,.button_connection = BUTTON_ACTIVE_LOW};

/*******************************************************************************/
/* Manual_Mode_Pin  To Read Auto Mode BTN   */
button_t  Auto_Mode_Btn ={.button_pin.port = PORTC,.button_pin.pin = GPIO_PIN0,
		.button_state = BUTTON_RELEASED,.button_connection = BUTTON_ACTIVE_LOW};
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
/* wait to ensure that is required from client    */
static Gpio_pin_config_t  Empty_water_Pin = {.port = PORTB, .pin = GPIO_PIN0,
		.direction = GPIO_PIN_OUTPOT, .logic = LOW};
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/


/*****************  GLOBAL VARIABLES   *************************/

/*****************  static function prototype   ***************/
static void start_water(void);
static void stop_water(void);
static void start_motor(void);
static void stop_motor(void);
static void empty_water(void);
static void read_water_level(uint8 * water_level_value);
static void read_mode_btns(Machine_Mode_t * btn_val);
/* to calculate washing time  return E_OK if time complete*/
static void calculate_washing_time(Std_ReturnType * time);
/* to calculate rinse time  return E_OK if time complete*/
static void calculate_rinse_time(Std_ReturnType * time);
/* to calculate drain time  return E_OK if time complete*/
static void calculate_drain_time(Std_ReturnType * time);
static Std_ReturnType Machine_Rinse(Std_ReturnType * state);
static Std_ReturnType Machine_Washing(Std_ReturnType * state);
static Std_ReturnType Machine_Drain(Std_ReturnType * state);

/*****************  GLOBAL FUNCTIONS   *************************/
void Machine_Init()
{
	gpio_pin_initialize(&Water_Pin);
	gpio_pin_initialize(&Heater_Pin);
	gpio_pin_initialize(&Rotate_Right_Pin);
	gpio_pin_initialize(&Rotate_Left_Pin);
	gpio_pin_initialize(&Drain_Pin);
	gpio_pin_initialize(&Buzzer_Pin);
	gpio_pin_initialize(&Led_Pin);
	gpio_pin_initialize(&Empty_water_Pin);
	gpio_pin_initialize(&Water_Level_Pin);
	button_initialize(&Manual_Mode_Btn);
	button_initialize(&Auto_Mode_Btn);


}
Std_ReturnType Machine_Select_Mode(Machine_Mode_t *machine_mode)
{
	Machine_Mode_t  Loc_btn_val =STOP_MODE;
	Std_ReturnType Ret = E_NOK;
	if(NULL == machine_mode)
	{
		Ret = E_NOK;
	}
	else
	{
		read_mode_btns(&Loc_btn_val);
		*machine_mode = Loc_btn_val;
		Ret = E_OK;
	}
	return Ret;
}
Std_ReturnType Machine_Auto_Function()
{
	Std_ReturnType Ret = E_NOK;
	Std_ReturnType Loc_M_Rinse_state = E_NOK;
	Std_ReturnType Loc_M_Rinse_state2 = E_NOK;
	Std_ReturnType Loc_M_Wash_state = E_NOK;
	Std_ReturnType Loc_M_Drain_state = E_NOK;
	switch (auto_machine_current_state)
	{
	case RINSE_STATE:
	{
		Machine_Rinse(&Loc_M_Rinse_state);
		if(E_OK == Loc_M_Rinse_state)
		{
			auto_machine_current_state = WASHING_STATE;
		}
		break;
	}
	case WASHING_STATE:
	{
		Machine_Washing(&Loc_M_Wash_state);
		if(E_OK == Loc_M_Wash_state)
		{
			auto_machine_current_state = WASHING_STATE;
		}
		break;
	}
	case RINSE_STATE2:
	{
		Machine_Rinse(&Loc_M_Rinse_state2);
		if(E_OK == Loc_M_Rinse_state2)
		{
			auto_machine_current_state = DRAIN_STATE;
		}
		break;
	}
	case DRAIN_STATE:
	{
		Machine_Drain(&Loc_M_Drain_state);
		if(E_OK == Loc_M_Drain_state)
				{
					auto_machine_current_state = END_STATE;
				}
		break;
	}
	case END_STATE:
	{
		break;
	}
	default:
	{

	}
	}

	return Ret;

}
Std_ReturnType Machine_Manual_Function()
{
	Std_ReturnType Ret = E_NOK;



	return Ret;
}



/*****************  static function    *************************/
static Std_ReturnType Machine_Rinse(Std_ReturnType * state)
{
	Std_ReturnType Ret =E_NOK;
	Std_ReturnType Loc_state = E_NOK;
	uint8 Loc_water_level_value =0;
	Std_ReturnType Loc_timer_value =0;
	if(RINSE_STATE == auto_machine_current_state)
	{
		/*start filling water*/
		start_water();
		/* wait water level sensor*/
		read_water_level(&Loc_water_level_value);
		if(HIGH == Loc_water_level_value)
		{

			/*stop water filling*/
			stop_water();
			/*star motor with rinse time*/
			start_motor();
			/*calculate rinse time*/
			calculate_rinse_time(&Loc_timer_value);
			if(E_OK == Loc_timer_value)
			{
				stop_motor();
				/*empty water */
				empty_water();
				Loc_state = E_OK;
			}
		}
		Ret =E_OK;
	}
	else
	{
		Ret =E_NOK;
		Loc_state = E_NOK;
	}
	* state = Loc_state;
	return Ret;
}
static Std_ReturnType Machine_Washing(Std_ReturnType * state)
{
	Std_ReturnType Ret =E_NOK;
	Std_ReturnType Loc_state = E_NOK;
	uint8 Loc_water_level_value =0;
	if(NULL == state)
	{

		Ret =E_OK;
	}
	else
	{
		Ret =E_NOK;
	}
	return Ret;
}

static Std_ReturnType Machine_Drain(Std_ReturnType * state)
{
	Std_ReturnType Ret =E_NOK;
	uint8 Loc_water_level_value =0;
	if(NULL == state)
	{
		Ret =E_OK;
	}
	else
	{
		Ret =E_NOK;
	}
	return Ret;
}

static void start_water(void)
{
	gpio_pin_write_logic(&Water_Pin, HIGH);
}
static void stop_water(void)
{
	gpio_pin_write_logic(&Water_Pin, LOW);
}
static void start_motor(void)
{
	gpio_pin_write_logic(&Rotate_Right_Pin, HIGH);
}
static void stop_motor(void)
{
	gpio_pin_write_logic(&Rotate_Right_Pin, LOW);
}
static void empty_water(void)
{
	gpio_pin_write_logic(&Rotate_Right_Pin, HIGH);
	/* wait  some time for empty water */
	gpio_pin_write_logic(&Rotate_Right_Pin, LOW);
}

static void read_water_level(uint8 * water_level_value)
{
	gpio_pin_read(&Water_Level_Pin, water_level_value);
}
/* to calculate washing time  return E_OK if time complete*/
static void calculate_washing_time(Std_ReturnType * time)
{
	static uint8 Loc_second =0;
	static uint8 Loc_minut =0;
	if(WASHING_STATE == auto_machine_current_state)
	{
		Timer0_Start();
		Timer0_Calculate_Min_And_Sec(&Loc_minut, &Loc_second);
		if(WASHING_TIME_MINUTS == Loc_minut)
		{
			*time = E_OK;
			Timer0_Stop();
		}
		else
		{
			*time = E_NOK;
		}
	}
	else
	{
		/*Do Nothing*/
	}
}
/* to calculate rinse time  return E_OK if time complete*/
static void calculate_rinse_time(Std_ReturnType * time)
{
	static uint8 Loc_second =0;
	static uint8 Loc_minut =0;
	if(RINSE_STATE == auto_machine_current_state)
	{
		Timer0_Start();
		Timer0_Calculate_Min_And_Sec(&Loc_minut, &Loc_second);
		if(RINSE_TIME_MINUTS == Loc_minut)
		{
			*time = E_OK;
			Timer0_Stop();
		}
		else
		{
			*time = E_NOK;
		}
	}
	else
	{
		/*Do Nothing*/
	}
}
/* to calculate drain time  return E_OK if time complete*/
static void calculate_drain_time(Std_ReturnType * time)
{
	static uint8 Loc_second =0;
	static uint8 Loc_minut =0;
	if(DRAIN_STATE == auto_machine_current_state)
	{
		Timer0_Start();
		Timer0_Calculate_Min_And_Sec(&Loc_minut, &Loc_second);
		if(DRAIN_TIME_MINUTS == Loc_minut)
		{
			*time = E_OK;
			Timer0_Stop();
		}
		else
		{
			*time = E_NOK;
		}
	}
	else
	{
		/*Do Nothing*/
	}
}

static void read_mode_btns(Machine_Mode_t * btn_val)
{
	//	Machine_Mode_t  Loc_btn_val = STOP_MODE;
	button_state_t  Loc_Auto_btn_val = BUTTON_RELEASED;
	button_state_t  Loc_Man_btn_val = BUTTON_RELEASED;

	button_read_state(&Auto_Mode_Btn, &Loc_Auto_btn_val);
	button_read_state(&Manual_Mode_Btn, &Loc_Man_btn_val);

	if((BUTTON_PRESSED == Loc_Auto_btn_val) && (BUTTON_RELEASED == Loc_Man_btn_val))
	{
		*btn_val = AUTO_MODE;
		Loc_Man_btn_val = BUTTON_RELEASED;
	}
	else if((BUTTON_PRESSED == Loc_Man_btn_val) && (BUTTON_RELEASED ==  Loc_Auto_btn_val))
	{
		*btn_val = MANUAL_MODE;
		Loc_Auto_btn_val = BUTTON_RELEASED;
	}
	else if((BUTTON_PRESSED == Loc_Man_btn_val) && (BUTTON_PRESSED == Loc_Auto_btn_val))
	{
		*btn_val = ERROR_CHOOSE_MODE;

		Loc_Auto_btn_val = BUTTON_PRESSED;
		Loc_Man_btn_val = BUTTON_PRESSED;
	}

	else
	{
		*btn_val = STOP_MODE;
		Loc_Auto_btn_val = BUTTON_RELEASED;
		Loc_Man_btn_val = BUTTON_RELEASED;
	}
}
