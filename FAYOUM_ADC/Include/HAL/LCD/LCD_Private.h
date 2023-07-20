/*
 * LCD_Private.h
 *
 *  Created on: Aug 15, 2021
 *      Author: DELL
 */

#ifndef INCLUDE_HAL_LCD_LCD_PRIVATE_H_
#define INCLUDE_HAL_LCD_LCD_PRIVATE_H_

/*LCD Send Instruction*/
void Private_voidSendInstruction(u8 copy_u8Instruction);


#define LCD_u8_POSITION         0b10000000
#define LCD_u8_ROW1Address      127
#define LCD_u8_ROW2Address      191
#define LCD_u8_CLR_DISPLAY 	    0b00000001
#define LCD_u8_FUNCTION_SET     0b00111100
#define LCD_u8_DISPLAY_CONTROL  0b00001100
#define LCD_u8_ENTRY_MODE 		0b00000010

#define LCD_u8_Row1       1
#define LCD_u8_Row2       2

#define LCD_u8_Column1    1
#define LCD_u8_Column16   16
#endif /* INCLUDE_HAL_LCD_LCD_PRIVATE_H_ */
