#ifndef BSP_H_
#define BSP_H_

/**
 * @file bsp.h
 * @brief Board Support Package (BSP) configurations for OLIMEXINO-STM32.
 *
 * This BSP file provides definitions for system configurations, peripheral
 * clock settings, baud rates for serial communication, and identifiers for
 * various peripherals for the OLIMEXINO-STM32 board, which utilizes the
 * STM32F103RB microcontroller.
 */

/** @defgroup System_Configurations System Configurations
 *  @brief System-wide settings and configurations.
 *  @{
 */
#define SYSTEM_CLOCK 					(8000000)
#define BAUDRATE 						(115200)
#define TIM2_PRESCALER_VALUE_FOR_100MS 	(31999)
#define TIM2_RELOAD_VALUE_FOR_100MS 	(24)
#define SERIAL_BUFFER_SIZE 				(96)
#define TIMER_TICK_RATE 				(100)
#define TIM3_PRESCALER_VALUE_FOR_1000MS (7999)
#define TIM3_RELOAD_VALUE_FOR_1000MS 	(999)
/** @} */


/** @defgroup Peripheral_Identifiers Peripheral Identifiers
 *  @brief Identifiers for peripherals on the OLIMEXINO-STM32 board.
 *  @{
 */
#define SERIAL_PORT_1 0
#define SERIAL_PORT_2 1
#define SERIAL_PORT_3 2
#define GPIO_PORT_A 3
#define GPIO_PORT_B 4
#define GPIO_PORT_C 5
#define GPIO_PORT_D 6
#define BASIC_TIMER_6 7
#define BASIC_TIMER_7 8
#define BASIC_TIMER_2 9
#define ADC1 10
#define ADC2 11
#define BASIC_TIMER_3 12
#define RESET 0
/** @} */


#endif /* BSP_H_ */
