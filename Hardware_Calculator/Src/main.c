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
void main (void)
{
	KEYPAD_u32_Calculator();																									/* Calling alculator Function	*/
}


