/****************************************************/
/* Library Directives							    */
/****************************************************/
#include"../Include/LIB/STD_TYPES.h"
#include"../Include/LIB/BIT_MATH.h"
#include<util/delay.h>

#include "../Include/HAL/LCD/LCD_Configuration.h"
/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include"../Include/MCAL/DIO/DIO_Interface.h"
#include"../Include/MCAL/DIO/DIO_Private.h"
#include"../Include/MCAL/DIO/DIO_Configuration.h"

/****************************************************/
/* LCD Directives								    */
/****************************************************/
#include"../Include/HAL/LCD/LCD_Interface.h"
#include"../Include/HAL/LCD/LCD_Private.h"
void Private_VoidSendInstruction(u8 Copy__U8Instruction)
{//Open Brackets of Private_VoidSEentdInstruction function

	/****************************************************/
	/* Instruction :									*/
	/* RS=0 --> Sending commands to LCD					*/
	/* RW=0 --> Write to LCD							*/
	/****************************************************/
	MDIO_voidSetPinValue(LCD_Control_Port,LCD_RS_PIN,DIO_u8_LOW);
	MDIO_voidSetPinValue(LCD_Control_Port,LCD_RW_PIN,DIO_u8_LOW);
	/* Write Instruction on data port*/
	MDIO_voidSetPortValue(LCD_Data_Port,Copy__U8Instruction);
	/* Enable Falling Edge (1 the 0) */
	MDIO_voidSetPinValue(LCD_Control_Port,LCD_E_PIN,DIO_u8_HIGH);
	/*	Wait for 1.53 msec	*/
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_Control_Port,LCD_RW_PIN,DIO_u8_LOW);

}//Close Brackets of Private_VoidSEentdInstruction function

void HLCD_voidInit()
{//Open Brackets of HLCD_voidInit
	/*	Wait for 30 Msec	*/
	_delay_ms(30);
	/*	Function Set Instruction	*/
	Private_VoidSendInstruction(LCD_u8_Function_Set);
	/*	Wait for 39 Msec	*/
	_delay_ms(1);
	/* Display (ON/OFF_) Control	*/
	Private_VoidSendInstruction(LCD_u8_Display_Control);
	/*	Wait for 39 Msec	*/
		_delay_ms(1);
	/* Clear Display Display 	*/
	Private_VoidSendInstruction(LCD_u8_Clear_Display);
	/*	Wait for 1.53 Msec	*/
			_delay_ms(2);
	/* Clear Display Display 	*/
	Private_VoidSendInstruction(LCD_u8_Entry_Set);
}//Close Brackets of HLCD_voidInit

void HLCD_voidSendData(u8 Copy_u8_SendData)
{//open Bracket Of HLCD_voidSendData Function
		/****************************************************/
		/* Data :									*/
		/* RS=1 --> Sending Data to LCD					*/
		/* RW=0 --> Write to LCD							*/
		/****************************************************/
		MDIO_voidSetPinValue(LCD_Control_Port,LCD_RS_PIN,DIO_u8_HIGH);
		MDIO_voidSetPinValue(LCD_Control_Port,LCD_RW_PIN,DIO_u8_LOW);
		/* Write Charachter on data port*/
		MDIO_voidSetPortValue(LCD_Data_Port,Copy_u8_SendData);
		/* Enable Falling Edge (1 the 0) */
		MDIO_voidSetPinValue(LCD_Control_Port,LCD_E_PIN,DIO_u8_HIGH);
		_delay_ms(2);
		MDIO_voidSetPinValue(LCD_Control_Port,LCD_RW_PIN,DIO_u8_LOW);

}//Close Bracket Of HLCD_voidSendData FunctionL

void HLCD_voidSendString(u8 *Copy_ptru8_SendData)
{//open Bracket Of HLCD_voidSendString Function

	while(*Copy_ptru8_SendData>0)	//Terminate Condition
	{//open Bracket of While Loop
		HLCD_voidSendData(*Copy_ptru8_SendData++); 	// Sent ptr char Value Then move ptr to next char
	}//open Bracket of While Loop

}//Close Bracket Of HLCD_voidSendString Function

void HLCD_voidClearDisplay(void)
{//open Bracket Of HLCD_voidClearDisplay Function
		/*send Clear command to the LCD	*/
		Private_VoidSendInstruction(LCD_u8_Entry_Set);
		/*	Wait for 1.53 msec	*/
			_delay_ms(2);
}//Close Bracket Of HLCD_voidClearDisplay Function

void HLCD_voidGoToPos(u8 Copy_u8RowNum,u8 Copy_u8ColumNum)
{//open Bracket Of HLCD_voidGoToPods Function
	switch(Copy_u8RowNum)	//Cheack Row Number
	{//open Bracket Of Switch
	case LCD_u8_Lin1:
		Private_VoidSendInstruction(LCD_u8_Row1_Address+Copy_u8ColumNum);
		break;
	case LCD_u8_Lin2:
			Private_VoidSendInstruction(LCD_u8_Row2_Address+Copy_u8ColumNum);
			break;
	}//Close Bracket Of Switch

	/* Wait for 30 msec	*/
	_delay_ms(1);

}//Close Bracket Of HLCD_voidGoToPods Function

void main(void)
{
MDIO_voidInit();
HLCD_voidInit();
_delay_ms(20);
HLCD_voidSendString("Amany");
HLCD_voidGoToPos(LCD_u8_Lin2,1);
HLCD_voidSendString("Abdelfattah");
while(1);
}

