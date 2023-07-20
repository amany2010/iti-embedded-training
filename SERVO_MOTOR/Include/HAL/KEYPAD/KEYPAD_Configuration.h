/*
 * KEYPAD_Configuration.h
 *
 *  Created on: Aug 16, 2021
 *      Author: Abdelrahman Hossam
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_

/* Definition For Keypad Port
 * options : DIO_u8_PORTA
 * 			 DIO_u8_PORTB
 * 			 DIO_u8_PORTC
 * 			 DIO_u8_PORTD
 * */
#define KEYPAD_u8_PORT       DIO_u8_PORTC

/* Definition For Keypad Rows Pins*/
#define KEYPAD_u8_R1_PIN     DIO_u8_PIN0
#define KEYPAD_u8_R2_PIN     DIO_u8_PIN1
#define KEYPAD_u8_R3_PIN     DIO_u8_PIN2
#define KEYPAD_u8_R4_PIN     DIO_u8_PIN3

/* Definition For Keypad Columns Pins*/
#define KEYPAD_u8_C1_PIN     DIO_u8_PIN4
#define KEYPAD_u8_C2_PIN     DIO_u8_PIN5
#define KEYPAD_u8_C3_PIN     DIO_u8_PIN6
#define KEYPAD_u8_C4_PIN     DIO_u8_PIN7
/* Definition For Keypad Dimensions*/
#define KEYPAD_u8_ROW_NUM     4
#define KEYPAD_u8_COL_NUM     4

/* Keypad Values */
#define KEYPAD_Au8_KEYS      {{'7','8','9','/'}, \
							  {'4','5','6','*'}, \
							  {'1','2','3','-'}, \
							  {'c','0','=','+'}}

/* Definition for Rows and Columns Array values  */
#define KEYPAD_Au8ROWS     {KEYPAD_u8_R1_PIN,KEYPAD_u8_R2_PIN,KEYPAD_u8_R3_PIN,KEYPAD_u8_R4_PIN}
#define KEYPAD_Au8COLS     {KEYPAD_u8_C1_PIN,KEYPAD_u8_C2_PIN,KEYPAD_u8_C3_PIN,KEYPAD_u8_C4_PIN}

/* Definition for returning non pressed value */
#define KEYPAD_u8_KEY_NOT_PRESSED   0xFF

/* Definition for De-bouncing Effect delay */
#define KEYPAD_u8_DEBOUNCING_MS     20

#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_ */
