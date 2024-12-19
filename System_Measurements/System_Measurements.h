/*
 * System_Measurements.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Amr
 */

#ifndef SYSTEM_MEASUREMENTS_SYSTEM_MEASUREMENTS_H_
#define SYSTEM_MEASUREMENTS_SYSTEM_MEASUREMENTS_H_

#include "std_types.h"
#include "System_Setup.h"

/********************************************************************************
 * System Measurements MACROS
 ********************************************************************************/

#define RUNTIME_MEASUREMENTS_TASK_PERIODICITY       (1000U)

/********************************************************************************
 * System Measurements Variables
 ********************************************************************************/

uint32 ullTasksOutTime[11];
uint32 ullTasksInTime[11];
uint32 ullTasksTotalTime[11];

/********************************************************************************
 * System_ Measurements Functions Prototypes
 ********************************************************************************/

void SystemMeasurements_Init(void);
void SystemMeasurements_CPULoad(void* pvParameters);

#endif /* SYSTEM_MEASUREMENTS_SYSTEM_MEASUREMENTS_H_ */
