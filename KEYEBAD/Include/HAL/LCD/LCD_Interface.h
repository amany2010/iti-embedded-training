/*
 * LCD_Interface.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Abdelrahman Hossam
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

void HLCD_voidInit(void);

void HLCD_voidSendData(u8 copy_u8Char);

void HLCD_voidClearDisplay (void);

void HLCD_voidGoToPos (u8 copy_u8RowNum, u8 copy_u8ColumnNo);

void LCD_voidSendSpecialCharacter (u8 *copy_pu8CharArr, u8 copy_u8PatternNum,
								   u8 copy_u8LineNum,   u8 copy_ColNum);

void HLCD_voidDisplayNumber(u32 copy_u32Number);


#define LCD_u8_LINE1    1
#define LCD_u8_LINE2    2

#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
