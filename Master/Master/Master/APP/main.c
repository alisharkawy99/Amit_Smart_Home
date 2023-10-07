/*
* GccApplication4.c
*
* Created: 11/3/2022 2:34:10 PM
* Author : Lenovo
*/

#include "main.h"
uint8_t data;
Uint16_t Str_toint(uint8_t k){
	switch (k)
	
	{
		case '1':
		return 1;
		break;
		case '2':
		return 2;
		break;
		case '3':
		return 3;
		break;
		case '4':
		return 4;
		break;
		case '5':
		return 5;
		break;
		case '6':
		return 6;
		break;
		case '7':
		return 7;
		break;
		case '8':
		return 8;
		break;
		case '9':
		return 9;
		break;
		case '0':
		return 0;
		break;
		
	}
}
uint8_t password_check(int *y){
	uint16_t password[4]= {7,7,7,7};
	for (int i=0;i<4;i++){
		if(y[i]!=password[i])
		LCD_Write_Number(y[i]);
		y++;
		return 0;
		break;
	}
	return 1;
	}
uint8_t ui8ComparePass(const uint8_t* pass1,const uint8_t* pass2,const uint8_t size)
{
	uint8_t pin_counter=0;//the offset of the character of the pin
	uint8_t ret_value = 1;
	while (pin_counter<size)//loop till the pin is fully entered
	{
		if (*(pass1+pin_counter)!=*(pass2+pin_counter))//if the two characters of the entered pin and the stored pin are not equal
		{
			ret_value= 0;//returns false that means the two PINs are not equal
			break;//break the loop
		}
		pin_counter++;//increase thee offset by one
	}
	return ret_value;//returns false that means the two PINs are equal since all characters of the PINs are equal
}
int main(void)
{	
	
	uint8_t Mode=NO_MODE;
	Uint16_t password_size=4,value=0;
	UART_Initialize(Asynchronous,Disable,Bit_2,Bits_8);
	Uint16_t x=0,Password_trials=3;
	uint8_t i=0,buffer[15],Guest_name[15],timeout=0;
	LCD_Initialize();
	KEYPAD_Initialize();
	uint8_t Admin_Password[4],Guest_password[4];
	SPI_Master_Initialize();
	uint8_t name_size_1, name_size_2;
	//******************************************************Admin Registration*************************************************************/
	while (value<1	){
	for (int i=0;i<2;i++)
	{
	
	if(eeprom_read_byte(ADMIN_PASS_STATUS_ADDRESS)!=1 || eeprom_read_byte(GUEST_PASS_STATUS_ADDRESS)!=1){
		LCD_Clear();
		LCD_String_xy(0,0,"1:Set Admin");LCD_String_xy(1,0,"2:Set Guest");
		uint8_t Bluetooth_Mode=UART_Received();
		_delay_ms(100);
			switch (Bluetooth_Mode)
			{
			case '1' :
			
			i=KEYPAD_Read();
			_delay_ms(10);
		
			if(i!='0'){
				_delay_ms(10);
				LCD_Clear();
				LCD_String_xy(0,0,"Name size: ");
				uint8_t name_size=UART_Received();
				_delay_ms(100);
				name_size_1=Str_toint(name_size);
				LCD_Write_Number(name_size);
				UART_Transmit("done");
				LCD_Clear();LCD_String_xy(0,0,"Name:");
				LCD_Write_Command(0xc0);
				for(int i=0;i<=name_size_1;i++){
					buffer[i]=UART_Received();		
				}
				USART_SendString("Done");LCD_String_xy(0,5,buffer);LCD_String_xy(1,0,"Password:");
				while (x<password_size)
				{
					_delay_ms(10);
					Bluetooth_Mode=UART_Received();
					if(i!='0'){
						if(Bluetooth_Mode=='1'|| Bluetooth_Mode=='2'|| Bluetooth_Mode=='3'|| Bluetooth_Mode=='4' || Bluetooth_Mode=='5' || Bluetooth_Mode=='6' || Bluetooth_Mode== '7' || Bluetooth_Mode=='8' || Bluetooth_Mode=='9' || i=='1'|| i=='2'|| i=='3'|| i=='4' || i=='5' || i=='6' || i== '7' || i=='8' || i=='9'){
							
							uint16_t counts =Str_toint(Bluetooth_Mode);
							Admin_Password[x]=counts;
							LCD_Write_Number(counts);_delay_ms(50);
							LCD_String_xy(1,9+x,"*");
							x++;
						}
					}
					
				}
				eeprom_write_byte(EEPROM_ADMIN_NAME_SIZE,name_size_1);
				eeprom_write_block(buffer,EEPROM_ADMIN_NAME,name_size_1);
				eeprom_write_block((const void*)Admin_Password,(void*)EEPROM_ADMIN_PASSWORD,sizeof(Admin_Password));
				eeprom_write_byte(ADMIN_PASS_STATUS_ADDRESS,1);
				LCD_Clear();LCD_Write_String("Admin Registered");_delay_ms(100);
					break;
				
			}
				/********************************************************Guest Registeration***************************************************/
				LCD_Clear();
				case '2':
				
				
				i=KEYPAD_Read();
				_delay_ms(10);
				x=0;
				if(i!='0'){
					_delay_ms(10);
					LCD_Clear();
					LCD_String_xy(0,0,"Name size: ");
					uint8_t name_size=UART_Received();
					_delay_ms(100);
					name_size_2=Str_toint(name_size);
					LCD_Write_Number(name_size);
					UART_Transmit("done");
					LCD_Clear();LCD_String_xy(0,0,"Name:");
					LCD_Write_Command(0xc0);
					for(int i=0;i<=name_size_2;i++){
						Guest_name[i]=UART_Received();
					}
					USART_SendString("Done");LCD_String_xy(0,5,Guest_name);LCD_String_xy(1,0,"Password:");_delay_ms(100);
					while (x<password_size)
					{
						_delay_ms(10);
						uint8_t Bluetooth_Mode=UART_Received();
						if(i!='0'){
							if(Bluetooth_Mode=='1'|| Bluetooth_Mode=='2'|| Bluetooth_Mode=='3'|| Bluetooth_Mode=='4' || Bluetooth_Mode=='5' || Bluetooth_Mode=='6' || Bluetooth_Mode== '7' || Bluetooth_Mode=='8' || Bluetooth_Mode=='9' || i=='1'|| i=='2'|| i=='3'|| i=='4' || i=='5' || i=='6' || i== '7' || i=='8' || i=='9'){
								uint16_t counts =Str_toint(Bluetooth_Mode);
								Guest_password[x]=counts;
								LCD_Write_Number(counts);_delay_ms(50);
								LCD_String_xy(1,9+x,"*");
								
								
								x++;
							}
						}
						
					}
					eeprom_write_byte(EEPROM_GUEST_NAME_SIZE,name_size_2);
					eeprom_write_block((const void *)Guest_name,(void *)EEPROM_GUEST_NAME,name_size_2);
					eeprom_write_block((const void *)Guest_password,(void *)EEPROM_GUEST_PASSWORD,sizeof(Guest_password));
					eeprom_write_byte((uint8_t*)GUEST_PASS_STATUS_ADDRESS,(uint8_t)1);
					LCD_Clear();LCD_Write_String("Guest Registered");_delay_ms(250);LCD_Clear();
				
				}
				
				
				
				
				break;
			}
	}
		}  
		//**********************************************Check for data*********************************
		if(eeprom_read_byte(ADMIN_PASS_STATUS_ADDRESS)==1 || eeprom_read_byte(GUEST_PASS_STATUS_ADDRESS)==1) {
			LCD_Clear();LCD_String_xy(0,0,"1:Admin 2: Guest");
			uint8_t s=UART_Received();
		while(timeout<3 && Mode==NO_MODE){
			if(s=='1'){
				//******************************************************Admin login***********************************************************
				LCD_Clear();LCD_Write_String("Admin Mode");LCD_Clear();LCD_String_xy(0,0,"Name:");
				name_size_1= eeprom_read_word((uint8_t*)EEPROM_ADMIN_NAME_SIZE);
				  eeprom_read_block((void*)&buffer,(const void*)EEPROM_ADMIN_NAME,name_size_1);
				LCD_String_xy(0,6,buffer);_delay_ms(10);
				LCD_String_xy(1,0,"Password:");x=0;uint8_t pass_check[4]={0,0,0,0};
				while (x<password_size)
				{
					_delay_ms(10);
					uint8_t Bluetooth_Mode=UART_Received();
					if(i!='0'){
						if(Bluetooth_Mode=='1'|| Bluetooth_Mode=='2'|| Bluetooth_Mode=='3'|| Bluetooth_Mode=='4' || Bluetooth_Mode=='5' || Bluetooth_Mode=='6' || Bluetooth_Mode== '7' || Bluetooth_Mode=='8' || Bluetooth_Mode=='9' || i=='1'|| i=='2'|| i=='3'|| i=='4' || i=='5' || i=='6' || i== '7' || i=='8' || i=='9'){
							pass_check[x]=Str_toint(Bluetooth_Mode);
							uint16_t counts =Str_toint(Bluetooth_Mode);
							LCD_Write_Number(counts);_delay_ms(50);
							LCD_String_xy(1,9+x,"*");
							x++;
						}
					}
					
				}
				uint8_t stored_pass[4]={1,2,4,3}; 
				LCD_Clear();
				eeprom_read_block((void*)&stored_pass,(const void*)EEPROM_ADMIN_PASSWORD,sizeof(stored_pass));
				
				
				if(ui8ComparePass(pass_check,stored_pass,password_size)==1){
					LCD_Clear();LCD_Write_String("Correct pass");LCD_String_xy(1,0,"Welcome sir");_delay_ms(250);
					Mode=ADMIN_MODE;
				}else if(ui8ComparePass(pass_check,stored_pass,4)==0){
					LCD_Write_String(" Wrong pass");
					timeout++;
					LCD_Clear();LCD_Write_String("please reenter ");LCD_String_xy(1,0,"the password");_delay_ms(150);
					Mode=NO_MODE;
					LCD_Clear();LCD_Write_String("Number of Trials");
					_delay_ms(150);
					LCD_String_xy(1,0,"NOF: ");
					LCD_Write_Number(Password_trials);_delay_ms(150);
					Password_trials--;
				}
			}
			//***************************************************Guest Login*****************************************************
			else if(s=='2'){
				
				LCD_Clear();LCD_Write_String("Guest Mode");LCD_Clear();LCD_String_xy(0,0,"Name:");
				name_size_2= eeprom_read_word((uint8_t*)EEPROM_GUEST_NAME_SIZE);
				eeprom_read_block((void*)&Guest_name,(const void*)EEPROM_GUEST_NAME,name_size_2);
				LCD_String_xy(0,6,Guest_name);_delay_ms(10);
				LCD_String_xy(1,0,"Password:");x=0;uint8_t pass_check[4]={0,0,0,0};
				while (x<password_size)
				{
					_delay_ms(10);
					uint8_t Bluetooth_Mode=UART_Received();
					if(i!='0'){
						if(Bluetooth_Mode=='1'|| Bluetooth_Mode=='2'|| Bluetooth_Mode=='3'|| Bluetooth_Mode=='4' || Bluetooth_Mode=='5' || Bluetooth_Mode=='6' || Bluetooth_Mode== '7' || Bluetooth_Mode=='8' || Bluetooth_Mode=='9' || i=='1'|| i=='2'|| i=='3'|| i=='4' || i=='5' || i=='6' || i== '7' || i=='8' || i=='9'){
							pass_check[x]=Str_toint(Bluetooth_Mode);
							uint16_t counts =Str_toint(Bluetooth_Mode);
							LCD_Write_Number(counts);_delay_ms(50);
							LCD_String_xy(1,9+x,"*");
							x++;
						}
					}
					
				}
				uint8_t stored_pass[4]={1,2,4,3};
				LCD_Clear();
				eeprom_read_block((void*)&stored_pass,(const void*)EEPROM_GUEST_PASSWORD,sizeof(stored_pass));
				
				
				if(ui8ComparePass(pass_check,stored_pass,password_size)==1){
					LCD_Clear();LCD_Write_String("Correct pass");LCD_String_xy(1,0,"Welcome sir");_delay_ms(250);
					Mode=GUEST_MODE;
					}else if(ui8ComparePass(pass_check,stored_pass,4)==0){
					LCD_Write_String(" Wrong pass");
					timeout++;
					LCD_Clear();LCD_Write_String("please reenter ");LCD_String_xy(1,0,"the password");_delay_ms(150);
					Mode=NO_MODE;
					LCD_Clear();LCD_Write_String("Number of Trials");
					_delay_ms(150);
					LCD_String_xy(1,0,"NOF: ");
					LCD_Write_Number(Password_trials);_delay_ms(150);
					Password_trials--;
				}
				

			}
				}
				//***************************************************Trials Number**********************************************
				if(timeout==3){
					LCD_Clear();
					LCD_Write_String("Wrong Password");
					LCD_String_xy(1,0,"Entered 3 Times");LCD_Clear();LCD_Write_String("i will call 911 ");LCD_String_xy(1,0,":):):(:(");
					Mode=NO_MODE;
					}
			//******************************************************Guest Password********************************************************************
				
		
		value++;
	}
			
		/*******************************************************************************************************************************************************
		**************************************************************************************************************************************/	
	
	
					
//**************************************************************** CONTROL OF THE HOUSE***************************************************\/
	while (1){
		switch (Mode)
		{
		case ADMIN_MODE :
		LCD_Clear();
		
		LCD_String_xy(0,0,"1:Room1  2:Room2");LCD_String_xy(1,0,"3:Door  4:AC");_delay_ms(500);
		
		uint8_t pressed_number=UART_Received();
		uint8_t responce =SPI_TranCeive(0);
		switch (pressed_number)
		{
		case '1'://************************************Room 1 control ***************************************
			 responce=SPI_TranCeive(1);
			 LCD_Clear();LCD_String_xy(0,0,"Room 1");_delay_ms(100);
			 
			 LCD_Clear();LCD_String_xy(0,0,"1:Status 2:Open light");LCD_String_xy(1,0,"3:Turn OFF Light");
			 pressed_number=UART_Received();
			 if(pressed_number=='2'){responce=SPI_TranCeive(2);LCD_Clear();LCD_String_xy(0,0,"Lights are ON");}
				 else if(pressed_number=='1'){
					 responce=SPI_TranCeive(1);
					 LCD_Clear();
					 responce=SPI_TranCeive(1);
					 if(responce==1)LCD_String_xy(0,0,"lights are on");else if(responce==0)LCD_String_xy(0,0,"lights are off");
					 _delay_ms(500);
					 LCD_Clear();
				 }else if(pressed_number=='3')responce=SPI_TranCeive(3);
			break;
		case '2'://************************************Room 2 control ***************************************
			 LCD_Clear();LCD_String_xy(0,0,"Room 2");_delay_ms(500);
			 responce=SPI_TranCeive(2);
			 LCD_Clear();LCD_String_xy(0,0,"1:Status 2:Open light");LCD_String_xy(1,0,"3:Turn OFF Light");
			 pressed_number=UART_Received();
			 if(pressed_number=='2'){responce=SPI_TranCeive(2);LCD_Clear();LCD_String_xy(0,0,"Lights are ON");}
			 else if(pressed_number=='1'){
				 responce=SPI_TranCeive(1);
				 LCD_Clear();
				 responce=SPI_TranCeive(1);
				 if(responce==1)LCD_String_xy(0,0,"Room lights on");else if(responce==0)LCD_String_xy(0,0,"Room lights off");
				 _delay_ms(500);
				 LCD_Clear();
			 }else if(pressed_number=='3')responce=SPI_TranCeive(3);
		 
			break;
		case '3':
		 responce =SPI_TranCeive(3);
			
			LCD_Clear();
			LCD_String_xy(0,0,"1:Open door");
			LCD_String_xy(1,0,"2:Close Door");
			_delay_ms(500);
			pressed_number=UART_Received();
			_delay_ms(100);
			if(pressed_number=='1'){
				responce=SPI_TranCeive(1);
				LCD_Clear();
				LCD_Write_String("Doors Open!");
				
				}
			else if(pressed_number=='2'){
				responce=SPI_TranCeive(2);
				LCD_Write_String("Doors Closed!");
					}
			_delay_ms(500);
			break;
		case '4':
		 responce =SPI_TranCeive(4);LCD_Clear();_delay_ms(100);
		 LCD_String_xy(0,0,"1:Turn on Ac");LCD_String_xy(1,0,"2:Turn off Ac");pressed_number=UART_Received();_delay_ms(100);
		 if(pressed_number=='1'){
			 LCD_Clear();LCD_String_xy(0,0,"Temp Higher");
			 LCD_String_xy(1,0,"than 30^C");
			 }else if(pressed_number=='2'){
				LCD_Clear();LCD_String_xy(0,0,"Temp Lower");
				LCD_String_xy(1,0,"than 21^C");
			 }
		 
			break;	
		}
		break;
//********************************************************Guest Mode*******************************************************
		
			case GUEST_MODE:
				LCD_Clear();
		
		LCD_String_xy(0,0,"1:Room1  2:Room2");LCD_String_xy(1,0,"3:AC");_delay_ms(500);
		
		pressed_number=UART_Received();
		responce =SPI_TranCeive(0);
		switch (pressed_number)
		{
		case '1'://************************************Room 1 control ***************************************
			 responce=SPI_TranCeive(1);
			 LCD_Clear();LCD_String_xy(0,0,"Room 1");_delay_ms(100);
			 
			 LCD_Clear();LCD_String_xy(0,0,"1:Status 2:Open light");LCD_String_xy(1,0,"3:Turn OFF Light");
			 pressed_number=UART_Received();
			 if(pressed_number=='2'){responce=SPI_TranCeive(2);LCD_Clear();LCD_String_xy(0,0,"Lights are ON");}
				 else if(pressed_number=='1'){
					 responce=SPI_TranCeive(1);
					 LCD_Clear();
					 responce=SPI_TranCeive(1);
					 if(responce==1)LCD_String_xy(0,0,"lights are on");else if(responce==0)LCD_String_xy(0,0,"lights are off");
					 _delay_ms(500);
					 LCD_Clear();
				 }else if(pressed_number=='3')responce=SPI_TranCeive(3);
			break;
		case '2'://************************************Room 2 control ***************************************
			 LCD_Clear();LCD_String_xy(0,0,"Room 2");_delay_ms(500);
			 responce=SPI_TranCeive(2);
			 LCD_Clear();LCD_String_xy(0,0,"1:Status 2:Open light");LCD_String_xy(1,0,"3:Turn OFF Light");
			 pressed_number=UART_Received();
			 if(pressed_number=='2'){responce=SPI_TranCeive(2);LCD_Clear();LCD_String_xy(0,0,"Lights are ON");}
			 else if(pressed_number=='1'){
				 responce=SPI_TranCeive(1);
				 LCD_Clear();
				 responce=SPI_TranCeive(1);
				 if(responce==1)LCD_String_xy(0,0,"Room lights on");else if(responce==0)LCD_String_xy(0,0,"Room lights off");
				 _delay_ms(500);
				 LCD_Clear();
			 }else if(pressed_number=='3')responce=SPI_TranCeive(3);
		 
			break;
			
		case '3':
		responce =SPI_TranCeive(4);LCD_Clear();_delay_ms(100);
		LCD_String_xy(0,0,"1:Turn on Ac");LCD_String_xy(1,0,"2:Turn off Ac");pressed_number=UART_Received();_delay_ms(100);
		if(pressed_number=='1'){
			LCD_Clear();LCD_String_xy(0,0,"Temp Higher");
			LCD_String_xy(1,0,"than 30^C");
			responce=SPI_TranCeive(4);
			}else if(pressed_number=='2'){
			LCD_Clear();LCD_String_xy(0,0,"Temp Lower");
			LCD_String_xy(1,0,"than 21^C");
			responce=SPI_TranCeive(4);
		}
		
		break;
			 }
			 break;
		}
					
			_delay_ms(200);
			
			
	}
		
	return 0;
				
			}
	
		
	







