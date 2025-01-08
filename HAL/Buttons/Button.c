/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.c
 *
 * Description: Source file for Button Module.
 *
 * Author: Amr Mohamed
 ******************************************************************************/
#include "Dio.h"
#include "Port.h"
#include "Button.h"
#include "Button_Cfg.h"
#include "tm4c123gh6pm_registers.h"

/* Button Configurations Structure */
Port_ConfigType g_Button_Config={
                                        CONSOLE_BUTTONS_PORT, DRIVER_BUTTON_PIN, PORT_PIN_IN, PULL_UP, PORT_PIN_LEVEL_HIGH, PORT_PIN_MODE_DIO, STD_OFF, STD_OFF,
                                        CONSOLE_BUTTONS_PORT, PASSENGER_BUTTON_PIN, PORT_PIN_IN, PULL_UP, PORT_PIN_LEVEL_HIGH, PORT_PIN_MODE_DIO, STD_OFF, STD_OFF,
                                        DRIVING_WHEEL_BUTTON_PORT_NUM, DRIVING_WHEEL_BUTTON_PIN, PORT_PIN_IN, PULL_UP, PORT_PIN_LEVEL_HIGH, PORT_PIN_MODE_DIO, STD_OFF, STD_OFF,

};

//Dio_ConfigChannel gd_Button_Config={
//                                    CONSOLE_BUTTONS_PORT,DRIVER_BUTTON_PIN,
//                                    CONSOLE_BUTTONS_PORT,PASSENGER_BUTTON_PIN,
//                                    DRIVING_WHEEL_BUTTON_PORT_NUM,DRIVING_WHEEL_BUTTON_PIN,
//};

static void Button_interrupt(void);
/*******************************************************************************************************************/
void Button_Init(void)
{
    Port_Init(&g_Button_Config);
    //Dio_Init(&gd_Button_Config);
    Button_interrupt();
}

/*******************************************************************************************************************/
static void Button_interrupt(void)
{
    GPIO_PORTF_IS_REG    &= ~((1<<4)|(1<<0));      /* PF4 detect edges */
    GPIO_PORTF_IBE_REG   &= ~((1<<4)|(1<<0));      /* PF4 will detect a certain edge */
    GPIO_PORTF_IEV_REG   &= ~((1<<4)|(1<<0));      /* PF4 will detect a falling edge */
    GPIO_PORTF_ICR_REG   |= ((1<<4)|(1<<0));       /* Clear Trigger flag for PF4 (Interrupt Flag) */
    GPIO_PORTF_IM_REG    |= ((1<<4)|(1<<0));       /* Enable Interrupt on PF4 pin */

    GPIO_PORTB_IS_REG    &= ~(1<<0);      /* PB0 detect edges */
    GPIO_PORTB_IBE_REG   &= ~(1<<0);      /* PF4 will detect a certain edge */
    GPIO_PORTB_IEV_REG   &= ~(1<<0);      /* PF4 will detect a falling edge */
    GPIO_PORTB_ICR_REG   |= (1<<0);       /* Clear Trigger flag for PF4 (Interrupt Flag) */
    GPIO_PORTB_IM_REG    |= (1<<0);       /* Enable Interrupt on PF4 pin */

    /* Set GPIO PORTB priority as 5 by set Bit number 5, 6 and 7 with value 2 */
    //NVIC_PRI0_REG = (NVIC_PRI0_REG & PORTB_PRIORITY_MASK) | (PORTB_INTERRUPT_PRIORITY << PORTB_PRIORITY_BITS_POS);
    NVIC_PRI0_REG = 0xA0;



    /* Set GPIO PORTF priority as 5 by set Bit number 21, 22 and 23 with value 2 */
    NVIC_PRI7_REG = (NVIC_PRI7_REG & PORTF_PRIORITY_MASK) | (PORTF_INTERRUPT_PRIORITY<<PORTF_PRIORITY_BITS_POS);
    NVIC_EN0_REG         |= 0x40000002;   /* Enable NVIC Interrupt for GPIO PORTB/PORTF by set bit number 30 and 1 in EN0 Register */
}
/*******************************************************************************************************************/
