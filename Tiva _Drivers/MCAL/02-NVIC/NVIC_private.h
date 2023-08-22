/**********************************************************/
/* Author    : Hamdy Al Sayed                                */
/* Date      : 19 August 2023                             */
/* Version   : V01                                        */
/**********************************************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_EN0_R       *((u32*)0xE000E100) /* Enable External interrupts from 0  to 31 */
#define NVIC_EN1_R       *((u32*)0xE000E104) /* Enable External interrupts from 32 to 63 */
#define NVIC_EN2_R       *((u32*)0xE000E108) /* Enable External interrupts from 64 to 95 */

  
#define NVIC_DIS0_R      *((u32*)0xE000E180)   /* Disable External interrupts from 0  to 31 */
#define NVIC_DIS1_R      *((u32*)0xE000E184)   /* Disable External interrupts from 32 to 63 */
#define NVIC_DIS2_R      *((u32*)0xE000E188)   /* Disable External interrupts from 64 to 95 */

#define NVIC_PEND0_R      *((u32*)0xE000E200)  /* Set Pending Flag from 0  to 31 */
#define NVIC_PEND1_R      *((u32*)0xE000E204)  /* Set Pending Flag from 32 to 63 */
#define NVIC_PEND2_R      *((u32*)0xE000E208)  /* Set Pending Flag from 64 to 95 */
 
#define NVIC_UNPEND0_R    *((u32*)0xE000E280)  /* Disable Pending Flag from 0  to 31 */
#define NVIC_UNPEND1_R    *((u32*)0xE000E284)  /* Disable Pending Flag from 32 to 63 */
#define NVIC_UNPEND2_R    *((u32*)0xE000E288)  /* Disable Pending Flag from 64 to 95 */

#define NVIC_ACTIVE0_R    *((volatile u32*)0xE000E300)    /* Active  Flag from 0  to 31 */
#define NVIC_ACTIVE1_R    *((volatile u32*)0xE000E304)    /* Active  Flag from 32 to 63 */
#define NVIC_ACTIVE2_R    *((volatile u32*)0xE000E308)    /* Active  Flag from 64 to 95 */


#define NVIC_IPR          ((u8*)0xE000E400)


#endif
