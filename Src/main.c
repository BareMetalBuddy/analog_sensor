#include <stdint.h>
#include <stdlib.h>
#include "rcc.h"
#include "status_led.h"
#include "user_led.h"
#include "task.h"
#include "timx.h"
#include "bsp.h"
#include "analog_sensor_1.h"
#include "nvic.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

TIMx_Handler_t timx_handler;
TIMx_Handler_t timx_handler_t3; // to configure timer 3

#define NUMBER_OF_TASK (2)
void task_1(void);
void task_2(void);

Task_t task[NUMBER_OF_TASK];

/* target  : STM32F103RB*/
/* details : just a basic example of how to read ADC channel using a bare-metal scheduler based on timer 2  */

int main(void)
{
	/*timer 2 is set with values for 100ms*/
	rcc_enable_clock(BASIC_TIMER_2);
	timx_init(&timx_handler,TIM2_BASE_ADDRESS,TIM2_PRESCALER_VALUE_FOR_100MS, TIM2_RELOAD_VALUE_FOR_100MS);
	timx_config(&timx_handler);
	timx_update_interrupt(&timx_handler, 1);

	status_led_init();
	user_led_init();
	analog_sensor_1_init();

	/*timer 3 is set to do an interruption each 1 second*/
	rcc_enable_clock(BASIC_TIMER_3);
	timx_init(&timx_handler_t3,TIM3_BASE_ADDRESS,TIM3_PRESCALER_VALUE_FOR_1000MS,TIM3_RELOAD_VALUE_FOR_1000MS);
	timx_config(&timx_handler_t3);
	timx_update_interrupt(&timx_handler_t3, 1);
	nvic_set_irq_priority(BASIC_TIMER_3,1);
	nvic_enable_irq(BASIC_TIMER_3);

	///////////////////////////////////////////////

	task_init(&task[0],500,0,&task_1,UNBLOCKED);
	task_init(&task[1],300,0,&task_2,UNBLOCKED);

	while(1){

		if((timx_handler.timx->TIMx_SR) & ((uint16_t)(0x0001))){
			timx_handler.timx->TIMx_SR &= ~((uint16_t)(0x0001));
	    	for (uint8_t i=0; i < NUMBER_OF_TASK; i++) {
	    		if (task[i].elapsed_time >= task[i].ticks && task[i].state) {
	    			task[i].function();
	    		    task[i].elapsed_time = 0;
	    		}
	    		task[i].elapsed_time += TIMER_TICK_RATE; 	/*Increment the elapsed time of the task by the timer tick rate*/
	    	}
	    }
	}
}


void task_1(void)
{
	status_led_toogle();
}

void task_2(void)
{
	uint32_t analog_value = analog_sensor_1_read();
}

void TIM3_IRQHandler(void)
{
	if ((timx_handler_t3.timx->TIMx_SR) & 0x01) {
		(timx_handler_t3.timx->TIMx_SR) &= ~0x01;
	}

	user_led_toogle();
}



