/*
* DC_Motor.c
*
* Created: 12/25/2021 11:23:54 AM
*  Author: karim
*/

#include "DC_Motor.h"

void Motor_Initialization(void)
{
	//Define direction for control pins
	DIO_SetPin_Direction(Motor_ControlPort, Motor_EN1, Motor_Out);
	//DIO_SetPin_Direction(Motor_ControlPort, Motor_EN2, Motor_Out);
	//Define Direction for data pins
	DIO_SetPin_Direction(Motor_DataPort, Motor_A1, Motor_Out);
	DIO_SetPin_Direction(Motor_DataPort, Motor_A2, Motor_Out);
	DIO_SetPin_Direction(Motor_DataPort, Motor_B1, Motor_Out);
	DIO_SetPin_Direction(Motor_DataPort, Motor_B2, Motor_Out);
}
void Motor_Start(Motor motor, Motor_Dir direction)
{	
	switch(motor)//Switch on which motor you want to start
	{
		case Motor1:
		DIO_SetPin_Value(Motor_ControlPort, Motor_EN1, Motor_On);
		switch (direction)//Switch on which direction
		{
			case Motor_CW:
			DIO_SetPin_Value(Motor_DataPort, Motor_A1, Motor_High);
			DIO_SetPin_Value(Motor_DataPort, Motor_A2, Motor_Low);
			break;
			case Motor_CCW:
			DIO_SetPin_Value(Motor_DataPort, Motor_A1, Motor_Low);
			DIO_SetPin_Value(Motor_DataPort, Motor_A2, Motor_High);
			break;
		}
		break;
		case Motor2:
		DIO_SetPin_Value(Motor_ControlPort, Motor_EN2, Motor_On);
		switch (direction)//Switch on which direction
		{
			case Motor_CW:
			DIO_SetPin_Value(Motor_DataPort, Motor_B1, Motor_High);
			DIO_SetPin_Value(Motor_DataPort, Motor_B2, Motor_Low);
			break;
			case Motor_CCW:
			DIO_SetPin_Value(Motor_DataPort, Motor_B1, Motor_Low);
			DIO_SetPin_Value(Motor_DataPort, Motor_B2, Motor_High);
			break;
		}
		break;
	}
}
void Motor_Stop(Motor motor)
{
	switch(motor)//Switch on which motor you want to start
	{
		case Motor1:
		DIO_SetPin_Value(Motor_ControlPort, Motor_EN1, Motor_Off);
		DIO_SetPin_Value(Motor_DataPort, Motor_A1, Motor_Low);
		DIO_SetPin_Value(Motor_DataPort, Motor_A2, Motor_Low);
		break;
		case Motor2:
		DIO_SetPin_Value(Motor_ControlPort, Motor_EN2, Motor_Off);
		DIO_SetPin_Value(Motor_DataPort, Motor_B1, Motor_Low);
		DIO_SetPin_Value(Motor_DataPort, Motor_B2, Motor_Low);
		break;
	}
}