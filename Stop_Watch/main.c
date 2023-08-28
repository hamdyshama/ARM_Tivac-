

#include "STD_TYPE.h"                 /* Include standard types */
#include "BIT_MATH.h"                 /* Include bit manipulation macros */
#include "tm4c123gh6pm.h"             /* Include microcontroller specific register definitions */

#include "GPIO_driver/GPIO_Interface.h"                /* Include GPIO driver interface */
#include "Interrupt_driver/Interrupt_Interface.h"      /* Include interrupt driver interface */
#include "SYSTICK_driver/SYSTICK_Interface.h"          /* Include SysTick driver interface */
#include "LCD_driver/LCD_interface.h"                  /* Include LCD driver interface */

int flag = 0;                                         /* Global variable declaration, initialize to 0 */
short second = 0, minute = 0, hour = 0;                /* Global variable declaration, initialize to 0 */

void start_stopwatch(void)
{
    while (1) {
        second++;                                     /* Increment second */
        LCD_voidSetCursorPosition(1, 13);             /* Set LCD cursor position */
        LCD_voidPrintNumberwitharray(second);          /* Print the updated second value on the LCD */

        if (second == 60) {
            LCD_voidSetCursorPosition(1, 14);         /* Set LCD cursor position */
            LCD_voidClearDisplay();                    /* Clear the LCD display */
            LCD_voidSetCursorPosition(0, 1);           /* Set LCD cursor position */
            LCD_voidPrintString("Time");                /* Print "Time" on the LCD display */
            LCD_voidSetCursorPosition(1, 12);          /* Set LCD cursor position */
            LCD_voidSendChar(':');                      /* Print ":" on the LCD display */
            second = 0;                                /* Reset second to 0 */
            minute++;                                  /* Increment minute */
        }

        LCD_voidSetCursorPosition(1, 10);             /* Set LCD cursor position */
        LCD_voidPrintNumberwitharray(minute);          /* Print the updated minute value on the LCD */

        delay_SYSTICK_ms(3000);                        /* Delay for 3 seconds using SysTick driver */

        if (GPIO_u8GetPinValue(GPIOF_PORT, PIN0) == 0) {
            NVIC_ST_CTRL_R = 0;                        /* Disable SysTick interrupt */
            GPIO_voidSetPinValue(GPIOF_PORT, PIN1, GPIO_HIGH);  /* Set GPIO pin to high */
            break;                                     /* Exit the loop */
        }
    }
}

int main(void)
{
    GPIO_void_Init();                                 /* Initialize GPIO */

    GPIO_voidSetPinDirection(GPIOF_PORT, PIN4, GPIO_INPUT);   /* Set GPIO pin direction as input */
    GPIO_voidSetPinPullUp(GPIOF_PORT, PIN4);                   /* Enable pull-up resistor */

    GPIO_voidSetPinDirection(GPIOF_PORT, PIN0, GPIO_INPUT);   /* Set GPIO pin direction as input */
    GPIO_voidSetPinPullUp(GPIOF_PORT, PIN0);                   /* Enable pull-up resistor */

    LCD_voidInit();                                   /* Initialize LCD */
    LCD_voidClearDisplay();                           /* Clear the LCD display */
    LCD_voidSetCursorPosition(0, 1);                  /* Set LCD cursor position */
    LCD_voidPrintString("Time");                       /* Print "Time" on the LCD display */
    LCD_voidSetCursorPosition(1, 12);                 /* Set LCD cursor position */
    LCD_voidSendChar(':');                             /* Print ":" on the LCD display */

    GPIO_voidSetPinDirection(GPIOF_PORT, PIN1, GPIO_OUTPUT);  /* Set GPIO pin direction as output */

    while (1) {
        if (GPIO_u8GetPinValue(GPIOF_PORT, PIN4) == 0) {         /* Check if switch 1 is pressed */
            while (GPIO_u8GetPinValue(GPIOF_PORT, PIN4) == 0);   /* Wait until switch 1 is released */
            GPIO_voidSetPinValue(GPIOF_PORT, PIN1, GPIO_LOW);    /* Set GPIO pin to low */
            start_stopwatch();                                   /* Start the stopwatch */
        } else if (GPIO_u8GetPinValue(GPIOF_PORT, PIN0) == 0) {  /* Check if switch 2 is pressed */
            flag = 1;                                            /* Set flag to 1 */
            while (GPIO_u8GetPinValue(GPIOF_PORT, PIN0) == 0);   /* Wait until switch 2 is released */
            GPIO_voidSetPinValue(GPIOF_PORT, PIN1, GPIO_HIGH);   /* Set GPIO pin to high */
            NVIC_ST_CTRL_R = 0;                                   /* Disable SysTick interrupt */
        }
    }
}
