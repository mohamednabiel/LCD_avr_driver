/*
 * LCD_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */


/*
 * LCD_int.h
 *
 *  Created on: sep 7, 2018
 *      Author: Nabil .
 */
#include "std_types.h"

#ifndef LCD_INT_H_
#define LCD_INT_H_



/*
 * !comment :
 * Description :this function takes the data from the user
 * Input  : 1) the character i want to print ..
 * Output: Function Error State.[0] for No Error, [1] if Error Existed.
 */
u8 Lcdu8WriteData(u8 u8DataCpy);


/*
 * !comment :
 * Description :this function takes the data from the user and set the cmd
 * Input  : 1) the binary , hexa , or decimal number related to the specific setting of cmd ..
 * Output : Output: Function Error State.[0] for No Error, [1] if Error Existed.
 */
void Lcdu8WriteCmd(u8 u8CmdCpy);


/*
 * !comment :
 * Description :this function takes the data from the user and set the cmd
 * Input  : 1) no Input , it sets the lcd like data sheet..
 * Output : Output: Function Error State.[0] for No Error, [1] if Error Existed.
 */
void LcdInitialization();

#endif /* LCD_INT_H_ */
