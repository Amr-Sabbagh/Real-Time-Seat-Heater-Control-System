/*************************************************
 * System_Measurements.c
 *
 *  Created on: Nov 5, 2024
 *      Author: Amr
 ************************************************/
#include "System_Measurements.h"
#include "GPTM.h"
#include "uart0.h"

void SystemMeasurements_Init(void)
{
    GPTM_WTimer0Init();
}

void SystemMeasurements_CPULoad(void* pvParameters)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        uint8 ucCounter;
        uint32 ullTotalTasksTime = 0;
        vTaskDelayUntil(&xLastWakeTime, 1000);
        //vTaskDelay(xDelay);

        for(ucCounter = 1; ucCounter < 11; ucCounter++)
        {
            ullTotalTasksTime += ullTasksTotalTime[ucCounter];
        }
        CPU_Load = (ullTotalTasksTime * 100) /  GPTM_WTimer0Read();
//
//        if(xSemaphoreTake(xUARTMutex, portMAX_DELAY) == pdTRUE)
//        {
//            //taskENTER_CRITICAL();
//            UART0_SendString("***** ***** CPU Load is ");
//            UART0_SendInteger(ucCPU_Load);
//            UART0_SendString("% ***** *****\r\n");
//            //taskEXIT_CRITICAL();
//
//            xSemaphoreGive(xUARTMutex);
//        }
    }
}
