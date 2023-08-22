/**********************************************************/
/* Author    : Hamdy Al Sayed                                */
/* Date      : 19 August 2023                             */
/* Version   : V01                                        */
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


// Function Enable  Interrupt
void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
    if ( Copy_u8IntNumber <= 31)
    {
        NVIC_EN0_R = (1 << Copy_u8IntNumber);
    }
    
    else if (  Copy_u8IntNumber <=63 )
    {
        Copy_u8IntNumber -= 32;
        NVIC_EN1_R = (1 << Copy_u8IntNumber);
    }
    
    else if (  Copy_u8IntNumber <= 78)
    {
        Copy_u8IntNumber -= 32;
        NVIC_EN3_R = (1 << Copy_u8IntNumber);
    }
    
    else
    {
        /* Return Error */
    }
    
}
// Function Disable Interrupt
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
    if ( Copy_u8IntNumber <= 31)
    {
        NVIC_DIS0_R = (1 << Copy_u8IntNumber);
    }
    
    else if (  Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        NVIC_DIS1_R = (1 << Copy_u8IntNumber);
    }
    
    else if (  Copy_u8IntNumber <= 78)
    {
        Copy_u8IntNumber -= 32;
        NVIC_DIS2_R = (1 << Copy_u8IntNumber);
    }
    
    else
    {
        /* Return Error */
    }
    
}

// Function Set Pending Flag
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
    if ( Copy_u8IntNumber <= 31)
    {
        NVIC_PEND0_R = (1 << Copy_u8IntNumber);
    }
    
    else if (  Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        NVIC_PEND1_R = (1 << Copy_u8IntNumber);
    }
    else if (  Copy_u8IntNumber <= 78)
    {
        Copy_u8IntNumber -= 32;
        NVIC_PEND2_R = (1 << Copy_u8IntNumber);
    }
    
    else
    {
        /* Return Error */
    }
    
}
// Function Clear Pending Flag
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
    if ( Copy_u8IntNumber <= 31)
    {
        NVIC_UNPEND0_R = (1 << Copy_u8IntNumber);
    }
    
    else if (  Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        NVIC_UNPEND1_R = (1 << Copy_u8IntNumber);
    }
    else if (  Copy_u8IntNumber <= 78)
    {
        Copy_u8IntNumber -= 32;
        NVIC_PEND2_R = (1 << Copy_u8IntNumber);
    }
    
    else
    {
        /* Return Error */
    }
    
}

// Function Active Flag
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
    u8 Local_u8Result;
    
    if ( Copy_u8IntNumber <= 31)
    {
        Local_u8Result = GET_BIT(NVIC_ACTIVE0_R,Copy_u8IntNumber);
    }
    
    else if (  Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32;
        Local_u8Result = GET_BIT(NVIC_ACTIVE1_R,Copy_u8IntNumber);
    }
    
    else if (  Copy_u8IntNumber <= 78)
    {
        Copy_u8IntNumber -= 32;
        Local_u8Result = GET_BIT(NVIC_ACTIVE2_R,Copy_u8IntNumber);
    }
    
    else
    {
        /* Return Error */
    }
    
    return Local_u8Result;
    
}


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
