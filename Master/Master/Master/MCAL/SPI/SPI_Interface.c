/*
* SPI_Interface.c
*
* Created: 4/8/2022 5:06:10 PM
*  Author: karim
*/


#include "SPI_Private.h"

void SPI_Master_Initialize(void)
{
	//Define directions of pins for master
	set_bit(DDRB, 5);//MOSI pins
	clr_bit(DDRB, 6);//MISO pins
	set_bit(DDRB, 7);//SCK pins
	set_bit(DDRB, 4);//SS pins
	//One Line
	SPCR = 0x53;
}
void SPI_SLave_Initialize(void)
{
	//Define direction of pins for slave
	clr_bit(DDRB, MOSI);//MOSI pins
	set_bit(DDRB, MISO);//MISO pins
	clr_bit(DDRB, SCK);//SCK pins
	clr_bit(DDRB, SS);//SS pins
	//One Line
	SPCR = 0x43;
	
}
void SPI_Transmit(uint8_t dataTransmit)
{
	//Two Lines
	
	SPDR = dataTransmit;
	while (get_bit(SPSR, SPIF) != 1);
	
}
uint8_t SPI_Receive(void)
{
	//Two Lines
	
	while (get_bit(SPSR, SPIF) != 1);
	return SPDR;
}
uint8_t SPI_TranCeive(uint8_t data)
{
	SPDR = data;
	while (get_bit(SPSR, SPIF) != 1);
	return SPDR;
}
// uint8_t SPI_ui8TransmitRecive (uint8_t data)
// {
// 	SPDR = data;//move the given data to SPI Data register
// 	
// 	//in case of master send data and wait till the data are fully transmitted
// 	//in case of slave wait the data to be transmitted by the master
// 	while (((SPSR&(1<<SPIF))>>SPIF)==0)	//wait till the transmitting is done
// 	;									//SPI flag is set to one if the transmission is done
// 	
// 	return SPDR;//return the value of SPI Data register after the transmission or receiving is done
// }
void SPI_SlaveSelect(uint8_t slave)
{
	//Six Lines
	switch (slave)
	{
		case Slave0:
		PORTB |= 0x1F;
		PORTB &=~(1<<SS);
		break;
		case Slave1:
		PORTB |= 0x1F;
		PORTB &=~(1<<SS);
		break;
		case Slave2:
		PORTB |= 0x1F;
		PORTB &=~(1<<SS);
		break;
		case Slave3:
		PORTB |= 0x1F;
		PORTB &=~(1<<SS);
		break;
		case Slave4:
		PORTB |= 0x1F;
		PORTB &=~(1<<SS);
		break;
	}
}
