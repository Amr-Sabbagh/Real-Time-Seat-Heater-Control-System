/*
 * System_Diagnostics.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Amr
 */

#ifndef SYSTEM_DIAGNOSTICS_H_
#define SYSTEM_DIAGNOSTICS_H_

#include "System_Setup.h"

#include "std_types.h"

/*
 * System Diagnostics Macros
 ***************************************/

/*
 * System Diagnostics Data Types
 ***************************************/

/**********Structure to hold diagnostics information**********/
typedef struct{
    TickType_t time_stamp;
    HeatingLevel_t last_seat_heating_level;
}DiagnosticsInformation_t;

/**********Type definition for System Diagnostics to be stored in RAM**********/
typedef struct{
    DiagnosticsInformation_t seats[NUMBER_OF_SEATS];
}SystemDiagnostics_t;

/**********Defining an array of structure for system diagnostics**********/
extern SystemDiagnostics_t system_diagnostics;

/**********Type definition for a pointer to the system structure**********/
extern SystemDiagnostics_t* system_diagnostics_ptr;

/*
 * System Diagnostics Tasks' Parameters
 ***************************************/

extern SaveFailureInfoTaskParameters_t DriverSeat_SaveFailureInfoTaskParameters;
extern SaveFailureInfoTaskParameters_t PassengerSeat_SaveFailureInfoTaskParameters;

/*
 * System Diagnostics Function
 * Prototypes
 ***************************************/

void SystemDiagnostics_Init(void);

void SystemDiagnostics_SaveFailureInfo(void *pvParameters);

#endif /* SYSTEM_DIAGNOSTICS_SYSTEM_DIAGNOSTICS_H_ */
