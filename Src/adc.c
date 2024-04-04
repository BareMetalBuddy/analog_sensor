#include "adc.h"

/**
 * @brief Initializes the ADC module.
 *
 * Initializes the specified ADC module based on the given base address and channel.
 * Note: For an unknown reason, the ADC enable register must be configured twice to ensure proper initialization.
 *
 * @param adcx Pointer to the ADC handler.
 * @param base_address_adc_selected Base address of the selected ADC module.
 * @param channel ADC channel to initialize.
 */
void adc_init(ADC_Handler_t *adcx,uint32_t base_address_adc_selected, uint8_t channel)
{
	adcx->adcx = (ADC_Reg_t*)base_address_adc_selected;

	/*For a unknown reason the ADC enable register must be configured twice*/
	adcx->adcx->ADC_CR2 |= (1<<0); 		// Enable ADC
	for (volatile uint32_t delay = 0; delay < 1000; delay++);
	adcx->adcx->ADC_CR2 |= (1<<0); 		// Enable ADC

	adcx->adcx->ADC_CR2 |= (1<<2); 			// ADC Calibration
	while (adcx->adcx->ADC_CR2  & (1<<2)); 	// Wait for the calibration is completed
	adcx->adcx->ADC_CR2 |= (1<<1);   		// set mode continuous conversion
	adcx->adcx->ADC_CR2 &= ~(1<<20);
	adcx->adcx->ADC_SMPR1 |= (4<<0); 		// Set Sample time selection - 100: 41.5 cycles
	adcx->adcx->ADC_SQR3 = channel; 		// Set channel
}

/**
 * @brief Starts the ADC conversion.
 *
 * Initiates the conversion process for the specified ADC module. This function should be
 * called after initializing the ADC with `adc_init`.
 *
 * @param adcx Pointer to the ADC handler.
 */
void adc_start_conversion(ADC_Handler_t *adcx)
{

}

/**
 * @brief Reads the ADC conversion result.
 *
 * Waits for the ADC conversion to complete and returns the result.
 * This function should be called after starting a conversion with `adc_start_conversion`.
 *
 * @param adcx Pointer to the ADC handler.
 * @return uint32_t The result of the ADC conversion.
 */
uint32_t adc_read(ADC_Handler_t *adcx)
{
	adcx->adcx->ADC_CR2 |= (1<<22); 				// Start ADC conversion
	while (!(adcx->adcx->ADC_SR & (1<<1))); 		// wait for conversion to be complete

	return adcx->adcx->ADC_DR; // read converted value
}
