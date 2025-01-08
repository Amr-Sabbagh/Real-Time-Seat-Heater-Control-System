/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button_Cfg.h
 *
 * Description: Header file for Pre-Compiler configuration used by Button Module
 *
 * Author: Amr Mohamed
 ******************************************************************************/

#ifndef BUTTON_CFG_H_
#define BUTTON_CFG_H_

#include "Dio_Cfg.h"

/* Set the Button Port */
#define CONSOLE_BUTTONS_PORT                DioConf_CONSOLE_BUTTONS_PORT_NUM
#define DRIVING_WHEEL_BUTTON_PORT_NUM       DioConf_DRIVING_WHEEL_BUTTONS_PORT_NUM

/* Set the Button Pin Number */
#define DRIVER_BUTTON_PIN               DioConf_DRIVER_BUTTON_CHANNEL_NUM
#define PASSENGER_BUTTON_PIN            DioConf_PASSENGER_BUTTON_CHANNEL_NUM
#define DRIVING_WHEEL_BUTTON_PIN        DioConf_DRIVING_WHEEL_BUTTON_CHANNEL_NUM

#define PORTF_INTERRUPT_PRIORITY    (5U)
#define PORTB_INTERRUPT_PRIORITY    (4U)

#endif /* BUTTON_CFG_H_ */
