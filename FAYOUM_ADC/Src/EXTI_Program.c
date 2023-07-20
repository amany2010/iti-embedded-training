/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : EXTI DRIVER                      */
/*   DATE        : 18 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_Private.h"
#include "../Include/MCAL/DIO/DIO_Configuration.h"

#include "../Include/MCAL/EXTI/EXTI_Interface.h"
#include "../Include/MCAL/EXTI/EXTI_Private.h"
#include "../Include/MCAL/EXTI/EXTI_Configuration.h"

// Array of pointers to function
static void (*pf[3]) (void)={NULL,NULL,NULL};


void MEXTI_voidEXTIEnable(u8 copy_u8EXTI_Num, u8 copy_u8EXTI_Sense)
{
	if (copy_u8EXTI_Num < 0 || copy_u8EXTI_Num > 2 || copy_u8EXTI_Sense < 0 || copy_u8EXTI_Sense > 3)
	{

	}
	else if ((copy_u8EXTI_Num == EXTI_u8_EXTI2) && (copy_u8EXTI_Sense < 2))
	{

	}
	else
	{
		switch (copy_u8EXTI_Num)
		{
		  case EXTI_u8_EXTI0:

						      SET_BIT(EXTI_u8_GICR,EXTI_u8_EXTI0_ENABLE_BIT);
						      switch (copy_u8EXTI_Sense)
						      {
						         case EXTI_u8_LOW_LEVEL_MODE:
						        	 	 	 	 	 	 	 CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT0);
															 CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT1);
															 break;
						         case EXTI_u8_IOC_MODE:
						        	 	 	 	 	 	 	 SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT0);
															 CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT1);
															 break;
						         case EXTI_u8_FALLING_EDGE_MODE:
						        	 	 	 	 	 	 	 CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT0);
															 SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT1);
															 break;
						         case EXTI_u8_RISING_EDGE_MODE:
						        	 	 	 	 	 	 	 SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT0);
															 SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT1);
															 break;
						      }
			  	  	  	  	  break;

		  case EXTI_u8_EXTI1:
							  SET_BIT(EXTI_u8_GICR,EXTI_u8_EXTI1_ENABLE_BIT);
						      switch (copy_u8EXTI_Sense)
						      {
						         case EXTI_u8_LOW_LEVEL_MODE:
						        	 	 	 	 	 	 	 CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT2);
															 CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT3);
															 break;
						         case EXTI_u8_IOC_MODE:
						        	 	 	 	 	 	 	 SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT2);
															 CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT3);
															 break;
						         case EXTI_u8_FALLING_EDGE_MODE:
						        	 	 	 	 	 	 	 CLR_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT2);
															 SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT3);
															 break;
						         case EXTI_u8_RISING_EDGE_MODE:
						        	 	 	 	 	 	 	 SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT2);
															 SET_BIT(EXTI_u8_MCUCR,EXTI_u8_MCUCR_BIT3);
															 break;
						      }
							  break;

		  case EXTI_u8_EXTI2:
							  SET_BIT(EXTI_u8_GICR,EXTI_u8_EXTI2_ENABLE_BIT);
						      switch (copy_u8EXTI_Sense)
						      {
						         case EXTI_u8_FALLING_EDGE_MODE:
						        	 	 	 	 	 	 	 CLR_BIT(EXTI_u8_MCUCSR,EXTI_u8_MCUCSR_BIT6);
															 break;
						         case EXTI_u8_RISING_EDGE_MODE:
						        	 	 	 	 	 	 	 SET_BIT(EXTI_u8_MCUCSR,EXTI_u8_MCUCSR_BIT6);
															 break;
						      }
							  break;

		}
	}
}


void MEXTI_voidEXTIDisable(u8 copy_u8EXTI_Num)
{
	switch (copy_u8EXTI_Num)
	{
		case  EXTI_u8_EXTI0: CLR_BIT(EXTI_u8_GICR,EXTI_u8_EXTI0_ENABLE_BIT); break;
		case  EXTI_u8_EXTI1: CLR_BIT(EXTI_u8_GICR,EXTI_u8_EXTI1_ENABLE_BIT); break;
		case  EXTI_u8_EXTI2: CLR_BIT(EXTI_u8_GICR,EXTI_u8_EXTI2_ENABLE_BIT); break;
		default: break;
	}
}


void MEXTI_voidSetCallBack (void(*copy_PtrToFunction)(void), u8 copy_u8Index)
{
	pf[copy_u8Index]= copy_PtrToFunction;
}


void __vector_1(void)    __attribute__((signal));
void __vector_1(void)
{
	if (pf[EXTI_u8_EXTI0] != NULL)
	{
		pf[EXTI_u8_EXTI0]();
	}

}


void __vector_2(void)    __attribute__((signal));
void __vector_2(void)
{
	if (pf[EXTI_u8_EXTI1] != NULL)
		{
			pf[EXTI_u8_EXTI1]();
		}
}


void __vector_3(void)    __attribute__((signal));
void __vector_3(void)
{
	if (pf[EXTI_u8_EXTI2] != NULL)
		{
			pf[EXTI_u8_EXTI2]();
		}
}
