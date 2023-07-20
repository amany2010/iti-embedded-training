/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : EXTI DRIVER                      */
/*   DATE        : 18 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_
#define INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_

#define EXTI_u8_MCUCR    *((volatile u8 *)0x55)
#define EXTI_u8_MCUCSR   *((volatile u8 *)0x54)
#define EXTI_u8_GICR     *((volatile u8 *)0x5B)
#define EXTI_u8_GIFR     *((volatile u8 *)0x5A)


#define  EXTI_u8_EXTI0     0
#define  EXTI_u8_EXTI1     1
#define  EXTI_u8_EXTI2     2


#define EXTI_u8_ENABLE      1
#define EXTI_u8_DISABLE     0

#define EXTI_u8_EXTI0_ENABLE_BIT  6
#define EXTI_u8_EXTI1_ENABLE_BIT  7
#define EXTI_u8_EXTI2_ENABLE_BIT  5



#define EXTI_u8_LOW_LEVEL_MODE      0
#define EXTI_u8_IOC_MODE   	    	1
#define EXTI_u8_FALLING_EDGE_MODE   2
#define EXTI_u8_RISING_EDGE_MODE    3


#define EXTI_u8_MCUCR_BIT0          0
#define EXTI_u8_MCUCR_BIT1          1
#define EXTI_u8_MCUCR_BIT2          2
#define EXTI_u8_MCUCR_BIT3          3

#define EXTI_u8_MCUCSR_BIT6         6
#endif /* INCLUDE_MCAL_EXTI_EXTI_PRIVATE_H_ */
