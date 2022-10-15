/*
 * led.h
 *
 *  Created on: Oct 12, 2022
 *      Author: Ahmed Tarek
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_
#include "../../LIB/std_types.h"

#define CARS_LEDS_PORT_ID			PORTA_ID
#define	CARS_LEDS_FIRST_PIN_ID		PIN0_ID

#define PED_LEDS_PORT_ID			PORTB_ID
#define	PED_LEDS_FIRST_PIN_ID		PIN0_ID

typedef enum
{
	RED,
	YELLOW,
	GREEN
}LEDS;

void LED_carInit(void);

void LED_pedInit(void);

void LED_carON(LEDS color);

void LED_carOFF(LEDS color);

void LED_pedON(LEDS color);

void LED_pedOFF(LEDS color);


#endif /* HAL_LED_LED_H_ */
