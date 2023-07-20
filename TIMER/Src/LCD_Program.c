/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : LCD DRIVER                       */
/*   DATE        : 22 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include"../Include/LIB/STD_TYPES.h"
#include"../Include/LIB/BIT_MATH.h"
#include <util/delay.h>
/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include"../Include/MCAL/DIO/DIO_Interface.h"
#include"../Include/MCAL/DIO/DIO_Private.h"
#include"../Include/MCAL/DIO/DIO_Configuration.h"

/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include"../Include/HAL/LCD/LCD_Interface.h"
#include"../Include/HAL/LCD/LCD_Private.h"
#include"../Include/HAL/LCD/LCD_Configuraion.h"


void Private_voidSendInstruction (u8 copy_u8Instruction)
{
	/* Instruction --> RS = 0, Write to LCD --> RW = 0 */
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_LOW);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);
	/* Instruction --> Data Port */
	MDIO_voidSetPortValue(LCD_DATA_PORT,copy_u8Instruction);
	/* Enable --> Falling Edge (1 then 0) */
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);

}


void HLCD_voidInit(void)
{
	/* wait for 30ms */
	_delay_ms(30);
	/* Function Set Instruction */
	Private_voidSendInstruction(LCD_u8_FUNCTION_SET);
	/* wait for more 39 usec */
	_delay_ms(1);
	/* Display ON/OFF Control */
	Private_voidSendInstruction(LCD_u8_DISPLAY_CONTROL);
	/* wait for more 39 usec */
	_delay_ms(1);
	/* Clear Display */
	Private_voidSendInstruction(LCD_u8_CLEAR_DISPLAY);
	/* wait for more 1.53 msec */
	_delay_ms(2);
	/* ENtry Set Mode */
	Private_voidSendInstruction(LCD_u8_ENTRY_SET);
}


void HLCD_voidSendData(u8 copy_u8Char)
{
	/* Data --> RS = 1, Write to LCD --> RW = 0 */
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_HIGH);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);
	/* Character --> Data Port */
	MDIO_voidSetPortValue(LCD_DATA_PORT,copy_u8Char);
	/* Enable --> Falling Edge (1 then 0) */
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);
}

void HLCD_voidSendString (u8 *copy_Pu8String)
{
	while (*copy_Pu8String > 0) // Termination Condition
	{
		HLCD_voidSendData(*copy_Pu8String++); //Send char then move pointer to next char
	}
}

void HLCD_voidClearDisplay (void)
{
	Private_voidSendInstruction(LCD_u8_CLEAR_DISPLAY);
	/* wait for more 1.53 msec */
	_delay_ms(2);
}



void HLCD_voidGoToPos (u8 copy_u8RowNum, u8 copy_u8ColumnNo)
{
	switch (copy_u8RowNum)
	{
	 case LCD_u8_LINE1: Private_voidSendInstruction(LCD_u8_ROW1_ADDRESS + copy_u8ColumnNo); break;
	 case LCD_u8_LINE2: Private_voidSendInstruction(LCD_u8_ROW2_ADDRESS + copy_u8ColumnNo); break;
	}
	/* wait for more 39 usec */
	_delay_ms(1);
}


void HLCD_voidDisplayNumber(s32 copy_u32Number)
{
	s32 local_u32Num = 1;
	if (copy_u32Number == 0)
	{
		HLCD_voidSendData('0');
	}
	if (copy_u32Number < 0)
	{
		HLCD_voidSendData('-');
		copy_u32Number *= -1;
	}
	while (copy_u32Number != 0)
	{
		local_u32Num = ((local_u32Num * 10) + (copy_u32Number % 10));
		copy_u32Number = (copy_u32Number / 10);
	}
	while (local_u32Num != 1)
	{
		HLCD_voidSendData((local_u32Num % 10) + 48);
		local_u32Num = (local_u32Num / 10);
	}
}


void LCD_voidSendSpecialCharacter (u8 *copy_pu8CharArr, u8 copy_u8PatternNum,
								   u8 copy_u8LineNum,   u8 copy_ColNum)
{
	u8 local_u8CGRAMAddress, local_u8Counter;
	/* Calculate CGRAM Address = Pattern Number * 8 */
	local_u8CGRAMAddress = copy_u8PatternNum * 8;
	SET_BIT(local_u8CGRAMAddress,6);
	/* Send Command to set CGRAM Address */
	Private_voidSendInstruction(local_u8CGRAMAddress);

	for (local_u8Counter=0; local_u8Counter < 8; local_u8Counter++)
	{
		/* Send byte from character array */
		HLCD_voidSendData(copy_pu8CharArr[local_u8Counter]);
	}

	/* Send Command to set DDRAM Address */
	HLCD_voidGoToPos(copy_u8LineNum,copy_ColNum);
	/* Display pattern from CGRAM */
	HLCD_voidSendData(copy_u8PatternNum);
}

u8 Global_u8Arr[]={
		0x00,
		0x00,
		0b00010001,
		0b00010001,
		0b00011111,
		0x00,
		0b00000100,
		0x00
};
