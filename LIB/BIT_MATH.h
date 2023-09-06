/*
 * BIT_MATH.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Abdelrahman
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(Reg,BitNum) 		(Reg |= (1<<BitNum))
#define CLR_BIT(Reg,BitNum)			(Reg &= ~(1<<BitNum))
#define Toggle_Bit(Reg,BitNum)		(Reg ^= (1<<BitNum))
#define GET_BIT(Reg,BitNum)		    ( (Reg>>BitNum) & 0x01)
#define SET_BYTE(Reg,Value)			(Reg =  value)


#endif /* LIB_BIT_MATH_H_ */
