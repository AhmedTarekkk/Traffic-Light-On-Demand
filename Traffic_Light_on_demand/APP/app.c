#include "app.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/LED/led.h"
#include "../MCAL/GLI/gli.h" /* Global Interrupt */
#include "../MCAL/TIMER/timer.h"
#include "../LIB/std_types.h"
#include "../MCAL/EXTI/exti.h"

/* Private Functions */
static void Normal_Mode(void);
static void Pedestrian_Mode(void);

uint8 g_time = 5 ;
uint8 NormalModeCase = 1;
uint8 PedestrainModeCase = 1;
uint8 flag = 0;

static void Normal_Mode(void)
{
	LCD_displayStringRowColumn(1, 0, "   Normal Mode  ");
	LCD_moveCursor(0, 1);
	LCD_intgerToString(g_time);
	switch(NormalModeCase)
	{
	case 1:
		LED_carON(GREEN);
		LED_carOFF(YELLOW);
		LED_carOFF(RED);

		LED_pedON(RED);
		LED_pedOFF(GREEN);
		LED_pedOFF(YELLOW);
		break;
	case 2: /* in case going from green to red for cars */
	case 4: /* or in case going from red to green for cars */
		if(g_time == 5 || g_time == 3 || g_time == 1 ) /* Blinking Yellow Led */
		{
			LED_pedON(YELLOW);
			LED_carON(YELLOW);
		}
		else
		{
			LED_pedOFF(YELLOW);
			LED_carOFF(YELLOW);
		}
		break;
	case 3:
		LED_carON(RED);
		LED_carOFF(GREEN);
		LED_carOFF(YELLOW);

		LED_pedON(GREEN);
		LED_pedOFF(RED);
		LED_pedOFF(YELLOW);
		break;
	default:
		NormalModeCase = 1;
	}
}

static void Pedestrian_Mode(void)
{
	LCD_displayStringRowColumn(1, 0, "Pedestrian Mode ");
	LCD_moveCursor(0, 1);
	LCD_intgerToString(g_time);
	if(NormalModeCase == 3) /* if the button is pressed when the car's led is red */
	{
		switch(PedestrainModeCase)
		{
			case 1:
				LED_carON(RED);
				LED_carOFF(GREEN);
				LED_carOFF(YELLOW);

				LED_pedON(GREEN);
				LED_pedOFF(RED);
				LED_pedOFF(YELLOW);
				break;
			case 2:
				LED_pedON(GREEN);
				if(g_time == 5 || g_time == 3 || g_time == 1 ) /* Blinking Yellow Led */
				{
					LED_pedON(YELLOW);
					LED_carON(YELLOW);
				}
				else
				{
					LED_pedOFF(YELLOW);
					LED_carOFF(YELLOW);
				}
				break;
			default:
				NormalModeCase = 1;  /* start from the first case */
				EXTI_enable(); /* so we can use the pedestrian button again */
				flag = 0; /* to go to the normal mode again */
		}
	}
	else /*else if the button is pressed when the car's led is green or yellow */
	{
		switch(PedestrainModeCase)
		{
			case 1: /* Turn on Red led for pedestrian and start blinking both yellow leds */
				LED_pedON(RED);
				if(g_time == 5 || g_time == 3 || g_time == 1 ) /* Blinking Yellow Led */
				{
					LED_pedON(YELLOW);
					LED_carON(YELLOW);
				}
				else
				{
					LED_pedOFF(YELLOW);
					LED_carOFF(YELLOW);
				}
				break;
			case 2:
				LED_carON(RED);
				LED_carOFF(GREEN);
				LED_carOFF(YELLOW);

				LED_pedON(GREEN);
				LED_pedOFF(RED);
				LED_pedOFF(YELLOW);
				break;
			case 3:
				LED_pedON(GREEN);
				if(g_time == 5 || g_time == 3 || g_time == 1 ) /* Blinking Yellow Led */
				{
					LED_pedON(YELLOW);
					LED_carON(YELLOW);
				}
				else
				{
					LED_pedOFF(YELLOW);
					LED_carOFF(YELLOW);
				}
				break;
			default:
				EXTI_enable(); /* so we can use the pedestrian button again */
				NormalModeCase = 1; /* start from the first case */
				flag = 0; /* to go to the normal mode again */
		}
	}

}

void TIMER_ISR(void)
{
	g_time--;
}

void EXTI0_ISR(void)
{
	if(flag == 0) /* if we are in the normal mode and want to go to pedestrian mode */
	{
		g_time = 5; /* reset the counter */
		flag = 1 ; /* go to pedestrian mode */
		PedestrainModeCase = 1;
	}
	EXTI_disable(); /* double press doesn't do any thing */
}


void appStart(void)
{
	GLI_Enable();

	LED_carInit();
	LED_pedInit();

	EXTI_init();
	EXTI_enable();
	EXTI_setCallBackFunction(EXTI0_ISR);

	LCD_init();
	LCD_moveCursor(0, 1);
	LCD_intgerToString(g_time);
	LCD_displayStringRowColumn(0, 3, "Sec Remaining");

	TIMER_setCallBackFunction(TIMER_ISR);
	TIMER_init();

	while(1)
	{

		if(g_time == 0)
		{
			g_time = 5;
			LCD_moveCursor(0, 1);
			LCD_intgerToString(g_time);
			if(flag == 0)
			{
				NormalModeCase++;
			}
			else
			{
				PedestrainModeCase++;
			}
		}

		if(flag == 0)
		{
			Normal_Mode();
		}
		else if(flag == 1)
		{
			Pedestrian_Mode();
		}
	}
}
