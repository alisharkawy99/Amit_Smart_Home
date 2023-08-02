/*
* Servo_Motor_Configuration.h
*
* Created: 12/25/2021 11:54:23 AM
*  Author: karim
*/


#ifndef SERVO_MOTOR_CONFIGURATION_H_
#define SERVO_MOTOR_CONFIGURATION_H_

#include "DIO_Private.h"
/*
#define Angle_0 5
#define Angle_P90 7
#define Angle_N90 10
*/
typedef enum
{
	Angle_0 = 5,
	Angle_P90 = 7,
	Angle_N90 = 10
}Servo_Angle;

#endif /* SERVO_MOTOR_CONFIGURATION_H_ */