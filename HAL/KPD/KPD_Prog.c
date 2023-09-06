/*
 * KPD_Progg.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Abdelrahman
 */


#include "KPD_Init.h"
#include "KPD_Config.h"

#if (RowNum == 4 && ColNum == 4 )

static u8 G_u8_Matrix[4][4]=
{
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'c','0','=','+'}
};

#elif (RowNum == 4 && ColNum == 3 )

static u8 G_u8_Matrix[4][3]=
	{
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'},
		{'*','0','#'}
	};


#else
#error "Choose the right configuration"
#endif

void HKPD_VoidInit()
{
#if (RowNum == 4 && ColNum == 4 )

	MDIO_voidSetPortDirection(KPD_PORT, 0x0f);
	MDIO_voidSetPortValue(KPD_PORT,0xff);

#elif (RowNum == 4 && ColNum == 3 )
	MDIO_voidSetPortDirection(KPD_PORT, 0b00000111);
	MDIO_voidSetPortValue(KPD_PORT,0xff);
#endif
	_delay_ms(10);
}


u8 HKPD_u8GetPressedKey()
{
	HKPD_VoidInit();
u8 L_u8_PressedKey, L_u8_Stop=1;


while(L_u8_Stop)
{
	for(u8 Col = 0 ; Col < ColNum ; Col++ )
	{

		MDIO_voidSetPinValue ( KPD_PORT ,Col, LOW );

		for(u8 Row = 0 ; Row < RowNum ; Row++ )
		{
			if(MDIO_u8GetPinValue(KPD_PORT, Row+ColNum ) == LOW)
			{
				L_u8_PressedKey=G_u8_Matrix[Row][Col];
				while(MDIO_u8GetPinValue(KPD_PORT, Row+ColNum ) == LOW ){}
				_delay_ms(10);
				L_u8_Stop=0;
				break;
			}

		}
		MDIO_voidSetPinValue ( KPD_PORT ,Col, HIGH);
	}
}
return L_u8_PressedKey ;
}
