#include "leds.h"

/*
Pin Assignments:
================
PC0 - Red LED
PC1 - Yellow LED
PC2 - Green LED
*/

/* Initialize LEDs */
void init_leds(void){

    /* Reset/set RCC for GPIOC */
    RCC_AHB1ENR &= ~(0x1 << 2);
    RCC_AHB1ENR |= (0x1 << 2);

    /* Reset/set output mode for all 3 output pins */
    GPIOC_MODER &= ~((0x3) | (0x3 << (1 * 2)) | (0x3 << (2 * 2)));
    GPIOC_MODER |= ( (0x1) | (0x1 << (1 * 2)) | (0x1 << (2 * 2)));

    /* Initialize with all three LEDs off */
    disable_all_leds();
};

/* Enable all LEDs at the start of the game */
void enable_all_leds(void){
    GPIOC_ODR &= ~(0x7);
    GPIOC_ODR |= 0x7;
};

/* For init and testing */
void disable_all_leds(void){
    GPIOC_ODR &= ~(0x7);
}

/* Disable the green LED (1st life) */
void disable_green_led(void){
    GPIOC_ODR &= ~(0x1 << (2 * 1));
};

/* Disable the yellow LED (2nd life) */
void disable_yellow_led(void){
    GPIOC_ODR &= ~(0x1 << (1 * 1));
};

/* Disable the red LED (3rd life) */
void disable_red_led(void){
    GPIOC_ODR &= ~(0x1);
};

// * I may be incorporating some sort of universal value for this so the game
// * knows when to stop showing the game over screen
/* Flash all LEDs once the game is over */
void flash_all_leds(void){
uint32_t flash_count = 3;

while(flash_count > 0){
    disable_all_leds();
    sleep(500);
    enable_all_leds();
    sleep(500);
    flash_count--;
}
};
