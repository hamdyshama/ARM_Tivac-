

/**
 * main.c
 */

#include"STD_TYPE.h"
#include"BIT_MATH.h"
#include"GPIO_private.h"
#include"GPIO_interface.h"
#include"LCD_interface.h"
#include"GPIO_config.h"
#include"LCD_config.h"
#include "TM4C123GH6PM.h"
int main(void)
{

    SYSCTL_RCGCGPIO_R|=0x00000012;

 while((SYSCTL_RCGCGPIO_R & 0x00000012)==0){};
   GPIOE->LOCK =0x4c4F434B;
   GPIOB->LOCK =0x4c4F434B;
   GPIOE->CR=0xFF;
   GPIOB->CR=0xFF;
   GPIOE->DEN=0xFF;
   GPIOB->DEN=0xFF;
   LCD_voidInit();
   LCD_voidPrintNumberwithoutarray(1234);




while(1)
{
    }


}
