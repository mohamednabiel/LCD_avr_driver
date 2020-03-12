/*
 * DIO_int.h
 *
 *  Created on: Aug 11, 2018
 *      Author: moham
 */


/*
 * DIO_int.h
 *
 *  Created on: Aug 14, 2018
 *      Author: Nabil .
 */

#include "std_types.h"

#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_u8PORTA     0
#define DIO_u8PORTB     (DIO_u8PORTA+1)
#define DIO_u8PORTC     (DIO_u8PORTB+1)
#define DIO_u8PORTD     (DIO_u8PORTC+1)
#define DIO_u8PORTNB    (DIO_u8PORTD+1)

#define DIO_u8PinPortA 	0
#define DIO_u8PinPortB 	(DIO_u8PinPortA+1)
#define DIO_u8PinPortC 	(DIO_u8PinPortB+1)
#define DIO_u8PinPortD 	(DIO_u8PinPortC+1)
#define DIO_u8PinPortNB (DIO_u8PinPortD+1)



#define DIO_u8PIN0   0
#define DIO_u8PIN1   1
#define DIO_u8PIN2   2
#define DIO_u8PIN3   3
#define DIO_u8PIN4   4
#define DIO_u8PIN5   5
#define DIO_u8PIN6   6
#define DIO_u8PIN7   7
#define DIO_u8PINNB  (DIO_u8PIN7 +1)

#define DI0_u8PortVolt0 0
#define DI0_u8PortVolt5 1


#define DIO_u8PortVolt0 0b00000000
#define DIO_u8PortVolt5 0b11111111

#define DIO_u8INPUT  0
#define DIO_u8OUTPUT 1

#define DIO_u8PortDirOUT  0b11111111
#define DIO_u8PortDirIN   0b00000000

#define DIO_u8PinVoltageH 5
#define DIO_u8PinVoltageL 0

#define DIO_u8OK  0
#define DIO_u8NOK 1
/*
!Comment:
Description: this Function Sets the DIO Pin Direction
Input: 1)u8PortNbCpy->the Port Index. [0:3]
	   2)u8PinNbCpy-> the Pin number. [0:7]
	   3)u8PinDirCpy-> the required Pin Direction,[0]for Input,
												  [1]for output
Output: Function Error State.[0] for No Error, [1] if Error Existed
*/
u8 DIO_u8SetPinDir(u8 u8PortNbCpy, u8 u8PinNbCpy, u8 u8PinDirCpy) ;

/*
!Comment:
Description: this Function Sets the DIO Pin Value
Input: 1)u8PortNbCpy ->the Port Index  . [0:3]
	   2)u8PinNbCpy  -> the Pin number . [0:7]
	   3)u8PinVoltage-> the pin voltage. [0,5]

Output: Function Error State.[0] for No Error, [1] if Error Existed
*/
u8 DIO_u8SetPinVlaue(u8 u8PortNbCpy, u8 u8PinNbCpy , u8 u8pinVoltage);

/*
!Comment:
Description: this Function Gets the PIN  Value
Input: 1)u8PortNbCpy->the Port Index.  [0:3]
	   2)u8PinNbCpy-> the Pin number.  [0:7]
	   3)u8PinPortNbCpy the pin Index. [A:D]
	   4)u8 *Pu8PinValueCpy-> the output .[0]for 0 Volt.
	   	   	   	   	   	   	   	   	   	  [1]for 1 Volt.
Output: Function Error State.[0] for No Error, [1] if Error Existed
*/
u8 DIO_u8GetPinVlaue(u8 u8PortNbCpy, u8 u8PinNbCpy,u8 u8PinPortNbCpy, u8 *Pu8PinValueCpy);


/*
!Comment:
Description: this Function Sets The Port Direction
Input: 1)u8PortNbCpy->the Port Index.  [0:3]
	   2)u8PinDirCpy-> the required Pin Direction,[0]for Input,
												  [1]for output

Output: Function Error State.[0] for No Error, [1] if Error Existed
*/
u8 DIO_u8SetPortDir(u8 u8PortNbCpy,u8 u8PortDirCpy);

/*
!Comment:
Description: this Function Sets The Port Value
Input: 1)u8PortNbCpy->the Port Index.  [0:3]
	   2)u8PottValCpy-> the required Port Value   ,[0]for 0 Volt,
												  [1]for 1 Volt

Output: Function Error State.[0] for No Error, [1] if Error Existed
*/
u8 DIO_u8SetPortVal(u8 u8PortNbCpy,u8 u8PortVoltCpy);



/*
!Comment:
Description: this Function Gets The Port Value
Input: 1)u8PortNbCpy->the Port Index.  [0:3]
	   2)u8 *Pu8PortValCpy-> the output The Value Of the Port.
Output: Function Error State.[0] for No Error, [1] if Error Existed
*/
u8 DIO_u8GetPortVal(u8 u8PortNbCpy,u8* Pu8PortValCpy);

#endif /* DIO_INT_H_ */
