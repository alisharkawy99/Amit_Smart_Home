#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

/*
 * main.h
 *
 * Created: 11/3/2022 7:08:17 PM
 *  Author: Lenovo
 */


#ifndef MAIN_H_
#define MAIN_H_

#include "CPU_Configuration.h"

#include "UART_Private.h"
#include "LED0_Private.h"

#include "LCD_Private.h"

#include "Keypad_Private.h"

#include "SPI_Private.h"

#include "ADC_Private.h"

#include  <avr/eeprom.h>

// *******************************EEPROM**************************
#define ADMIN_PASS_STATUS_ADDRESS (Uint16_t) 0x100
#define GUEST_PASS_STATUS_ADDRESS (Uint16_t) 0x102

#define EEPROM_ADMIN_PASSWORD      (Uint16_t) 35
#define EEPROM_ADMIN_NAME		(Uint16_t ) 40
#define EEPROM_ADMIN_NAME_SIZE (Uint16_t) 46

#define EEPROM_GUEST_NAME      (Uint16_t) 50
#define EEPROM_GUEST_PASSWORD (Uint16_t) 55
#define EEPROM_GUEST_NAME_SIZE		(Uint16_t)60
//****************************Modes*********************
#define NO_MODE (Uint8_t)0
#define ADMIN_MODE   (Uint8_t)1
#define GUEST_MODE   (Uint8_t)2
#define TRUE 1
#define FALSE 0
//*****************Room 1*********************
#define ROOM1_ON 1
#define ROOM1_OFF 0
#define ROOM1_TURN_ON 1
#define ROOM1_TURN_OFF 0

#endif /* MIAN_H_ */


#endif // MAIN_H_INCLUDED
