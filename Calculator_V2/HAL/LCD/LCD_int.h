/*
 * SSD_int.h
 *
 *  Created on: Feb 9, 2023
 *      Author: esraa
 */

#ifndef SSD_INT_H_
#define SSD_INT_H_

#include "../../MCAL/DIO/errorstate.h"
#include "../../MCAL/DIO/stdTypes.h"


 ES_t LCD_enuinit(void);
 ES_t LCD_enusendcmd(u8 copy_cmd);
 ES_t LCD_enuwritedate(u8 copy_data);
 u8 static setposition(u8 r,u8 c);
 ES_t LCD_enudisplaystring(u8 *copy_string,u8 r,u8 c); //array of char?
 ES_t storechar(u8 index, u8 *pattern);
 ES_t dispaystoredchar(u8 index, u8 r, u8 c);
// void LCD_voidWriteNumber(u16 Copy_u16Number);
 static u16 Private_u16GetPower(u8 Copy_u8Number1, u8 Copy_u8Number2);
 ES_t LCD_voidWriteNumber(u16 Copy_u16Number);
#endif /* SSD_INT_H_ */
