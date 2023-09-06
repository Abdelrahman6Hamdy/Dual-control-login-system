/*
 * DIO_Init.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Abdelrahman
 */

#ifndef MCAL_DIO_DIO_INIT_H_
#define MCAL_DIO_DIO_INIT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#define PORTA	0
#define PORTB	1
#define PORTC	2
#define PORTD	3

#define INPUT  	0
#define OUTPUT 	1

#define LOW  	0
#define HIGH 	1

#define DIO_PORTA_REG 	 *((volatile u8 *) 0x3B)
#define DIO_DDRA_REG 	 *((volatile u8 *) 0x3A)
#define DIO_PINA_REG 	 *((volatile u8 *) 0x39)

#define DIO_PORTB_REG 	 *((volatile u8 *) 0x38)
#define DIO_DDRB_REG 	 *((volatile u8 *) 0x37)
#define DIO_PINB_REG 	 *((volatile u8 *) 0x36)

#define DIO_PORTC_REG 	 *((volatile u8 *) 0x35)
#define DIO_DDRC_REG 	 *((volatile u8 *) 0x34)
#define DIO_PINC_REG 	 *((volatile u8 *) 0x33)

#define DIO_PORTD_REG 	 *((volatile u8 *) 0x32)
#define DIO_DDRD_REG 	 *((volatile u8 *) 0x31)
#define DIO_PIND_REG 	 *((volatile u8 *) 0x30)

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7




void MDIO_voidSetPortDirection(u8 A_u8_PortNum, u8 A_u8_PortDirection);

void MDIO_voidSetPortValue(u8 A_u8_PortNum, u8 A_u8_PortValue);

void MDIO_voidSetPinDirection(u8 A_u8_PortNum, u8 A_u8_PinNum, u8 A_u8_PinDirection);

void MDIO_voidSetPinValue(u8 A_u8_PortNum, u8 A_u8_PinNum, u8 A_u8_PinValue);

u8 MDIO_u8GetPinValue(u8 A_u8_PortNum, u8 A_u8_PinNum);




#endif /* MCAL_DIO_DIO_INIT_H_ */

