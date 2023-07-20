/*
 * ADC_Program.c
 *
 *  Created on: Aug 19, 2021
 *      Author: Abdelrahman Hossam
 */


/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../Include/MCAL/ADC/ADC_Interface.h"
#include "../Include/MCAL/ADC/ADC_Private.h"

void ADC_voidInit(void)
{
	/*	1- Select Vref = AVCC
		2- Right Adjust
		3- Disable AutoTrigger
		4- Select CLK/64
		5- Enable ADC
	 */
	CLR_BIT(ADC_u8_ADMUX_REG,7);
	SET_BIT(ADC_u8_ADMUX_REG,6);

	CLR_BIT(ADC_u8_ADMUX_REG,5);

	CLR_BIT(ADC_u8_ADCSRA_REG,5);

	SET_BIT(ADC_u8_ADCSRA_REG,2);
	SET_BIT(ADC_u8_ADCSRA_REG,1);
	CLR_BIT(ADC_u8_ADCSRA_REG,0);

	SET_BIT(ADC_u8_ADCSRA_REG,7);
}

u16   ADC_u8GetDigitalValue(u8 Copy_u8ChannelNb)
{
	u16 local_u16DigitalValue=0;
	if((Copy_u8ChannelNb < 32))
	{
		/* Clear MUX4..0 */
		ADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNb;
		/* Start Conversion */
		SET_BIT(ADC_u8_ADCSRA_REG,6);
		/* Wait flag = 1 */
		while((GET_BIT(ADC_u8_ADCSRA_REG,4)== 0))
		{

		}
		//while(!GET_BIT(ADC_u8_ADCSRA_REG,4));
		if(GET_BIT(ADC_u8_ADCSRA_REG,4)!= 0)//(Local_u32TimeOutCounter<ADC_u32_TIME_OUT_MAX_VALUE)
		{
			/* Clear flag */
			SET_BIT(ADC_u8_ADCSRA_REG,4);
			/* Read the Digital Value */
			local_u16DigitalValue = ADC_u16_ADC_REG;
		}
		else
		{

		}
	}
	else
	{

	}
return local_u16DigitalValue;
}
