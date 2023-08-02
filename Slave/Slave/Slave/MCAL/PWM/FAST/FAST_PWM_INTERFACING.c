/*
* FAST_PWM_INTERFACING.c
*
* Created: 08/10/2022 11:42:06 ص
*  Author: mogavcs
*/
#include "FAST_PWM_PRIVATE.h"


void PWM_init()
{
	/*set fast PWM mode with non-inverted output*/
	TCCR2 = (1<<WGM20) | (1<<WGM20) | (1<<COM21) | (1<<CS20);
	DDRD|=(1<<PD7);  /*set OC0 pin as output*/
	/*set fast PWM mode with non-inverted output*/
	//TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	//DDRB|=(1<<PB3);  /*set OC0 pin as output*/
}
void FAST_PWM_set_duty(FAST_Mode mode , uint8_t duty_cycle){

	switch(mode)
	{
		case FAST_OC0_Disconnected:
		clr_bit(TCCR2,COM21) ; clr_bit(TCCR2,COM20) ;
		break;
		case FAST_OC0_RESERVED:
		clr_bit(TCCR2,COM21) ; set_bit(TCCR2,COM20) ;
		break;

		case FAST_OC0_NON_INVERTING:{
		set_bit(TCCR2,COM21) ; clr_bit(TCCR2,COM20) ;
		OCR2=(((256-duty_cycle)/100)-1);
		}
		break;
		case FAST_OC0_INVERTING:
		{
		set_bit(TCCR2,COM21) ; set_bit(TCCR2,COM20) ;
		OCR2=(256-1)-(((256-duty_cycle)/100)-1);
		}
		break;
	}
}
