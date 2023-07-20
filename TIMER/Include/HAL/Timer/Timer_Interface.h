/*
 * Timer_Interface.h
 *
 *  Created on: Aug 29, 2021
 *      Author: bahgat
 */

#ifndef INCLUDE_HAL_TIMER_TIMER_INTERFACE_H_
#define INCLUDE_HAL_TIMER_TIMER_INTERFACE_H_


void void_Timer0_Init(void);
void MTIMERS_voidTimer0OVFSetCallBack (void (*copy_pf)(void));
void MTIMERS_voidTimer0CTCSetCallBack (void (*copy_pf)(void));

#endif /* INCLUDE_HAL_TIMER_TIMER_INTERFACE_H_ */
