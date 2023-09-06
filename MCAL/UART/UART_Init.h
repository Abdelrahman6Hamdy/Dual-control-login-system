/*
 * UART_Init.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Abdelrahman
 */

#ifndef MCAL_UART_UART_INIT_H_
#define MCAL_UART_UART_INIT_H_


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void MUART_VoidInit();
void MUART_VoidTransmit( u8 A_u8_Data );
u8 	 MUART_u8Receive();
void MUART_VoidSetBaudRate( u32 A_u32_Baud );

void MUART_VoidSendString	( u8* A_u8_StringPtr );
void MUART_VoidReceiveString( u8 *A_u8_StringPtr ,u8 A_u8_Size );
void MUART_VoidSendNumber	( u32 A_u32_Number 	 );

u32 MUART_u32ReceiveNumber();

void MUART_VoidReceiveString2( u8 *A_u8_StringPtr, u32 A_size );
void MUART_VoidReceiveString3( u8* A_u8_StringPtr );

//void MUART_VoidSendString2	( u8* A_u8_StringPtr );


#endif /* MCAL_UART_UART_INIT_H_ */
