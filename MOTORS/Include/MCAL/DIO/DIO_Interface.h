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

void MDIO_voidInit(void);

void MDIO_voidSetPinDIrection (u8 copy_u8PortID, u8 copy_u8PinID, u8 copy_u8PinDIrection);



#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
