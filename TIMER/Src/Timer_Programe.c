#include "../Include/HAL/Timer/TIMER_Interface.h"
#include "../Include/HAL/Timer/TIMER_Private.h"
#include "../Include/HAL/Timer/Timer_Configration.h"
#include"../Include/LIB/STD_TYPES.h"
#include"../Include/LIB/BIT_MATH.h"
#include<stdio.h>
static void(*TIMERS_pfTimer0OVF)(void) =NULL;
static void(*TIMERS_pfTimer0CTC)(void) = NULL;

void void_Timer0_Init(void)
{
	CLR_BIT(TCCR0,TIMER_u8_TCCR0_WGM01);
	CLR_BIT(TCCR0,TIMER_u8_TCCR0_WGM00);
	SET_BIT(TIMSK,TIMERS_u8_TIMSK_TOIE0);
	TCNT0=Timer_Preload_value;
	TCCR0&=TIMERS_u8_TCCR0_PRESCALE_MASK;
	TCCR0|=Timer_u8_CS02_prescaller;

}
void MTIMERS_voidTimer0OVFSetCallBack (void (*copy_pf)(void))
{
	if(copy_pf!=NULL)
	{
		TIMER_u8_OVF_INTERRUPT = copy_pf;
	}
}
MTIMERS_voidTimer0CTCSetCallBack (void (*copy_pf)(void))
{

	if(copy_pf!=NULL)
	{
		TIMER_u8_CTC_INTERRUPT=copy_pf;
	}
}
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	static u16 local_u16CounterOVF=0;
	local_u16CounterOVF++;
	if (local_u16CounterOVF==3907)
	{
		//update Preload Value
		TCNT0 = Timer_Preload_value;
		//Clear Counter value
		local_u16CounterOVF=0;
		if (TIMERS_pfTimer0OVF != NULL)
		{
			TIMERS_pfTimer0OVF();
		}
	}
}



void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{
	static u16 local_u16CounterCTC=0;
	local_u16CounterCTC++;
	if (local_u16CounterCTC==10000)
	{
		//Clear Counter value
		local_u16CounterCTC=0;
		if (TIMERS_pfTimer0CTC != NULL)
		{
			TIMERS_pfTimer0CTC();
		}
	}
}
