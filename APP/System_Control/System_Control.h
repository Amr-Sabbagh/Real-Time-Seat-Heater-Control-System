/*************************************************
 * System_Control.h
 *
 *  Created on: Nov 5, 2024
 *      Author: Amr
 ************************************************/

#ifndef APP_SYSTEM_CONTROL_SYSTEM_CONTROL_H_
#define APP_SYSTEM_CONTROL_SYSTEM_CONTROL_H_

#include "System_Setup.h"

/*************************************************
 * Module Common MACROs
 ************************************************/

#define DRIVER_SEAT_BUTTON                  (1<<4)
#define DRIVER_SEAT_DRIVING_WHEEL_BUTTON    (1<<0)
#define PASSENGER_SEAT_BUTTON               (1<<0)

#define DRIVER_SEAT_HEATING_LEVEL_EVENT_BITS            (( 1UL << 0UL )|( 1UL << 1UL ))
#define PASSENGER_SEAT_HEATING_LEVEL_EVENT_BITS         ( 1UL << 2UL )

#define DRIVER_SEAT_LEDS_OFFSET             (0U)
#define PASSENGER_SEAT_LEDS_OFFSET          (3U)

/*************************************************
 * Module Functions Parameters Structures
 ************************************************/

typedef struct{
    SeatIndexType_t SeatIndex;
    TaskEventBitsType_t TaskEventBits;
}HeatingLevelTaskParameters_t;

typedef struct{
    SeatIndexType_t SeatIndex;
    SeatLEDsOffsetType_t SeatLEDsOffset;
}HeaterIntensityTaskParameters_t;

typedef struct{
    SeatIndexType_t SeatIndex;
    TaskEventBitsType_t TaskEventBits;
}TemperatureTaskParameters_t;

extern const HeatingLevelTaskParameters_t DriverSeat_HeatingLevelTaskParameters;
extern const HeatingLevelTaskParameters_t PassengerSeat_HeatingLevelTaskParameters;

extern const HeaterIntensityTaskParameters_t DriverSeat_HeaterIntensityTaskParameters;
extern const HeaterIntensityTaskParameters_t PassengerSeat_HeaterIntensityTaskParameters;

extern const TemperatureTaskParameters_t DriverSeat_TempreatureTaskParameters;
extern const TemperatureTaskParameters_t PassengerSeat_TempreatureTaskParameters;


/*************************************************
 * Module Functions  Prototype
 ************************************************/

void SystemControl_Init(void);

void SystemControl_Handler(void);

void SystemControl_UpdateHeatingLevel(void *pvParameters);

void SystemControl_UpdateHeaterIntensity(void *pvParameters);

void SystemControl_UpdateTemperature(void *pvParameters);

#endif /* APP_SYSTEM_CONTROL_SYSTEM_CONTROL_H_ */
