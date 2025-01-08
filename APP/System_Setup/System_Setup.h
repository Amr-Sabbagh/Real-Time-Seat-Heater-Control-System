/*************************************************
 * System_Setup.h
 *
 *  Created on: Nov 5, 2024
 *      Author: Amr
 ************************************************/

#ifndef APP_SYSTEM_SETUP_SYSTEM_SETUP_H_
#define APP_SYSTEM_SETUP_SYSTEM_SETUP_H_

#include "System_Setup_Cfg.h"

#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"
#include "semphr.h"
#include "timers.h"

/*************************************************
 * System Common MACROS
 ************************************************/

#define NUMBER_OF_SEATS        (2U)
#define DRIVER_SEAT            (0U)
#define PASSENGER_SEAT         (1U)

#define DRIVER_SEAT_FAILURE_EVENT_BITS      ( 1UL << 3UL )
#define PASSENGER_SEAT_FAILURE_EVENT_BITS   ( 1UL << 4UL )

/*************************************************
 * System Types Definition
 ************************************************/

typedef sint8 Temperatrue_t;

typedef enum{
    SAFE,
    TEMP_OUT_OF_RANGE
}SensorState_t;

typedef enum{
    NOT_CONTROLLED,
    LOW_HEATING=25,
    MEDIUM_HEATING=30,
    HIGH_HEATING=35
}HeatingLevel_t;

typedef enum{
    DISABLED,
    LOW_INTENSITY,
    MEDIUM_INTENSITY,
    HIGH_INTENSITY
}HeaterIntensity_t;


typedef struct{
    Temperatrue_t temp;
    SensorState_t sensor;
    HeatingLevel_t seat_heating_level;
    HeaterIntensity_t seat_heater_intensity;
}SeatState_t;

typedef struct{
    SeatState_t seats[NUMBER_OF_SEATS];
}SystemState_t;

typedef uint8       SeatIndexType_t;

typedef TickType_t  TaskEventBitsType_t;

typedef uint8       SeatLEDsOffsetType_t;

/*************************************************
 * Module External Variables
 ************************************************/

extern SystemState_t    System_State;
extern SystemState_t*   System_State_Ptr;

extern uint8            CPU_Load;

/*************************************************
 * System Event Groups, MUTEXs & Tasks Handles
 ************************************************/

xSemaphoreHandle    xSystemStateMutex;

EventGroupHandle_t  SystemControlEventGroup;

/*************************************************
 * System Tasks' Handles
 ************************************************/

TaskHandle_t    DisplayTaskHandle;

TaskHandle_t    MeasurementsTaskHandle;

TaskHandle_t    DrvHeatingLevelHandle;
TaskHandle_t    PaxHeatingLevelHandle;

TaskHandle_t    DrvHeaterIntensityHandle;
TaskHandle_t    PaxHeaterIntensityHandle;

TaskHandle_t    DrvTempHandle;
TaskHandle_t    PaxTempHandle;

TaskHandle_t    DrvFailureHandle;
TaskHandle_t    PaxFailureHandle;

/*************************************************
 * Module Functions  Prototype
 ************************************************/
void SystemSetup_Init(void);

#endif /* APP_SYSTEM_SETUP_SYSTEM_SETUP_H_ */
