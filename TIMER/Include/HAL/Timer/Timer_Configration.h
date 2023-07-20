/*
 * Timer_Configration.h
 *
 *  Created on: Aug 29, 2021
 *      Author: bahgat
 */

#ifndef INCLUDE_HAL_TIMER_TIMER_CONFIGRATION_H_
#define INCLUDE_HAL_TIMER_TIMER_CONFIGRATION_H_


/*WGM01:0: Timer Generation Mode*/
/* Options						*/
/* Timer_u8_Normal				*/
/*Timer_u8_CTC					*/
#define Timer_u8_Mode			TIMER_u8_NORMAL

/* Timer Interrupt options	*/
/* Enable	, Disable		*/
#define TIMER_u8_OVF_INTERRUPT    Enable
#define TIMER_u8_CTC_INTERRUPT    Enable

/*Clock Selection							*/
/*options									*/
/*NoClock -->	0							*/
/*Noprescaling -->	1						*/
/*8	 -->	2								*/
/*64 -->	3								*/
/*256 -->	4								*/
/*1024 -->	5								*/
#define	Timer_u8_CS02_prescaller			2

#define Timer_Preload_value					192
#endif /* INCLUDE_HAL_TIMER_TIMER_CONFIGRATION_H_ */
