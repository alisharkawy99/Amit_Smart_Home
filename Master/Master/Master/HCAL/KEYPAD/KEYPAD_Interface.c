/*
 * Keypad_Interface.h
 *
 * Created: 11/21/2022 8:37:06 PM
 *  Author: Lenovo
 */ 



#include "KEYPAD_Private.h"

const uint8_t keypad[4][4] =
{
	{'7', '4', '1', '*'},
	
	{'8', '5', '2', '0'},
	
	{'9', '6', '3', '='},
	
	{'+', '-', 'C', '/'}
};
void KEYPAD_Initialize(void)
{
	//Define direction for pins
	DIO_SetPin_Direction(KEYPAD_PRT, KEYPAD_PIN_OUT0, KEYPAD_OUT);
	DIO_SetPin_Direction(KEYPAD_PRT, KEYPAD_PIN_OUT1, KEYPAD_OUT);
	DIO_SetPin_Direction(KEYPAD_PRT, KEYPAD_PIN_OUT2, KEYPAD_OUT);
	DIO_SetPin_Direction(KEYPAD_PRT, KEYPAD_PIN_OUT3, KEYPAD_OUT);
	//Set logic to high
	DIO_SetPin_Value(KEYPAD_PRT, KEYPAD_PIN_OUT0, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PRT, KEYPAD_PIN_OUT1, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PRT, KEYPAD_PIN_OUT2, KEYPAD_HIGH);
	DIO_SetPin_Value(KEYPAD_PRT, KEYPAD_PIN_OUT3, KEYPAD_HIGH);
	//Define direction for pins
	DIO_SetPin_Direction(KEYPAD_PRT, KEYPAD_PIN_INP0, KEYPAD_INP);
	DIO_SetPin_Direction(KEYPAD_PRT, KEYPAD_PIN_INP1, KEYPAD_INP);
	DIO_SetPin_Direction(KEYPAD_PRT, KEYPAD_PIN_INP2, KEYPAD_INP);
	DIO_SetPin_Direction(KEYPAD_PRT, KEYPAD_PIN_INP3, KEYPAD_INP);
	//Activate internal pull up
	DIO_SetPin_PullUp(KEYPAD_PRT, KEYPAD_PIN_INP0);
	DIO_SetPin_PullUp(KEYPAD_PRT, KEYPAD_PIN_INP1);
	DIO_SetPin_PullUp(KEYPAD_PRT, KEYPAD_PIN_INP2);
	DIO_SetPin_PullUp(KEYPAD_PRT, KEYPAD_PIN_INP3);
}
uint8_t KEYPAD_Read(void)
{
	uint8_t val = 0;
	uint8_t btn = 0;
	uint8_t Row_Loc = 0; //counter for rows
	uint8_t Col_Loc = 0; //counter for columns 
	for (Col_Loc = KEYPAD_COL_START; Col_Loc <= KEYPAD_COL_END; Col_Loc++) //loop for columns 
	{
		DIO_SetPin_Value(KEYPAD_PRT, Col_Loc, KEYPAD_LOW);
		for (Row_Loc = KEYPAD_ROW_START; Row_Loc <= KEYPAD_ROW_END; Row_Loc++) //loop for rows
		{
			val = DIO_GetPin_Value(KEYPAD_PRT, Row_Loc);
			if(val == KEYPAD_PRESSED)
			{
				btn = keypad[Row_Loc - KEYPAD_ROW_START][Col_Loc - KEYPAD_COL_START];
				while (val == KEYPAD_PRESSED)
				{
					val = DIO_GetPin_Value(KEYPAD_PRT, Row_Loc);
				}
				_delay_ms(10);
			}
		}
		DIO_SetPin_Value(KEYPAD_PRT, Col_Loc, KEYPAD_HIGH);
	}
	return btn;
}


