/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led_Cfg.h
 *
 * Description: Header file for Pre-Compiler configuration used by Led Module
 *
 * Author: Amr Mohamed
 ******************************************************************************/

#ifndef LED_CFG_H_
#define LED_CFG_H_

#include "Dio_Cfg.h"

/* Set the led ON/OFF according to its configuration Positive logic or negative logic */
#define LED_ON          STD_HIGH
#define LED_OFF         STD_LOW

/* Set the LED Port */
#define DRIVER_LED_PORT         DioConf_LED1_PORT_NUM
#define PASSENGER_LED_PORT      DioConf_LED2_PORT_NUM

#define RED_LED_PIN             DioConf_RED_LED_CHANNEL_NUM
#define BLUE_LED_PIN            DioConf_BLUE_LED_CHANNEL_NUM
#define GREEN_LED_PIN           DioConf_GREEN_LED_CHANNEL_NUM

#endif /* LED_CFG_H_ */
