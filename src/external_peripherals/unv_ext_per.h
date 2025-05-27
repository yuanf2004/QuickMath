/* Header file for universal registers / macros used by external peripherals */

#include "stm32f446xx.h"

/* RCC for all GPIO */
#define RCC_AHB1ENR *((uint32_t *)(0x40023800 + 0x30))