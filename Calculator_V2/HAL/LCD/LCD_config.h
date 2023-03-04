/*
 * SSD_config.h
 *
 *  Created on: Feb 9, 2023
 *      Author: esraa
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "../../MCAL/DIO/DIO_Init.h"

 #define RS_port DIO_u8PORTA
 #define RS_PIN DIO_PIN0

 #define RW_port DIO_u8PORTA
 #define RW_PIN DIO_PIN1

 #define EN_port DIO_u8PORTA
 #define EN_PIN DIO_PIN2

 #define D7_port DIO_u8PORTA
 #define D7_PIN DIO_PIN3

 #define D6_port DIO_u8PORTA
 #define D6_PIN DIO_PIN4

 #define D5_port DIO_u8PORTA
 #define D5_PIN DIO_PIN5

 #define D4_port DIO_u8PORTA
 #define D4_PIN DIO_PIN6

#endif /* SSD_CONFIG_H_ */
