#include "System_Setup.h"
#include "System_Setup.h"
#include "System_Diagnostics.h"
#include "System_Measurements.h"
#include "System_Control.h"
#include "System_Display.h"


int main(void)
{



    /* Modules Init */
    SystemDisplay_Init();

    SystemControl_Init();

    SystemDiagnostics_Init();

    /* Semph/Mutex and Event Groups Creation */
    SystemControlEventGroup = xEventGroupCreate();

    xSystemStateMutex = xSemaphoreCreateMutex();


    /* Tasks Creation */

    xTaskCreate(SystemMeasurements_CPULoad, "CPULoad", 32, NULL, 2, &CPULoadHandle);

    xTaskCreate(SystemDisplay_DisplaySystemState, "Display", 32, NULL, 2, &DisplayHandle);

    xTaskCreate(SystemControl_UpdateTemperature, "DriverTemperatureMonitor", 32, (void*)&DriverSeat_TempreatureTaskParameters, 3, &DrvTempHandle);

    xTaskCreate(SystemControl_UpdateTemperature, "PassengerTemperatureMonitor", 32, (void*)&PassengerSeat_TempreatureTaskParameters, 3, &PaxTempHandle);

    xTaskCreate(SystemControl_UpdateHeaterIntensity, "DriverHeaterIntensity", 32, (void*)&DriverSeat_HeaterIntensityTaskParameters, 3, &DrvHeaterIntensityHandle);

    xTaskCreate(SystemControl_UpdateHeaterIntensity, "PassengerHeaterIntensity", 32, (void*)&PassengerSeat_HeaterIntensityTaskParameters, 3, &PaxHeaterIntensityHandle);

    xTaskCreate(SystemControl_UpdateHeatingLevel, "DriverHeatingLevel", 32, (void*)&DriverSeat_HeatingLevelTaskParameters, 1, &DrvHeatingLevelHandle);

    xTaskCreate(SystemControl_UpdateHeatingLevel, "PassengerHeatingLevel", 32, (void*)&PassengerSeat_HeatingLevelTaskParameters, 1, &PaxHeatingLevelHandle);

    xTaskCreate(SystemDiagnostics_SaveFailureInfo, "SaveDriverFailure ", 32, (void*)&DriverSeat_SaveFailureInfoTaskParameters, 1, &DrvFailureHandle);

    xTaskCreate(SystemDiagnostics_SaveFailureInfo, "SavePassengerFailure", 32, (void*)&PassengerSeat_SaveFailureInfoTaskParameters, 1,&PaxFailureHandle);

    vTaskSetApplicationTaskTag( CPULoadHandle, ( TaskHookFunction_t ) 1 );

    vTaskSetApplicationTaskTag( DisplayHandle, ( TaskHookFunction_t ) 2 );

    vTaskSetApplicationTaskTag( DrvTempHandle, ( TaskHookFunction_t ) 3 );
    vTaskSetApplicationTaskTag( PaxTempHandle, ( TaskHookFunction_t ) 4 );

    vTaskSetApplicationTaskTag( DrvHeaterIntensityHandle, ( TaskHookFunction_t ) 5 );
    vTaskSetApplicationTaskTag( PaxHeaterIntensityHandle, ( TaskHookFunction_t ) 6 );

    vTaskSetApplicationTaskTag( DrvHeatingLevelHandle, ( TaskHookFunction_t ) 7 );
    vTaskSetApplicationTaskTag( PaxHeatingLevelHandle, ( TaskHookFunction_t ) 8 );

    vTaskSetApplicationTaskTag( DrvFailureHandle, ( TaskHookFunction_t ) 9 );
    vTaskSetApplicationTaskTag( PaxFailureHandle, ( TaskHookFunction_t ) 10 );


    SystemMeasurements_Init();  //last initialization to start the timer before scheduler

    vTaskStartScheduler();

    for(;;);
}
