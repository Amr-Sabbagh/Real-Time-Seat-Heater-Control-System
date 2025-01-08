 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H

/*
 * Module Version 1.0.0
 */
#define DIO_CFG_SW_MAJOR_VERSION              (1U)
#define DIO_CFG_SW_MINOR_VERSION              (0U)
#define DIO_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                (STD_OFF)

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES              (11U)

/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_LED1_CHANNEL_ID_INDEX        (uint8)0x00
#define DioConf_SW1_CHANNEL_ID_INDEX         (uint8)0x01

/* DIO Configured Port ID's  */
#define DioConf_LED1_PORT_NUM                 (Dio_PortType)5 /* PORTF */
#define DioConf_LED2_PORT_NUM                 (Dio_PortType)1 /* PORTB */

#define DioConf_CONSOLE_BUTTONS_PORT_NUM            (Dio_PortType)5 /* PORTF */
#define DioConf_DRIVING_WHEEL_BUTTONS_PORT_NUM      (Dio_PortType)1 /* PORTB */

#define DioConf_POTENTIOMETERS_PORT_NUM             (Dio_PortType)4 /* PORTE */

/* DIO Configured Channel ID's */
#define DioConf_DRIVER_BUTTON_CHANNEL_NUM           (Dio_ChannelType)4 /* Pin 4 in PORTF */
#define DioConf_PASSENGER_BUTTON_CHANNEL_NUM        (Dio_ChannelType)0 /* Pin 0 in PORTF */
#define DioConf_DRIVING_WHEEL_BUTTON_CHANNEL_NUM    (Dio_ChannelType)0 /* Pin 0 in PORTB */


#define DioConf_RED_LED_CHANNEL_NUM                 (Dio_ChannelType)1 /* Pin 1 in PORTF */
#define DioConf_BLUE_LED_CHANNEL_NUM                (Dio_ChannelType)2 /* Pin PF2 */
#define DioConf_GREEN_LED_CHANNEL_NUM               (Dio_ChannelType)3 /* Pin PF3 */

#define DioConf_POT1_CHANNEL_NUM                    (Dio_ChannelType)3 /* Pin PE3 */
#define DioConf_POT2_CHANNEL_NUM                    (Dio_ChannelType)2 /* Pin PE2 */

#endif /* DIO_CFG_H */
