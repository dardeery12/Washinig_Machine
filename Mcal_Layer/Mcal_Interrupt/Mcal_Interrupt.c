/**
 ********************************************************************************
 * @file    Mcal_Interrupt.c
 * @author  Drd
 * @date    Jul 29, 2023
 * @brief   
 ********************************************************************************/

/*****************  INCLUDES   *******************************/
#include "../Mcal_Maneger/Mcal_Maneger.h"

#if   EXT_INTERRUPT_ACTIVE == ENABLE
#include "Mcal_Interrupt_Interface.h"

/***************** EXTERN VARIABLES  *************************/

 
/*****************  STATIC FUNCTION PROTOTYPES  ****************/
/**
 * helper function to select external interrupt sours
 * @param Interrupt_Cnfg_obj
 * @return     Standard Return Type
 */


/**
 * helper function to set  interrupt INT0, INT1, INT2 sense edge
 * INTERRUPT_FALLING_EDGE
 * INTERRUPT_RISING_EDGE
 * INTERRUPT_LOGICAL_CHANGE
 * INTERRUPT_LOW_LEVEL
 * @param Interrupt_Cnfg_obj
 * @return
 */

/**
 * helper function to set  only interrupt0 sense edge
 * INTERRUPT_FALLING_EDGE
 * INTERRUPT_RISING_EDGE
 * INTERRUPT_LOGICAL_CHANGE
 * INTERRUPT_LOW_LEVEL
 * @param Interrupt_Cnfg_obj
 * @return
 */

/**
 * helper function to set  only interrupt1 sense edge
 * INTERRUPT_FALLING_EDGE
 * INTERRUPT_RISING_EDGE
 * INTERRUPT_LOGICAL_CHANGE
 * INTERRUPT_LOW_LEVEL
 * @param Interrupt_Cnfg_obj
 * @return
 */

/**
 * helper function to set  only interrupt2 sense edge
 * INTERRUPT_FALLING_EDGE
 * INTERRUPT_RISING_EDGE
 * INTERRUPT_LOGICAL_CHANGE
 * INTERRUPT_LOW_LEVEL
 * @param Interrupt_Cnfg_obj
 * @return
 */
static Std_ReturnType Ext_Interrupt_Select_INTx(Interrupt_Cnfg_t * Interrupt_Cnfg_obj);
static Std_ReturnType Ext_Interrupt_INTx_Set_Sence(Interrupt_Cnfg_t * Interrupt_Cnfg_obj);
static Std_ReturnType Ext_Interrupt0_Set_Sence(Interrupt_Cnfg_t * Interrupt_Cnfg_obj);
static Std_ReturnType Ext_Interrupt1_Set_Sence(Interrupt_Cnfg_t * Interrupt_Cnfg_obj);
static Std_ReturnType Ext_Interrupt2_Set_Sence(Interrupt_Cnfg_t * Interrupt_Cnfg_obj);
static Std_ReturnType Ext_Interrupt_Set_Pin(Interrupt_Cnfg_t * Interrupt_Cnfg_obj);

static Std_ReturnType Ext_Interrupt_Tx_Set_Handler(Interrupt_Cnfg_t * Interrupt_Cnfg_obj) ;
static Std_ReturnType Ext_Interrupt0_Set_Handler(void (*interrupt_handle)(void)) ;
static Std_ReturnType Ext_Interrupt1_Set_Handler(void (*interrupt_handle)(void)) ;
static Std_ReturnType Ext_Interrupt2_Set_Handler(void (*interrupt_handle)(void)) ;

static void (*Ext_Interrupt0_Handler)(void);
static void (*Ext_Interrupt1_Handler)(void);
static void (*Ext_Interrupt2_Handler)(void);


/*****************  GLOBAL FUNCTIONS   *************************/
Std_ReturnType Interrupt_External_Init(Interrupt_Cnfg_t * Interrupt_Cnfg_obj)
{
	Std_ReturnType ret = E_NOK, ret1 = E_NOK, ret2 = E_NOK, ret3 = E_NOK, ret4 = E_NOK, ret5 = E_NOK ;
	if(NULL == Interrupt_Cnfg_obj)
	{
		ret = E_NOK;
	}
	else
	{

		/* Set INT1 and INT0 bits in the General Interrupt Control Register (GICR) */
		ret1 = Ext_Interrupt_Select_INTx(Interrupt_Cnfg_obj);

		/* Configure MCU Control Register (MCUCR) to select interrupt sense.*/
		ret2 = Ext_Interrupt_INTx_Set_Sence(Interrupt_Cnfg_obj);

		/* Set Global Interrupt(I-bit) Enable bit in the AVR Status Register(SREG)*/
		ret3 = Interrupt_Global_Enable();

		/*set interrupt pin as input */
		ret4 = Ext_Interrupt_Set_Pin(Interrupt_Cnfg_obj);

		/* Handle the interrupt in the Interrupt Service Routine code*/
		ret5 = Ext_Interrupt_Tx_Set_Handler(Interrupt_Cnfg_obj);

		ret = (ret1 && ret2 && ret3 && ret4 && ret5 );
	}
	return ret;
}
Std_ReturnType Interrupt_External_Dinit(Interrupt_Cnfg_t * Interrupt_Cnfg_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == Interrupt_Cnfg_obj)
	{
		ret = E_NOK;
	}
	else
	{
		ret = E_OK;
	}
	return ret;
}

Std_ReturnType Interrupt_Global_Enable(void)
{
	Std_ReturnType ret = E_NOK;
	//SREG  |=(1<<7);
	INTERRUPT_GLOBAL_ENABLE();
	ret = E_OK;
	return ret;
}

Std_ReturnType Interrupt_Global_Disable(void)
{
	Std_ReturnType ret = E_NOK;

	INTERRUPT_GLOBAL_ENABLE();
	ret = E_OK;
	return ret;
}

/*****************  STATIC FUNCTIONS   *************************/
static Std_ReturnType Ext_Interrupt_INTx_Set_Sence(Interrupt_Cnfg_t * Interrupt_Cnfg_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == Interrupt_Cnfg_obj)
	{
		ret = E_NOK;
	}
	else
	{
		switch(Interrupt_Cnfg_obj->Interrupt_Num)
		{
		case INTERRUPT_EXTERNAL_INT0:
			Ext_Interrupt0_Set_Sence(Interrupt_Cnfg_obj);
			break;
		case INTERRUPT_EXTERNAL_INT1:
			Ext_Interrupt1_Set_Sence(Interrupt_Cnfg_obj);
			break;
		case INTERRUPT_EXTERNAL_INT2:
			Ext_Interrupt2_Set_Sence(Interrupt_Cnfg_obj);
			break;
		default :
			ret = E_NOK;
			break;
		}
		ret = E_OK;
	}
	return ret;
}

static Std_ReturnType Ext_Interrupt_Select_INTx(Interrupt_Cnfg_t * Interrupt_Cnfg_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == Interrupt_Cnfg_obj)
	{
		ret = E_NOK;
	}
	else
	{
		switch(Interrupt_Cnfg_obj->Interrupt_Num)
		{
		case INTERRUPT_EXTERNAL_INT0:
			INTERRUPT_EXT_INT0_ENABLE();
			break;
		case INTERRUPT_EXTERNAL_INT1:
			INTERRUPT_EXTERNAL_INT1_ENABLE();
			break;
		case INTERRUPT_EXTERNAL_INT2:
			INTERRUPT_EXTERNAL_INT2_ENABLE();
			break;
		default :
			ret = E_NOK;
			break;
		}
		ret = E_OK;
	}
	return ret;
}

static Std_ReturnType Ext_Interrupt0_Set_Sence(Interrupt_Cnfg_t * Interrupt_Cnfg_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == Interrupt_Cnfg_obj)
	{
		ret = E_NOK;
	}
	else
	{
		switch(Interrupt_Cnfg_obj->Interrupt_Sense)
		{
		case INTERRUPT_FALLING_EDGE:
			INTERRUPT0_FALLING_EDGE_ENABLE();
			break;
		case INTERRUPT_RISING_EDGE:
			INTERRUPT0_RISING_EDGE_ENABLE();
			break;
		case INTERRUPT_LOGICAL_CHANGE:
			INTERRUPT0_LOGICAL_CHANGE_ENABLE();
			break;
		case INTERRUPT_LOW_LEVEL:
			INTERRUPT0_LOW_LEVEL_ENABLE() ;
			break;
		default :
			ret = E_NOK;
			break;
		}
	}
	return ret;
}
static Std_ReturnType Ext_Interrupt1_Set_Sence(Interrupt_Cnfg_t * Interrupt_Cnfg_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == Interrupt_Cnfg_obj)
	{
		ret = E_NOK;
	}
	else
	{
		switch(Interrupt_Cnfg_obj->Interrupt_Sense)
		{
		case INTERRUPT_FALLING_EDGE:
			INTERRUPT1_FALLING_EDGE_ENABLE();
			break;
		case INTERRUPT_RISING_EDGE:
			INTERRUPT1_RISING_EDGE_ENABLE();
			break;
		case INTERRUPT_LOGICAL_CHANGE:
			INTERRUPT1_LOGICAL_CHANGE_ENABLE();
			break;
		case INTERRUPT_LOW_LEVEL:
			INTERRUPT1_LOW_LEVEL_ENABLE();
			break;
		default :
			ret = E_NOK;
			break;
		}
	}
	return ret;
}
static Std_ReturnType Ext_Interrupt2_Set_Sence(Interrupt_Cnfg_t * Interrupt_Cnfg_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == Interrupt_Cnfg_obj)
	{
		ret = E_NOK;
	}
	else
	{
		switch(Interrupt_Cnfg_obj->Interrupt_Sense)
		{
		case INTERRUPT_FALLING_EDGE:
			INTERRUPT2_FALLING_EDGE_ENABLE();
			break;
		case INTERRUPT_RISING_EDGE:
			INTERRUPT2_RISING_EDGE_ENABLE();
			break;

		default :
			ret = E_NOK;
			break;
		}
	}
	return ret;
}

static Std_ReturnType Ext_Interrupt_Set_Pin(Interrupt_Cnfg_t * Interrupt_Cnfg_obj)
{
	Gpio_pin_config_t INT0_PIN = {.port = PORTD, .pin = GPIO_PIN2, .direction = GPIO_PIN_INPOT};
	Gpio_pin_config_t INT1_PIN = {.port = PORTD, .pin = GPIO_PIN3, .direction = GPIO_PIN_INPOT};
	Gpio_pin_config_t INT2_PIN = {.port = PORTB, .pin = GPIO_PIN3, .direction = GPIO_PIN_INPOT};

	Std_ReturnType ret = E_NOK;
	if(NULL == Interrupt_Cnfg_obj)
	{
		ret = E_NOK;
	}
	else
	{
		switch(Interrupt_Cnfg_obj->Interrupt_Num)
		{
		case INTERRUPT_EXTERNAL_INT0:
			gpio_pin_initialize(&INT0_PIN);
			break;
		case INTERRUPT_EXTERNAL_INT1:
			gpio_pin_initialize(&INT1_PIN);
			break;
		case INTERRUPT_EXTERNAL_INT2:
			gpio_pin_initialize(&INT2_PIN);
			break;
		default :
			ret = E_NOK;
			break;
		}
	}
	return ret;
}

Std_ReturnType Ext_Interrupt0_Set_Handler(void (*interrupt_handle)(void))
{
	Std_ReturnType ret = E_NOK;
	if(NULL == interrupt_handle)
	{
		ret = E_NOK;
	}
	else
	{
		Ext_Interrupt0_Handler = interrupt_handle;
		ret = E_OK;
	}
	return ret;
}
Std_ReturnType Ext_Interrupt1_Set_Handler(void (*interrupt_handle)(void))
{
	Std_ReturnType ret = E_NOK;
	if(NULL == interrupt_handle)
	{
		ret = E_NOK;
	}
	else
	{
		Ext_Interrupt1_Handler = interrupt_handle;
		ret = E_OK;
	}
	return ret;
}
Std_ReturnType Ext_Interrupt2_Set_Handler(void (*interrupt_handle)(void))
{
	Std_ReturnType ret = E_NOK;
	if(NULL == interrupt_handle)
	{
		ret = E_NOK;
	}
	else
	{
		Ext_Interrupt2_Handler = interrupt_handle;
		ret = E_OK;
	}
	return ret;
}

Std_ReturnType Ext_Interrupt_Tx_Set_Handler(Interrupt_Cnfg_t * Interrupt_Cnfg_obj)
{
	Std_ReturnType ret = E_NOK;
	if(NULL == Interrupt_Cnfg_obj)
	{
		ret = E_NOK;
	}
	else
	{
		switch(Interrupt_Cnfg_obj->Interrupt_Num)
		{
		case INTERRUPT_EXTERNAL_INT0:
			Ext_Interrupt0_Set_Handler(Interrupt_Cnfg_obj->INTERRUPT_HANDLER);
			break;
		case INTERRUPT_EXTERNAL_INT1:
			Ext_Interrupt1_Set_Handler(Interrupt_Cnfg_obj->INTERRUPT_HANDLER);
			break;
		case INTERRUPT_EXTERNAL_INT2:
			Ext_Interrupt2_Set_Handler(Interrupt_Cnfg_obj->INTERRUPT_HANDLER);
			break;
		default :
			ret = E_NOK;
			break;
		}
		ret = E_OK;
	}
	return ret;
}

void __vector_1 (void) __attribute__ ((signal)) ;
void __vector_1 (void)
{
	Ext_Interrupt0_Handler();
	INTERRUPT0_CLEAR_FLAGE();
}

void __vector_2 (void) __attribute__ ((signal)) ;
void __vector_2 (void)
{
	Ext_Interrupt1_Handler();
	INTERRUPT1_CLEAR_FLAGE();

}
void __vector_3 (void) __attribute__ ((signal)) ;
void __vector_3 (void)
{
	Ext_Interrupt2_Handler();
	INTERRUPT2_CLEAR_FLAGE();
}
/*
ISR(INT0_vect)
{
	Ext_Interrupt0_Handler();
}

ISR(INT1_vect)
{
	Ext_Interrupt1_Handler();
}
ISR(INT2_vect)
{
	Ext_Interrupt2_Handler();
}

 */

#endif
