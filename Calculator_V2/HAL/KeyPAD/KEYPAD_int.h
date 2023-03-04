/*
 * KEYPAD_int.h

 *
 *      Author: esraa
 */

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_

ES_t Keypad_enuInit(void);

ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8KeyValue);

#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
