/*
 * SPI_Configuration.h
 *
 * Created: 4/8/2022 5:05:38 PM
 *  Author: karim
 */ 


#ifndef SPI_CONFIGURATION_H_
#define SPI_CONFIGURATION_H_

#include "SPI_Address.h"
#include "CPU_Configuration.h"

#define MOSI   PB5
#define MISO   PB6
#define SCK    PB7
#define SS     PB4

#define Slave0 SS
#define Slave1 PB3
#define Slave2 PB2
#define Slave3 PB1
#define Slave4 PB0



#endif /* SPI_CONFIGURATION_H_ */