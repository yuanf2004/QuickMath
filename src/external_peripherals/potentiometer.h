#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

/*
Pin Assignments:
================
PC5 - Potentiometer ADC in -> ADC1 Channel 15
*/

#include "unv_ext_per.h"
#include "helpers/systick.h"
#include <stdint.h>

/* RCC clock enable for ADC */
#define RCC_APB2ENR *(uint32_t *)(0x40023800 + 0x44)

/* GPIOC Config Registers */
#define GPIOC_MODER *((uint32_t *) 0x40020800)

/* 
ADC INIT NOTE:
================================================================================
Steps for ADC Conversion Init:

ADC1_SMPR1 - Set sampling time per channel (the longer the more accurate)
ADC1_SQR3 - Define which channel to convert to ADC (Channel 15 in my case)
ADC1_SQR1 - Define the number of conversions needed (only 1 in my case for 1 pin)
ADC1_CR2 - Power on ADC
ADC1_SR - Check when conversion is finished
ADC1_DR - For reading the conversion result
*/

#define ADC1_SMPR1 *((uint32_t *) (0x40012000 + 0x0C))
#define ADC1_SQR3 *((uint32_t *) (0x40012000 + 0x34))
#define ADC1_SQR1 *((uint32_t *) (0x40012000 + 0x2C))
#define ADC1_CR2 *((uint32_t *) (0x40012000 + 0x08))
#define ADC1_SR *((uint32_t *) (0x40012000))
#define ADC1_DR *((uint32_t *) (0x40012000 + 0x4C))

void init_adc(void);

uint32_t read_pot_val(void);

#endif 