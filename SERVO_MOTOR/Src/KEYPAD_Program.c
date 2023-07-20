#include "util/delay.h"
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"

#include "../Include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../Include/HAL/KEYPAD/KEYPAD_Private.h"
#include "../Include/HAL/KEYPAD/KEYPAD_Configuration.h"
/****************************************************/
/* LCD Directives								    */
/****************************************************/
#include"../Include/HAL/LCD/LCD_Interface.h"
#include"../Include/HAL/LCD/LCD_Private.h"
#include"../Include/HAL/LCD/LCD_Configuration.h"
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

u16 CHAR_2_Decmal(u8 *Copy_u8_ptr)
{
	u16 LOCAL_s32_val=0,i=0;
	while(Copy_u8_ptr[i]!='=')
	{
		LOCAL_s32_val=LOCAL_s32_val*10+(Copy_u8_ptr[i]-'0');														/*Cnovert KEY Value FRom Character to decimal */		i++;
	}
	return LOCAL_s32_val;
}
