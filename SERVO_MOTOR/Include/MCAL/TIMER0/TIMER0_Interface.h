#ifndef INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_

void MTIMERS_voidTimer0Init(void);
void MTIMERS_voidTimer0OVFSetCallBack (void (*copy_pf)(void));
void MTIMERS_voidTimer0CTCSetCallBack (void (*copy_pf)(void));
void MTIMERS_voidTimer1Init(u32 angle);
#endif /* INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
