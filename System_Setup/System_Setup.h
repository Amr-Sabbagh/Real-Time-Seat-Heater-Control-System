/*
 * System_Setup.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Amr
 */

#ifndef SYSTEM_SETUP_H_
#define SYSTEM_SETUP_H_

#include "FreeRTOS.h"

#include "task.h"
#include "event_groups.h"
#include "semphr.h"
#include "timers.h"

#include "std_types.h"

/********************************************************************************
 * System Setup MACROS
 ********************************************************************************/

#define NUMBER_OF_SEATS     (2U)

#define DRIVER_SEAT         (0U)
#define PASSENGER_SEAT      (1U)

#define DRIVER_SEAT_FAILURE_EVENT_BITS      ( 1UL << 3UL )
#define PASSENGER_SEAT_FAILURE_EVENT_BITS   ( 1UL << 4UL )

/*********************************************************************************
 * System Data Types
 *********************************************************************************/

/* System State Structure Types */

typedef uint8 TemperatureType_t;

typedef enum{
    SAFE,
    TEMP_OUT_OF_RANGE
}SystemFailure_t;

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
    TemperatureType_t temp;
    SystemFailure_t state;
    HeatingLevel_t seat_heating_level;
    HeaterIntensity_t seat_heater_intensity;
}SeatState_t;

typedef struct{
    SeatState_t seats[NUMBER_OF_SEATS];
}SystemState_t;

/* Tasks' Parameters Structure Types */

typedef uint8 SeatIndexType_t;

typedef TickType_t TaskEventBitsType_t;

typedef uint16 TaskPeriodType_t;

typedef uint8 SeatLEDsOffsetType_t;

typedef struct{
    SeatIndexType_t SeatIndex;
    TaskEventBitsType_t TaskEventBits;
}SaveFailureInfoTaskParameters_t;

typedef struct{
    SeatIndexType_t SeatIndex;
    TaskEventBitsType_t TaskEventBits;
}HeatingLevelTaskParameters_t;

typedef struct{
    SeatIndexType_t SeatIndex;
    TaskEventBitsType_t TaskEventBits;
    TaskPeriodType_t TaskPeriod;
    SeatLEDsOffsetType_t SeatLEDsOffset;
}HeaterIntensityTaskParameters_t;

typedef struct{
    SeatIndexType_t SeatIndex;
    TaskEventBitsType_t TaskEventBits;
    TaskPeriodType_t TaskPeriod;
    SeatLEDsOffsetType_t SeatLEDsOffset;
}TemperatureTaskParameters_t;

/*********************************************************************************
 * System Global Variables
 *********************************************************************************/

uint8 CPU_Load;

extern SystemState_t system_state;

extern SystemState_t* system_state_ptr;

extern SaveFailureInfoTaskParameters_t DriverSeat_SaveFailureInfoTaskParameters;
extern SaveFailureInfoTaskParameters_t PassengerSeat_SaveFailureInfoTaskParameters;

extern HeatingLevelTaskParameters_t DriverSeat_HeatingLevelTaskParameters;
extern HeatingLevelTaskParameters_t PassengerSeat_HeatingLevelTaskParameters;

extern HeaterIntensityTaskParameters_t DriverSeat_HeaterIntensityTaskParameters;
extern HeaterIntensityTaskParameters_t PassengerSeat_HeaterIntensityTaskParameters;

extern TemperatureTaskParameters_t DriverSeat_TempreatureTaskParameters;
extern TemperatureTaskParameters_t PassengerSeat_TempreatureTaskParameters;


/*********************************************************************************
 * System Event Groups, MUTEXs & Tasks Handles
 *********************************************************************************/

EventGroupHandle_t SystemControlEventGroup;

xSemaphoreHandle xSystemStateMutex;

TaskHandle_t    DrvFailureHandle;
TaskHandle_t    PaxFailureHandle;

TaskHandle_t    DrvHeatingLevelHandle;
TaskHandle_t    PaxHeatingLevelHandle;

TaskHandle_t    DrvHeaterIntensityHandle;
TaskHandle_t    PaxHeaterIntensityHandle;

TaskHandle_t    DrvTempHandle;
TaskHandle_t    PaxTempHandle;

TaskHandle_t    DisplayHandle;

TaskHandle_t    CPULoadHandle;

/*********************************************************************************
 * System Functions Prototypes
 *********************************************************************************/

void SystemSetup_Init(void);

#endif /* SYSTEM_SETUP_SYSTEM_SETUP_H_ */
