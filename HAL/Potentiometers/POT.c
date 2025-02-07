/*
 * POT.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Amr
 */

#include "Port.h"
#include "Dio.h"
#include "POT.h"
#include "POT_Cfg.h"
#include <stdlib.h>
#include "ADC.h"

/* Button Configurations Structure */
Port_ConfigType g_POT_Config={
                                     POT_PORT, POT1_PIN, PORT_PIN_IN, PULL_UP, PORT_PIN_LEVEL_HIGH, PORT_PIN_MODE_ADC, STD_OFF, STD_OFF,
                                     POT_PORT, POT2_PIN, PORT_PIN_IN, PULL_UP, PORT_PIN_LEVEL_HIGH, PORT_PIN_MODE_ADC, STD_OFF, STD_OFF,
};

void POT_Init(void)
{
    Port_Init(&g_POT_Config);
    Dio_Init(&Dio_Configuration);
    ADC_Init();
}

uint32 POT_Read(uint8 pin)
{
    uint32 ret = ADC_Read(pin)*45/ADC_MAXIMUM_VALUE;
    return ( ret );
}
