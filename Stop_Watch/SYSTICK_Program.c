

#include "../STD_TYPE.h"
#include "../BIT_MATH.h"
#include <tm4c123gh6pm.h>

#include "SYSTICK_Interface.h"
#include "SYSTICK_Private.h"
#include "SYSTICK_Config.h"



void SYSTICK_void_INIT(void)
{

    NVIC_ST_CTRL_R = 0;         // SysTick Control and Status Register enable the counter (bit 0), enable the SysTick interrupt(bit 1), and determine counter status(bit 16).
    NVIC_ST_RELOAD_R = 80000000-1; // SysTick Reload Value Register specifies the start value to load into the SysTick Current Value (STCURRENT) register 24 bit
    NVIC_ST_CURRENT_R = 0;      // SysTick Current Value Register contains the current value of the SysTick counter. 24 bit
    NVIC_ST_CTRL_R = 0x05;    // Enable the counter and clock source
}

void delay_SYSTICK_ms(int n)     // delay milli second
{
    NVIC_ST_CTRL_R = 0;         // SysTick Control and Status Register enable the counter (bit 0), enable the SysTick interrupt(bit 1), and determine counter status(bit 16).
    NVIC_ST_RELOAD_R = (16000-1)*n; // SysTick Reload Value Register specifies the start value to load into the SysTick Current Value (STCURRENT) register 24 bit
    NVIC_ST_CURRENT_R = 0;      // SysTick Current Value Register contains the current value of the SysTick counter. 24 bit
    NVIC_ST_CTRL_R = 0x05;    // Enable the counter and clock source

    while( (NVIC_ST_CTRL_R&0x10000)  == 0 )     //      GET_BIT(NVIC_ST_CTRL_R,16)
    {

    }
}

void delay_SYSTICK_MS(int n)    // delay micro second
{
       NVIC_ST_CTRL_R = 0;         // SysTick Control and Status Register enable the counter (bit 0), enable the SysTick interrupt(bit 1), and determine counter status(bit 16).
       NVIC_ST_RELOAD_R = (80-1)*n; // SysTick Reload Value Register specifies the start value to load into the SysTick Current Value (STCURRENT) register 24 bit
       NVIC_ST_CURRENT_R = 0;      // SysTick Current Value Register contains the current value of the SysTick counter. 24 bit
       NVIC_ST_CTRL_R = 0x05;    // Enable the counter and clock source

       while( (NVIC_ST_CTRL_R&0x10000)  == 0 )     //      GET_BIT(NVIC_ST_CTRL_R,16)
       {

       }
}


void stop_timer(void)
{
      // NVIC_ST_CTRL_R = 0;         // SysTick Control and Status Register enable the counter (bit 0), enable the SysTick interrupt(bit 1), and determine counter status(bit 16).
       CLR_BIT(NVIC_ST_CTRL_R,1);
       SET_BIT(NVIC_ST_CTRL_R,0);
       NVIC_ST_RELOAD_R = 0; // SysTick Reload Value Register specifies the start value to load into the SysTick Current Value (STCURRENT) register 24 bit
       NVIC_ST_CURRENT_R = 0;      // SysTick Current Value Register contains the current value of the SysTick counter. 24 bit
//       NVIC_ST_CTRL_R = 0x0;    // Enable the counter and clock source


}
