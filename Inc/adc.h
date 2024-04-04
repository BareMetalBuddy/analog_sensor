
#ifndef DRIVERS_ADC_H_
#define DRIVERS_ADC_H_

#include <stdint.h>

#define ADC1_BASE_ADDRESS (0X40012400) /**< Base address for ADC1 */
#define ADC2_BASE_ADDRESS (0X40012800) /**< Base address for ADC2 */

/**
 * @brief Structure to represent ADC registers.
 *
 * This structure represents all the necessary registers to control an ADC module.
 * Each register is 32-bit wide and volatile to ensure direct access to hardware and prevent optimization.
 */
typedef struct
{
	volatile uint32_t ADC_SR;
	volatile uint32_t ADC_CR1;
	volatile uint32_t ADC_CR2;
	volatile uint32_t ADC_SMPR1;
	volatile uint32_t ADC_SMPR2;
	volatile uint32_t ADC_JOFR1;
	volatile uint32_t ADC_JOFR2;
	volatile uint32_t ADC_JOFR3;
	volatile uint32_t ADC_JOFR4;
	volatile uint32_t ADC_HTR;
	volatile uint32_t ADC_LTR;
	volatile uint32_t ADC_SQR1;
	volatile uint32_t ADC_SQR2;
	volatile uint32_t ADC_SQR3;
	volatile uint32_t ADC_JSQR;
	volatile uint32_t ADC_JDR1;
	volatile uint32_t ADC_JDR2;
	volatile uint32_t ADC_JDR3;
	volatile uint32_t ADC_JDR4;
	volatile uint32_t ADC_DR;

}ADC_Reg_t;


/**
 * @brief ADC handler structure.
 *
 * This structure holds a pointer to the ADC_Reg_t structure for a specific ADC module, allowing easy access
 * and manipulation of the ADC registers.
 */
typedef struct
{
	volatile ADC_Reg_t *adcx;
}ADC_Handler_t;

/**
 * @brief Initializes the ADC module.
 *
 * This function initializes the specified ADC module with the provided base address and channel.
 *
 * @param adcx Pointer to the ADC handler.
 * @param base_address_adc_selected Base address of the selected ADC module.
 * @param channel ADC channel to initialize.
 */
void adc_init(ADC_Handler_t *adcx,uint32_t base_address_adc_selected, uint8_t channel);

/**
 * @brief Starts the ADC conversion.
 *
 * Initiates the conversion process for the specified ADC module.
 *
 * @param adcx Pointer to the ADC handler.
 */
void adc_start_conversion(ADC_Handler_t *adcx);

/**
 * @brief Reads the ADC conversion result.
 *
 * Returns the result of the ADC conversion.
 *
 * @param adcx Pointer to the ADC handler.
 * @return uint32_t Result of the ADC conversion.
 */
uint32_t adc_read(ADC_Handler_t *adcx);

#endif /* DRIVERS_ADC_H_ */
