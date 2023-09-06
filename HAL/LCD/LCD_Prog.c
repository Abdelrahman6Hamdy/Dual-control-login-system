/*
 * LCD_Prog.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Abdelrahman
 */

#include "LCD_Int.h"

//u8 G_u8_Cursor_Pos  = 0;
//u8 G_u8_Cursor_Line = 0;


void HLCD_VoidSendCommand(u8 A_u8_cmd)
{
	//Send Command
	MDIO_voidSetPortValue(Data_Port,A_u8_cmd);

	//Clear RW to send Command
	MDIO_voidSetPinValue(Control_Port,RW_PIN,LOW);

	//Clear Rs to send Command
	MDIO_voidSetPinValue(Control_Port,RS_PIN,LOW);

	//Enable On
	MDIO_voidSetPinValue(Control_Port,ENABLE_PIN,HIGH);
	_delay_ms(1);


	//Enable oFF
	MDIO_voidSetPinValue(Control_Port,ENABLE_PIN,LOW);
	_delay_ms(1);

}


void HLCD_VoidSendData(u8 A_u8_Data)
{
	//Send Command
	MDIO_voidSetPortValue(Data_Port,A_u8_Data);

	//Clear RW to send Command
	MDIO_voidSetPinValue(Control_Port,RW_PIN,LOW);

	//Enable On
	MDIO_voidSetPinValue(Control_Port,ENABLE_PIN,HIGH);
	_delay_ms(1);

	//Set Rs to send Command
	MDIO_voidSetPinValue(Control_Port,RS_PIN,HIGH);
	_delay_ms(1);

	//Enable oFF
	MDIO_voidSetPinValue(Control_Port,ENABLE_PIN,LOW);
	_delay_ms(1);

//	G_u8_Cursor_Pos++;

//	if(G_u8_Cursor_Pos<15)
//	{G_u8_Cursor_Pos -= 16;}

}


void HLCD_VoidInit(){

	MDIO_voidSetPortDirection(Data_Port,0XFF);
	MDIO_voidSetPortDirection(Control_Port,0XFF);

	// wait for 30ms
	_delay_ms(30);
	// function Set 0b00111100
	HLCD_VoidSendCommand(LCD_functionSet);
	// wait for 39 us -> 1ms
	_delay_ms(1);
	// Dispaly ON/OFF 0b00001100
	HLCD_VoidSendCommand(LCD_DispalyOnOff);
	// wait for 39 us -> 1ms
	_delay_ms(1);
	// Dispaly clear 0b00000001
	HLCD_VoidSendCommand(LCD_Dispalyclear);
	//wait for 1.53ms -> 2ms
	_delay_ms(2);
	// Entry Mode 0b00000110
	HLCD_VoidSendCommand(LCD_EntryMode);
	//_delay_ms(1);
}



void HLCD_VoidClear()
{
	//display clear
	HLCD_VoidSendCommand(1);
	_delay_ms(2);

//	G_u8_Cursor_Pos  = 0;
//	G_u8_Cursor_Line = 0;
}


void HLCD_VoidCursor(u8 A_u8_Pos,u8 A_u8_Line)
{
	switch(A_u8_Line)
	{
	case LINE0 : HLCD_VoidSendCommand( 0X80 + A_u8_Pos); break;

	case LINE1 : HLCD_VoidSendCommand( 0XC0 + A_u8_Pos); break;
	}
//	G_u8_Cursor_Pos  = A_u8_Pos;
//	G_u8_Cursor_Line = A_u8_Line;
}


void HLCD_VoidSendString(char *A_u8_PtrString)
{
	u8 L_u8_Counter    = 0;
	u8 L_u8_Cursor_Pos = 0;


	while( (A_u8_PtrString[L_u8_Counter]) != '\0')
	{
		if(L_u8_Cursor_Pos > 15)
			{
				HLCD_VoidCursor(0,LINE1);
				L_u8_Cursor_Pos  = 0;

//				G_u8_Cursor_Line = 1;
//				G_u8_Cursor_Pos  = 0;
			}

		HLCD_VoidSendData(A_u8_PtrString[L_u8_Counter++]);
		L_u8_Cursor_Pos++;

		//G_u8_Cursor_Pos++;

	}

}
void HLCD_VoidSendNumber(s32 A_s32_Number  )
{
	u32 L_u32_TempNum=1;

	if(A_s32_Number==0)
	{
		HLCD_VoidSendData('0');

		//G_u8_Cursor_Pos++;
		return;
	}
	if(A_s32_Number<0)
	{
		HLCD_VoidSendData('-');
		A_s32_Number *= -1;

		//G_u8_Cursor_Pos++;
	}

	while (A_s32_Number != 0)
	{
		L_u32_TempNum = (L_u32_TempNum * 10) + (A_s32_Number%10);
		A_s32_Number /= 10;
	}

	while(L_u32_TempNum != 1)
	{
//		if(G_u8_Cursor_Pos > 15)
//			{
//				HLCD_VoidCursor(0,LINE1);

//				G_u8_Cursor_Pos  = 0;
//				G_u8_Cursor_Line = 1;

//			}

		HLCD_VoidSendData((L_u32_TempNum % 10)+48);
		L_u32_TempNum /= 10;

		//G_u8_Cursor_Pos++;
	}



}

void HLCD_VoidSaveCustomChar(u8 A_u8_CGRAMIndex, u8 A_u8_CustomArray[])
{
	HLCD_VoidSendCommand( 0b01000000 + ( A_u8_CGRAMIndex * 8 ) );

	for(u8 L_u8_Index = 0; L_u8_Index < 8; L_u8_Index++ )
	{
		HLCD_VoidSendData(A_u8_CustomArray[L_u8_Index]);
	}

/*	switch(G_u8_Cursor_Line)
	{
	case LINE0 : HLCD_VoidSendCommand( 0X80 + G_u8_Cursor_Pos); break;

	case LINE1  : HLCD_VoidSendCommand( 0XC0 + G_u8_Cursor_Pos); break;
	}*/

	HLCD_VoidSendCommand(0x80);
}

void HLCD_VoidDisplayCustomChar(u8 A_u8_CGRAMIndex)
{
	if(A_u8_CGRAMIndex < 8)
	{
		HLCD_VoidSendData(A_u8_CGRAMIndex);
	}
		//G_u8_Cursor_Pos++;
}

