/*
 * UART_Private.h
 *
 *  Created on: Aug 25, 2021
 *      Author: Abdelrahman Hossam
 */

#ifndef INCLUDE_MCAL_UART_UART_PRIVATE_H_
#define INCLUDE_MCAL_UART_UART_PRIVATE_H_

/*address of UART Control and status register A*/
#define UCSRnA *((volatile u8*)0x2B)

/*address of UART Control and status register B*/
#define UCSRnB *((volatile u8*)0x2A)

/*address of UART Control and status register C*/
#define UCSRnC *((volatile u8*)0x40)

/*address of USART I/O register*/
#define UDR *((volatile u8*)0x2C)

#define UBRRL *((volatile u8*)0x29)
#define UBRRH *((volatile u8*)0x40)

/* The equation to calculate the UBBR value */
#define MyUBRR (FOCS/16/BaudRate-1)
#endif /* INCLUDE_MCAL_UART_UART_PRIVATE_H_ */
