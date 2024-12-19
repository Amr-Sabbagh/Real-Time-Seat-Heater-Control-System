/*
 * System_Display.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Amr
 */

#include "System_Display.h"
#include "System_Setup.h"
#include  "uart0.h"

void SystemDisplay_Init(void)
{
    UART0_Init();
}

void SystemDisplay_DisplaySystemState(void *pvParameters)
{
    const TickType_t xDelay = pdMS_TO_TICKS(1000);

    for(;;)
    {
        vTaskDelay(xDelay);

        if(xSemaphoreTake(xSystemStateMutex, portMAX_DELAY) == pdTRUE)
        {
            /*
             * Passenger state
             ********************************************************/
            switch(system_state_ptr->seats[DRIVER_SEAT].state)
            {
            case TEMP_OUT_OF_RANGE:
                UART0_SendString("FAILURE IN DRIVER SEAT HEATING SYSTEM \r\n(( TEMPERATURE SENSOR READING OUT OF RANGE! ))\r\n\n"); break;
            case SAFE: break;
            }

            UART0_SendString("Driver seat Temperature: ");
            UART0_SendInteger(system_state_ptr->seats[DRIVER_SEAT].temp);
            UART0_SendString("\r\n");

            UART0_SendString("Driver seat Heating Level: ");

            switch(system_state_ptr->seats[DRIVER_SEAT].seat_heating_level)
            {
            case NOT_CONTROLLED: UART0_SendString("NOT CONTROLLED"); break;
            case LOW_HEATING: UART0_SendString("LOW_HEATING"); break;
            case MEDIUM_HEATING:UART0_SendString("MEDIUM_HEATING"); break;
            case HIGH_HEATING: UART0_SendString("HIGH_HEATING"); break;
            }
            UART0_SendString("\r\n");

            UART0_SendString("Driver seat heater intensity: ");

            switch(system_state_ptr->seats[DRIVER_SEAT].seat_heater_intensity)
            {
            case DISABLED: UART0_SendString("DISABLED"); break;
            case LOW_INTENSITY: UART0_SendString("LOW_INTENSITY"); break;
            case MEDIUM_INTENSITY: UART0_SendString("MEDIUM_INTENSITY"); break;
            case HIGH_INTENSITY: UART0_SendString("HIGH_INTENSITY"); break;

            }
            UART0_SendString("\r\n");


            /*
             * Passenger state
             ********************************************************/
            switch(system_state_ptr->seats[PASSENGER_SEAT].state)
            {
            case TEMP_OUT_OF_RANGE: UART0_SendString("FAILURE IN PASSENGER SEAT HEATING SYSTEM \r\n(( TEMPERATURE SENSOR READING OUT OF RANGE! ))\r\n"); break;
            case SAFE: break;
            }

            UART0_SendString("Passenger seat temperature: ");
            UART0_SendInteger(system_state_ptr->seats[PASSENGER_SEAT].temp);
            UART0_SendString("\r\n");

            UART0_SendString("Passenger seat heating level: ");
            switch(system_state_ptr->seats[PASSENGER_SEAT].seat_heating_level)
            {
            case NOT_CONTROLLED: UART0_SendString("NOT CONTROLLED"); break;
            case LOW_HEATING: UART0_SendString("LOW_HEATING"); break;
            case MEDIUM_HEATING:UART0_SendString("MEDIUM_HEATING"); break;
            case HIGH_HEATING: UART0_SendString("HIGH_HEATING"); break;
            }
            UART0_SendString("\r\n");

            UART0_SendString("Passenger seat heater intensity: ");
            switch(system_state_ptr->seats[PASSENGER_SEAT].seat_heater_intensity)
            {
            case DISABLED: UART0_SendString("DISABLED"); break;
            case LOW_INTENSITY: UART0_SendString("LOW_INTENSITY"); break;
            case MEDIUM_INTENSITY: UART0_SendString("MEDIUM_INTENSITY"); break;
            case HIGH_INTENSITY: UART0_SendString("HIGH_INTENSITY"); break;
            }
            UART0_SendString("\r\n");

            UART0_SendString("****** CPU Load is ");
            UART0_SendInteger(&CPU_Load);
            UART0_SendString("% ******\r\n\n");

            xSemaphoreGive(xSystemStateMutex);
        }
    }
}
