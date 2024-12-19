/*
 * System_Diagnostics.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Amr
 */
#include "FreeRTOS.h"
#include "event_groups.h"

#include "GPTM.h"

#include "System_Diagnostics.h"

SystemDiagnostics_t system_diagnostics={
                                            0,NOT_CONTROLLED,
                                            0,NOT_CONTROLLED,
};

SystemDiagnostics_t* system_diagnostics_ptr = &system_diagnostics;

SaveFailureInfoTaskParameters_t DriverSeat_SaveFailureInfoTaskParameters={ DRIVER_SEAT,DRIVER_SEAT_FAILURE_EVENT_BITS};
SaveFailureInfoTaskParameters_t PassengerSeat_SaveFailureInfoTaskParameters={ PASSENGER_SEAT,PASSENGER_SEAT_FAILURE_EVENT_BITS};

void SystemDiagnostics_Init(void)
{
    //GPTM_WTimer0Init();
}

void SystemDiagnostics_SaveFailureInfo(void *pvParameters)
{
    SaveFailureInfoTaskParameters_t* ptr = /*(SaveFailureInfoTaskParameters_t*)*/pvParameters;

    for(;;)
    {
        xEventGroupWaitBits( SystemControlEventGroup,   /* The event group to read. */
                             ptr->TaskEventBits,        /* Bits to test. */
                             pdTRUE,                    /* Clear bits on exit if the unblock condition is met. */
                             pdFALSE,                   /* Don't wait for all bits. */
                             portMAX_DELAY);            /* Don't time out. */
        if(xSemaphoreTake(xSystemStateMutex, portMAX_DELAY) == pdTRUE)
        {
            system_diagnostics_ptr->seats[ptr->SeatIndex].time_stamp=GPTM_WTimer0Read();
            system_diagnostics_ptr->seats[ptr->SeatIndex].last_seat_heating_level=system_state_ptr->seats[ptr->SeatIndex].seat_heating_level;

            xSemaphoreGive(xSystemStateMutex);
        }
    }
}
