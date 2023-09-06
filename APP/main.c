/*
 * transmitter
 *
 *  Created on: Sep 5, 2023
 *  Author: Abdelrahman Hamdy
 */

#include "Func_main.h"

u8 CheckID();

u16 GetNumber();

u8 CheckPassword( u8 A_Bool );

int main(){


	HLCD_VoidInit();
	MUART_VoidInit();
	HKPD_VoidInit();

while(1){

	u8 Bool1=9, Bool2=9;
	u8 Received_Key;
	u8 Pressed_Key;

	if ((Pressed_Key = HKPD_u8GetPressedKey())=='*'
	|| Pressed_Key == '#')
	{
		MUART_VoidTransmit('C');
		for(u8 i = 0 ; i < 3 ; i++ )
		{
			Bool1 = CheckID();
			if ( Bool1 == 1 || Bool1 == 2 || Bool1 == 3)
				{	break;	}

		}

	if( Bool1 == 1 || Bool1 == 2 || Bool1 == 3)
	{
		for(u8 i = 0 ; i < 3 ; i++ )
		{
			Bool2=CheckPassword(Bool1);
			if (Bool2 == 1 || Bool2 == 2 || Bool2 == 3)
				{	break;	}

		}
	}


		switch(Bool2)
		{
		case 1:
			HLCD_VoidClear();
			HLCD_VoidSendString("Welcome");
			HLCD_VoidCursor(0,LINE1);
			HLCD_VoidSendString("Abdelrahman");
			MUART_VoidTransmit('M');

			_delay_ms(1000);

			HLCD_VoidClear();
			HLCD_VoidSendString("Please wait for");
			HLCD_VoidCursor(0,LINE1);
			HLCD_VoidSendString("admin approval");

			while ((Received_Key = MUART_u8Receive()) != 'P'
				 && Received_Key  != 'X');

		HLCD_VoidClear();
		if(Received_Key  == 'P')
			{
				HLCD_VoidSendString("You can pass now");
			}
		else if(Received_Key == 'X')
			{
				HLCD_VoidSendString("You can't pass");
			}
		_delay_ms(1000);
		HLCD_VoidClear();

		break;

		case 2:
			HLCD_VoidClear();
			HLCD_VoidSendString("Welcome");
			HLCD_VoidCursor(0,LINE1);
			HLCD_VoidSendString("Amr");
			MUART_VoidTransmit('B');

			_delay_ms(1000);

			HLCD_VoidClear();
			HLCD_VoidSendString("Please wait for");
			HLCD_VoidCursor(0,LINE1);
			HLCD_VoidSendString("admin approval");

			while ((Received_Key = MUART_u8Receive()) != 'P'
				&& Received_Key  != 'X');

		HLCD_VoidClear();
		if(Received_Key  == 'P')
			{
				HLCD_VoidSendString("You can pass now");
			}
		else if(Received_Key == 'X')
			{
				HLCD_VoidSendString("You can't pass");
			}
		_delay_ms(1000);
		HLCD_VoidClear();


		break;

		case 3:
				HLCD_VoidClear();
				HLCD_VoidSendString("Welcome");
				HLCD_VoidCursor(0,LINE1);
				HLCD_VoidSendString("Wael");
				MUART_VoidTransmit('W');

				_delay_ms(1000);

				HLCD_VoidClear();
				HLCD_VoidSendString("Please wait for");
				HLCD_VoidCursor(0,LINE1);
				HLCD_VoidSendString("admin approval");

				while ((Received_Key = MUART_u8Receive()) != 'P'
					 && Received_Key != 'X');

			HLCD_VoidClear();
			if(Received_Key  == 'P')
				{
					HLCD_VoidSendString("You can pass now");
				}
			else if(Received_Key == 'X')
				{
					HLCD_VoidSendString("You can't pass");
				}
			_delay_ms(1000);
			HLCD_VoidClear();

			break;


		default:

			HLCD_VoidClear();
			HLCD_VoidCursor(0,LINE0);
			HLCD_VoidSendString("Access denied");
			HLCD_VoidCursor(0,LINE1);
			HLCD_VoidSendString("Wait for admin");
			MUART_VoidTransmit('D');
			while ((Received_Key = MUART_u8Receive()) != 'A'
				 && Received_Key != 'X');

			if( Received_Key == 'A' )
			{
			HLCD_VoidClear();
			HLCD_VoidSendString("Access allowed");
			_delay_ms(1000);
			HLCD_VoidClear();

			HLCD_VoidSendString("Re-enter your");
			HLCD_VoidCursor(0,LINE1);
			HLCD_VoidSendString("ID and Password");

			_delay_ms(1000);
			HLCD_VoidClear();
			}
			else if( Received_Key == 'X' )
			{
			HLCD_VoidClear();
				HLCD_VoidSendString("You can't pass");

			_delay_ms(1500);
			HLCD_VoidClear();
			}
		}
	}
}
return 0;
}



u16 GetNumber()
{
	u16 L_Number=0;
	u8 L_PressedKey=0;

	L_PressedKey=HKPD_u8GetPressedKey();
	while(L_PressedKey == '*' || L_PressedKey == '#' )
	{
		L_PressedKey=HKPD_u8GetPressedKey();
	}
	HLCD_VoidSendData(L_PressedKey);
	L_Number = (L_PressedKey-'0')*1000;


	L_PressedKey=HKPD_u8GetPressedKey();
	while(L_PressedKey == '*' || L_PressedKey == '#' )
	{
		L_PressedKey=HKPD_u8GetPressedKey();
	}
	HLCD_VoidSendData(L_PressedKey);
	L_Number += ((L_PressedKey-'0')*100);

	L_PressedKey=HKPD_u8GetPressedKey();
	while(L_PressedKey == '*' || L_PressedKey == '#' )
	{
		L_PressedKey=HKPD_u8GetPressedKey();
	}
	HLCD_VoidSendData(L_PressedKey);
	L_Number += ((L_PressedKey-'0')*10);


	L_PressedKey=HKPD_u8GetPressedKey();
	while(L_PressedKey == '*' || L_PressedKey == '#' )
	{
		L_PressedKey=HKPD_u8GetPressedKey();
	}
	HLCD_VoidSendData(L_PressedKey);
	L_Number += (L_PressedKey-'0');
	_delay_ms(500);
	return L_Number;
}

u8 CheckID()
{
	u16 L_ID, id1=1234, id2=5678, id3=7891;

	HLCD_VoidClear();
	HLCD_VoidSendString("Please enter ID:");
	HLCD_VoidCursor(0,LINE1);
	L_ID=GetNumber();

	if		( L_ID==id1 )	{	return 1;	}
	else if	( L_ID==id2 )	{	return 2;	}
	else if ( L_ID==id3 )	{	return 3;	}
	else
	{
		_delay_ms(500);
		HLCD_VoidClear();
		HLCD_VoidSendString("Wrong ID");
		_delay_ms(1500);

		return 11;
	}

}
u8 CheckPassword( u8 A_Bool )
{
	u16 pass1=4321 /* Ahmed  */	,
		pass2=8765 /*  Nour  */	,
		pass3=1987 /* Khaled */ ;

	u16 L_Pass;

	HLCD_VoidClear();
	HLCD_VoidSendString("Enter Password:");
	HLCD_VoidCursor(0,LINE1);
	L_Pass=GetNumber();

	if		(A_Bool == 1 && L_Pass==pass1 )	{	return 1;	}
	else if	(A_Bool == 2 && L_Pass==pass2 )	{	return 2;	}
	else if (A_Bool == 3 && L_Pass==pass3 )	{	return 3;	}
	else
	{
		HLCD_VoidClear();
		HLCD_VoidSendString("Wrong password");

		_delay_ms(1000);

		return 11;
	}


}
