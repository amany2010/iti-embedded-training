/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : DIO DRIVER                       */
/*   DATE        : 19 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include"../Include/LIB/STD_TYPES.h"
#include"../Include/LIB/BIT_MATH.h"

/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include"../Include/MCAL/DIO/DIO_Interface.h"
#include"../Include/MCAL/DIO/DIO_Private.h"
#include"../Include/MCAL/DIO/DIO_Configuration.h"


void MDIO_voidInit(void)
{
	/*Set all port A pins Direction due to pre-configurations.*/
	DIO_u8_DDRA_REG= CONC_BIT(DIO_u8_PA7_INITIAL_DIRECTION,DIO_u8_PA6_INITIAL_DIRECTION,DIO_u8_PA5_INITIAL_DIRECTION,
							  DIO_u8_PA4_INITIAL_DIRECTION,DIO_u8_PA3_INITIAL_DIRECTION,DIO_u8_PA2_INITIAL_DIRECTION,
							  DIO_u8_PA1_INITIAL_DIRECTION,DIO_u8_PA0_INITIAL_DIRECTION);

	/*Set all port B pins Direction due to pre-configurations.*/
	DIO_u8_DDRB_REG= CONC_BIT(DIO_u8_PB7_INITIAL_DIRECTION,DIO_u8_PB6_INITIAL_DIRECTION,DIO_u8_PB5_INITIAL_DIRECTION,
							  DIO_u8_PB4_INITIAL_DIRECTION,DIO_u8_PB3_INITIAL_DIRECTION,DIO_u8_PB2_INITIAL_DIRECTION,
							  DIO_u8_PB1_INITIAL_DIRECTION,DIO_u8_PB0_INITIAL_DIRECTION);

	/*Set all port C pins Direction due to pre-configurations.*/
	DIO_u8_DDRC_REG= CONC_BIT(DIO_u8_PC7_INITIAL_DIRECTION,DIO_u8_PC6_INITIAL_DIRECTION,DIO_u8_PC5_INITIAL_DIRECTION,
							  DIO_u8_PC4_INITIAL_DIRECTION,DIO_u8_PC3_INITIAL_DIRECTION,DIO_u8_PC2_INITIAL_DIRECTION,
							  DIO_u8_PC1_INITIAL_DIRECTION,DIO_u8_PC0_INITIAL_DIRECTION);

	/*Set all port D pins Direction due to pre-configurations.*/
	DIO_u8_DDRD_REG= CONC_BIT(DIO_u8_PD7_INITIAL_DIRECTION,DIO_u8_PD6_INITIAL_DIRECTION,DIO_u8_PD5_INITIAL_DIRECTION,
							  DIO_u8_PD4_INITIAL_DIRECTION,DIO_u8_PD3_INITIAL_DIRECTION,DIO_u8_PD2_INITIAL_DIRECTION,
							  DIO_u8_PD1_INITIAL_DIRECTION,DIO_u8_PD0_INITIAL_DIRECTION);


	/*Set all port A pins Values due to pre-configurations.*/
	DIO_u8_PORTA_REG= CONC_BIT(DIO_u8_PA7_INITIAL_VALUE, DIO_u8_PA6_INITIAL_VALUE, DIO_u8_PA5_INITIAL_VALUE,
							   DIO_u8_PA4_INITIAL_VALUE, DIO_u8_PA3_INITIAL_VALUE, DIO_u8_PA2_INITIAL_VALUE,
							   DIO_u8_PA1_INITIAL_VALUE, DIO_u8_PA0_INITIAL_VALUE);

	/*Set all port B pins Values due to pre-configurations.*/
	DIO_u8_PORTB_REG= CONC_BIT(DIO_u8_PB7_INITIAL_VALUE, DIO_u8_PB6_INITIAL_VALUE, DIO_u8_PB5_INITIAL_VALUE,
							   DIO_u8_PB4_INITIAL_VALUE, DIO_u8_PB3_INITIAL_VALUE, DIO_u8_PB2_INITIAL_VALUE,
							   DIO_u8_PB1_INITIAL_VALUE, DIO_u8_PB0_INITIAL_VALUE);

	/*Set all port C pins Values due to pre-configurations.*/
	DIO_u8_PORTC_REG= CONC_BIT(DIO_u8_PC7_INITIAL_VALUE, DIO_u8_PC6_INITIAL_VALUE, DIO_u8_PC5_INITIAL_VALUE,
							   DIO_u8_PC4_INITIAL_VALUE, DIO_u8_PC3_INITIAL_VALUE, DIO_u8_PC2_INITIAL_VALUE,
							   DIO_u8_PC1_INITIAL_VALUE, DIO_u8_PC0_INITIAL_VALUE);

	/*Set all port D pins Values due to pre-configurations.*/
	DIO_u8_PORTD_REG= CONC_BIT(DIO_u8_PD7_INITIAL_VALUE, DIO_u8_PD6_INITIAL_VALUE, DIO_u8_PD5_INITIAL_VALUE,
							   DIO_u8_PD4_INITIAL_VALUE, DIO_u8_PD3_INITIAL_VALUE, DIO_u8_PD2_INITIAL_VALUE,
							   DIO_u8_PD1_INITIAL_VALUE, DIO_u8_PD0_INITIAL_VALUE);

}

/******************************************************************************/
/* Function: MDIO_voidSetPinDirection                        				  */
/* I/P Parameters: Port ID,  Pin ID, Pin Direction			          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the direction of a given pin				       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinId: From DIO_u8_PIN0 to DIO_u8_PIN7							  */
/* copy_u8PinDirection: DIO_u8_OUTPUT - DIO_u8_INPUT						  */
/******************************************************************************/
void MDIO_voidSetPinDIrection (u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinDIrection)
{
	/*Inputs Validation*/
	if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA) ||
		(copy_u8PinID > DIO_u8_PIN7)   || (copy_u8PinID < DIO_u8_PIN0)	)
	{

	}
	else
	{
		switch (copy_u8PortID)
		{
		   case DIO_u8_PORTA:
			   	   	   	   	   switch (copy_u8PinDIrection) //check on direction
			   	   	   	   	   {
			   	   	   	   	     case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRA_REG,copy_u8PinID);  break; //set pin to output mode
			   	   	   	   	     case DIO_u8_INPUT:  CLR_BIT(DIO_u8_DDRA_REG,copy_u8PinID);  break; //set pin to input mode
			   	   	   	   	   }//end of switch
			   	   	   	   	   break;
		   case DIO_u8_PORTB:
							   switch (copy_u8PinDIrection) //check on direction
							   {
								 case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRB_REG,copy_u8PinID);  break; //set pin to output mode
								 case DIO_u8_INPUT:  CLR_BIT(DIO_u8_DDRB_REG,copy_u8PinID);  break; //set pin to input mode
							   }//end of switch
							   break;
		   case DIO_u8_PORTC:
							   switch (copy_u8PinDIrection) //check on direction
							   {
								 case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRC_REG,copy_u8PinID);  break; //set pin to output mode
								 case DIO_u8_INPUT:  CLR_BIT(DIO_u8_DDRC_REG,copy_u8PinID);  break; //set pin to input mode
							   }//end of switch
							   break;
		   case DIO_u8_PORTD:
							   switch (copy_u8PinDIrection) //check on direction
							   {
								 case DIO_u8_OUTPUT: SET_BIT(DIO_u8_DDRD_REG,copy_u8PinID);  break; //set pin to output mode
								 case DIO_u8_INPUT:  CLR_BIT(DIO_u8_DDRD_REG,copy_u8PinID);  break; //set pin to input mode
							   }//end of switch
							   break;
		}//end of switch
	}//end of else
}//end of function


/******************************************************************************/
/* Function: MDIO_voidSetPinValue	                        				  */
/* I/P Parameters: Port ID,  Pin ID, Pin Value				          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the Value of a given pin					       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinId: From DIO_u8_PIN0 to DIO_u8_PIN7							  */
/* copy_u8Value: DIO_u8_HIGH - DIO_u8_LOW		    						  */
/******************************************************************************/
void MDIO_voidSetPinValue (u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinValue)
{
	/*Inputs Validation*/
	if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA) ||
		(copy_u8PinID > DIO_u8_PIN7)   || (copy_u8PinID < DIO_u8_PIN0)	)
	{

	}
	else
	{
		switch (copy_u8PortID)
		{
		   case DIO_u8_PORTA:
			   	   	   	   	   switch (copy_u8PinValue) //check on direction
			   	   	   	   	   {
			   	   	   	   	     case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTA_REG,copy_u8PinID);  break; //set pin to High mode
			   	   	   	   	     case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTA_REG,copy_u8PinID);  break; //set pin to Low mode
			   	   	   	   	   }//end of switch
			   	   	   	   	   break;
		   case DIO_u8_PORTB:
							   switch (copy_u8PinValue) //check on direction
							   {
								 case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTB_REG,copy_u8PinID);  break; //set pin to High mode
								 case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTB_REG,copy_u8PinID);  break; //set pin to Low mode
							   }//end of switch
							   break;
		   case DIO_u8_PORTC:
							   switch (copy_u8PinValue) //check on direction
							   {
								 case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTC_REG,copy_u8PinID);  break; //set pin to High mode
								 case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTC_REG,copy_u8PinID);  break; //set pin to Low mode
							   }//end of switch
							   break;
		   case DIO_u8_PORTD:
							   switch (copy_u8PinValue) //check on direction
							   {
								 case DIO_u8_HIGH: SET_BIT(DIO_u8_PORTD_REG,copy_u8PinID);  break; //set pin to High mode
								 case DIO_u8_LOW : CLR_BIT(DIO_u8_PORTD_REG,copy_u8PinID);  break; //set pin to Low mode
							   }//end of switch
							   break;
		}//end of switch
	}//end of else
}//end of function

/******************************************************************************/
/* Function: MDIO_u8GetPinValue		                        				  */
/* I/P Parameters: Port ID,  Pin ID							          		  */
/* Returns:it returns u8 value of pin                          				  */
/* Desc:This Function Gets the Value of a given pin					       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinId: From DIO_u8_PIN0 to DIO_u8_PIN7							  */
/******************************************************************************/
u8 MDIO_u8GetPinValue (u8 copy_u8PortID, u8 copy_u8PinID)
{
	u8 local_u8PinValue=2;
	/*Inputs Validation*/
		if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA) ||
			(copy_u8PinID > DIO_u8_PIN7)   || (copy_u8PinID < DIO_u8_PIN0)	)
		{

		}
		else
		{
			switch (copy_u8PortID)
			{
				case DIO_u8_PORTA:  local_u8PinValue = GET_BIT(DIO_u8_PINA_REG,copy_u8PinID); break;
				case DIO_u8_PORTB:  local_u8PinValue = GET_BIT(DIO_u8_PINB_REG,copy_u8PinID); break;
				case DIO_u8_PORTC:  local_u8PinValue = GET_BIT(DIO_u8_PINC_REG,copy_u8PinID); break;
				case DIO_u8_PORTD:  local_u8PinValue = GET_BIT(DIO_u8_PIND_REG,copy_u8PinID); break;
			}

		}
		return local_u8PinValue;
}

/******************************************************************************/
/* Function: MDIO_voidSetPortDirection                        				  */
/* I/P Parameters: Port ID,   Port Direction				          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the direction of a given port			       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PoryDirection: Set the Direction in hex format 					  */
/******************************************************************************/
void MDIO_voidSetPortDirection (u8 copy_u8PortID, u8 copy_u8PortDirection)
{
	/*Inputs Validation*/
		if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA))
		{

		}
		else
		{
			switch (copy_u8PortID)
			{
				case DIO_u8_PORTA: DIO_u8_DDRA_REG = copy_u8PortDirection ; break;
				case DIO_u8_PORTB: DIO_u8_DDRB_REG = copy_u8PortDirection  ; break;
				case DIO_u8_PORTC: DIO_u8_DDRC_REG = copy_u8PortDirection  ; break;
				case DIO_u8_PORTD: DIO_u8_DDRD_REG = copy_u8PortDirection  ; break;
			}

		}
}


/******************************************************************************/
/* Function: MDIO_voidSetPortValue	                        				  */
/* I/P Parameters: Port ID,   Port Value					          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the Value of a given port				       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PortValue: Set the Direction in hex format 					  	  */
/******************************************************************************/
void MDIO_voidSetPortValue (u8 copy_u8PortID, u8 copy_u8PortValue)
{
	/*Inputs Validation*/
		if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA))
		{

		}
		else
		{
			switch (copy_u8PortID)
			{
				case DIO_u8_PORTA: DIO_u8_PORTA_REG = copy_u8PortValue ; break;
				case DIO_u8_PORTB: DIO_u8_PORTB_REG = copy_u8PortValue  ; break;
				case DIO_u8_PORTC: DIO_u8_PORTC_REG = copy_u8PortValue  ; break;
				case DIO_u8_PORTD: DIO_u8_PORTD_REG = copy_u8PortValue  ; break;
			}

		}
}



