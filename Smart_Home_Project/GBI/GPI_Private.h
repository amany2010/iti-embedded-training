/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : GPI DRIVER                       */
/*   DATE        : 18 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef INCLUDE_MCAL_GBI_GPI_PRIVATE_H_
#define INCLUDE_MCAL_GBI_GPI_PRIVATE_H_

#define SREG  *((volatile u8 *)0x5f)

#define GPI_u8_ENABLE   1
#define GPI_u8_DISABLE  0


#define GPI_u8_INTERRUPT_ENABLE_BIT   7

#endif /* INCLUDE_MCAL_GBI_GPI_PRIVATE_H_ */
