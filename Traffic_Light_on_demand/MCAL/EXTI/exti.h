/*
 * exti.h
 *
 *  Created on: Oct 13, 2022
 *      Author: Ahmed Tarek
 */

#ifndef MCAL_EXTI_EXTI_H_
#define MCAL_EXTI_EXTI_H_

void EXTI_init(void);

void EXTI_enable(void);

void EXTI_disable(void);

void EXTI_setCallBackFunction( void (*a_ptr)(void) );

#endif /* MCAL_EXTI_EXTI_H_ */
