/*
 * timer.h
 *
 *  Created on: Oct 12, 2022
 *      Author: Ahmed Tarek
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include "../../LIB/std_types.h"

void TIMER_init();

void TIMER_setCallBackFunction( void (*a_ptr)(void) );


#endif /* MCAL_TIMER_TIMER_H_ */
