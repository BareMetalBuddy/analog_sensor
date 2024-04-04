#include "rcc.h"

void rcc_enable_clock(uint8_t module)
{
	switch(module)
	{
		case SERIAL_PORT_1:
			RCC_USART1_CLOCK_ENABLE();
			break;

		case SERIAL_PORT_2:
			RCC_USART2_CLOCK_ENABLE();
			break;

		case SERIAL_PORT_3:
			RCC_USART3_CLOCK_ENABLE();
			break;

		case GPIO_PORT_A:
			RCC_GPIOA_CLOCK_ENABLE();
			break;

		case GPIO_PORT_B:
			RCC_GPIOB_CLOCK_ENABLE();
			break;

		case GPIO_PORT_C:
			RCC_GPIOC_CLOCK_ENABLE();
			break;

		case BASIC_TIMER_6:
			RCC_TIM6_CLOCK_ENABLE();
			break;

		case BASIC_TIMER_7:
			RCC_TIM7_CLOCK_ENABLE();
			break;

		case BASIC_TIMER_2:
			RCC_TIM2_CLOCK_ENABLE();
			break;

		case ADC1:
			ADC1_CLOCK_ENABLE();
			break;

		case ADC2:
			ADC2_CLOCK_ENABLE();
			break;

		case BASIC_TIMER_3:
			RCC_TIM3_CLOCK_ENABLE();
			break;

		default:
			break;
	}
}
