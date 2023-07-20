/*
 * LCD_Private.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Abdelrahman Hossam
 */

#ifndef INCLUDE_HAL_LCD_LCD_PRIVATE_H_
#define INCLUDE_HAL_LCD_LCD_PRIVATE_H_

void Private_voidSendInstruction (u8 copy_u8Instruction);

#define LCD_u8_FUNCTION_SET      0b00111100
#define LCD_u8_DISPLAY_CONTROL   0b00001100
#define LCD_u8_CLEAR_DISPLAY     0b00000001
#define LCD_u8_ENTRY_SET         0b00000010

#define LCD_u8_ROW1_ADDRESS      127
#define LCD_u8_ROW2_ADDRESS      191


#endif /* INCLUDE_HAL_LCD_LCD_PRIVATE_H_ */
