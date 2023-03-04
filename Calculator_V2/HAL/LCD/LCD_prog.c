/*
 * LCD_prog.c
 *
 *  Created on: Feb 24, 2023
 *      Author: esraa
 */


//#include <avr/delay.h>
#include"util/delay.h"
#include "../../MCAL/DIO/errorstate.h"
#include "../../MCAL/DIO/stdTypes.h"

#include "../../MCAL/DIO/DIO_Init.h"

//#include "LCD_priv.h"
#include "LCD_config.h"
#include "LCD_int.h"


 u8 static initfinished=0;

 ES_t LCD_enuinit()
 {
	 /***************************************************************************************/
	 /****************************   		8-bits code  	******************************/
	 /***************************************************************************************/
	 	 /* make port b as output */
	 	 DIO_enuSetPortDIR(1, 0xff);

	 	 /* make pins A0, A1, A2 ===> sr, wr, en as output */
	 	 DIO_enuSetPinDIR(0, 0, 1);
	 	 DIO_enuSetPinDIR(0, 1, 1);
	 	 DIO_enuSetPinDIR(0, 2, 1);

	 	 _delay_ms(50) ; // becuase of if lcd_init () call first
	 	 LCD_enusendcmd(0x38) ;  // 8 bit ,, 2 line ,, 5*7 font
	 	 _delay_ms(1) ;
	 	 LCD_enusendcmd(0x0c) ;  // 0x0e ,, 0x0f cursor
	 	 _delay_ms(1) ;
	 	 LCD_enusendcmd(0x01) ; // clear screen
	 	 _delay_ms(2) ;
	 	 LCD_enusendcmd(0x06) ; // Address increase no shift


	  	 return ES_OK;
 }
 ES_t LCD_enusendcmd(u8 copy_cmd)
 {
	 /***************************************************************************************/
	 /****************************   		8-bits code  	******************************/
	 /***************************************************************************************/
	 	 /* clear sr */
	 	 DIO_enuSetPinVAL(0, 0, 0);

	 	 /* send the command on port b */
	 	 DIO_enuSetPortVAL(1, copy_cmd);

	 	 /* set en as high */
	 	 DIO_enuSetPinVAL(0, 2, 1);
	 	 _delay_ms(1) ;

	 	 /* clear en */
	 	 DIO_enuSetPinVAL(0, 2, 0);
	 	 _delay_ms(1) ;
	 	 return ES_OK;
 }
 ES_t LCD_enuwritedate(u8 copy_data){
	 /***************************************************************************************/
	 /****************************   		8-bits code  	******************************/
	 /***************************************************************************************/
	 	 /* set sr as high */
	 	 DIO_enuSetPinVAL(0, 0, 1);

	 	 /* write the data on port b */
	 	 DIO_enuSetPortVAL(1, copy_data);

	 	 /* set en as high */
	 	 DIO_enuSetPinVAL(0, 2, 1);

	 	 _delay_ms(1) ;

	 	 /* clear en */
	 	 DIO_enuSetPinVAL(0, 2, 0);
	 	 _delay_ms(1) ;
	 	return ES_OK;
 }

 u8 static setposition(u8 r,u8 c)
{
 	if(r<2&& c<16)
 	{
 	u8 address=r*0x40+c;
 	address|=(1<<7);
 	LCD_enusendcmd(address);
 	}
 }
 ES_t LCD_enudisplaystring(u8 *copy_string,u8 r,u8 c)
 {
 	setposition(r,c);
 	u8 local_it=0;
 	u8 LOCAL_u8inline=0;
 	while(copy_string[local_it]!='\0'&&(16*r+c+local_it)<32)
 	{

 		if((16*r+c+local_it)<16)
 		{
 			LCD_enuwritedate(copy_string[local_it]);
 			local_it++;
 		}
 		else if((16*r+c+local_it)==16&&LOCAL_u8inline==0)
 		{
 			setposition(1,0);
 			LOCAL_u8inline=1;
 		}
 		else
 		{
 			LCD_enuwritedate(copy_string[local_it]);
 			local_it++;
 		}

 	}

 	return ES_OK;

 }


 ES_t storechar(u8 index, u8 *pattern)
 {
 	if(index>=0&&index<8)
 	{
 	u8 address=index*8;
 	address|=(1<<7);
 	//go to cg ram
 	LCD_enusendcmd(address);
 	for(int i=0;i<8;i++)
 	{
 		LCD_enuwritedate(pattern[i]);
 	}
 	//return to ddram
 	LCD_enusendcmd(0x02);
 	}
 	return ES_OK;
 }

 ES_t dispaystoredchar(u8 index, u8 r, u8 c)
 {
 	setposition(r,c);
 	LCD_enuwritedate(index);
 }

 static u16 Private_u16GetPower(u8 Copy_u8Number1, u8 Copy_u8Number2)
 {
 	u16 Local_u16Result = 1;
 	u8 Local_u8Counter = 0;

 	for(Local_u8Counter = 0; Local_u8Counter < Copy_u8Number2; Local_u8Counter++)
 	{
 		Local_u16Result *= Copy_u8Number1;
 	}
 	return Local_u16Result;
 }

 ES_t LCD_voidWriteNumber(u16 Copy_u16Number)
 {
 	u8 Local_u8Counter = 0, Local_u8Digits = 0, Local_u8Current;
 	u16 Local_u16CopyNumber = Copy_u16Number;

 	if(0 == Copy_u16Number)
 	{
 		LCD_enuwritedate('0');
 	}
 	else
 	{
 		while(Local_u16CopyNumber)
 		{
 			Local_u16CopyNumber /= 10;
 			Local_u8Digits++;
 		}
 		Local_u16CopyNumber = Copy_u16Number;

 		for(Local_u8Counter = 0; Local_u8Counter < Local_u8Digits; Local_u8Counter++)
 		{
 			Local_u8Current = Local_u16CopyNumber / (Private_u16GetPower(10, Local_u8Digits - 1 - Local_u8Counter));
 			LCD_enuwritedate(Local_u8Current + '0');
 			Local_u16CopyNumber %= (Private_u16GetPower(10, Local_u8Digits - 1 - Local_u8Counter));
 		}
 	}
 }
