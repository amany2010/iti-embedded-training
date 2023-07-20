/*
 * LCD_Configuraion.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Abdelrahman Hossam
 */

#ifndef INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_
#define INCLUDE_HAL_LCD_LCD_CONFIGURATION_H_

/* options: DIO_u8_PORTA, DIO_u8_PORTB, DIO_u8_PORTC, DIO_u8_PORTD */
#define LCD_DATA_PORT        DIO_u8_PORTA
#define LCD_CONTROL_PORT     DIO_u8_PORTB

/* options: DIO_u8_PIN0 to DIO_u8_PIN7*/
#define LCD_RS_PIN           DIO_u8_PIN2
#define LCD_RW_PIN           DIO_u8_PIN1
#define LCD_E_PIN            DIO_u8_PIN0


#endif /* INCLUDE_HAL_LCD_LCD_CONFIGURAION_H_ */
