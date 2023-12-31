//#include "./Tiva_DIO/Tiva_DIO.h"
//#include "./LCD_Driver/LCD_Driver.h"
//#include "./keyPad_Driver/keyPad_Driver.h"


#include "GPIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"
#include "stackOp/stackOp.h"


char key = DEFAULT_K;
char infix[MAX_SIZE];   // array to take the user input (e.g. 5+8)
char postfix[MAX_SIZE]; // array to put the infix array in postfix Expression (e.g 5 8 +)
int ind = 0; // index to track the index of infix array

char _ReadKeyPad()
{
    char _key = DEFAULT_K;
    key_col = key_flag-1;
    _key = symbol[key_row][key_col];
    return _key;
}

// GPIOB Interrupt handler
void GPIOB_Handler(void)
{
    if (K_MIS_R & 1<<KP_IN1) /* check if interrupt caused by PB0 */
    {
        GPIO_PORTB_ICR_R |= 1<<KP_IN1;
        key_flag = 1;
    }
    else if (K_MIS_R & 1<<KP_IN2) /* check if interrupt caused by PB0 */
    {
        GPIO_PORTB_ICR_R |= 1<<KP_IN2;
        key_flag = 2;
    }
    else if (K_MIS_R & 1<<KP_IN3) /* check if interrupt caused by PB0 */
    {
        GPIO_PORTB_ICR_R |= 1<<KP_IN3;
        key_flag = 3;
    }
    else if (K_MIS_R & 1<<KP_IN4) /* check if interrupt caused by PB0 */
    {
        GPIO_PORTB_ICR_R |= 1<<KP_IN4;
        key_flag = 4;
    }
}



/**
 * main.c
 */
void main(void)
{
    // Initialize used ports
    MGIO_voidInitPort(GPIOA_PORT);
    MGIO_voidInitPort(GPIOB_PORT);
    MGIO_voidInitPort(GPIOE_PORT);
    MGIO_voidInitPort(GPIOF_PORT);

    // Initialize LCD and all its connected pins
    LCD_voidInit();

    // just printing HELLO
    LCD_voidSetCursorPosition(0, 3);
    LCD_voidPrintNumberwithoutarray("HELLO...");

    // Initialize keypad and all its connected pins (with interrupt)
    KeyPad_Init();

    // Enable global interrupt to use it for the keypad
    __asm(" CPSIE  I");

    int clear_flag =1;

    while(812){

        KeyPad_Read();
        if(key_flag)
        {
            __asm(" CPSID  I");
            key = _ReadKeyPad();
            if (clear_flag){ // clear LCD and start over
                LCD_Clear();
                clear_flag =0;
            }
            if(key == '.')  // clear LCD and start over
            {
                LCD_Clear();
                memset(infix, 0, sizeof(infix));     // Clear infix array
                memset(postfix, 0, sizeof(postfix)); // Clear postfix array
                ind = 0;

            }
            else if (key == '=')
            {
                static int result = 0;
                if(infix != '\0')
                {
                    infixToPostfix(infix, postfix);     // get the postfix array from infix
                    result = evaluatePostfix(postfix);  // evaluate the postfix array to get the result
                    LCD_SetCursor(1, 0);
                    LCD_voidPrintNumberwitharray(result);
                    clear_flag =1;
                    memset(infix, 0, sizeof(infix));     // Clear infix array
                    memset(postfix, 0, sizeof(postfix)); // Clear postfix array
                    ind = 0;
                }
                else
                {
                    LCD_voidSetCursorPosition(1, 0);
                    LCD_voidPrintNumberwitharray(result);
                    clear_flag = 1;
                }
            }
            else
            {
                // get the Expression from user
                infix[ind++] = key;
                LCD_voidSendChar(key);
//                int count =0; while(count<50*3180){count++;}

            }
            key_flag=0;
            __asm(" CPSIE  I");

        }

    }
}
