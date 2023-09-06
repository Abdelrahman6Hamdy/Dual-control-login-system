/*
 * KPD_Prog.h
 *
 *  Created on: Aug 26, 2023
 *      Author: Abdelrahman
 */

#ifndef HAL_KPD_KPD_INIT_H_
#define HAL_KPD_KPD_INIT_H_

#include "../../MCAL/DIO/DIO_Init.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>


void HKPD_VoidInit();
u8 	 HKPD_u8GetPressedKey();




#endif /* HAL_KPD_KPD_INIT_H_ */
