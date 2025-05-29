#include "potentiometer.h"
#include "unv_ext_per.h"

/*
Pin Assignments:
================
PC5 - Potentiometer ADC in -> ADC1 Channel 15
*/

/* Initalize the ADC pin */
void init_adc(void){
    /* Enable RCC for ADC - ADC1 is bit 8 */
    RCC_APB2ENR &= ~(0x1 << 8);
    RCC_APB2ENR |= (0x1 << 8);

    /* Set GPIO PC5 to analog mode */
    GPIOC_MODER &= ~(0x3 << (5 * 2));
    GPIOC_MODER |= (0x3 << (5 * 2));

    /* Set 144 cycle sampling time for potentiometer reading */
    ADC1_SMPR1 = 0x0;
    ADC1_SMPR1 |= (0x6 << (5 * 3));

    /* Convert ADC on channel 15 */
    ADC1_SQR3 = 0x0;
    ADC1_SQR3 |= 0xF;

    /* Define number of conversions needed, reset is default 1 conversion */
    ADC1_SQR1 = 0x0;

    /* Enable and configure ADC */
    /*
    NOTE ON ADC1_CR2
    ================
    Bit 30 SWSTART: 1 for triggering conversions, set to 1 EACH TIME to read
    Bit 11 ALIGN: 0 for right-align (default)
    Bit 10 EOCS (end of conversion selection): 1 for single-channel voltage reading
    Bit 1 CONT: 0 for non continuous conversion mode
    Bit 0 ADON: 1 for enable ADC  
    */
    ADC1_CR2 = 0x0;
    ADC1_CR2 |= (0x1 | 0x1 << 10 | 0x1 << 30);
}

/* Read voltage value of potentiometer */
uint32_t read_pot_val(){

    /* Set SWSTART to start conversion */
    ADC1_CR2 |= 0x1 << 30;

    /* Wait for conversion to finish */
    while ((ADC1_SR & 0x2) != 0x2){
    }

    /* Return reading */
    return (uint32_t) ADC1_DR;
}