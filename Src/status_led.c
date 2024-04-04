#include "status_led.h"

/*Status led library. Wrapped low level gpio functions in user functions  */

static GPIO_Handler_t status_led;

/**
 * @brief Initializes the status LED.
 *
 * Configures the GPIO pin associated with the status LED as an output and
 * sets the initial state to off (low).
 */
void status_led_init()
{
	rcc_enable_clock(GPIO_PORT_A);
	gpio_init(&status_led,GPIOA_BASE_ADDRESS,GPIO_pin_5,GPIO_General_purpose_output_push_pull,GPIO_Output_mode_max_speed_10_MHz);
	gpio_config(&status_led);
	gpio_write_pin(&status_led,0);
}

/**
 * @brief Toggles the state of the status LED.
 *
 * If the LED is on, it turns it off. If the LED is off, it turns it on.
 */
void status_led_toogle()
{
	gpio_toogle_pin(&status_led);
}

/**
 * @brief Turns on the status LED.
 *
 * Sets the status LED pin high, turning the LED on.
 */
void status_led_on()
{
	gpio_write_pin(&status_led,1);
}

/**
 * @brief Turns off the status LED.
 *
 * Sets the status LED pin low, turning the LED off.
 */
void status_led_off()
{
	gpio_write_pin(&status_led,0);
}

