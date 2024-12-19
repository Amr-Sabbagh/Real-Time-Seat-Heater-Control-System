/*
 * System_Setup.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Amr
 */

#include "System_Setup.h"
#include "System_Diagnostics.h"
#include "System_Measurements.h"
#include "System_Control.h"
#include "System_Display.h"

SystemState_t system_state= {
                                        0,SAFE, NOT_CONTROLLED, DISABLED,
                                        0,SAFE, NOT_CONTROLLED, DISABLED
    };

SystemState_t* system_state_ptr = &system_state;

void SystemSetup_Init(void)
{
    /* Modules Init */
    //SystemDisplay_Init();

    //SystemControl_Init();

    //SystemDiagnostics_Init();

    /* Semph/Mutex and Event Groups Creation */
    //SystemControlEventGroup = xEventGroupCreate();

    //xSystemStateMutex = xSemaphoreCreateMutex();

    /* Tasks Creation */

    xTaskCreate(SystemMeasurements_CPULoad, "CPULoad", 256, NULL, 1, NULL);

    xTaskCreate(SystemDisplay_DisplaySystemState, "Display", 256, NULL, 1, NULL);

//    xTaskCreate(SystemControl_UpdateTemperature, "Driver Temperature Monitor", 256, (void*)&DriverSeat_TempreatureTaskParameters, 3, &DrvTempHandle);
//
//    xTaskCreate(SystemControl_UpdateTemperature, "Passenger Temperature Monitor", 256, (void*)&PassengerSeat_TempreatureTaskParameters, 3, &PaxTempHandle);
//
//    xTaskCreate(SystemControl_UpdateHeaterIntensity, "Driver Heater Intensity", 256, (void*)&DriverSeat_HeaterIntensityTaskParameters, 3, &DrvHeaterIntensityHandle);
//
//    xTaskCreate(SystemControl_UpdateHeaterIntensity, "Passenger Heater Intensity", 256, (void*)&PassengerSeat_HeaterIntensityTaskParameters, 3, &PaxHeaterIntensityHandle);
//
//    xTaskCreate(SystemControl_UpdateHeatingLevel, "Driver Heating Level", 256, (void*)&DriverSeat_HeatingLevelTaskParameters, 1, &DrvHeatingLevelHandle);
//
//    xTaskCreate(SystemControl_UpdateHeatingLevel, "Passenger Heating Level", 256, (void*)&PassengerSeat_HeatingLevelTaskParameters, 1, &PaxHeatingLevelHandle);
//
//    xTaskCreate(SystemDiagnostics_SaveFailureInfo, "Save Driver Failure ", 256, (void*)&DriverSeat_SaveFailureInfoTaskParameters, 1, &DrvFailureHandle);
//
//    xTaskCreate(SystemDiagnostics_SaveFailureInfo, "Save Passenger Failure", 256, (void*)&PassengerSeat_SaveFailureInfoTaskParameters, 1, &PaxFailureHandle);


    //SystemMeasurements_Init();  //last initialization to start the timer before scheduler

    vTaskStartScheduler();

    for(;;);
}
