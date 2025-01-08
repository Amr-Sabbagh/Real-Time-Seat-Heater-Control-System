/*************************************************
 * System_Display.c
 *
 *  Created on: Nov 5, 2024
 *      Author: Amr
 ************************************************/

#include "System_Display.h"
#include "uart0.h"

void SystemDisplay_Init(void)
{
    UART0_Init();
}

void SystemDisplay_Print(void *pvParameters)
{
    const TickType_t xDelay = pdMS_TO_TICKS(1000);
    for(;;)
    {
        vTaskDelay(xDelay);

        if(xSemaphoreTake(xSystemStateMutex, portMAX_DELAY) == pdTRUE)
        {
            uint8 i=0;
            for (;i<NUMBER_OF_SEATS;i++)
            {
                UART0_SendString("***** *****");
                if(i==DRIVER_SEAT)
                {
                    UART0_SendString(" DRIVER ");
                }
                else if(i==PASSENGER_SEAT)
                {
                    UART0_SendString("PASSENGER ");
                }
                UART0_SendString("SEAT STATUS ***** *****\r\n");

                switch (System_State_Ptr->seats[i].sensor)
                {
                case TEMP_OUT_OF_RANGE:
                    UART0_SendString("  FAFAILURE IN ");
                    if(i==DRIVER_SEAT)
                    {
                        UART0_SendString("DRIVER ");
                    }
                    else if(i==PASSENGER_SEAT)
                    {
                        UART0_SendString("PASSENGER ");
                    }
                    UART0_SendString("SEAT HEATING SYSTEM\r\n(( TEMPERATURE SENSOR READING OUT OF RANGE! ))\r\n\n"); break;
                case SAFE: break;
                }

                UART0_SendString("- Temperature: ");
                UART0_SendInteger(System_State_Ptr->seats[i].temp);
                UART0_SendString("\r\n- Heating Level: ");

                switch(System_State_Ptr->seats[i].seat_heating_level)
                {
                case NOT_CONTROLLED: UART0_SendString("NOT CONTROLLED\r\n- Heater Intensity: "); break;
                case LOW_HEATING: UART0_SendString("LOW_HEATING\r\n- Heater Intensity: "); break;
                case MEDIUM_HEATING:UART0_SendString("MEDIUM_HEATING\r\n- Heater Intensity: "); break;
                case HIGH_HEATING: UART0_SendString("HIGH_HEATING\r\n- Heater Intensity: "); break;
                }

                switch(System_State_Ptr->seats[i].seat_heater_intensity)
                {
                case DISABLED: UART0_SendString("DISABLED\r\n"); break;
                case LOW_INTENSITY: UART0_SendString("LOW_INTENSITY\r\n"); break;
                case MEDIUM_INTENSITY: UART0_SendString("MEDIUM_INTENSITY\r\n"); break;
                case HIGH_INTENSITY: UART0_SendString("HIGH_INTENSITY\r\n"); break;
                }
            }
            UART0_SendString("\n***** ***** **CPU Load is ");
            UART0_SendInteger(CPU_Load);
            UART0_SendString("%** ***** *****\r\n");

            xSemaphoreGive(xSystemStateMutex);
        }

    }
}
