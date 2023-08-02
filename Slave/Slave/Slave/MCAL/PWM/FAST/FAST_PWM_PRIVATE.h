/*
 * FAST_PWM_PRIVATE.h
 *
 * Created: 08/10/2022 11:42:40 ص
 *  Author: mogavcs
 */ 


#ifndef FAST_PWM_PRIVATE_H_
#define FAST_PWM_PRIVATE_H_

#include "FAST_PWM_CONFGURATION.h"

void FAST_PWM_intialization(FAST_Prescaler prescaler);
void FAST_PWM_set_duty(FAST_Mode mode , uint8_t duty_cycle);
void PWM_init();


#endif /* FAST_PWM_PRIVATE_H_ */