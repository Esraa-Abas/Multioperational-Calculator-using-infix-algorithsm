/*
 * DIO_Init.h
 *
 *  Created on: Dec 15, 2022
 *      Author: esraa
 */

#ifndef DIO_INIT_H_
#define DIO_INIT_H_
#include "errorstate.h"
#include "stdTypes.h"
#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3


#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_PIN_OUTPUT   1
#define DIO_PIN_INPUT    0

#define DIO_PIN_LOW     0
#define DIO_PIN_HIGH    1

#define DIO_FLOAT		0
#define DIO_PULL_UP	    1

#define DIO_PORT_OUTPUT  0XFF
#define DIO_PORT_INPUT   0

ES_t DIO_enuInit(void);
ES_t DIO_enuSetPortDIR(u8 copy_u8port, u8 copy_u8value);
ES_t DIO_enuSetPortVAL(u8 copy_u8port, u8 copy_u8value);
ES_t DIO_enuTogPort(u8 copy_u8port);
ES_t DIO_enuSetPinDIR(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8value);
ES_t DIO_enuSetPinVAL(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8value);
ES_t DIO_enuTogPin(u8 copy_u8port,u8 copy_u8pin);
ES_t DIO_enuGetPortval(u8 copy_u8port, u8 *copy_u8value);
ES_t DIO_enuGetPinval(u8 copy_u8port,u8 copy_u8pin, u8 *copy_u8value);
#endif /* DIO_INIT_H_ */
