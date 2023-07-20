/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : DIO DRIVER                       */
/*   DATE        : 19 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/
#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

#define DIO_u8_PORTA  0
#define DIO_u8_PORTB  1
#define DIO_u8_PORTC  2
#define DIO_u8_PORTD  3

#define DIO_u8_PIN0   0
#define DIO_u8_PIN1   1
#define DIO_u8_PIN2   2
#define DIO_u8_PIN3   3
#define DIO_u8_PIN4   4
#define DIO_u8_PIN5   5
#define DIO_u8_PIN6   6
#define DIO_u8_PIN7   7

#define DIO_u8_OUTPUT 1
#define DIO_u8_INPUT  0

#define DIO_u8_HIGH   1
#define DIO_u8_LOW    0

/******************************************************************************/
/* Function: MDIO_voidInit			                        				  */
/* I/P Parameters: No thing									          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Set the initial direction & value of All pins       	  */
/******************************************************************************/
void MDIO_voidInit(void);

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
void MDIO_voidSetPinDIrection (u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinDIrection);

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
void MDIO_voidSetPinValue (u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinValue);

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
u8 MDIO_u8GetPinValue (u8 copy_u8PortID, u8 copy_u8PinID);

/******************************************************************************/
/* Function: MDIO_voidSetPortDirection                        				  */
/* I/P Parameters: Port ID,   Port Direction				          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the direction of a given port			       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinDirection: Set the Direction in hex format 					  */
/******************************************************************************/
void MDIO_voidSetPortDirection (u8 copy_u8PortID, u8 copy_u8PortDirection);


/******************************************************************************/
/* Function: MDIO_voidSetPortValue	                        				  */
/* I/P Parameters: Port ID,   Port Value					          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the Value of a given port				       	  */
/******************************************************************************/
/* Options																	  */
/* copy_PortId: DIO_u8_PORTA - DIO_u8_PORTB - DIO_u8_PORTC - DIO_u8_PORTD     */
/* copy_u8PinValue: Set the Direction in hex format 					  	  */
/******************************************************************************/
void MDIO_voidSetPortValue (u8 copy_u8PortID, u8 copy_u8PortValue);



#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
