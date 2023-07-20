/*
 * ADC_Interface.h
 *
 *  Created on: Aug 19, 2021
 *      Author: Abdelrahman Hossam
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_

#define ADC_u8_CHANNEL_0                  0
#define ADC_u8_CHANNEL_1                  1
#define ADC_u8_CHANNEL_2                  2
#define ADC_u8_CHANNEL_3                  3
#define ADC_u8_CHANNEL_4                  4
#define ADC_u8_CHANNEL_5                  5
#define ADC_u8_CHANNEL_6                  6
#define ADC_u8_CHANNEL_7                  7

void ADC_voidInit(void);
u16   ADC_u8GetDigitalValue(u8 Copy_u8ChannelNb);

#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
