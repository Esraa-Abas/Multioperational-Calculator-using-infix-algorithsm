/*
 * DIO_priv.h
 *
 *  Created on: Dec 15, 2022
 *      Author: esraa
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define DIO_MASKING 0xff

#define NULL *((void*)0x0)


#define DDRA *(u8*)0x3A
#define PORTA *(u8*)0x3B
#define PINA *(u8*)0x39

#define DDRB *(u8*)0x37
#define PORTB *(u8*)0x38
#define PINB *(u8*)0x36

#define DDRC *(u8*)0x34
#define PORTC *(u8*)0x35
#define PINC *(u8*)0x33

#define DDRD *(u8*)0x31
#define PORTD *(u8*)0x32
#define PIND *(u8*)0x30


#define OUTPUT 1
#define INPUT 0

#define LOW 0
#define HIGH 1

#define FLOAT 0
#define PULL_UP 1



#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3


#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


#define masking_bit  1

#define CONC_H(b7,b6,b5,b4,b3,b2,b1,b0) b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0) CONC_H(b7,b6,b5,b4,b3,b2,b1,b0)

#endif /* DIO_PRIV_H_ */
