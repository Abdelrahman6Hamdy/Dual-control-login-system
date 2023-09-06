/*
 * UART_Prog.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Abdelrahman
 */

#include "UART_Init.h"
#include "UART_Priv.h"
#include "UART_Config.h"
#include "../../HAL/LCD/LCD_Int.h"

u8 G_u8_RecievedString[35];

void MUART_VoidInit()
{
	UCSRB = 0b00011000;
	UCSRC = 0b10000110;
	MUART_VoidSetBaudRate(51);
}


void MUART_VoidTransmit( u8 A_u8_Data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = A_u8_Data;
}


u8 	 MUART_u8Receive()
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}


void MUART_VoidSetBaudRate( u32 A_u32_Baud )
{
	UBRRL = A_u32_Baud;
}

void MUART_VoidSendString	( u8* A_u8_StringPtr )
{


	while(  *A_u8_StringPtr != '\0')
	{
		MUART_VoidTransmit(*A_u8_StringPtr);
		A_u8_StringPtr++;
	}
}

//void MUART_VoidSendString2	( u8* A_u8_StringPtr )
//{
//	u8 L_u8_Counter    = 0;
//
//	while( (A_u8_StringPtr[L_u8_Counter]) != '\0')
//	{
//		MUART_VoidTransmit(A_u8_StringPtr[L_u8_Counter++]);
//	}
//}

//void MUART_VoidReceiveString( u8 *A_u8_StringPtr ,u32 A_u32_Size )
//{
//	u32 i =0;
//	while ( !( UCSRA & (1<<UDRE)) || i<A_u32_Size )
//	{
//		A_u8_StringPtr[i] = MUART_u8Receive();
//
//		MDIO_voidSetPinValue(PORTC,i,LOW);
//		_delay_ms(10);
//
//
//		if(A_u8_StringPtr[i] == '\n' || A_u8_StringPtr[i] == '\r')
//		{	A_u8_StringPtr[i] = '\0';	break;		}
//		i++;
//	}
//
//	A_u8_StringPtr[A_u32_Size-1] = '\0';
//}

void MUART_VoidReceiveString( u8* A_u8_StringPtr ,u8 A_u8_Size )
{

	for(u8 i = 0; i < A_u8_Size ; i++ )
	{
		A_u8_StringPtr[i] = MUART_u8Receive();

		if(A_u8_StringPtr[i] == '\n' || A_u8_StringPtr[i] == '\r')
		{	A_u8_StringPtr[i] = '\0';	break;		}
	}

	A_u8_StringPtr[A_u8_Size] = '\0';
}
void MUART_VoidReceiveString2( u8 *A_u8_StringPtr, u32 A_size )
{
	    u8 i = 0;
	    u8 receivedChar;

	    // Receive characters until buffer is full or newline character is received
	    do {
	        receivedChar = MUART_u8Receive();
	        A_u8_StringPtr[i] = receivedChar;
	        i++;
	    } while (receivedChar != '\0' && i < A_size - 1);

	    // Add null termination to the string
	    A_u8_StringPtr[i] = '\0';

}

void MUART_VoidReceiveString3( u8* A_u8_StringPtr )
{
	u8 L_u8_Counter    = 0;

	while ( !( UCSRA & (1<<UDRE)) )
	{
		A_u8_StringPtr[L_u8_Counter++] = MUART_u8Receive();
		MDIO_voidSetPinValue(PORTC,L_u8_Counter,HIGH);
	}
	A_u8_StringPtr[L_u8_Counter] = MUART_u8Receive();

}


void MUART_VoidSendNumber	( u32 A_u32_Number )
{
	u32 L_u32_Temp;
	u8 L_u8_Temp;
	for(u8 counter1 = 0 ; counter1 <= 3 ; counter1++)
	{
		L_u32_Temp=A_u32_Number;

		L_u32_Temp = (L_u32_Temp >> ( (3-counter1) * 8 ));

		L_u8_Temp = (u8)L_u32_Temp;
		MUART_VoidTransmit( L_u8_Temp );
	}
}

u32 MUART_u32ReceiveNumber()
{
	u32 L_u32_ReceivedData=0;
	u8  L_u8_Temp1;
	u32 L_u32_Temp2;

	for(u8 counter = 0 ; counter <=3 ; counter++)
	{
		L_u8_Temp1 =  MUART_u8Receive();

		L_u32_Temp2 = L_u8_Temp1;


		L_u32_Temp2 = L_u32_Temp2 << ((3-counter)*8);


		L_u32_ReceivedData += L_u32_Temp2;

	}
return L_u32_ReceivedData;
}


