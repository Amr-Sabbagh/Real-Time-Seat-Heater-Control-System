/*************************************************
 * System_Diagnostics.h
 *
 *  Created on: Nov 15, 2024
 *      Author: Amr
 ************************************************/
#ifndef APP_SYSTEM_DIAGNOSTICS_SYSTEM_DIAGNOSTICS_H_
#define APP_SYSTEM_DIAGNOSTICS_SYSTEM_DIAGNOSTICS_H_

#include "System_Setup.h"

#include "Std_Types.h"

typedef struct{
    TickType_t time_stamp;
    HeatingLevel_t last_seat_heating_level;
}DiagnosticsInformation_t;

typedef struct{
    DiagnosticsInformation_t seats[NUMBER_OF_SEATS];
}SystemDiagnostics_t;

typedef struct{
    SeatIndexType_t SeatIndex;
    TaskEventBitsType_t TaskEventBits;
}SaveFailureInfoTaskParameters_t;

extern const SaveFailureInfoTaskParameters_t DriverSeat_SaveFailureInfoTaskParameters;
extern const SaveFailureInfoTaskParameters_t PassengerSeat_SaveFailureInfoTaskParameters;

/*************************************************
 * Module Functions  Prototype
 ************************************************/

void SystemDiagnostics_Init(void);

void SystemDiagnostics_SaveFailureInfo(void *pvParameters);

#endif /* APP_SYSTEM_DIAGNOSTICS_SYSTEM_DIAGNOSTICS_H_ */
