/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.c
 *
 * Description: Source file for Led Module.
 *
 * Author: Amr Mohamed
 ******************************************************************************/
#include "Port.h"
#include "Dio.h"
#include "Led.h"
#include "Led_Cfg.h"

/* LED Configurations Structure */
Port_ConfigType  g_LED_Config={
                                        DRIVER_LED_PORT,RED_LED_PIN,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PIN_MODE_DIO,STD_OFF,STD_OFF,
                                        DRIVER_LED_PORT,BLUE_LED_PIN,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PIN_MODE_DIO,STD_OFF,STD_OFF,
                                        DRIVER_LED_PORT,GREEN_LED_PIN,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PIN_MODE_DIO,STD_OFF,STD_OFF,

                                        PASSENGER_LED_PORT,RED_LED_PIN,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PIN_MODE_DIO,STD_OFF,STD_OFF,
                                        PASSENGER_LED_PORT,BLUE_LED_PIN,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PIN_MODE_DIO,STD_OFF,STD_OFF,
                                        PASSENGER_LED_PORT,GREEN_LED_PIN,PORT_PIN_OUT,OFF,PORT_PIN_LEVEL_LOW,PORT_PIN_MODE_DIO,STD_OFF,STD_OFF,
};

//Dio_ConfigChannel gd_LED_Config={
//                                 DRIVER_LED_PORT,RED_LED_PIN,
//                                 DRIVER_LED_PORT,BLUE_LED_PIN,
//                                 DRIVER_LED_PORT,GREEN_LED_PIN,
//
//                                 PASSENGER_LED_PORT,RED_LED_PIN,
//                                 PASSENGER_LED_PORT,BLUE_LED_PIN,
//                                 PASSENGER_LED_PORT,GREEN_LED_PIN,
//
//};
/*********************************************************************************************/
void Led_Init(void)
{
    Port_Init(&g_LED_Config);
    //Dio_Init(&gd_LED_Config);
}

/*********************************************************************************************/
void Led_SetOn(uint8 pin, uint8 offset)
{
    Dio_WriteChannel((pin+offset),LED_ON);  /* LED ON */
}

/*********************************************************************************************/
void Led_SetOff(uint8 pin, uint8 offset)
{
    Dio_WriteChannel((pin+offset),LED_OFF); /* LED OFF */
}
