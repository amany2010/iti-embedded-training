#ifndef INCLUDE_MCAL_TIMER0_TIMER0_CONFIGURATION_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_CONFIGURATION_H_


/*
 * Options:
 * TIMER_u8_NORMAL_MODE
 * TIMER_u8_CTC_MODE
 * TIMER_u8_FAST_PWM_MODE
 * */
#define TIMER_u8_MODE    TIMER_u8_FAST_PWM_MODE

/*
 * Options:
 * ENABLE
 * DISABLE
 * */
#define TIMER_u8_OVF_INTERRUPT    ENABLE
#define TIMER_u8_CTC_INTERRUPT    ENABLE

#define TIMERS_u8_PRELOAD_VALUE   192
#define TIMERS_u8_OCR0_VALUE      99

/*
 * options
 * TIMER Stop   =>  No CLK                =>  0
 * CLK Source   =>  FCPU                  =>  1
 * CLK Source   =>  FCPU/8                =>  2
 * CLK Source   =>  FCPU/64               =>  3
 * CLK Source   =>  FCPU/256              =>  4
 * CLK Source   =>  FCPU/1024             =>  5
 * CLK Source   =>  External Falling Edge =>  6
 * CLK Source   =>  External Rising Edge  =>  7
 * */
#define TIMERS_u8_PRESCALER_VALUE      2


#endif /* INCLUDE_MCAL_TIMER0_TIMER0_CONFIGURATION_H_ */
