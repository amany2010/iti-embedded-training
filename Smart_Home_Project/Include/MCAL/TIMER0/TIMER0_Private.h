/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : TIMER DRIVER                     */
/*   DATE        : 22 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_


/* Registers Addresses define */
#define TIMERS_u8_TIMSK_REG      *((volatile u8 *)0x59)
#define TIMERS_u8_TIFR_REG       *((volatile u8 *)0x58)
#define TIMERS_u8_TCCR0_REG      *((volatile u8 *)0x53)
#define TIMERS_u8_TCNT0_REG      *((volatile u8 *)0x52)
#define TIMERS_u8_OCR0_REG       *((volatile u8 *)0x5C)


#define TIMER_u8_NORMAL_MODE     0
#define TIMER_u8_CTC_MODE        1
#define TIMER_u8_FAST_PWM_MODE   3


#define TIMERS_u8_TCCR0_WGM01    6
#define TIMERS_u8_TCCR0_WGM00    3

#define TIMERS_u8_TIMSK0_TOIE0   0
#define TIMERS_u8_TIMSK0_OCIE0   1

#define  ENABLE 				 1
#define  DISABLE 				 0


#define TIMERS_u8_TCCR1A_REG       *((volatile u8 *)0x4F)
#define TIMERS_u8_TCCR1B_REG       *((volatile u8 *)0x4E)

#define TIMERS_u8_TCNT1H_REG       *((volatile u8 *)0x4D)
#define TIMERS_u8_TCNT1L_REG       *((volatile u8 *)0x4C)
#define TIMERS_u16_TCNT1_REG       *((volatile u16 *)0x4C)

#define TIMERS_u8_OCR1AH_REG       *((volatile u8 *)0x4B)
#define TIMERS_u8_OCR1AL_REG       *((volatile u8 *)0x4A)
#define TIMERS_u16_OCR1A_REG       *((volatile u16 *)0x4A)

#define TIMERS_u8_ICR1H_REG        *((volatile u8 *)0x47)
#define TIMERS_u8_ICR1L_REG        *((volatile u8 *)0x46)
#define TIMERS_u16_ICR1_REG        *((volatile u16 *)0x46)

#define TIMERS_u8_TCCR0_PRESCALE_MASK 0b11111000
#endif /* INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_ */
