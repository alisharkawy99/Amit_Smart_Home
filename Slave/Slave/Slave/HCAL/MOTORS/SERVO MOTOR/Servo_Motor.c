/*
* Servo_Motor.c
*
* Created: 12/25/2021 11:54:37 AM
*  Author: karim
*/


#include "Servo_Motor.h"

void ServoMotor_Initialization(void)
{
	//Define Direction of OC1A
	DDRD |= (1<<PD5);	/* Make OC1A pin as output */
	TCNT1 = 0;			/* Set timer1 count zero */
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */

	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
}
void ServoMotor_Rotate(uint8_t angle)
{
	OCR1A = angle;
}