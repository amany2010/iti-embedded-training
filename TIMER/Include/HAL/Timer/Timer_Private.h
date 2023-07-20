/*
 * Timer_Private.h
 *
 *  Created on: Aug 29, 2021
 *      Author: bahgat
 */

#ifndef INCLUDE_HAL_TIMER_TIMER_PRIVATE_H_
#define INCLUDE_HAL_TIMER_TIMER_PRIVATE_H_

/* Timer0 Registered	*/
#define TCCR0   (* (volatile u8 *) (0x53))
#define TCNT0   (* (volatile u8 *) (0x52))
#define OCR0    (* (volatile u8 *) (0x5C))
#define TIMSK   (* (volatile u8 *) (0x59))
#define TIFR    (* (volatile u8 *) (0x58))

/*WGM01:0: Timer Generation Mode*/
#define TIMER_u8_NORMAL						0
#define TIMER_u8_CTC						1

/*Waveform Generation Mode*/
#define TIMER_u8_TCCR0_WGM01				3
#define TIMER_u8_TCCR0_WGM00				6

#define TIMERS_u8_TIMSK_TOIE0	  			 0
#define TIMERS_u8_TIMSK_OCIE0			   	 1

/*Compare Match Output Mode*/
#define TIMER_u8_OC0_Disconnect				0
#define TIMER_u8_OC0_Toggle					1
#define TIMER_u8_OC0_Clear					2
#define TIMER_u8_OC0_Set					3

/*Clock Selection							*/
#define TIMER_u8_CS02_NoClock				0
#define TIMER_u8_CS02_Noprescaling			1
#define TIMER_u8_CS02_8						2
#define TIMER_u8_CS02_64					3
#define TIMER_u8_CS02_256					4
#define TIMER_u8_CS02_1024					5

/* Timer Status		*/
#define	Enable								1
#define Disable								0

#define TIMERS_u8_TCCR0_PRESCALE_MASK 0b11111000

#endif /* INCLUDE_HAL_TIMER_TIMER_PRIVATE_H_ */
