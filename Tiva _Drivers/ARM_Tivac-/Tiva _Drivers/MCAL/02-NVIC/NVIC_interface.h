/**********************************************************/
/* Author    : Hamdy Al Sayed                                */
/* Date      : 19 August 2023                             */
/* Version   : V01                                        */
/**********************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


// Function Enable  Interrupt
void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);
// Function Disable Interrupt
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
// Function SET Pending Flag
void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);
// Function Clear Pending Flag
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
// Function Active Flag
u8     MNVIC_u8GetActiveFlag    (u8 Copy_u8IntNumber);

#endif
