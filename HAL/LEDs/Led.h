/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.h
 *
 * Description: Header file for Led Module.
 *
 * Author: Amr Mohamed
 ******************************************************************************/
#ifndef LED_H
#define LED_H

#include "Std_Types.h"

#define RED_LED         (0U)
#define BLUE_LED        (1U)
#define GREEN_LED       (2U)

/* Description: 1. Set the PIN direction which the led is connected as OUTPUT pin
 *		        2. Initialize the led ON/OFF according to the initial value
 */
void Led_Init(void);

/* Description: Set the LED state to OFF */
void Led_SetOn(uint8 pin, uint8 offset);

/*Description: Toggle the LED state */
void Led_SetOff(uint8 pin, uint8 offset);

#endif /* LED_H */
