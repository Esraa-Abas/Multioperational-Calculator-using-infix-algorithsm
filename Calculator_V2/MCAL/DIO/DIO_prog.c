/*
 * DIO_prog.c
 *
 *  Created on: Dec 15, 2022
 *      Author: esraa
 */

#ifndef DIO_PROG_C_
#define DIO_PROG_C_

#include"errorstate.h"
#include"DIO_priv.h"
#include"DIO_config.h"
#include "stdtypes.h"

ES_t DIO_enuInit(void){

	DDRA=CONC(PORTA_PIN7,PORTA_PIN6,PORTA_PIN5,PORTA_PIN4,PORTA_PIN3,PORTA_PIN2,PORTA_PIN1,PORTA_PIN0);
	DDRB=CONC(PORTB_PIN7,PORTB_PIN6,PORTB_PIN5,PORTB_PIN4,PORTB_PIN3,PORTB_PIN2,PORTB_PIN1,PORTB_PIN0);
	DDRC=CONC(PORTC_PIN7,PORTC_PIN6,PORTC_PIN5,PORTC_PIN4,PORTC_PIN3,PORTC_PIN2,PORTC_PIN1,PORTC_PIN0);
	DDRD=CONC(PORTD_PIN7,PORTD_PIN6,PORTD_PIN5,PORTD_PIN4,PORTD_PIN3,PORTD_PIN2,PORTD_PIN1,PORTD_PIN0);

}
ES_t DIO_enuSetPortDIR(u8 copy_u8port, u8 copy_u8value){
switch(copy_u8port){
case DIO_u8PORTA:
	DDRA=copy_u8value;
	break;

case DIO_u8PORTB:
	DDRB=copy_u8value;
	break;

case DIO_u8PORTC:
	DDRC=copy_u8value;
	break;

case DIO_u8PORTD:
	DDRD=copy_u8value;
	break;
}
}
ES_t DIO_enuSetPortVAL(u8 copy_u8port, u8 copy_u8value){
	switch(copy_u8port){
	case DIO_u8PORTA:
		PORTA=copy_u8value;
		break;

	case DIO_u8PORTB:
		PORTB=copy_u8value;
		break;

	case DIO_u8PORTC:
		PORTC=copy_u8value;
		break;

	case DIO_u8PORTD:
		PORTD=copy_u8value;
		break;
	}
}
ES_t DIO_enuTogPort(u8 copy_u8port){
	switch(copy_u8port){
		case DIO_u8PORTA:
			PORTA=~PORTA;
			break;

		case DIO_u8PORTB:
			PORTB=~PORTB;
			break;

		case DIO_u8PORTC:
			PORTC=~PORTC;
			break;

		case DIO_u8PORTD:
			PORTD=~PORTD;
			break;
		}

}
ES_t DIO_enuSetPinDIR(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8value){
	if(copy_u8pin>=PIN0&&copy_u8pin<=PIN7&&copy_u8value>=INPUT&&copy_u8value<=OUTPUT){
	switch(copy_u8port){
		case DIO_u8PORTA:
			DDRA&=~(masking_bit<<copy_u8pin);
			DDRA|=(copy_u8value<<copy_u8pin);
			break;

		case DIO_u8PORTB:
			DDRB&=~(masking_bit<<copy_u8pin);
			DDRB|=(copy_u8value<<copy_u8pin);
			break;

		case DIO_u8PORTC:
			DDRC&=~(masking_bit<<copy_u8pin);
			DDRC|=(copy_u8value<<copy_u8pin);
			break;

		case DIO_u8PORTD:
			DDRD&=~(masking_bit<<copy_u8pin);
			DDRD|=(copy_u8value<<copy_u8pin);
			break;
		}
	}
	return ES_OK;
}

ES_t DIO_enuSetPinVAL(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8value){
	if(copy_u8pin>=PIN0&&copy_u8pin<=PIN7&&copy_u8value>=LOW&&copy_u8value<=HIGH){
	switch(copy_u8port){
		case DIO_u8PORTA:
			PORTA&=~(masking_bit<<copy_u8pin);
			PORTA|=(copy_u8value<<copy_u8pin);
			break;

		case DIO_u8PORTB:
			PORTB&=~(masking_bit<<copy_u8pin);
			PORTB|=(copy_u8value<<copy_u8pin);
			break;

		case DIO_u8PORTC:
			PORTC&=~(masking_bit<<copy_u8pin);
			PORTC|=(copy_u8value<<copy_u8pin);
			break;

		case DIO_u8PORTD:
			PORTD&=~(masking_bit<<copy_u8pin);
			PORTD|=(copy_u8value<<copy_u8pin);
			break;
		}
	}
	return ES_OK;
}
ES_t DIO_enuTogPin(u8 copy_u8port,u8 copy_u8pin){
	switch(copy_u8port){
			case DIO_u8PORTA:
				PORTA^=(masking_bit<<copy_u8pin);
				break;

			case DIO_u8PORTB:
				PORTB=(masking_bit<<copy_u8pin);
				break;

			case DIO_u8PORTC:
				PORTC=(masking_bit<<copy_u8pin);
				break;

			case DIO_u8PORTD:
				PORTD=(masking_bit<<copy_u8pin);
				break;
			}
}

ES_t DIO_enuGetPortval(u8 copy_u8port, u8 *copy_u8value){
	switch(copy_u8port){
			case DIO_u8PORTA:
				*copy_u8value=PINA;
				break;

			case DIO_u8PORTB:
				*copy_u8value=PINB;
				break;

			case DIO_u8PORTC:
				*copy_u8value=PINC;
				break;

			case DIO_u8PORTD:
				*copy_u8value=PIND;
				break;
			}

}
ES_t DIO_enuGetPinval(u8 copy_u8port,u8 copy_u8pin, u8 *copy_u8value){
	switch(copy_u8port){
			case DIO_u8PORTA:
				*copy_u8value=((PINA>>copy_u8pin) &masking_bit);
				break;

			case DIO_u8PORTB:
				*copy_u8value=((PINB>>copy_u8pin) &masking_bit);
				break;

			case DIO_u8PORTC:
				*copy_u8value=((PINC>>copy_u8pin) &masking_bit);
				break;

			case DIO_u8PORTD:
				*copy_u8value=((PIND>>copy_u8pin) &masking_bit);
				break;
			}

}
#endif /* DIO_PROG_C_ */
