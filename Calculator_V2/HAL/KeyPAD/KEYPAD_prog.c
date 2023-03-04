/*
 * KEYPAD_prog.c
 *
 *      Author: esraa
 */
#include"util/delay.h"
#include"../../MCAL/DIO/stdtypes.h"
#include"../../MCAL/DIO/errorstate.h"

#include"../../MCAL/DIO/DIO_Init.h"

#include"KEYPAD_int.h"
#include"KEYPAD_priv.h"
#include"KEYPAD_config.h"



ES_t Keypad_enuInit(void){

	DIO_enuSetPinDIR(C1_PORT,C1_PIN, DIO_PIN_OUTPUT);
	DIO_enuSetPinDIR(C2_PORT,C2_PIN, DIO_PIN_OUTPUT);
	DIO_enuSetPinDIR(C3_PORT,C3_PIN, DIO_PIN_OUTPUT);
	DIO_enuSetPinDIR(C4_PORT,C4_PIN, DIO_PIN_OUTPUT);

	DIO_enuSetPinVAL(C1_PORT,C1_PIN, DIO_PIN_HIGH);
	DIO_enuSetPinVAL(C2_PORT,C2_PIN, DIO_PIN_HIGH);
	DIO_enuSetPinVAL(C3_PORT,C3_PIN, DIO_PIN_HIGH);
	DIO_enuSetPinVAL(C4_PORT,C4_PIN, DIO_PIN_HIGH);


	DIO_enuSetPinDIR(R1_PORT,R1_PIN, DIO_PIN_INPUT);
	DIO_enuSetPinDIR(R2_PORT,R2_PIN, DIO_PIN_INPUT);
	DIO_enuSetPinDIR(R3_PORT,R3_PIN, DIO_PIN_INPUT);
	DIO_enuSetPinDIR(R4_PORT,R4_PIN, DIO_PIN_INPUT);

	DIO_enuSetPinVAL(R1_PORT,R1_PIN, DIO_PULL_UP);
	DIO_enuSetPinVAL(R2_PORT,R2_PIN, DIO_PULL_UP);
	DIO_enuSetPinVAL(R3_PORT,R3_PIN, DIO_PULL_UP);
	DIO_enuSetPinVAL(R4_PORT,R4_PIN, DIO_PULL_UP);
}

ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8KeyValue)
{

  u8 local_u8R_Iterator;

  u8 local_u8C_Iterator;

  u8 local_u8PIN_VAL;

  u8 Local_Au8KeyValues[ROWS_NUM][COLS_NUM] = KEYS_VALUES;

  u8 local_Au8R_PORT[ROWS_NUM]={R1_PORT,R2_PORT,R3_PORT,R4_PORT};
  u8 local_Au8C_PORT[ROWS_NUM]={C1_PORT,C2_PORT,C3_PORT,C4_PORT};
  u8 local_Au8R_PIN[ROWS_NUM]={R1_PIN,R2_PIN,R3_PIN,R4_PIN};
  u8 local_Au8C_PIN[ROWS_NUM]={C1_PIN,C2_PIN,C3_PIN,C4_PIN};


while(1){
  for(local_u8C_Iterator=0;local_u8C_Iterator<COLS_NUM;local_u8C_Iterator++)
  {
	  DIO_enuSetPinVAL(local_Au8C_PORT[local_u8C_Iterator],local_Au8C_PIN[local_u8C_Iterator],DIO_PIN_LOW);

	  for(local_u8R_Iterator=0;local_u8R_Iterator<ROWS_NUM;local_u8R_Iterator++)
	  {
		  DIO_enuGetPinval(local_Au8R_PORT[local_u8R_Iterator],local_Au8R_PIN[local_u8R_Iterator],&local_u8PIN_VAL);
		  if (local_u8PIN_VAL==0)
		  {

			_delay_ms(10);
			DIO_enuGetPinval(local_Au8R_PORT[local_u8R_Iterator],local_Au8R_PIN[local_u8R_Iterator],&local_u8PIN_VAL);
			if (local_u8PIN_VAL==0)
			{
				while (local_u8PIN_VAL==0)
				{
					DIO_enuGetPinval(local_Au8R_PORT[local_u8R_Iterator],local_Au8R_PIN[local_u8R_Iterator],&local_u8PIN_VAL);
				}
				DIO_enuSetPinVAL(local_Au8C_PORT[local_u8C_Iterator],local_Au8C_PIN[local_u8C_Iterator],DIO_PIN_HIGH);
				*Copy_pu8KeyValue = Local_Au8KeyValues[local_u8R_Iterator][local_u8C_Iterator];

				return ES_OK;
			}
		  }

       }
	  DIO_enuSetPinVAL(local_Au8C_PORT[local_u8C_Iterator],local_Au8C_PIN[local_u8C_Iterator],DIO_PIN_HIGH);
   }
}
}
