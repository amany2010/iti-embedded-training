
/****************************************************/
/* Library Directives							    */
/****************************************************/
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"


#include "../Include/MCAL/GBI/GPI_Interface.h"

#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_Private.h"
#include "../Include/MCAL/TIMER0/TIMER0_Configuration.h"
/****************************************************/
/* KEYBAD Directives							    */
/****************************************************/
#include "../Include/HAL/KEYPAD/KEYPAD_Interface.h"
#include "../Include/HAL/KEYPAD/KEYPAD_Private.h"
#include "../Include/HAL/KEYPAD/KEYPAD_Configuration.h"

/****************************************************/
/* LCD Directives								    */
/****************************************************/
#include"../Include/HAL/LCD/LCD_Interface.h"
#include"../Include/HAL/LCD/LCD_Private.h"
#include"../Include/HAL/LCD/LCD_Configuration.h"

void (main)(void)
{//open bracket of main function
	_delay_ms(20);//wait 20 msec
	/*********************************************************************************/
	/*Note: Enter equal '=' after angle by keypad									 */
	/* variables:																	 */
	/* 1- char variable to take value from keypad			  						 */
	/* 2- array of char to stor values that return from keypad						 */
	/* 2- integer counter i to Reaches all items in array	  						 */
	/* 2- integer variable angle to stor angle value after converting from u8 to u16 */
	/*********************************************************************************/
	u8 arr[10],local_u8KeypadValue=255;
	u16 i=0,angle=0;
	MDIO_voidInit();	//initialize DIO Driver
	HLCD_voidInit();	//initialize LCD driver
	GPI_voidEnable();	// Enable Global interput
	while (1)//super loop
		{//open bracket of super loop
		local_u8KeypadValue=HKEYPAD_u8_GetPressedKey();				/*take keypad value from user										*/

		if (local_u8KeypadValue != KEYPAD_u8_KEY_NOT_PRESSED)		/* check if key is Not pressed										*/
		{//open bracket of Not pressed	 condiation
			if(local_u8KeypadValue=='c')							/* check if pressed key is c chachter								*/
			{//open bracket of c char condiation
				HLCD_voidClearDisplay();							/* Clear LCD	screen												*/
				i=0;												/* assign i(counter) to zero										*/
				continue;											/* jumb this loop													*/
			}//close bracket of c char condiation

			else		//if key value not c
			{//open bracket of else
				HLCD_voidSendData(local_u8KeypadValue);				/* display key value on LCD											*/
				arr[i]=local_u8KeypadValue;							/* stor key value in array											*/
				if(local_u8KeypadValue=='=')						/* Check if key value is '='										*/
				{//open bracket of '=' condition
					angle=CHAR_2_Decmal(arr);						/*assign vlaue that reurn from calling convrting function to angle	*/
					MTIMERS_voidTimer1Init(angle);					/* calling function to intialize Timer 1							*/
					MTIMERS_voidTimer0Init();						/* calling function to intialize Timer 0							*/
					i=0;											/* assign i(counter) to zero										*/
				}//close bracket of else
				i++;												/* increment i(counter) to zero										*/
			}//open bracket of else

		}//close bracket of Not pressed	 condiation
	}//close bracket of super loop
}//open bracket of main function
