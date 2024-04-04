
#ifndef APP_STATUS_LED_H_
#define APP_STATUS_LED_H_

#include "gpio.h"
#include "rcc.h"
#include "bsp.h"

/**
 * @brief Initializes the status LED.
 *
 * Sets up the GPIO port and pin for the status LED, including output mode and speed.
 * Ensures the GPIO clock for the corresponding port is enabled before configuring the pin.
 */
void status_led_init();

/**
 * @brief Toggles the state of the status LED.
 *
 * Switches the status LED from on to off, or vice versa.
 */
void status_led_toogle();

/**
 * @brief Turns on the status LED.
 *
 * Sets the status LED pin high, turning the LED on.
 */
void status_led_on();

/**
 * @brief Turns off the status LED.
 *
 * Sets the status LED pin low, turning the LED off.
 */
void status_led_off();


#endif /* APP_STATUS_LED_H_ */
