/*
 * ADC_Private.h
 *
 *  Created on: Aug 19, 2021
 *      Author: Abdelrahman Hossam
 */

#ifndef INCLUDE_MCAL_ADC_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_ADC_PRIVATE_H_

#define ADC_u8_ADMUX_REG          *((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REG         *((volatile u8 *)0x26)
#define ADC_u8_ADCH_REG           *((volatile u8 *)0x25)
#define ADC_u8_ADCL_REG           *((volatile u8 *)0x24)

#define ADC_u16_ADC_REG           *((volatile u16 *)0x24)

#define ADC_u8_SFIOR_REG          *((volatile u8 *)0x50)




#endif /* INCLUDE_MCAL_ADC_ADC_PRIVATE_H_ */
