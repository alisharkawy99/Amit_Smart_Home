#include "main.h"

uint8_t temperature_Read(void){
	uint16_t temperuture=ADC_Read(2);
	uint16_t Celcuis= (temperuture*4.88)/10;
	LCD_Write_Number(Celcuis);LCD_Write_String("^C");_delay_ms(500);
	if(Celcuis >28){
		Motor_Start(Motor1,Motor_CW);
	}else if(Celcuis <=21)Motor_Stop(Motor1);
	_delay_ms(10);
	return Celcuis;
}
void Dimming_LED(void){
	uint16_t ADC_Data=ADC_Read(1);
	ADC_Data=ADC_Data/4;
	OCR2=ADC_Data;
	FAST_PWM_set_duty(FAST_OC0_NON_INVERTING,ADC_Data);
	_delay_ms(10);
	
}
void Rotate_Servo(uint8_t angle){
			ServoMotor_Rotate(angle);
			_delay_ms(1000);
}
void External_interupt(void){
	MCUCR=(1<<ISC01);
	PORTD=(1<<7);
	GICR=(1<<7)|(1<<6)|(1<<5);
}

int main(void)
{
	
	LCD_Initialize(); SPI_SLave_Initialize(); LED0_Initialize(); LED1_Initialize(); LED2_Initialize();PWM_init();
	ADC_Initialization(AVCC,ADC_PRE128);
	Motor_Initialization();
	ServoMotor_Initialization();
	External_interupt();
	sei();
	uint8_t responce = DEFAULT;
	uint8_t status=DEFAULT;
	uint16_t ADC_Data;
	
	
	while(1){
		LCD_Clear();
		// Receive reading from THe first micro controller
		responce=SPI_TranCeive(DEFAULT);
		
		_delay_ms(100);
		if(responce==1){//***********************Room 1**********************************
			uint8_t x=Room1_status();
			responce=SPI_TranCeive(0);
			if(responce==2)LED1_ON();else if(responce==1)responce=SPI_TranCeive(x);else if(responce==3)LED1_OFF();
		}else if(responce ==2){
			
			uint8_t x=Room2_status();//******************************Room 2****************************
			responce=SPI_TranCeive(8);
			if(responce==2){
				
				Dimming_LED();
				
				}
				else if(responce==1)responce=SPI_TranCeive(x);else if(responce==3)LED2_OFF();
		}else if(responce==3){//***************************Door*****************************
			responce=SPI_TranCeive(0);
			
			if(responce==1){
				Rotate_Servo(186.2);
				LCD_Write_String("Doors Opened");_delay_ms(250);
				
			}else if(responce==2){
				Rotate_Servo(-186);
				LCD_Write_String("Doors Closed");_delay_ms(250);
			}
			
			}
			else if(responce==4){
				uint16_t x=temperature_Read();
				//****************AC ON************************
				if(x>28)responce=SPI_TranCeive(0);
				//*****************AC OFF****************
				else if(x<21)responce=SPI_TranCeive(1);
				
			}
		
		//responce=SPI_TranCeive(DEFAULT);
		//**********************Dimming the led***********************************************
		//LCD_Write_String("DIMMING LED");
		//Dimming_LED();
		//************************AIR CONDITIONER*********************************************
		//LCD_Clear();
		//temperature_Read();
		//******************************DOOR CONTROL *****************************************
		//Rotate_Servo(186);
		//*****************************************************************
		
		
	
	}
	return 0;
}
ISR(INT1_vect){
	Dimming_LED();
}
