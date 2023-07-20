/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : TIMER DRIVER                     */
/*   DATE        : 22 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_Private.h"
#include "../Include/MCAL/TIMER0/TIMER0_Configuration.h"

static void (*TIMERS_pfTimer0OVF)(void) = NULL;
static void (*TIMERS_pfTimer0CTC)(void) = NULL;

void MTIMERS_voidTimer0Init(void)
{
  #if  (TIMER_u8_MODE  ==  TIMER_u8_NORMAL_MODE)
	// Enable Normal Mode
	CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_TCCR0_WGM00);
	CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_TCCR0_WGM01);
    #if (TIMER_u8_OVF_INTERRUPT  ==  ENABLE)
		//Enable Timer 0 OVF Interrupt
	    SET_BIT(TIMERS_u8_TIMSK_REG,TIMERS_u8_TIMSK0_TOIE0);
    #else
	    //Disable Timer 0 OVF Interrupt
	    CLR_BIT(TIMERS_u8_TIMSK_REG,TIMERS_u8_TIMSK0_TOIE0);
    #endif
	    // Set preload value
	    TIMERS_u8_TCNT0_REG = TIMERS_u8_PRELOAD_VALUE;
  #elif (TIMER_u8_MODE  ==  TIMER_u8_CTC_MODE)
	// Enable CTC Mode
	CLR_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_TCCR0_WGM00);
	SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_TCCR0_WGM01);
	#if (TIMER_u8_CTC_INTERRUPT  ==  ENABLE)
		//Enable Timer 0 CTC Interrupt
		SET_BIT(TIMERS_u8_TIMSK_REG,TIMERS_u8_TIMSK0_OCIE0);
	#else
		//Disable Timer 0 CTC Interrupt
		CLR_BIT(TIMERS_u8_TIMSK_REG,TIMERS_u8_TIMSK0_OCIE0);
	#endif
		TIMERS_u8_OCR0_REG = TIMERS_u8_OCR0_VALUE;
   #elif (TIMER_u8_MODE == TIMER_u8_FAST_PWM_MODE)
		// Configure Fast PWM Mode
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_TCCR0_WGM00);
		SET_BIT(TIMERS_u8_TCCR0_REG,TIMERS_u8_TCCR0_WGM01);
		//  Set OC0 on compare match, clear OC0 at TOP (Inverting Mode)
		SET_BIT(TIMERS_u8_TCCR0_REG,4);
		SET_BIT(TIMERS_u8_TCCR0_REG,5);
		// Set value at OCR0
		TIMERS_u8_OCR0_REG = TIMERS_u8_OCR0_VALUE;
		#endif
	// Clear for 3 bits
	TIMERS_u8_TCCR0_REG &= TIMERS_u8_TCCR0_PRESCALE_MASK;
	// SET Prescaler Value
	TIMERS_u8_TCCR0_REG |= TIMERS_u8_PRESCALER_VALUE;
}

void MTIMERS_voidTimer0OVFSetCallBack (void (*copy_pf)(void))
{
	if (copy_pf != NULL)
	{
		TIMERS_pfTimer0OVF = copy_pf;
	}
}

void MTIMERS_voidTimer0CTCSetCallBack (void (*copy_pf)(void))
{
	if (copy_pf != NULL)
	{
		TIMERS_pfTimer0CTC = copy_pf;
	}
}


void MTIMERS_voidTimer1Init(u32 angle)
{
	/*Select Timer 1 mode ==> 14*/
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1B_REG,4);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	/* Select HW Action on OC1A pin => Non Inverting */
	SET_BIT(TIMERS_u8_TCCR1A_REG,7);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,6);

	/* Set top value in ICR1 */
	TIMERS_u16_ICR1_REG=19999;

	/* set angle of servo motor */
	u32 value=0;
	value=((((1999-999)*angle)/180)+999);
	TIMERS_u16_OCR1A_REG=value;

	/*Set prescaler*/
	CLR_BIT(TIMERS_u8_TCCR1B_REG,2);
	SET_BIT(TIMERS_u8_TCCR1B_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,0);

}

void setServo(u8  angle)
{
	u32 value = 0;
	value = (((1999-999)* (angle)/(180)) ) + 999;
	TIMERS_u16_OCR1A_REG = value;
}

#define WDT_u8_WDTCR_REG      *((volatile u8 *)0x41)
void WDT_voidEnable (void)
{
	//Enable WDT = 2.1 sec
	WDT_u8_WDTCR_REG = 0b00001111;
}
void WDT_voidDisable (void)
{
	WDT_u8_WDTCR_REG |= ((1<<4)|(1<<3));

	WDT_u8_WDTCR_REG=0x00;
}

void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	static u16 local_u16CounterOVF=0;
	local_u16CounterOVF++;
	if (local_u16CounterOVF==3907)
	{
		//update Preload Value
		TIMERS_u8_TCNT0_REG = TIMERS_u8_PRELOAD_VALUE;
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
	if (local_u16CounterCTC==5)
	{
		//Clear Counter value
		local_u16CounterCTC=0;
		if (TIMERS_pfTimer0CTC != NULL)
		{
			TIMERS_pfTimer0CTC();
		}
	}
}
