// #include "buttons.h"

// /* 
// Assignments: 
// ==================
// PB0 - Left Button
// PB1 - Right Button 
// */

// /* Initialize button input pins */
// void buttons_init(){

// /* Reset and Set GPIOBEN */
// RCC_AHB1ENR &= ~(0x1 << 1);
// RCC_AHB1ENR |= (0x1 << 1);

// /* Configure input mode for PB0 and PB1 */
// GPIOB_MODER &= ~((0x3) | (0x3 << (1 * 2)));

// /* Set pull-down for both pins */
// GPIOB_PUPDR &= ~((0x3) | (0x3 << (1 * 2)));
// GPIOB_PUPDR |= ((0x2) | (0x2 << (1 * 2)));
// }

// /* Read the value of the left button (PB0), 1 if true and 0 if false */
// uint32_t read_left_button(){
//     /* If left button is reading 1, return 1 */
//     if((GPIOB_IDR & 0x1) == 0x1){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

// /* Read the value of the right button (PB1), 1 if true and 0 if false */
// uint32_t read_right_button(){
//     if((GPIOB_IDR & (0x1 << 1)) == (0x1 << 1)){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
