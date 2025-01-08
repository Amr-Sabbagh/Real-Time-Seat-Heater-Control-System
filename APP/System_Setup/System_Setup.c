/*************************************************
 * System_Setup.c
 *
 *  Created on: Nov 5, 2024
 *      Author: Amr
 ************************************************/

#include "System_Setup.h"
#include "System_Display.h"
#include "System_Control.h"
#include "System_Measurements.h"
#include "System_Diagnostics.h"

SystemState_t System_State = {
                              41,TEMP_OUT_OF_RANGE,NOT_CONTROLLED,DISABLED,
                              1,SAFE,NOT_CONTROLLED,DISABLED,
};

SystemState_t* System_State_Ptr = &System_State;

void SystemSetup_Init(void)
{
    /*Modules Init */
    SystemDisplay_Init();
    SystemControl_Init();
    SystemMeasurements_Init();
    SystemDiagnostics_Init();

    /* Semaphores */

    /* MUTEXs */

    SystemControlEventGroup = xEventGroupCreate();

    xSystemStateMutex = xSemaphoreCreateMutex();

    /* Tasks */
    xTaskCreate(SystemMeasurements_CPULoad, "Run Time", 32, NULL, 2, &MeasurementsTaskHandle);

    xTaskCreate(SystemDisplay_Print, "Display", 32, NULL, 2, &DisplayTaskHandle);

    xTaskCreate(SystemControl_UpdateHeatingLevel, "Driver Heating Level", 64, (void*)&DriverSeat_HeatingLevelTaskParameters, 1, &DrvHeatingLevelHandle);
    xTaskCreate(SystemControl_UpdateHeatingLevel, "Passenger Heating Level", 64, (void*)&PassengerSeat_HeatingLevelTaskParameters, 1, &PaxHeatingLevelHandle);

    xTaskCreate(SystemControl_UpdateHeaterIntensity, "Driver Heater Intensity", 32, (void*)&DriverSeat_HeaterIntensityTaskParameters, 1, &DrvHeaterIntensityHandle);
    xTaskCreate(SystemControl_UpdateHeaterIntensity, "Passenger Heater Intensity", 32, (void*)&PassengerSeat_HeaterIntensityTaskParameters, 1, &PaxHeaterIntensityHandle);

    xTaskCreate(SystemControl_UpdateTemperature, "Driver Temperature", 32, (void*)&DriverSeat_TempreatureTaskParameters, 1, &DrvTempHandle);
    xTaskCreate(SystemControl_UpdateTemperature, "Passenger Temperature", 32, (void*)&PassengerSeat_TempreatureTaskParameters, 1, &PaxTempHandle);

    xTaskCreate(SystemDiagnostics_SaveFailureInfo, "Save Failure in Driver Seat Heater", 32, (void*)&DriverSeat_SaveFailureInfoTaskParameters, 1, &DrvFailureHandle);
    xTaskCreate(SystemControl_UpdateHeaterIntensity, "Save Failure in Passenger Heater", 32, (void*)&PassengerSeat_SaveFailureInfoTaskParameters, 1, &PaxFailureHandle);


    /* Tasks Tags*/
    vTaskSetApplicationTaskTag( MeasurementsTaskHandle, ( TaskHookFunction_t ) 1 );

    vTaskSetApplicationTaskTag( DisplayTaskHandle, ( TaskHookFunction_t ) 2 );

    vTaskSetApplicationTaskTag( DrvHeatingLevelHandle, ( TaskHookFunction_t ) 3 );
    vTaskSetApplicationTaskTag( PaxHeatingLevelHandle, ( TaskHookFunction_t ) 4 );

    vTaskSetApplicationTaskTag( DrvHeaterIntensityHandle, ( TaskHookFunction_t ) 5 );
    vTaskSetApplicationTaskTag( PaxHeaterIntensityHandle, ( TaskHookFunction_t ) 6 );

    vTaskSetApplicationTaskTag( DrvTempHandle, ( TaskHookFunction_t ) 7 );
    vTaskSetApplicationTaskTag( PaxTempHandle, ( TaskHookFunction_t ) 8 );

    vTaskSetApplicationTaskTag( DrvFailureHandle, ( TaskHookFunction_t ) 9 );
    vTaskSetApplicationTaskTag( PaxFailureHandle, ( TaskHookFunction_t ) 10 );


    /* Scheduler */
    vTaskStartScheduler();
}

