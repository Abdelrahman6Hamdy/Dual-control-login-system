/*
 * DIO_Prog.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Abdelrahman
 */

#ifndef MCAL_DIO_DIO_PROG_C_
#define MCAL_DIO_DIO_PROG_C_

#include "DIO_Init.h"



void MDIO_voidSetPortDirection(u8 A_u8_PortNum, u8 A_u8_PortDirection)
{
	if(A_u8_PortNum <= PORTD  &&  A_u8_PortDirection <= 0xff)
	{
		switch (A_u8_PortNum)
		{
		case PORTA : DIO_DDRA_REG = A_u8_PortDirection; break;
		case PORTB : DIO_DDRB_REG = A_u8_PortDirection; break;
		case PORTC : DIO_DDRC_REG = A_u8_PortDirection; break;
		case PORTD : DIO_DDRD_REG = A_u8_PortDirection; break;
		}
	}
}

void MDIO_voidSetPortValue(u8 A_u8_PortNum, u8 A_u8_PortValue)
{
	if(A_u8_PortNum <= PORTD  &&  A_u8_PortValue <= 0xff)
	{
		switch (A_u8_PortNum)
		{
		case PORTA : DIO_PORTA_REG = A_u8_PortValue; break;
		case PORTB : DIO_PORTB_REG = A_u8_PortValue; break;
		case PORTC : DIO_PORTC_REG = A_u8_PortValue; break;
		case PORTD : DIO_PORTD_REG = A_u8_PortValue; break;
		}
	}
}
void MDIO_voidSetPinDirection(u8 A_u8_PortNum, u8 A_u8_PinNum, u8 A_u8_PinDirection)
{
	if( A_u8_PortNum <= PORTA && A_u8_PinNum<= PIN7 && A_u8_PinDirection <= OUTPUT)
	{
		switch (A_u8_PortNum)
		{
			case PORTA:

				switch (A_u8_PinDirection)
				{
					case INPUT  : CLR_BIT(DIO_DDRA_REG,A_u8_PinNum);break;
					case OUTPUT : SET_BIT(DIO_DDRA_REG,A_u8_PinNum);break;
				}
			break;


			case PORTB:

				switch (A_u8_PinDirection)
				{
					case INPUT  : CLR_BIT(DIO_DDRB_REG,A_u8_PinNum);break;
					case OUTPUT : SET_BIT(DIO_DDRB_REG,A_u8_PinNum);break;
				}
			break;


			case PORTC:

				switch (A_u8_PinDirection)
				{
					case INPUT  : CLR_BIT(DIO_DDRC_REG,A_u8_PinNum);break;
					case OUTPUT : SET_BIT(DIO_DDRC_REG,A_u8_PinNum);break;
				}
			break;


			case PORTD:

				switch (A_u8_PinDirection)
				{
					case INPUT  : CLR_BIT(DIO_DDRD_REG,A_u8_PinNum);break;
					case OUTPUT : SET_BIT(DIO_DDRD_REG,A_u8_PinNum);break;
				}
			break;

		}
	}
}

void MDIO_voidSetPinValue(u8 A_u8_PortNum, u8 A_u8_PinNum, u8 A_u8_PinValue)
{
	if(A_u8_PortNum <= PORTD && A_u8_PinNum <= PIN7 && A_u8_PinValue <= HIGH)
	{
		switch(A_u8_PortNum)
		{
			case PORTA:

				switch (A_u8_PinValue)
					{
						case LOW  : CLR_BIT(DIO_PORTA_REG,A_u8_PinNum);break;
						case HIGH : SET_BIT(DIO_PORTA_REG,A_u8_PinNum);break;
					}
			break;


			case PORTB:

				switch (A_u8_PinValue)
					{
						case LOW  : CLR_BIT(DIO_PORTB_REG,A_u8_PinNum);break;
						case HIGH : SET_BIT(DIO_PORTB_REG,A_u8_PinNum);break;
					}
			break;


			case PORTC:

				switch (A_u8_PinValue)
					{
						case LOW  : CLR_BIT(DIO_PORTC_REG,A_u8_PinNum);break;
						case HIGH : SET_BIT(DIO_PORTC_REG,A_u8_PinNum);break;
					}
			break;


			case PORTD:

				switch (A_u8_PinValue)
					{
						case LOW  : CLR_BIT(DIO_PORTD_REG,A_u8_PinNum);break;
						case HIGH : SET_BIT(DIO_PORTD_REG,A_u8_PinNum);break;
					}
			break;
		}
	}
}

u8 MDIO_u8GetPinValue(u8 A_u8_PortNum, u8 A_u8_PinNum)
{
	u8 L_u8_Pinvalue=6;

	if( A_u8_PortNum <= PORTD && A_u8_PinNum <= PIN7)
	{

		switch(A_u8_PortNum)
		{
			case PORTA : L_u8_Pinvalue = GET_BIT(DIO_PINA_REG,A_u8_PinNum); break;
			case PORTB : L_u8_Pinvalue = GET_BIT(DIO_PINB_REG,A_u8_PinNum); break;
			case PORTC : L_u8_Pinvalue = GET_BIT(DIO_PINC_REG,A_u8_PinNum); break;
			case PORTD : L_u8_Pinvalue = GET_BIT(DIO_PIND_REG,A_u8_PinNum); break;
		}

	}
	return  L_u8_Pinvalue;
}



#endif /* MCAL_DIO_DIO_PROG_C_ */
