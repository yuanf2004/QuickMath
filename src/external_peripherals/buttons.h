#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdint.h>
/* Includes the RCC setup */
#include "unv_ext_per.h"
#include "helpers/systick.h"

/* For setting up the GPIO (MODER, IDR, PUPDR)*/
#define GPIOB_MODER *((uint32_t *) 0x40020400)
/* NOTE: IDR may not be used, keep just in case though */
#define GPIOB_IDR *((uint32_t *)(0x40020400 + 0x10))
#define GPIOB_PUPDR *((uint32_t *)(0x40020400 + 0x0C))

/* For setting external interrupt lines */
#define SYSCFG_EXTICR1 *((uint32_t *) (0x40013800 + 0x08))

/* EXTI configuration for lines 0 and 1 */
/* Interrupt mask register */
#define EXTI_IMR *(uint32_t *)(( 0x40013C00))
/* Rising trigger behavior for EXTI */
#define EXTI_RTSR *((uint32_t *) (0x40013C00 + 0x08))
/* Pending register to be cleared inside of interrupt handler function */
#define EXTI_PR *(uint32_t *)(( 0x40013C00 + 0x14))

/*
Pin Assignments:
====================================
PB0 - Left Button [Pull-down EXTI0]
PB1 - Right Button [Pull-down EXTI1]
*/

extern volatile uint32_t lb_pressed;
extern volatile uint32_t rb_pressed;

void init_exti(void);

void init_buttons(void);

void clear_EXTI_bit(uint32_t bit_pos);

void EXTI0_IRQHandler(void);

void EXTI1_IRQHandler(void);

/* ### Functions that will go inside the handlers ### */

void lb_press_reg(void);

void lb_press_clear(void);

void rb_press_reg(void);

void rb_press_clear(void);

#endif