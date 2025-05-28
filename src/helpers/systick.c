#include "systick.h"

volatile uint32_t ms_ticks;

/* Initialize SysTick */
void init_systick(){
    //! Move enable irq elsewhere later in the code for a general init block
    __enable_irq();

    /* Match the 16 MHz clock cycle but minus 1 since it starts at 0 */
    SYSTICK_RLD = 15999; 
    SYSTICK_CUR_VAL = 0;
    /* Clear bits [2:0] */
    SYSTICK_CTRL &= ~(0x7);
    /* 
    CLKSOURCE = 1 = Processor Clock
    TICKINT = 1 = SysTick Exception Request on 0 for interrupt
    ENABLE = 1 
    */
    SYSTICK_CTRL |= 0x7;
}

void SysTickHandler(void){
    ms_ticks++;
}

/* Sleep system in milliseconds */
void sleep(uint32_t time){
    uint32_t ms_curr = ms_ticks;
    while(ms_ticks - ms_curr < time){
    }
}