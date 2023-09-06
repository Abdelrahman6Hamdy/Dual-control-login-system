/*
 * UART_Priv.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Abdelrahman
 */

#ifndef MCAL_UART_UART_PRIV_H_
#define MCAL_UART_UART_PRIV_H_

#define UDR  	*((volatile u8 *) 0x2C )
#define UCSRA 	*((volatile u8 *) 0x2B )
#define UCSRB	*((volatile u8 *) 0x2A )
#define UCSRC  	*((volatile u8 *) 0x40 )
#define UBRRH  	*((volatile u8 *) 0x40 )
#define UBRRL  	*((volatile u8 *) 0x29 )


#define UDRE 5
#define RXC 7




#endif /* MCAL_UART_UART_PRIV_H_ */
