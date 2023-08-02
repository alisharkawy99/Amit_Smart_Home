/*
 * LED2_Interface.h
 *
 * Created: 11/7/2022 8:38:44 PM
 *  Author: Lenovo
 */ 


#ifndef LED2_INTERFACE_H_
#define LED2_INTERFACE_H_

#include "LED2_Private.h"


void LED2_Initialize(void)
{
	/*
	set_bit(DDRC, PC2);
	set_bit(LED0_DDR, LED0);
	*/
	DIO_SetPin_Direction(LED2_PRT, LED2, LED2_OUT);
}
void LED2_ON(void)
{
	/*
	set_bit(PORTC, PC2);
	set_bit(LED0_PRT, LED0);
	*/
	DIO_SetPin_Value(LED2_PRT, LED2, LED2_HIGH);
}
void LED2_OFF(void)
{
	/*
	clr_bit(PORTC, PC2);
	clr_bit(LED0_PRT, LED0);
	*/
	DIO_SetPin_Value(LED2_PRT, LED2, LED2_LOW);
}
void LED2_TGL(void)
{
	DIO_TglPin_Value(LED2_PRT, LED2);
}




#endif /* LED2_INTERFACE_H_ */