#include "util/delay.h"
#include"../Include/LIB/STD_TYPES.h"
#include"../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"

#include "../Include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../Include/HAL/KEYPAD/KEYPAD_Private.h"
#include "../Include/HAL/KEYPAD/KEYPAD_Configuration.h"

/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include"../Include/HAL/LCD/LCD_Interface.h"
#include"../Include/HAL/LCD/LCD_Private.h"
#include"../Include/HAL/LCD/LCD_Configuraion.h"


u8 KEYPAD_Au8Keys [KEYPAD_u8_ROW_NUM][KEYPAD_u8_COL_NUM]= KEYPAD_Au8_KEYS;

u8 KEYPAD_Au8RowsPins [KEYPAD_u8_ROW_NUM] = KEYPAD_Au8ROWS;
u8 KEYPAD_Au8ColsPins [KEYPAD_u8_COL_NUM] = KEYPAD_Au8COLS;

u8 HKEYPAD_u8_GetPressedKey (void)
{
	/* Variables Definitions for Loop Counters, Read pin Values, Get pressed key Value, and a flag for breaking the loop */
	u8 local_u8RowCounter, local_u8ColCounter, local_u8PinValue, local_u8KeyValue = KEYPAD_u8_KEY_NOT_PRESSED,
			local_u8Flag = KEYPAD_u8_FLAG_DOWN;

	/* for loop to activate Rows and check on columns */
	for (local_u8RowCounter = 0; local_u8RowCounter < KEYPAD_u8_ROW_NUM; local_u8RowCounter++)
	{
		MDIO_voidSetPinValue(KEYPAD_u8_PORT,KEYPAD_Au8RowsPins[local_u8RowCounter], DIO_u8_LOW); //Activate Row by setting 0 at output

		/*For Loop to check on Columns*/
		for (local_u8ColCounter=0; local_u8ColCounter < KEYPAD_u8_COL_NUM; local_u8ColCounter++)
		{
			local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_u8_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter]); //Read Column Value

			if (local_u8PinValue == DIO_u8_LOW) //Check on column Value (if true, switch is pressed)
			{
				_delay_ms (KEYPAD_u8_DEBOUNCING_MS);
				local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_u8_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter]); //Read Column Value
				while (local_u8PinValue == DIO_u8_LOW)
				{
					local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_u8_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter]); //Read Column Value
				}
				local_u8KeyValue = KEYPAD_Au8Keys[local_u8RowCounter][local_u8ColCounter]; //Get Value for pressed Key
				local_u8Flag =KEYPAD_u8_FLAG_UP; // Raise Flag up
				break;  //break from Column Loop After found pressed Key
			}
		}//end of Column Loop

		MDIO_voidSetPinValue(KEYPAD_u8_PORT,KEYPAD_Au8RowsPins[local_u8RowCounter], DIO_u8_HIGH); //Deactivate Row by setting 0 at output
		if (local_u8Flag == KEYPAD_u8_FLAG_UP) //check on flag to break and return pressed key value
		{
			break; //break from Row Loop After found pressed Key
		}
	}//end of Row for Loop

return local_u8KeyValue; //return for pressed key value
}

void KEYPAD_u32_Calculator()
{// Open Brackets of KEYPAD_u32_Calculator() Function

/*******************************************************************************/
/* LOCAL_u32_val1:		To store decimal value of characters  after operation */
/* LOCAL_u32_val2: 		To store decimal value of characters  befor operation  */
/* LOCAL_u32_Result: 	To store The Result Value Of Entered Equation		   */
/* local_u8KeypadValue: To store The The that returned from KEYPAD			   */
/* LOCAL_u8_Operation: 	To store The Operation Value						   */
/*******************************************************************************/
s32 LOCAL_u32_val1=0,LOCAL_u32_val2=0, LOCAL_u32_Result;
u8 LOCAL_u8_Operation,local_u8KeypadValue=255,LOCAL_u32_f=KEYPAD_u8_FLAG_DOWN;
	MDIO_voidInit();
	HLCD_voidInit();

	while (1)																												/*LOOP To make infitiy INPut	*/
	{// Open Brackets of While LOOP

		local_u8KeypadValue = HKEYPAD_u8_GetPressedKey();																	/* Get KEYPD Value */
		if (local_u8KeypadValue != KEYPAD_u8_KEY_NOT_PRESSED)																/* Check if KEYPAD Is UnPressed	*/
		{// Open Brackets of UnPressed Condition

			if(local_u8KeypadValue=='c')																					/* Check if Clear Butom Is Pressed	*/
			{// Open Brackets of Clear Condition
				HLCD_voidClearDisplay();																					/* Calling Clear Screen Function	*/
				LOCAL_u32_val2=LOCAL_u32_val1=0;																			/* return Two Values To zero*/
				LOCAL_u32_f=KEYPAD_u8_FLAG_DOWN;

			}//Close Brackets of Clear Condition

			else if(local_u8KeypadValue!='=')																				/* Check if KEy Equal Number Or operation */
			{// Open Brackets of Numbers&operation Condition
				HLCD_voidSendData(local_u8KeypadValue);																		/* Display Key Value On SCreen			  */
				if(local_u8KeypadValue=='+'||local_u8KeypadValue=='-'||local_u8KeypadValue=='*'||local_u8KeypadValue=='/')	/* Check if KEy is operation */
				{// Open Brackets of operation Condition
					if(local_u8KeypadValue=='-'&&(LOCAL_u32_val2>0||LOCAL_u32_val1==0))										/* Check if Value Is Negative			   */
					{// Open Brackets of Negative Condition
						LOCAL_u32_f=KEYPAD_u8_FLAG_UP;																		/* Enable Flag								*/
						continue;																							/* Jump negative signal value				*/
					}// Close Brackets of Negative Condition
					else
					{
						LOCAL_u8_Operation=local_u8KeypadValue;																/* Stor KeyValue In OPeration Value			*/
						LOCAL_u32_val2=LOCAL_u32_val1;																		/* Stor Value1 in Value 2					*/
						LOCAL_u32_val1=0;																					/* return value 1 to 0 To calculate value after operation */
						continue;																							/* Jump OperationValue						*/
					}
				}//Close Brackets of operation Condition

				LOCAL_u32_val1=LOCAL_u32_val1*10+(local_u8KeypadValue-'0');													/*Cnovert KEY Value FRom Character to decimal */

				if(LOCAL_u32_f)																								/*Cheack if Flag is enable*/
				{// Open Brackets of Enable flag Condition
					LOCAL_u32_val1*=-1;																						/* Muktiplay value by -1	*/
					LOCAL_u32_f=KEYPAD_u8_FLAG_DOWN;																		/* disEnable Flag			*/

				}// Open Brackets of Enable flag Condition


			}//Close Brackets of Numbers&operation Condition


		else																												/*	if KEY VAlue Equal =	*/
		{// Open Brackets of else
			HLCD_voidSendData(local_u8KeypadValue);																			/* Display Key Value On Screen	*/

			switch(LOCAL_u8_Operation)																						/* Check Operation Value		*/
			{// Opemn Brackets of Switch
				case '+':
						LOCAL_u32_Result=LOCAL_u32_val2+LOCAL_u32_val1;														/*Result Equal Summation of tow values	*/
						break;
				case '-':

						LOCAL_u32_Result=LOCAL_u32_val2-LOCAL_u32_val1;												        /*Result Equal Subtraction of tow values	*/
						break;
				case '*':
						LOCAL_u32_Result=LOCAL_u32_val2*LOCAL_u32_val1;												        /*Result Equal Multiplication of tow values	*/
						break;
				case '/':

						if(LOCAL_u32_val1==0)																		        /* Check if Second Value Equal Zero*/
						{
							LOCAL_u32_f=KEYPAD_u8_FLAG_UP;															        /*Enable Becous Can't Divion on Zero	*/
						}

						else
						{
						LOCAL_u32_Result=LOCAL_u32_val2/LOCAL_u32_val1;												        /*Result Equal division of tow values	*/
						}
						break;
			}// Close Brackets of Switch
			if(LOCAL_u32_f)                                                                                                    /* Cheack if Flag is enable	*/
				{
					HLCD_voidClearDisplay();                                                                                   /* Clear Screen				*/
					HLCD_voidSendString("MATH ERORR !");                                                                       /* Display MAth Error		*/
				}


			else
				{

					HLCD_voidDisplayNumber(LOCAL_u32_Result);
				}
				LOCAL_u32_val2=LOCAL_u32_val1=0;																				/* return Two Values To zero*/
				LOCAL_u32_f=KEYPAD_u8_FLAG_DOWN;																				/* disEnable Flag			*/
		}// Close Brackets of else
		}// Close Brackets of UnPressed Condition

	}// Close Brackets of While LOOP

}// Close Brackets of KEYPAD_u32_Calculator() Function

void main (void)
{
	_delay_ms(20);																												/* Delay 20 msec					*/
	KEYPAD_u32_Calculator();																									/* Calling alculator Function	*/
}

