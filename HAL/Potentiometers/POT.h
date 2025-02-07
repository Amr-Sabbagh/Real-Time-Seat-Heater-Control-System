/*
 * POT.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Amr
 */

#ifndef HAL_POTENTIOMETER_POT_H_
#define HAL_POTENTIOMETER_POT_H_

#include "Std_Types.h"

#define POT1    (0U)
#define POT2    (1U)

void POT_Init(void);
uint32 POT_Read( uint8 pin );

#endif /* HAL_POTENTIOMETER_POT_H_ */
