/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : EXTI DRIVER                      */
/*   DATE        : 18 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_
#define INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_


void MEXTI_voidEXTIEnable(u8 copy_u8EXTI_Num, u8 copy_u8EXTI_Sense);
void MEXTI_voidEXTIDisable(u8 copy_u8EXTI_Num);
void MEXTI_voidSetCallBack (void(*copy_PtrToFunction)(void), u8 copy_u8Index);


#endif /* INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_ */
