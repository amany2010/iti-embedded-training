/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : EXTI DRIVER                      */
/*   DATE        : 18 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
/****************************************************/
/* TIMER Directives								    */
/****************************************************/
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_Private.h"
#include "../Include/MCAL/TIMER0/TIMER0_Configuration.h"
/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"

#include "../Include/MCAL/UART/UART_Interface.h"
#include "../Include/MCAL/UART/UART_Private.h"
#include "../Include/MCAL/UART/UART_Configuration.h"

void (main)(void)																		/* Calling Main Function						   					*/
{//Open Bracket of Main function
	u8 Local_u8_x=0;																	/* Local char Variable to recive data from user    					*/
	MDIO_voidInit();																	/* calling MDIO_voidInit function to intialize DIO 					*/
	UART_Init();																		/* calling UART_Init function to intialize UART	   					*/
	GPI_voidEnable();																	/* calling GPI_voidEnable function to Enable Global Interrupt UART	*/

	while (1)																			/* Super Loop														*/
	{//Open Bracket Of super Loop
		UART_voidPrintf("1->Door Controller\n2->Light Controller\n3->Close\n");			/* Calling UART print function To Display Choices Menu on user Screen*/
		Local_u8_x=UART_RecieveData();
		switch(Local_u8_x)
		{// open bracket of Switch
		case '1':																		/* if user choice Door Controller									  */
				Door_controller();                                                      /* Calling  Door Controller Function								  */
			break;//end of case 1
		case '2':                                                                       /* if user choice Light Controller									   */
				LIGHT_Controller();                                                     /* Calling Light Controller	Function								   */
			break;//end of case 2
		case '3':																		/* if user choice Return											   */
			return;                                                                     /* Exit from function												   */
		}// Close bracket of Switch
	}//Close Bracket Of super Loop
}//Close Bracket of Mainfunction

