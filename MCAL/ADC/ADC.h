/*
 * ADC.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Amr
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

#define ADC_MAXIMUM_VALUE           4095
#define ADC_REF_VOLT_VALUE          3.3

void ADC_Init(void);
uint32 ADC_Read(uint8 channel);

#endif /* MCAL_ADC_ADC_H_ */
