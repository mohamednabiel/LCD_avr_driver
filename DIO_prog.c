/*
 * DIO_prog.c
 *
 *  Created on: Aug 11, 2018
 *      Author: moham
 */

/*
 * DIO_prog.c
 *
 *  Created on: Aug 14, 2018
 *      Author: Nabil .
 */

#include "std_types.h"

#include "utils.h"

#include "AVR_GPIO_REG.h"

#include "DIO_int.h"




/*
!Comment:
Description: this Function Sets the DIO Pin Direction
Input: 1)u8PortNbCpy->the Port Index. [0:3]
	   2)u8PinNbCpy-> the Pin number. [0:7]
	   3)u8PinDirCpy-> the required Pin Direction,[0]for Input,
												  [1]for output4
Output: Function Error State.[0] for No Error, [1] if Error Existed
 */
u8 DIO_u8SetPinDir(u8 u8PortNbCpy, u8 u8PinNbCpy, u8 u8PinDirCpy)
{
	/*Local Varibales*/

	/*Error State*/
	u8 u8ErrLoc = DIO_u8OK;

	/*check that port number is in range*/
	if(u8PortNbCpy >= DIO_u8PORTNB)
	{
		/*Set the error State of the function*/
		u8ErrLoc = DIO_u8NOK;
	}
	/*check that pin number is in range*/
	else if(u8PinNbCpy >= DIO_u8PINNB)
	{
		/*Set the error State of the function*/
		u8ErrLoc = DIO_u8NOK;
	}
	/*check that pin Direction is in range*/
	else if ((u8PinDirCpy!=DIO_u8INPUT) &&(u8PinDirCpy!=DIO_u8OUTPUT) )
	{
		/*Set the error State of the function*/
		u8ErrLoc = DIO_u8NOK;
	}
	/*All inputs are in range*/
	else
	{
		u8ErrLoc = DIO_u8OK;

		switch(u8PortNbCpy)
		{
		case DIO_u8PORTA:
			if(u8PinDirCpy == DIO_u8OUTPUT)
			{
				Set_Bit(DDRA,u8PinNbCpy);
			}
			else
			{
				Rst_Bit(DDRA,u8PinNbCpy);
			}
			break;
		case DIO_u8PORTB:
			if(u8PinDirCpy == DIO_u8OUTPUT)
			{
				Set_Bit(DDRB,u8PinNbCpy);
			}
			else
			{
				Rst_Bit(DDRB,u8PinNbCpy);
			}
			break;
		case DIO_u8PORTC:
			if(u8PinDirCpy == DIO_u8OUTPUT)
			{
				Set_Bit(DDRC,u8PinNbCpy);
			}
			else
			{
				Rst_Bit(DDRC,u8PinNbCpy);
			}
			break;
		case DIO_u8PORTD:
			if(u8PinDirCpy == DIO_u8OUTPUT)
			{
				Set_Bit(DDRD,u8PinNbCpy);
			}
			else
			{
				Rst_Bit(DDRD,u8PinNbCpy);
			}
			break;

		default :
		{

		}
		}

	}
	/*Function Return*/
	return u8ErrLoc;
}


/*
!Comment:
Description: this Function Sets the Pin Value
Input: 1)u8PortNbCpy->the Port Index. [0:3]
	   2)u8PinNbCpy-> the Pin number. [0:7]

Output: Function Error State.[0] for No Error, [1] if Error Existed
*/

u8 DIO_u8SetPinVlaue(u8 u8PortNbCpy, u8 u8PinNbCpy , u8 u8pinVoltage)
{
		/*Local Varibales*/

		/*Error State*/
		u8 u8ErrLoc = DIO_u8OK;

		/*check that port number is in range*/
		if(u8PortNbCpy >= DIO_u8PORTNB)
			{
			/*Set the error State of the function*/
			u8ErrLoc = DIO_u8NOK;
			}
			/*check that pin number is in range*/
		else if(u8PinNbCpy >= DIO_u8PINNB)
			{
			/*Set the error State of the function*/
			u8ErrLoc = DIO_u8NOK;
			}
			/*check for the voltage */
		else if((u8pinVoltage != DIO_u8PinVoltageH)&&(u8pinVoltage != DIO_u8PinVoltageL ))
		{
			/*Set the error State of the function*/
			u8ErrLoc = DIO_u8NOK;
		}
			/*All inputs are in range*/
		else
		{
			u8ErrLoc = DIO_u8OK;

			switch(u8PortNbCpy)
			{
			case DIO_u8PORTA:
					if(u8pinVoltage == DIO_u8PinVoltageH )
					{
						Set_Bit(PORTA ,u8PinNbCpy);
					}
					else
					{
						Rst_Bit(PORTA,u8PinNbCpy);
					}
				break;
			case DIO_u8PORTB:
				if(u8pinVoltage == DIO_u8PinVoltageH )
				{
					Set_Bit(PORTB ,u8PinNbCpy);
				}
				else
				{
					Rst_Bit(PORTB,u8PinNbCpy);
				}

				break;
			case DIO_u8PORTC:
				if(u8pinVoltage == DIO_u8PinVoltageH )
				{
					Set_Bit(PORTC ,u8PinNbCpy);
				}
				else
				{
					Rst_Bit(PORTC,u8PinNbCpy);
				}
				break;
			case DIO_u8PORTD:
				if(u8pinVoltage == DIO_u8PinVoltageH )
				{
					Set_Bit(PORTD ,u8PinNbCpy);
				}
				else
				{
					Rst_Bit(PORTD,u8PinNbCpy);
				}
					break;
			default :
			{

			}
			}

		}
		/*Function Return*/
		return u8ErrLoc;
}

/*
!Comment:
Description: this Function Gets the PIN  Value
Input: 1)u8PortNbCpy->the Port Index. [0:3]
	   2)u8PinNbCpy-> the Pin number. [0:7]
	   3)u8 *Pu8PinValueCpy-> the output .[0]for 0 Volt.
	   	   	   	   	   	   	   	   	   	  [1]for 1 Volt.
Output: Function Error State.[0] for No Error, [1] if Error Existed
*/
u8 DIO_u8GetPinVlaue(u8 u8PortNbCpy,u8 u8PinPortNbCpy,  u8 u8PinNbCpy, u8 *Pu8PinValueCpy)
{
	/*Local Varibales*/

	/*Error State*/
	u8 u8ErrLoc = DIO_u8OK;

	/*check that port number is in range*/
	if(u8PortNbCpy >= DIO_u8PORTNB)
		{
		/*Set the error State of the function*/
		u8ErrLoc = DIO_u8NOK;
		}
		/*check that pin number is in range*/
	else if(u8PinNbCpy >= DIO_u8PINNB)
		{
		/*Set the error State of the function*/
		u8ErrLoc = DIO_u8NOK;
		}
		/*check that pin Port number is in range*/
	else if(u8PinPortNbCpy >= DIO_u8PinPortNB)
		{
		/*Set the error State of the function*/
		u8ErrLoc = DIO_u8NOK;
		}
		/*All inputs are in range*/
	else
	{
		u8ErrLoc = DIO_u8OK;

		switch(u8PortNbCpy)
		{
		case DIO_u8PORTA:
			(*Pu8PinValueCpy)=Get_Bit(PINA,u8PinPortNbCpy);
			break;
		case DIO_u8PORTB:
			(*Pu8PinValueCpy)=Get_Bit(PINB,u8PinPortNbCpy);
			break;
		case DIO_u8PORTC:
			(*Pu8PinValueCpy)=Get_Bit(PINC,u8PinPortNbCpy);
			break;
		case DIO_u8PORTD:
			(*Pu8PinValueCpy)=Get_Bit(PIND,u8PinPortNbCpy);
				break;
		default :
		{

		}
		}

	}
	/*Function Return*/
	return u8ErrLoc;

}

/*
!Comment:
Description: this Function Sets The Port Direction
Input: 1)u8PortNbCpy->the Port Index.  [0:3]
	   2)u8PinDirCpy-> the required Pin Direction,[0]for Input,
												  [1]for output

Output: Function Error State.[0] for No Error, [1] if Error Existed
*/
u8 DIO_u8SetPortDir(u8 u8PortNbCpy,u8 u8PortDirCpy)
{
	/*Local Varibales*/

	/*Error State*/
	u8 u8ErrLoc = DIO_u8OK;

	/*check that port number is in range*/
	if(u8PortNbCpy >= DIO_u8PORTNB)
	{
		/*Set the error State of the function*/
		u8ErrLoc = DIO_u8NOK;
	}
	/*check that pin Direction is in range*/
	else if ((u8PortDirCpy!=DIO_u8INPUT) &&(u8PortDirCpy!=DIO_u8OUTPUT)  )
	{
		/*Set the error State of the function*/
		u8ErrLoc = DIO_u8NOK;
	}
	else
	{
		u8ErrLoc = DIO_u8OK;

		switch(u8PortNbCpy)
		{
		case DIO_u8PORTA:
			if(u8PortDirCpy == DIO_u8OUTPUT)
						{
							DDRA = DIO_u8PortDirOUT ;
						}
			else
						{
							DDRA = DIO_u8PortDirIN;
						}
						break;
		case DIO_u8PORTB:
			 if(u8PortDirCpy == DIO_u8OUTPUT)
						{
							DDRB = DIO_u8PortDirOUT ;
						}
			 else
						{
							DDRB = DIO_u8PortDirIN;
						}
			 	 	 	 break;
		case DIO_u8PORTC:
			if(u8PortDirCpy == DIO_u8OUTPUT)
						{
							DDRC = DIO_u8PortDirOUT ;
						}
			else
						{
							DDRC = DIO_u8PortDirIN;
						}
						break;
		case DIO_u8PORTD:
			if(u8PortDirCpy == DIO_u8OUTPUT)
						{
							DDRD = DIO_u8PortDirOUT ;
						}
			else
						{
							DDRD = DIO_u8PortDirIN;
						}
						break;
		default :
		{

		}
			}
	}
	/*Function Return*/
	return u8ErrLoc;

}


/*
!Comment:
Description: this Function Sets The Port Value
Input: 1)u8PortNbCpy->the Port Index.  [0:3]
	   2)u8PottValCpy-> the required Port Value   ,[0]for 0 Volt,
												  [1]for 1 Volt

Output: Function Error State.[0] for No Error, [1] if Error Existed
*/
u8 DIO_u8SetPortVal(u8 u8PortNbCpy,u8 u8PortVoltCpy)
{
		/*Local Varibales*/

		/*Error State*/
		u8 u8ErrLoc = DIO_u8OK;

		/*check that port number is in range*/
		if(u8PortNbCpy >= DIO_u8PORTNB)
		{
			/*Set the error State of the function*/
			u8ErrLoc = DIO_u8NOK;
		}
			/*check that port value  is in range*/
		else if ((u8PortVoltCpy!=DI0_u8PortVolt0) &&(u8PortVoltCpy!=DI0_u8PortVolt5)  )
			{
				/*Set the error State of the function*/
				u8ErrLoc = DIO_u8NOK;
			}
		else
			{
				switch(u8PortNbCpy)
						{
						case DIO_u8PORTA:
							if(u8PortVoltCpy == DI0_u8PortVolt0)
										{
											PORTA = DIO_u8PortVolt0 ;
										}
							else
										{
											PORTA = DIO_u8PortVolt5;
										}
										break;
						case DIO_u8PORTB:
							if(u8PortVoltCpy == DI0_u8PortVolt0)
										{
											PORTB = DIO_u8PortVolt0 ;
										}
							else
										{
											PORTB = DIO_u8PortVolt5;
										}
							 	 	 	 break;
						case DIO_u8PORTC:
							if(u8PortVoltCpy == DI0_u8PortVolt0)
										{
											PORTC = DIO_u8PortVolt0 ;
										}
							else
										{
											PORTC = DIO_u8PortVolt5;
										}
										break;
						case DIO_u8PORTD:
							if(u8PortVoltCpy == DI0_u8PortVolt0)
										{
											PORTD = DIO_u8PortVolt0 ;
										}
							else
										{
											PORTD = DIO_u8PortVolt5;
										}
										break;
						default :
						{

						}
							}

					}
		/*Function Return*/
		return u8ErrLoc;
}

/*
!Comment:
Description: this Function Gets The Port Value
Input: 1)u8PortNbCpy->the Port Index.  [0:3]
	   2)u8 *Pu8PortValCpy-> the output The Value Of the Port.
Output: Function Error State.[0] for No Error, [1] if Error Existed
*/
u8 DIO_u8GetPortVal(u8 u8PortNbCpy,u8* Pu8PortValCpy)
{
	/*Local Varibales*/

			/*Error State*/
			u8 u8ErrLoc = DIO_u8OK;

			/*check that port number is in range*/
			if(u8PortNbCpy >= DIO_u8PORTNB)
			{
				/*Set the error State of the function*/
				u8ErrLoc = DIO_u8NOK;
			}
			else
			{
				u8ErrLoc = DIO_u8OK;

			switch(u8PortNbCpy)
			{
			case DIO_u8PORTA:
					if(DDRA == DIO_u8PortDirIN)
					{
							(*Pu8PortValCpy)=PINA;
					}
				break;
			case DIO_u8PORTB:
				if(DDRB == DIO_u8PortDirIN)
				{
						(*Pu8PortValCpy)=PINB;
				}
				break;
			case DIO_u8PORTC:
				if(DDRC == DIO_u8PortDirIN)
				{
						(*Pu8PortValCpy)=PINC;
				}
				break;
			case DIO_u8PORTD:
				if(DDRD == DIO_u8PortDirIN)
				{
						(*Pu8PortValCpy)=PIND;
				}
					break;
			default :
			{

			}

			}
			}

			/*Function Return*/
			return u8ErrLoc;
			}

