/*
 * ADC_Interface.h
 *
 *  Created on: Aug 19, 2021
 *      Author: Abdelrahman Hossam
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_

/*************************************************/
/* Macros ForADC Chanles						 */
/*************************************************/
#define ADC_u8_CHANNEL_0                  0
#define ADC_u8_CHANNEL_1                  1
#define ADC_u8_CHANNEL_2                  2
#define ADC_u8_CHANNEL_3                  3
#define ADC_u8_CHANNEL_4                  4
#define ADC_u8_CHANNEL_5                  5
#define ADC_u8_CHANNEL_6                  6
#define ADC_u8_CHANNEL_7                  7


/*************************************************/
/* Macros for ADC VOltage SElction Referance	 */
/*************************************************/
#define ADC_u8_REFS_AREF			0b00000000
#define ADC_u8_REFS_AVCC			0b01000000
#define ADC_u8_REFS_Reserved		0b10000000
#define ADC_u8_REFS_2.56VC			0b11000000

/*************************************************/
/* Macros for ADC Control and Status Register	 */
/*************************************************/
#define ADC_u8_ADCSRA_ADPS0				0
#define ADC_u8_ADCSRA_ADPS1				1
#define ADC_u8_ADCSRA_ADPS2				2
#define ADC_u8_ADCSRA_ADIE				3
#define ADC_u8_ADCSRA_ADIF				4
#define ADC_u8_ADCSRA_ADATE				5
#define ADC_u8_ADCSRA_ADSC				6
#define ADC_u8_ADCSRA_ADEN				7

void ADC_voidInit(void);
u16   ADC_u8GetDigitalValue(u8 Copy_u8ChannelNb);

#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
