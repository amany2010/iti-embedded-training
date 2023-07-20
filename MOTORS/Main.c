/****************************************************/
/* Library Directives							    */
/****************************************************/
#include"Include/LIB/STD_TYPES.h"
#include"Include/LIB/BIT_MATH.h"
#include <util/delay.h>
/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include"Include/MCAL/DIO/DIO_Interface.h"
#include"Include/MCAL/DIO/DIO_Private.h"
#include"Include/MCAL/DIO/DIO_Configuration.h"
/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include"Include/HAL/LCD/LCD_Interface.h"
#include"Include/HAL/LCD/LCD_Private.h"
#include"Include/HAL/LCD/LCD_Configuraion.h"
void main (void )					/*	Calling main function	*/
{// open breacket of main function

	MDIO_voidInit();				/*	Intialize DIO Driver	*/
	HLCD_voidInit();				/*	Intialize LCD Driver	*/
	 while(1)						/*	Super Loop				*/
	 {//open breacket of Super Loop

		 _delay_ms(20);				/*Wite 20 msec				*/
		 HLCD_voidClearDisplay();	/* Clear Screen				*/

		 /*********************************************************/
		 /* Check switchs Status								  */
		 /* 1--> switch  1 pressed	& switch 2  pressed  		  */
		 /* OR 	 switch  1 Not pressed	& switch 2 Not  pressed	  */
		 /* action: Clear Screen and Motor Cannot Rotate   		  */
		 /* 2--> switch  1 is pressed							  */
		 /* actions:1- counterclockwise rotation 				  */
		 /* 	   2-Display counterclockwise On Screen 		  */
		 /* 3--> switch  2 is pressed							  */
		 /* actions:1- rotation with clockwise 					  */
		 /* 		2- Display clockwise On Screen 			  	  */
		 /*********************************************************/

		 if((MDIO_u8GetPinValue (DIO_u8_PORTD, DIO_u8_PIN0)==0&&MDIO_u8GetPinValue (DIO_u8_PORTD, DIO_u8_PIN1)==0)||
			(MDIO_u8GetPinValue (DIO_u8_PORTD, DIO_u8_PIN0)==1&&MDIO_u8GetPinValue (DIO_u8_PORTD, DIO_u8_PIN1)==1))
		 {//open bracket of 2 switchs are pressed or 2 switchs aren't pressed condition

			 MDIO_voidSetPinValue (DIO_u8_PORTC, DIO_u8_PIN0,DIO_u8_LOW);
			 MDIO_voidSetPinValue (DIO_u8_PORTC, DIO_u8_PIN1,DIO_u8_LOW);
		 }//Close bracket of 2 switchs are pressed or 2 switchs aren't pressed condition
		 else if(MDIO_u8GetPinValue (DIO_u8_PORTD, DIO_u8_PIN0)==0)
		 {//open bracket of switch 1 pressed condition
			 MDIO_voidSetPinValue (DIO_u8_PORTC, DIO_u8_PIN0,DIO_u8_LOW);
			 MDIO_voidSetPinValue (DIO_u8_PORTC, DIO_u8_PIN1,DIO_u8_HIGH);
			 HLCD_voidSendString("counter clockwise");
		 }//Close bracket of switch 1 pressed condition

		 else if(MDIO_u8GetPinValue (DIO_u8_PORTD, DIO_u8_PIN1)==0)
	    {//open bracket of switch 2 pressed condition
			 MDIO_voidSetPinValue (DIO_u8_PORTC, DIO_u8_PIN1,DIO_u8_LOW);
			 MDIO_voidSetPinValue (DIO_u8_PORTC, DIO_u8_PIN0,DIO_u8_HIGH);
			 HLCD_voidSendString("clockwise");

	    }//Close bracket of switch 2 pressed condition
	 }//Close breacket of Super Loop
}// open breacket of main function
