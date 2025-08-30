#include <lpc17xx.h>
#include "sensors.h"

// Initialize ADC
void adc_init() {
    LPC_PINCON->PINSEL1 |= (1 << 18) | (1 << 20); // P0.24 (AD0.1), P0.25 (AD0.2)
    LPC_SC->PCONP |= (1 << 12); // Power to ADC
    LPC_ADC->ADCR = (1 << 21) | (4 << 8); // Enable ADC, PCLK = CCLK/4
}

unsigned int adc_read(unsigned char channel) {
    LPC_ADC->ADCR &= ~(0xFF);
    LPC_ADC->ADCR |= (1 << channel); // Select channel
    LPC_ADC->ADCR |= (1 << 24);      // Start conversion
    while ((LPC_ADC->ADGDR & (1U << 31)) == 0);
    unsigned int result = (LPC_ADC->ADGDR >> 4) & 0xFFF;
    return result;
}

float read_temperature() {
    unsigned int adc_val = adc_read(1); // LM35 on AD0.1
    float voltage = (adc_val * 3.3) / 4095;
    return voltage * 100; // LM35 = 10mV per °C
}

float read_air_quality() {
    unsigned int adc_val = adc_read(2); // MQ sensor on AD0.2
    return (adc_val / 4095.0) * 100; // Percentage scale
}
