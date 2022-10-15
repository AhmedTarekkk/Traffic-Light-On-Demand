/*
 * timer.c
 *
 *  Created on: Oct 12, 2022
 *      Author: Ahmed Tarek
 */

#include "timer.h"
#include "../../LIB/common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h> /* To use ICU/Timer1 Registers */
#include <avr/interrupt.h> /* For ICU ISR */

static volatile void (*g_callBackPtr)(void) = NULL_PTR;


void TIMER_init()
{
	TCCR1A = (1<<FOC1A) ;
	TCCR1B = (1<<WGM12) | (1<<CS12) | (1<<CS10) ; /* F/1024 Prescaler , CTC Mode */
	TCNT1 = 0;
	OCR1A = 1000;
	TIMSK |= (1<<OCIE1A) ;
}

void TIMER_setCallBackFunction( void (*a_ptr)(void) )
{
	g_callBackPtr = a_ptr;
}

ISR(TIMER1_COMPA_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
