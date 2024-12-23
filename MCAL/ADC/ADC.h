/*
 * ADC.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Amr
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

#define ADC_MAXIMUM_VALUE           0xFFF
#define ADC_REF_VOLT_VALUE          3.3

typedef enum {
    PE3_PIN,PE2_PIN,PE1_PIN,PE0_PIN,PD3_PIN,PD2_PIN,PD1_PIN,PD0_PIN,
    PE5_PIN,PE4_PIN,PB4_PIN,PB5_PIN
} channel_no;

typedef uint8 ChannelType_t;


void ADC0_EnableCLock(void);
uint32 ADC0_ReadChannel(ChannelType_t channel);


#endif /* MCAL_ADC_ADC_H_ */
