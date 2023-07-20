/*
 * LCD_Interface.h
 *
 *  Created on: Aug 15, 2021
 *      Author: DELL
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

/*LCD Init*/
void HLCD_voidInit();

/*LCD Send Data*/
void HLCD_voidSendData(u8 copy_u8Char);
void HLCD_voidSendString (char *copy_ptrString);
void HLCD_voidGoToPos (u8 copy_u8RowNum, u8 copy_u8ColumnNum);
void HLCD_voidDisplayClear (void);
#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
