/*
 * exit.c
 *
 *  Created on: Oct 13, 2022
 *      Author: Ahmed Tarek
 */
#include "exti.h"
#include "../../LIB/std_types.h"
#include "avr/interrupt.h"
#include "../GPIO/gpio.h"
#include "../../LIB/common_macros.h"

static volatile void (*g_callBackPtr2)(void) = NULL_PTR;

void EXTI_init(void)
{
	GPIO_setupPinDirection(PORTD_ID, PIN2_ID, PIN_INPUT);
	MCUCR |= (1<<ISC01); /* falling edge */
}

void EXTI_enable(void)
{
	SET_BIT(GICR,INT0); /* External interrupt enable */
}

void EXTI_disable(void)
{
	CLEAR_BIT(GICR,INT0); /* External interrupt enable */
}

void EXTI_setCallBackFunction( void (*a_ptr)(void) )
{
	g_callBackPtr2 = a_ptr;
}

ISR(INT0_vect)
{
	if(g_callBackPtr2 != NULL_PTR)
	{
		(*g_callBackPtr2)();
	}
}
