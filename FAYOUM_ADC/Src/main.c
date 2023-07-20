/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : EXTI DRIVER                      */
/*   DATE        : 18 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"

#include "../Include/MCAL/EXTI/EXTI_Interface.h"
#include "../Include/MCAL/EXTI/EXTI_Private.h"
#include "../Include/MCAL/EXTI/EXTI_Configuration.h"

#include "../Include/MCAL/GBI/GPI_Interface.h"


#include "../Include/MCAL/ADC/ADC_Interface.h"
#include "../Include/MCAL/ADC/ADC_Private.h"



void (main)(void)
{
	MDIO_voidInit();
	ADC_voidInit();
	u16 digital =ADC_u8GetDigitalValue(0);
	u16 analog=0;
	while (1)
	{
		digital =ADC_u8GetDigitalValue(0);
		analog = (u16)((digital*500UL)/1024);
		if (analog >30)
		{
			MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
		}
		else
		{
			MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
		}
//    	if (analog <= 1500)
//    	{
//    		MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
//    		MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
//    		MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_LOW);
//    	}
//    	else if ((analog > 1500)&&(analog <= 3000))
//    	{
//    		MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
//			MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
//			MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_LOW);
//    	}
//    	else if (analog >3000)
//		{
//			MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
//			MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
//			MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
//		}
	}

}

void ToggleLed(void)
{
	static u8 flag=0;
	if (flag==0)
	{

		flag=1;
	}
	else
	{
		MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		flag=0;
	}
}
