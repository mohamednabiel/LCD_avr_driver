
/* * LCD_prog.c
 *
 *  Created on: 7/9/2018
 *      Author: nabil
 */




/*
 * !comment :
 * Description :this function takes the data from the user and is set it to port A
 *
 * Input  : 1) the character i want to print ..
 * Output: Function Error State.[0] for No Error, [1] if Error Existed.
 */
#include "std_types.h"

#include "utils.h"

#include "AVR_GPIO_REG.h"

#include "LCD_int.h"
#include "DIO_int.h"
#include "avr/delay.h"

u8 Lcdu8WriteData(u8 u8DataCpy)
{

	//set the pin direction of port A as ouput pin
	 DIO_u8SetPinDir(DIO_u8PinPortA , DIO_u8PIN0  , DIO_u8OUTPUT);

	//set the pin value output as 5 volts for RS PIN
	 DIO_u8SetPinVlaue(DIO_u8PinPortA , DIO_u8PIN0 , DIO_u8PinVoltageH);

	//set the pin direction of port A as ouput pin
	 DIO_u8SetPinDir(DIO_u8PinPortA , DIO_u8PIN1  , DIO_u8OUTPUT);

	//Reset the pin value output as 5 volts FOR R/W
	 DIO_u8SetPinVlaue(DIO_u8PinPortA , DIO_u8PIN1 , DIO_u8PinVoltageL);

	 //set PORTD as Output
	 DIO_u8SetPortDir( DIO_u8PORTD , DIO_u8PortDirOUT);
	 PORTD = u8DataCpy;

	 //set the pin direction of port A as ouput pin for enaple
	 DIO_u8SetPinDir(DIO_u8PinPortA , DIO_u8PIN2  , DIO_u8OUTPUT);

	 //set the pin value output as 5 volts for RS PIN for enable
	 DIO_u8SetPinVlaue(DIO_u8PinPortA , DIO_u8PIN2 , DIO_u8PinVoltageH);

	 _delay_ms(2);


	 //Reset the pin direction of port A as ouput pin for enaple
	 DIO_u8SetPinDir(DIO_u8PinPortA , DIO_u8PIN2  , DIO_u8OUTPUT);

	 //Reset the pin value output as 5 volts for RS PIN for enable
	 DIO_u8SetPinVlaue(DIO_u8PinPortA , DIO_u8PIN2 , DIO_u8PinVoltageL);
}
void Lcdu8WriteCmd(u8 u8CmdCpy)
{
	//set the pin direction of port A as ouput pin
	 DIO_u8SetPinDir(DIO_u8PinPortA , DIO_u8PIN0  , DIO_u8OUTPUT);

	 //set the pin value output as 0 volts for RS PIN
	 DIO_u8SetPinVlaue(DIO_u8PinPortA , DIO_u8PIN0 , DIO_u8PinVoltageL);

	 //set the pin direction of port A as ouput pin
	 DIO_u8SetPinDir(DIO_u8PinPortA , DIO_u8PIN1  , DIO_u8OUTPUT);

	 //Reset the pin value output as 5 volts FOR R/W
	 DIO_u8SetPinVlaue(DIO_u8PinPortA , DIO_u8PIN1 , DIO_u8PinVoltageL);

	 //set PORTD as Output
		 DIO_u8SetPortDir( DIO_u8PORTD , DIO_u8PortDirOUT);
		 PORTD = u8CmdCpy;

		 //set the pin direction of port A as ouput pin for enaple
		 DIO_u8SetPinDir(DIO_u8PinPortA , DIO_u8PIN2  , DIO_u8OUTPUT);

		 //set the pin value output as 5 volts for RS PIN for enable
		 DIO_u8SetPinVlaue(DIO_u8PinPortA , DIO_u8PIN2 , DIO_u8PinVoltageH);

		 _delay_ms(2);


		 //Reset the pin direction of port A as ouput pin for enaple
		 DIO_u8SetPinDir(DIO_u8PinPortA , DIO_u8PIN2  , DIO_u8OUTPUT);

		 //Reset the pin value output as 5 volts for RS PIN for enable
		 DIO_u8SetPinVlaue(DIO_u8PinPortA , DIO_u8PIN2 , DIO_u8PinVoltageL);

}

void LcdInitialization()
{

			_delay_ms(50);

			/* Function Set  */
			Lcdu8WriteCmd(0b00111000);
			_delay_ms(2);

			/* Display ON OFF Control */
			Lcdu8WriteCmd(0b00001110);
			_delay_ms(2);

			 /* Clear Display */
			Lcdu8WriteCmd(0b00000001);
			_delay_ms(2);
}




