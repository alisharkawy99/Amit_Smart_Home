/*
* LED0_Interface.c
*
* Created: 11/7/2022 7:42:40 PM
*  Author: Lenovo
*/

#include "LED0_Private.h"


void LED0_Initialize(void)
{
	/*
	set_bit(DDRC, PC2);
	set_bit(LED0_DDR, LED0);
	*/
	DIO_SetPin_Direction(LED0_PRT, LED0, LED0_OUT);
}
void LED0_ON(void)
{
	/*
	set_bit(PORTC, PC2);
	set_bit(LED0_PRT, LED0);
	*/
	DIO_SetPin_Value(LED0_PRT, LED0, LED0_HIGH);
}
void LED0_OFF(void)
{
	/*
	clr_bit(PORTC, PC2);
	clr_bit(LED0_PRT, LED0);
	*/
	DIO_SetPin_Value(LED0_PRT, LED0, LED0_LOW);
}
void LED0_TGL(void)
{
	DIO_TglPin_Value(LED0_PRT, LED0);
}
uint8_t LED0_Get(void){
	
	if(get_bit(LED0_PRT,LED0)==1){
		return 1;
	}else{
		return 0;
	}
}