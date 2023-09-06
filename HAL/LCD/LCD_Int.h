/*
 * LCD_Int.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Abdelrahman
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#define F_CPU 8000000UL

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Init.h"
#include   <util/delay.h>
#include <stdlib.h>

#define Data_Port		PORTA
#define Control_Port 	PORTB

#define RS_PIN 		PIN0
#define RW_PIN 		PIN1
#define ENABLE_PIN 	PIN2

#define LINE0	0
#define LINE1	1

#define	LCD_functionSet	 0b00111100
#define	LCD_DispalyOnOff 0b00001100
#define LCD_Dispalyclear 0b00000001
#define LCD_EntryMode	 0b00000110

void HLCD_VoidInit();
void HLCD_VoidSendCommand(u8 A_u8_cmd);
void HLCD_VoidSendData(u8 A_u8_Data);
void HLCD_VoidClear();
void HLCD_VoidCursor(u8 A_u8_RowNum,u8 A_u8_ColNum);
void HLCD_VoidSendString(char *A_u8_PtrString);
void HLCD_VoidSendNumber(s32 A_s32_Number  );
void HLCD_VoidSaveCustomChar(u8 A_u8_CGRAMIndex, u8 A_u8_CustomArray[]);
void HLCD_VoidDisplayCustomChar(u8 A_u8_CGRAMIndex);

#endif /* HAL_LCD_LCD_INT_H_ */
