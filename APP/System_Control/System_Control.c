/*************************************************
 * System_Control.c
 *
 *  Created on: Nov 5, 2024
 *      Author: Amr
 ************************************************/

#include "System_Control.h"

#include "Button.h"
#include "Led.h"
#include "POT.h"

#include "tm4c123gh6pm_registers.h"

const HeatingLevelTaskParameters_t DriverSeat_HeatingLevelTaskParameters = { DRIVER_SEAT, DRIVER_SEAT_HEATING_LEVEL_EVENT_BITS };
const HeatingLevelTaskParameters_t PassengerSeat_HeatingLevelTaskParameters = { PASSENGER_SEAT, PASSENGER_SEAT_HEATING_LEVEL_EVENT_BITS };

const HeaterIntensityTaskParameters_t DriverSeat_HeaterIntensityTaskParameters = { DRIVER_SEAT, DRIVER_SEAT_LEDS_OFFSET };
const HeaterIntensityTaskParameters_t PassengerSeat_HeaterIntensityTaskParameters = { PASSENGER_SEAT, PASSENGER_SEAT_LEDS_OFFSET };

const TemperatureTaskParameters_t DriverSeat_TempreatureTaskParameters = { DRIVER_SEAT, DRIVER_SEAT_FAILURE_EVENT_BITS };
const TemperatureTaskParameters_t PassengerSeat_TempreatureTaskParameters = { PASSENGER_SEAT, PASSENGER_SEAT_FAILURE_EVENT_BITS };


void SystemControl_Init(void)
{
    Button_Init();
    Led_Init();
    POT_Init();
}
void SystemControl_Handler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdTRUE;

    if(GPIO_PORTF_RIS_REG & PASSENGER_SEAT_BUTTON)           /* PF0 handler code */
    {
        xEventGroupSetBitsFromISR(SystemControlEventGroup, PASSENGER_SEAT_HEATING_LEVEL_EVENT_BITS, &xHigherPriorityTaskWoken);
        GPIO_PORTF_ICR_REG   |= (PASSENGER_SEAT_BUTTON);       /* Clear Trigger flag for PF0 (Interrupt Flag) */
    }
    else if(GPIO_PORTF_RIS_REG & DRIVER_SEAT_BUTTON)      /* PF4 handler code */
    {
        xEventGroupSetBitsFromISR(SystemControlEventGroup, DRIVER_SEAT_HEATING_LEVEL_EVENT_BITS, &xHigherPriorityTaskWoken);
        GPIO_PORTF_ICR_REG   |= (DRIVER_SEAT_BUTTON);       /* Clear Trigger flag for PF4 (Interrupt Flag) */
    }
    else if(GPIO_PORTB_RIS_REG & DRIVER_SEAT_DRIVING_WHEEL_BUTTON)      /* PB0 handler code */
    {
        xEventGroupSetBitsFromISR(SystemControlEventGroup, DRIVER_SEAT_HEATING_LEVEL_EVENT_BITS, &xHigherPriorityTaskWoken);
        GPIO_PORTB_ICR_REG   |= (DRIVER_SEAT_DRIVING_WHEEL_BUTTON);       /* Clear Trigger flag for PB4 (Interrupt Flag) */
    }

    portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}

void SystemControl_UpdateHeatingLevel(void *pvParameters)
{
    HeatingLevelTaskParameters_t* ptr = /*(HeatingLevelTaskParameters_t*)*/pvParameters;

    for(;;)
    {
        xEventGroupWaitBits( SystemControlEventGroup,   /* The event group to read. */
                             ptr->TaskEventBits,        /* Bits to test. */
                             pdTRUE,                    /* Clear bits on exit if the unblock condition is met. */
                             pdFALSE,                   /* Don't wait for all bits. */
                             portMAX_DELAY);            /* Don't time out. */
        vTaskDelay(pdMS_TO_TICKS(100));

        if(xSemaphoreTake(xSystemStateMutex, portMAX_DELAY) == pdTRUE)
        {
            switch(System_State_Ptr->seats[ptr->SeatIndex].seat_heating_level)
            {
            case NOT_CONTROLLED:
                System_State_Ptr->seats[ptr->SeatIndex].seat_heating_level= LOW_HEATING; break;
            case LOW_HEATING:
                System_State_Ptr->seats[ptr->SeatIndex].seat_heating_level= MEDIUM_HEATING; break;
            case MEDIUM_HEATING:
                System_State_Ptr->seats[ptr->SeatIndex].seat_heating_level= HIGH_HEATING; break;
            case HIGH_HEATING:
                System_State_Ptr->seats[ptr->SeatIndex].seat_heating_level= NOT_CONTROLLED; break;
            }

            xSemaphoreGive(xSystemStateMutex);
        }
    }
}

/*
 * Description:*********************************************
 */
void SystemControl_UpdateHeaterIntensity(void *pvParameters)
{
    HeaterIntensityTaskParameters_t* ptr = /*(HeaterIntensityTaskParameters_t*)*/pvParameters;

    //TickType_t xLastWakeTime = xTaskGetTickCount();

    Temperatrue_t TemperatureDifference;

    for(;;)
    {
        //vTaskDelayUntil( &xLastWakeTime,200/*pdMS_TO_TICKS( ptr->TaskPeriod )*/);
        vTaskDelay(pdMS_TO_TICKS(100));

        if(xSemaphoreTake(xSystemStateMutex, portMAX_DELAY) == pdTRUE)
        {
            switch(System_State_Ptr->seats[ptr->SeatIndex].sensor)
            {
                case SAFE:
                {
                    TemperatureDifference = System_State_Ptr->seats[ptr->SeatIndex].seat_heating_level-System_State_Ptr->seats[ptr->SeatIndex].temp;

                    if(TemperatureDifference >= 10)
                    {
                        System_State_Ptr->seats[ptr->SeatIndex].seat_heater_intensity=HIGH_INTENSITY;
                        Led_SetOff(RED_LED,ptr->SeatLEDsOffset);
                        Led_SetOn(GREEN_LED,ptr->SeatLEDsOffset);
                        Led_SetOn(BLUE_LED,ptr->SeatLEDsOffset);
                    }
                    else if(TemperatureDifference < 10 && TemperatureDifference >=5)
                    {
                        System_State_Ptr->seats[ptr->SeatIndex].seat_heater_intensity=MEDIUM_INTENSITY;
                        Led_SetOff(RED_LED,ptr->SeatLEDsOffset);
                        Led_SetOff(GREEN_LED,ptr->SeatLEDsOffset);
                        Led_SetOn(BLUE_LED,ptr->SeatLEDsOffset);
                    }
                    else if(TemperatureDifference < 5 && TemperatureDifference >=2)
                    {
                        System_State_Ptr->seats[ptr->SeatIndex].seat_heater_intensity=LOW_INTENSITY;
                        Led_SetOff(RED_LED,ptr->SeatLEDsOffset);
                        Led_SetOff(BLUE_LED,ptr->SeatLEDsOffset);
                        Led_SetOn(GREEN_LED,ptr->SeatLEDsOffset);
                    }
                    else if(TemperatureDifference < 2)
                    {
                        System_State_Ptr->seats[ptr->SeatIndex].seat_heater_intensity=DISABLED;
                        Led_SetOff(RED_LED,ptr->SeatLEDsOffset);
                        Led_SetOff(GREEN_LED,ptr->SeatLEDsOffset);
                        Led_SetOff(BLUE_LED,ptr->SeatLEDsOffset);
                    }
                    break;
                }
                case TEMP_OUT_OF_RANGE:
                {
                    System_State_Ptr->seats[ptr->SeatIndex].seat_heater_intensity=DISABLED;
                    Led_SetOn(RED_LED,ptr->SeatLEDsOffset);
                    Led_SetOff(BLUE_LED,ptr->SeatLEDsOffset);
                    Led_SetOff(GREEN_LED,ptr->SeatLEDsOffset);
                    break;
                }
            }

            xSemaphoreGive(xSystemStateMutex);
        }
    }
}

/*
 * Description:*****************************************
 */
void SystemControl_UpdateTemperature(void *pvParameters)
{
    TemperatureTaskParameters_t* ptr = /*(TemperatureTaskParameters_t*)*/pvParameters;

    TickType_t xLastWakeTime = xTaskGetTickCount();

    Temperatrue_t Temperature;

    for(;;)
    {
        vTaskDelayUntil( &xLastWakeTime,200);

        Temperature=POT_Read(ptr->SeatIndex);

        if(xSemaphoreTake(xSystemStateMutex, portMAX_DELAY) == pdTRUE)
        {
            if( Temperature > 40 || Temperature < 5 )
            {
                System_State_Ptr->seats[ptr->SeatIndex].sensor=TEMP_OUT_OF_RANGE;
                System_State_Ptr->seats[ptr->SeatIndex].temp=Temperature;

                xEventGroupSetBits(SystemControlEventGroup, ptr->TaskEventBits);
            }
            else
            {
                System_State_Ptr->seats[ptr->SeatIndex].sensor=SAFE;
                System_State_Ptr->seats[ptr->SeatIndex].temp=Temperature;
            }

            xSemaphoreGive(xSystemStateMutex);
        }
    }
}
