/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : GPI DRIVER                       */
/*   DATE        : 18 AGU 2021                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../Include/MCAL/GBI/GPI_Interface.h"
#include "../Include/MCAL/GBI/GPI_Private.h"
#include "../Include/MCAL/GBI/GPI_Configuration.h"


void GPI_voidInit   (void)
{
	#if GPI_u8_MODE == GPI_u8_ENABLE
		SET_BIT(SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
    #else
		CLR_BIT(SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
    #endif
}

void GPI_voidEnable (void)
{
	SET_BIT(SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
}

void GPI_voidDisable(void)
{
	CLR_BIT(SREG,GPI_u8_INTERRUPT_ENABLE_BIT);
}
