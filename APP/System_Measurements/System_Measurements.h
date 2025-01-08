/*************************************************
 * System_Measurements.h
 *
 *  Created on: Nov 5, 2024
 *      Author: Amr
 ************************************************/

#ifndef APP_SYSTEM_MEASUREMENTS_SYSTEM_MEASUREMENTS_H_
#define APP_SYSTEM_MEASUREMENTS_SYSTEM_MEASUREMENTS_H_

#include "System_Setup.h"

uint8 CPU_Load;

uint32 ullTasksOutTime[11];
uint32 ullTasksInTime[11];
uint32 ullTasksTotalTime[11];

/*************************************************
 * Module Functions  Prototype
 ************************************************/

void SystemMeasurements_Init(void);

void SystemMeasurements_CPULoad(void* pvPArameters);

#endif /* APP_SYSTEM_MEASUREMENTS_SYSTEM_MEASUREMENTS_H_ */
