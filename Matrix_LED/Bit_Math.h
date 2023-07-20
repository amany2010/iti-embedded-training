#ifndef _BIT_MATH_H
#define _BIT_MATH_H
#define SET_BIT(regist,bitNumber)		(regist|=(1<<bitNumber))
#define CLR_BIT(regist,bitNumber)		(regist&=~(1<<bitNumber))
#define TOG_BIT(regist,bitNumber)		(regist^=(1<<bitNumber))
#define GET_BIT(regist,bitNumber)		(regist>>(bitNumber)&1)

#endif
