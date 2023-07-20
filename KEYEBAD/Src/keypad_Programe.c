/****************************************************/
/* Library Directives							    */
/****************************************************/
#include"../Include/LIB/STD_TYPES.h"
#include"../Include/LIB/BIT_MATH.h"
#include<util/delay.h>

/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include"../Include/MCAL/DIO/DIO_Interface.h"
#include"../Include/MCAL/DIO/DIO_Private.h"
#include"../Include/MCAL/DIO/DIO_Configuration.h"


/****************************************************/
/* KeyPad Directives								*/
/****************************************************/
#include"../Include/HAL/keybad/keypad_Interface.h"
#include"../Include/HAL/keybad/keypad_Private.h"
#include"../Include/HAL/keybad/keypad_Configuration.h"

u8 KEYPAD_u8Arr[KEYPAD_u8_ROW_NUM][KEYPAD_u8_COL_NUM]=KEYPAD_ARRu8_Keys;
u8 KEYPAD_u8Arr_ROWPins[KEYPAD_u8_ROW_NUM]=KEYPAD_u8ARR_ROWS;
u8 KEYPAD_u8Arr_COLPins[KEYPAD_u8_COL_NUM]=KEYPAD_u8ARR_COLS;


u8 HKEPAD_u8_GETPressedKey(void)
{
		u8 local_u8rowcounter,local_u8colcounter,local_u8pinvalue,local_u8keyvalue=KEYPAD_u8_NOTPressed,local_u8flag=KeyPAd_u8Flag_Down ;
		for(local_u8rowcounter=0; local_u8rowcounter < KEYPAD_u8_ROW_NUM ; local_u8rowcounter++)
		{
			MDIO_voidSetPinValue (KEYPAD_u8_PORT,KEYPAD_u8Arr_ROWPins[local_u8rowcounter], DIO_u8_LOW);

			for(local_u8colcounter=0 ; local_u8colcounter < KEYPAD_u8_COL_NUM ; local_u8colcounter++)
			{
				local_u8pinvalue=MDIO_u8GetPinValue (KEYPAD_u8_PORT, KEYPAD_u8Arr_COLPins[local_u8colcounter]);

				if(local_u8pinvalue==DIO_u8_LOW)
				{
					_delay_ms(KEYPAD_u8_DEBOUNCING_MS);
					local_u8pinvalue=MDIO_u8GetPinValue (KEYPAD_u8_PORT,KEYPAD_u8Arr_COLPins[local_u8colcounter]);
					while(local_u8pinvalue==DIO_u8_LOW)
					{
						local_u8pinvalue=MDIO_u8GetPinValue(KEYPAD_u8_PORT,KEYPAD_u8Arr_COLPins[local_u8colcounter]);
					}

					local_u8keyvalue = KEYPAD_u8Arr[local_u8rowcounter][local_u8colcounter];
					local_u8flag = KeyPAd_u8Flag_UP;
					break;
				}
			}

			MDIO_voidSetPinValue (KEYPAD_u8_PORT, KEYPAD_u8Arr_ROWPins[local_u8rowcounter], DIO_u8_HIGH);
			if(local_u8flag == KeyPAd_u8Flag_UP)
			{
				break;
			}
		}
	return local_u8keyvalue ;
	}

	void main(void)
	{
		MDIO_voidInit();
		HLCD_voidInit();
		u8 local_u8keypadvalue=255;
		while(1)
		{
			local_u8keypadvalue	= HKEPAD_u8_GETPressedKey();
			if( local_u8keypadvalue!= KEYPAD_u8_NOTPressed)
			{
				HLCD_voidSendData(local_u8keypadvalue);
			}
		}
	}
