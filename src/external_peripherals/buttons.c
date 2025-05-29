/* NOTE: Interrupt logic may need restructuring later on to
be tailored towards game logic */

#include "buttons.h"

/*
Pin Assignments:
====================================
PB0 - Left Button [Pull-down EXTI0]
PB1 - Right Button [Pull-down EXTI1]
*/

volatile uint32_t lb_pressed;
volatile uint32_t rb_pressed;

/* Initialize external interrupt */
void init_exti(void){
    /* Connect EXTI lines to PB0 and PB1 */
    SYSCFG_EXTICR1 &= ~(0xF | (0xF << 4));
    SYSCFG_EXTICR1 |= (0x1 | (0x1 << 4));

    /* Unmask lines 0 and 1 */
    EXTI_IMR &= ~(0x3);
    EXTI_IMR |= 0x3;

    /* Set both lines 0 and 1 to rising edge trigger */
    EXTI_RTSR &= ~(0x3);
    EXTI_RTSR |= 0x3;

    /* Enable interrupt requessts for NVIC */
    __NVIC_EnableIRQ(EXTI0_IRQn);
    __NVIC_EnableIRQ(EXTI1_IRQn);
};

/* Initialize buttons, including init_exti() */
void init_buttons(void){
    /* Initialize external interrupt */
    init_exti();

    /* Set PB0 and PB1 to input (reset state) */
    GPIOB_MODER &= ~(0x3 | (0x3 << 2));

    /* Set both PB0 and PB1 to pull down */
    GPIOB_PUPDR &= ~(0x3 | (0x3 << 2));
    GPIOB_PUPDR |= (0x2 | (0x2 << 2));

    /* Buttons by default are not pressed */
    lb_pressed = 0;
    rb_pressed = 0;
};

/* Clear specific bit of the EXTI_PR */
void clear_EXTI_bit(uint32_t bit_pos){
    EXTI_PR |= (0x1 << bit_pos);
};

/* Handle PB0/Left Button being pressed */
void EXTI0_IRQHandler(void){
    lb_press_reg();
    clear_EXTI_bit(0);
};

/* Handle PB1/Right Button being pressed */
void EXTI1_IRQHandler(void){
    rb_press_reg();
    clear_EXTI_bit(1);
};

/* ### Functions that will go inside the handlers ### */

void lb_press_reg(void){
    lb_pressed = 1;
};

void lb_press_clear(void){
    lb_pressed = 0;
};

/* For clearing the pressed flag once a new math problem is generated */

void rb_press_reg(void){
    rb_pressed = 1;
};

void rb_press_clear(void){
    rb_pressed = 0;
};