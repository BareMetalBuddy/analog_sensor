#include "user_led.h"

static GPIO_Handler_t user_led;

void user_led_init(void)
{
	rcc_enable_clock(GPIO_PORT_A);
	gpio_init(&user_led,GPIOA_BASE_ADDRESS,GPIO_pin_1,GPIO_General_purpose_output_push_pull,GPIO_Output_mode_max_speed_10_MHz);
	gpio_config(&user_led);
	gpio_write_pin(&user_led,0);
}

void user_led_toogle(void)
{
	gpio_toogle_pin(&user_led);
}

void user_led_on(void)
{
	gpio_write_pin(&user_led,1);
}

void user_led_off(void)
{
	gpio_write_pin(&user_led,0);
}
