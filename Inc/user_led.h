#ifndef APP_USER_LED_H_
#define APP_USER_LED_H_

#include "gpio.h"
#include "rcc.h"
#include "bsp.h"


void user_led_init(void);
void user_led_toogle(void);
void user_led_on(void);
void user_led_off(void);


#endif /* APP_USER_LED_H_*/
