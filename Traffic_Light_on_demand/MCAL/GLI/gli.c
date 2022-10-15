/*
 * gli.c
 *
 *  Created on: Oct 12, 2022
 *      Author: Ahmed Tarek
 */

#include "../../LIB/common_macros.h"
#include "avr/io.h"

void GLI_Enable(void)
{
	SET_BIT(SREG,7);
}

void GLI_Disable(void)
{
	CLEAR_BIT(SREG,7);
}
