/*************************************************
 * System_Diagnostics.c
 *
 *  Created on: Nov 15, 2024
 *      Author: Amr
 ************************************************/

#include "System_Diagnostics.h"

SystemDiagnostics_t System_Diagnostics;

SystemDiagnostics_t* System_Diagnostics_Ptr = &System_Diagnostics;


const SaveFailureInfoTaskParameters_t DriverSeat_SaveFailureInfoTaskParameters = { DRIVER_SEAT, DRIVER_SEAT_FAILURE_EVENT_BITS };
const SaveFailureInfoTaskParameters_t PassengerSeat_SaveFailureInfoTaskParameters = { PASSENGER_SEAT, PASSENGER_SEAT_FAILURE_EVENT_BITS };

void SystemDiagnostics_Init(void)
{
    //GPTM_WTimer0Init();
}

void SystemDiagnostics_SaveFailureInfo(void *pvParameters)
{
    SaveFailureInfoTaskParameters_t* ptr = pvParameters;

    for(;;)
    {
        xEventGroupWaitBits( SystemControlEventGroup,   /* The event group to read. */
                             ptr->TaskEventBits,        /* Bits to test. */
                             pdTRUE,                    /* Clear bits on exit if the unblock condition is met. */
                             pdFALSE,                   /* Don't wait for all bits. */
                             portMAX_DELAY);            /* Don't time out. */
        if(xSemaphoreTake(xSystemStateMutex, portMAX_DELAY) == pdTRUE)
        {
            System_Diagnostics_Ptr->seats[ptr->SeatIndex].time_stamp=GPTM_WTimer0Read();
            System_Diagnostics_Ptr->seats[ptr->SeatIndex].last_seat_heating_level=System_State_Ptr->seats[ptr->SeatIndex].seat_heating_level;

            xSemaphoreGive(xSystemStateMutex);
        }
    }
}

