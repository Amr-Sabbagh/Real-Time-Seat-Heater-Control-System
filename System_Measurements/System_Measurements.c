/*
 * System_Measurements.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Amr
 */

#include "System_Measurements.h"

#include "uart0.h"
#include "GPTM.h"

void SystemMeasurements_Init(void)
{
    GPTM_WTimer0Init();
}

void SystemMeasurements_CPULoad(void* pvParameters)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    uint8_t* pucCPU_Load = (uint8_t*)pvParameters;
    uint8 ucCounter;

    for (;;)
    {
        uint32 ullTotalTasksTime = 0;

        vTaskDelay(pdMS_TO_TICKS( RUNTIME_MEASUREMENTS_TASK_PERIODICITY ));

        for(ucCounter = 0; ucCounter < 11; ucCounter++)
        {
            ullTotalTasksTime += ullTasksTotalTime[ucCounter];
        }
        *pucCPU_Load = (ullTotalTasksTime*  100) /  GPTM_WTimer0Read();
    }
}

