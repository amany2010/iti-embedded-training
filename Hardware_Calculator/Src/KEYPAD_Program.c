#include "util/delay.h"
#include"../Include/LIB/STD_TYPES.h"
#include"../Include/LIB/BIT_MATH.h"
#include<stdlib.h>
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
/************************************************************/
/* Function  : Convert chachter To Decimal					*/
/* Parameter : Array Of Charachter							*/
/* return 	 : Float Number									*/
/************************************************************/
f32 CHAR_2_Decmal(u8 *Copy_u8_ptr)
{// Open Bracket of function
	f32 LOCAL_s32_val=0;// Float variable to stor returne value
	u16 Local_u16_Co=0;// integer variable as counter
	u8 LOCAL_u8_f=KEYPAD_u8_FLAG_DOWN;// char variable as Flag
	while(Copy_u8_ptr[Local_u16_Co]!=NULL)//Loop on array
	{//open bracket of while loop
		if(Copy_u8_ptr[Local_u16_Co]=='-')// Cheack if array element is '-'
		{//open bracket of signe '-' conditation
			LOCAL_u8_f=KEYPAD_u8_FLAG_UP; // Enable Flag
			Local_u16_Co++;// incerement Counter by 1
			continue;//jumb this case
		}//Close bracket of signe '-' conditation
		LOCAL_s32_val=LOCAL_s32_val*10+(Copy_u8_ptr[Local_u16_Co]-'0');/*Cnovert KEY Value FRom Character to decimal */
		Local_u16_Co++;
	}//Close bracket of while loop

	if(LOCAL_u8_f)//Cheack if Flag is enable
	{// Open Brackets of Enable flag Condition
		LOCAL_s32_val*=-1;	// Multiplay value by -1
		LOCAL_u8_f=KEYPAD_u8_FLAG_DOWN;// disEnable Flag
	}// Open Brackets of Enable flag Condition

	return LOCAL_s32_val;	//return integer value

}// Close Bracket of function

/************************************************************/
/* Function  : Clear Array									*/
/* Parameter : Array Of Charachter							*/
/* return 	 : No											*/
/************************************************************/
void Clear_array(u8 *ptr)
{// Open Bracket of function
	u16 Local_u8_Co=0;// integer variable as counter
	while(ptr[Local_u8_Co]!=NULL)//Loop on array
	{//open bracket of while loop
		ptr[Local_u8_Co]=NULL;	// assign array element to NULL
		Local_u8_Co++;// incerement counter by 1
	}//Close bracket of while loop
}// Close Bracket of function

/************************************************************/
/* Function  : Take values and apply operation on them		*/
/* Parameter : No											*/
/* return 	 : No											*/
/************************************************************/
void KEYPAD_u32_Calculator()
{// Open Brackets of KEYPAD_u32_Calculator() Function

/*************************************************************************************************/
/* LOCAL_f32_values	  :	Array To store decimal values of characters  To apply operation  		 */
/* LOCAL_f32_Result   : To store The Result Value Of Entered Equation		   	   			 	 */
/* local_u8KeypadValue: To store The The that returned from KEYPAD			   	   			 	 */
/* LOCAL_u8_Operation : To store The Operation Value						   	   				 */
/* Local_u8_KEYValues : Array to stor char value to passing ir as a parameter to CHAR_2_Decmal() */
/* Lcal_u16_Counter	  : Counter To Loop on array							   	   			 	 */
/*************************************************************************************************/
	f32 LOCAL_f32_values[2], LOCAL_f32_Result=0;
	u16 Lcal_u16_Counter=0;
	u8 LOCAL_u8_Operation,local_u8KeypadValue=255,LOCAL_u8_f=KEYPAD_u8_FLAG_DOWN,Local_u8_KEYValues[5]={NULL};
	MDIO_voidInit();
	HLCD_voidInit();

	while (1)																												    /*LOOP To make infitiy INPut		         */
	{// Open Brackets of While LOOP
		local_u8KeypadValue = HKEYPAD_u8_GetPressedKey();																	    /* Get KEYPD Value 					         */
		if (local_u8KeypadValue != KEYPAD_u8_KEY_NOT_PRESSED)																    /* Check if KEYPAD Is UnPressed	             */
			{// Open Brackets of UnPressed Condition
				HLCD_voidSendData(local_u8KeypadValue);																			/* Display Key Value On SCreen	             */
				if(local_u8KeypadValue=='c')																					/* Check if Clear Butom Is Pressed	         */
				{// Open Brackets of Clear Condition
					HLCD_voidClearDisplay();																					/* Calling Clear Screen Function	         */
					Clear_array(LOCAL_f32_values);																				/* Make LOCAL_f32_values array Empty         */
					Clear_array(Local_u8_KEYValues);																			/* Make Local_u8_KEYValues Empty	         */
					LOCAL_u8_f=KEYPAD_u8_FLAG_DOWN;																				/* Disable Falg						         */
					Lcal_u16_Counter=0;																							/* assign counter to 0				         */
				}//Close Brackets of Clear Condition

			else if(local_u8KeypadValue=='+'||local_u8KeypadValue=='-'||local_u8KeypadValue=='*'||local_u8KeypadValue=='/')		/* Check if Key value is operation	         */
			{// Open Brackets of operation Condition

				if(local_u8KeypadValue=='-'&&Local_u8_KEYValues[0]==NULL)														 /* Check if Value Is Negative	             */
				{// Open Brackets of Negative Condition
					Local_u8_KEYValues[0]=local_u8KeypadValue;														  			 /* Enable Flag						         */
					Lcal_u16_Counter++;																							 /* incerement counter by 1			         */
				}// Close Brackets of Negative Condition

				else//if key value is normal operation
				{// Open Brackets key value is normal operation conditation
					LOCAL_u8_Operation=local_u8KeypadValue;																		 /* assign Operation Value to key value      */
					LOCAL_f32_values[0]=CHAR_2_Decmal(Local_u8_KEYValues);														 /* convert char to decimal by pasiing array of key values as a parameter and stor returned value in array[0]	*/
					Clear_array(Local_u8_KEYValues);																			 /* Clear array of key values			     */
					Lcal_u16_Counter=0;																							 /* assign counter to 0				         */
				}// Close Brackets key value is normal operation conditation
			}//Close Brackets of operation Condition
			else if(local_u8KeypadValue=='=')																					 /*	if KEY VAlue Equal '='				     */
			{// Open Brackets of else
				LOCAL_f32_values[1]=CHAR_2_Decmal(Local_u8_KEYValues);															 /* convert char to decimal by pasiing array of key values as a parameter and stor returned value in array[1]	*/
				Lcal_u16_Counter=0;																							     /* assign counter to 0				         */
				switch(LOCAL_u8_Operation)																						 /* Check Operation Value				     */
				{// Opemn Brackets of Switch
					case '+':
							LOCAL_f32_Result=LOCAL_f32_values[0]+LOCAL_f32_values[1];											 /*Result Equal Summation of tow values	     */
							break;// end of case 1
					case '-':

							LOCAL_f32_Result=LOCAL_f32_values[0]-LOCAL_f32_values[1];											 /*Result Equal Subtraction of tow values    */
							break;// end of case 2
					case '*':
							LOCAL_f32_Result=LOCAL_f32_values[0]*LOCAL_f32_values[1];											 /*Result Equal Multiplication of tow values */
							break;// end of case 3
					case '/':

							if(LOCAL_f32_values[1]==0)																		     /* Check if Second Value Equal Zero	     */
							{//open bracket of Second Value Equal Zero condtion
								LOCAL_u8_f=KEYPAD_u8_FLAG_UP;															         /*Enable Becous Can't Divion on Zero	     */
							}//close bracket of Second Value Equal Zero condtion

							else
							{//open bracket of else
								LOCAL_f32_Result=LOCAL_f32_values[0]/LOCAL_f32_values[1];										 /*Result Equal division of tow values	     */
							}// close bracket of else
							break;// end of case 4
				}// Close Brackets of Switch
				if(LOCAL_u8_f)                                                                                                   /* Cheack if Flag is enable			     */
					{//open bracket of Flag is enable condition
						HLCD_voidClearDisplay();                                                                                 /* Clear Screen						     */
						HLCD_voidSendString("MATH ERORR !");                                                                     /* Display MAth Error					     */
					}//close bracket of Flag is enable condition
				else
					{//open bracket of else
						HLCD_voidDisplayNumber(LOCAL_f32_Result);																/* Display equation Result				     */
					}// close bracket of else
					LOCAL_u8_f=KEYPAD_u8_FLAG_DOWN;																				/* disEnable Flag						     */
			}// Close Brackets of else

			else																											    /* Key value is Number					     */
			{//open bracket of else
				Local_u8_KEYValues[Lcal_u16_Counter]=local_u8KeypadValue;														/* store key value in array of charchter     */
				Lcal_u16_Counter++;
			}// close bracket of else
		}// Close Brackets of UnPressed Condition

	}// Close Brackets of While LOOP

}// Close Brackets of KEYPAD_u32_Calculator() Function



