/*
 * led.c
 *
 *  Created on: Oct 12, 2022
 *      Author: Ahmed Tarek
 */

#include "led.h"
#include "../../MCAL/GPIO/gpio.h"

void LED_carInit(void)
{
	GPIO_setupPinDirection(CARS_LEDS_PORT_ID, CARS_LEDS_FIRST_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(CARS_LEDS_PORT_ID, CARS_LEDS_FIRST_PIN_ID+1, PIN_OUTPUT);
	GPIO_setupPinDirection(CARS_LEDS_PORT_ID, CARS_LEDS_FIRST_PIN_ID+2, PIN_OUTPUT);
}

void LED_pedInit(void)
{
	GPIO_setupPinDirection(PED_LEDS_PORT_ID, PED_LEDS_FIRST_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PED_LEDS_PORT_ID, PED_LEDS_FIRST_PIN_ID+1, PIN_OUTPUT);
	GPIO_setupPinDirection(PED_LEDS_PORT_ID, PED_LEDS_FIRST_PIN_ID+2, PIN_OUTPUT);
}

void LED_carON(LEDS color)
{
	switch(color)
	{
	case RED:
		GPIO_writePin(CARS_LEDS_PORT_ID, CARS_LEDS_FIRST_PIN_ID, LOGIC_HIGH);
		break;
	case YELLOW:
		GPIO_writePin(CARS_LEDS_PORT_ID, CARS_LEDS_FIRST_PIN_ID+1, LOGIC_HIGH);
		break;
	case GREEN:
		GPIO_writePin(CARS_LEDS_PORT_ID, CARS_LEDS_FIRST_PIN_ID+2, LOGIC_HIGH);
		break;
	}
}

void LED_carOFF(LEDS color)
{
	switch(color)
	{
	case RED:
		GPIO_writePin(CARS_LEDS_PORT_ID, CARS_LEDS_FIRST_PIN_ID, LOGIC_LOW);
		break;
	case YELLOW:
		GPIO_writePin(CARS_LEDS_PORT_ID, CARS_LEDS_FIRST_PIN_ID+1, LOGIC_LOW);
		break;
	case GREEN:
		GPIO_writePin(CARS_LEDS_PORT_ID, CARS_LEDS_FIRST_PIN_ID+2, LOGIC_LOW);
		break;
	}
}

void LED_pedON(LEDS color)
{
	switch(color)
	{
	case RED:
		GPIO_writePin(PED_LEDS_PORT_ID, PED_LEDS_FIRST_PIN_ID, LOGIC_HIGH);
		break;
	case YELLOW:
		GPIO_writePin(PED_LEDS_PORT_ID, PED_LEDS_FIRST_PIN_ID+1, LOGIC_HIGH);
		break;
	case GREEN:
		GPIO_writePin(PED_LEDS_PORT_ID, PED_LEDS_FIRST_PIN_ID+2, LOGIC_HIGH);
		break;
	}
}

void LED_pedOFF(LEDS color)
{
	switch(color)
	{
	case RED:
		GPIO_writePin(PED_LEDS_PORT_ID, PED_LEDS_FIRST_PIN_ID, LOGIC_LOW);
		break;
	case YELLOW:
		GPIO_writePin(PED_LEDS_PORT_ID, PED_LEDS_FIRST_PIN_ID+1, LOGIC_LOW);
		break;
	case GREEN:
		GPIO_writePin(PED_LEDS_PORT_ID, PED_LEDS_FIRST_PIN_ID+2, LOGIC_LOW);
		break;
	}
}

