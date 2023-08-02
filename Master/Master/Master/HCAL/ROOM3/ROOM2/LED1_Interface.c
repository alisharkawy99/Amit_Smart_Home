/*
 * LED2_Interface.h
 *
 * Created: 11/7/2022 8:37:24 PM
 *  Author: Lenovo
 */ 


#ifndef LED2_INTERFACE_H_
#define LED2_INTERFACE_H_


#include "LED1_Private.h"


void LED1_Initialize(void)
{
	/*
	set_bit(DDRC, PC2);
	set_bit(LED0_DDR, LED0);
	*/
	DIO_SetPin_Direction(LED1_PRT, LED1, LED1_OUT);
}
void LED1_ON(void)
{
	/*
	set_bit(PORTC, PC2);
	set_bit(LED0_PRT, LED0);
	*/
	DIO_SetPin_Value(LED1_PRT, LED1, LED1_HIGH);
}
void LED1_OFF(void)
{
	/*
	clr_bit(PORTC, PC2);
	clr_bit(LED0_PRT, LED0);
	*/
	DIO_SetPin_Value(LED1_PRT, LED1, LED1_LOW);
}
void LED1_TGL(void)
{
	DIO_TglPin_Value(LED1_PRT, LED1);
}


#endif /* LED2_INTERFACE_H_ */