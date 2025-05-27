#ifndef LEDS_H
#define LEDS_H

#include "unv_ext_per.h"
#include "helpers/systick.h"
#include <stdint.h>

/* GPIOC mode register */
#define GPIOC_MODER *((uint32_t *)(0x40020800))
/* GPIOC output data register */
#define GPIOC_ODR *((uint32_t *)(0x40020800 + 0x14))

/*
Pin Assignments:
================
PC0 - Red LED
PC1 - Yellow LED
PC2 - Green LED
*/

void init_leds(void);

void enable_all_leds(void);

void disable_all_leds(void);

void disable_green_led(void);

void disable_yellow_led(void);

void disable_red_led(void);

void flash_all_leds(void);

#endif 