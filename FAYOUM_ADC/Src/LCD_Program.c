/*
 * LCD_Program.c
 *
 *  Created on: Aug 15, 2021
 *      Author: DELL
 */
#include "util/delay.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../Include/HAL/LCD/LCD_Interface.h"
#include "../Include/HAL/LCD/LCD_Private.h"
#include "../Include/HAL/LCD/LCD_Configurations.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"


void Private_voidSendInstruction(u8 copy_u8Instruction)
{
	/*Instruction --> RS = 0, Writer --> RW = 0*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN,DIO_u8_LOW);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN,DIO_u8_LOW);
	/*Instruction --> Data_Port*/
	MDIO_voidSetPortValue(LCD_DATA_PORT,copy_u8Instruction);
	/*Enable --> Falling Edge (1 then 0)*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,DIO_u8_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,DIO_u8_LOW);
}


/*LCD Init*/
void HLCD_voidInit()
{
	_delay_ms(30);
	/*Fn set*/
	Private_voidSendInstruction(LCD_u8_FUNCTION_SET);
	_delay_ms(30);
	/*Display ON/OFF control*/
	Private_voidSendInstruction(LCD_u8_DISPLAY_CONTROL);
	_delay_ms(30);
	/*Clear Display*/
	Private_voidSendInstruction(LCD_u8_CLR_DISPLAY);
	_delay_ms(30);
	/*Entry Mode Set*/
	Private_voidSendInstruction(LCD_u8_ENTRY_MODE);
	_delay_ms(30);
}

/*LCD Send Data*/
void HLCD_voidSendData(u8 copy_u8Char) /* 'A' */
{
		/*Data --> RS = 1, Writer --> RW = 0*/
		MDIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN,DIO_u8_HIGH);
		MDIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN,DIO_u8_LOW);
		/*Instruction --> Data_Port*/
		MDIO_voidSetPortValue(LCD_DATA_PORT,copy_u8Char);
		/*Enable --> Falling Edge (1 then 0)*/
		MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,DIO_u8_HIGH);
		_delay_ms(2);
		MDIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN,DIO_u8_LOW);
}

void HLCD_voidSendString (char *copy_ptrString)
{
	while (*copy_ptrString > 0) //Termination condition
	{
		HLCD_voidSendData(*copy_ptrString++); //Send char then move pointer to next char
	}
}

void HLCD_voidGoToPos (u8 copy_u8RowNum, u8 copy_u8ColumnNum)
{
	if ((copy_u8RowNum >= LCD_u8_Row1) && (copy_u8RowNum <= LCD_u8_Row2) &&
		(copy_u8ColumnNum >= LCD_u8_Column1) && (copy_u8ColumnNum <= LCD_u8_Column16))
	{
		Private_voidSendInstruction(LCD_u8_POSITION);
		if (copy_u8RowNum==1)
		{
			Private_voidSendInstruction(LCD_u8_ROW1Address + copy_u8ColumnNum);
		}
		else
		{
			Private_voidSendInstruction(LCD_u8_ROW2Address + copy_u8ColumnNum);
		}
	}

}

void HLCD_voidDisplayClear (void)
{
	Private_voidSendInstruction(LCD_u8_CLR_DISPLAY);
}



