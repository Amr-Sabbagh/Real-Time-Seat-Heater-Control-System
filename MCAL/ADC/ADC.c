/*
 * ADC.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Amr
 */

#include "ADC.h"
#include "tm4c123gh6pm_registers.h"

void ADC_Init(void)
{
    ADC_ADCRCGCADC_REG |= (1<<0) | (1<<1);

    while ((ADC_ADCRCGCADC_REG & 0x03) == 0); // Wait for ADC clock to stabilize

    ADC0_ADCACTSS_REG    = 0x00000000;
    ADC0_ADCSSMUX3_REG   = 0;
    ADC0_ADCSSCTL3_REG   = 0x06;
    ADC0_ADCACTSS_REG   |= 0x08;

    ADC1_ADCACTSS_REG    = 0x00000000;
    ADC1_ADCSSMUX3_REG   = 1;
    ADC1_ADCSSCTL3_REG   = 0x06;
    ADC1_ADCACTSS_REG   |= 0x08;

}

uint32 ADC_Read(uint8 channel)
{
    uint32 result;
    switch (channel)
    {
        case 0:
        {
            ADC0_ADCPSSI_REG = 0x08;
            while(!(ADC0_ADCRIS_REG & 0x00000008)); // Wait for the conversion to complete
            result = ADC0_ADCSSFIFO3_REG;
            ADC0_ADCISC_REG = 0x08;
            break;
        }
        case 1:
        {
            ADC1_ADCPSSI_REG = 0x08;
            while(!(ADC1_ADCRIS_REG & 0x00000008)); // Wait for the conversion to complete
            result = ADC1_ADCSSFIFO3_REG;
            ADC1_ADCISC_REG = 0x08;
            break;
        }
    }
    return result;
}
