/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.h
 *
 * Description: Header file for Button Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/
#ifndef BUTTON_H
#define BUTTON_H

#include "Std_Types.h"

#define PORTF_PRIORITY_MASK         0XFF1FFFFF
#define PORTB_PRIORITY_MASK         0XFFFFFF1F

#define PORTF_PRIORITY_BITS_POS     (21U)
#define PORTB_PRIORITY_BITS_POS     (5U)

/* 
 * Description: 1. Fill the button configurations structure 
 *              2. Set the PIN direction which the button is connected as INPUT pin
 *              3. Set the pin internal resistor
 */
void Button_Init(void);

#endif /* BUTTON_H */
