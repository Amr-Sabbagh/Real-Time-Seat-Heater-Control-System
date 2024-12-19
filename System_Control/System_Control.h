/*
 * System_Control.h
 *
 *  Created on: Oct 28, 2024
 *      Author: Amr
 */

#ifndef SYSTEM_CONTROL_H_
#define SYSTEM_CONTROL_H_

#include "System_Setup.h"

/*********************************************************************************
 * System_Control MACROS
 *********************************************************************************/

#define DRIVER_SEAT_BUTTON                  (1<<4)
#define DRIVER_SEAT_DRIVING_WHEEL_BUTTON    (1<<0)
#define PASSENGER_SEAT_BUTTON               (1<<0)

#define DRIVER_SEAT_LEDS_OFFSET             (0U)
#define PASSENGER_SEAT_LEDS_OFFSET          (3U)

#define DRIVER_SEAT_HEATING_LEVEL_EVENT_BITS            (( 1UL << 0UL )|( 1UL << 1UL))
#define PASSENGER_SEAT_HEATING_LEVEL_EVENT_BITS         ( 1UL << 2UL )

#define HEATER_INTENSITY_TASK_PERIOD    (200U)
#define TEMPERATURE_TASK_PERIOD         (200U)


/*********************************************************************************
 * System_Control Global Variables
 *********************************************************************************/

extern HeatingLevelTaskParameters_t DriverSeat_HeatingLevelTaskParameters;
extern HeatingLevelTaskParameters_t PassengerSeat_HeatingLevelTaskParameters;

extern HeaterIntensityTaskParameters_t DriverSeat_HeaterIntensityTaskParameters;
extern HeaterIntensityTaskParameters_t PassengerSeat_HeaterIntensityTaskParameters;

extern TemperatureTaskParameters_t DriverSeat_TempreatureTaskParameters;
extern TemperatureTaskParameters_t PassengerSeat_TempreatureTaskParameters;

/*********************************************************************************
 * System_Control Functions Prototypes
 *********************************************************************************/

void SystemControl_Init(void);

void SystemControl_Handler(void);

void SystemControl_UpdateHeatingLevel(void *pvParameters);

void SystemControl_UpdateHeaterIntensity(void *pvParameters);

void SystemControl_UpdateTemperature(void *pvParameters);

#endif /* SYSTEM_CONTROL_SYSTEM_CONTROL_H_ */
