/*
 * DC_Motor.h
 *
 * Created: 12/25/2021 11:23:47 AM
 *  Author: karim
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "DC_Motor_Configuration.h"
#include "FAST_PWM_ADRRESS.h"
void Motor_Initialization(void);
void Motor_Start(Motor motor, Motor_Dir direction);
void Motor_Stop(Motor motor);

#endif /* DC_MOTOR_H_ */