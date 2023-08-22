/*************************************************************************************************
Author   : Hamdy Al Sayed                                                                       * 
Data    : 13/8/2023                                                                              *
Version : 01                                                                                     *
**************************************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


/* Macros Of Port */	
#define  GPIOA_PORT			0
#define  GPIOB_PORT			1
#define  GPIOC_PORT			2
#define  GPIOD_PORT			3
#define  GPIOE_PORT			4
#define  GPIOF_PORT			5

	/* Macros Of Pins */
#define  PIN0				0
#define  PIN1				1
#define  PIN2				2
#define  PIN3				3
#define  PIN4				4
#define  PIN5				5
#define  PIN6				6
#define  PIN7				7


// Macros of Direction
#define DIR_INPUT  0
#define DIR_OUTPUT 1

/* ============= Function Init GPIO Config  ============= */
void MGIO_voidInitPort(u8 Copy_u8Port);

/* ============= Function SET PIN DIR  ============= */
void MGOIP_voidSetPinDir(u8 copy_u8Port ,u8 copy_u8Pin,u8 copy_Direction);

	/* ============= Function Enable The Alternate Function ============= */
void MGOIP_voidSetPinALFun(u8 copy_u8Port ,u8 copy_u8Pin); 

	/* ============= Function To Read Data From Data ============= */
u8 MGPIO_u8ReadData(u8 copy_u8PORT ,u8 copy_u8PIN);

	/* ============= Function To Write Data At DATA	Value = High , LOW ============= */
void MGPIO_voidWriteData(u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8Value )  ;

	/* ============= Function Set The PULL  UP  ============= */
void MGPIO_voidSetPullUp(u8 copy_u8PORT ,u8 copy_u8Pin);

        /* ============= Function Set The PULL  Down  ============= */
void MGPIO_voidSetPullDown(u8 copy_u8PORT ,u8 copy_u8Pin);

/* ============= Function SET PORT  DIR  ============= */
void MGPIO_voidPortDir(u8 copy_u8PORT ,u8 copy_u8Value);

/* ============= Function Write PORT  VALUE  ============= */
void MGPIO_voidWritePort(u8 copy_u8PORT ,u8 copy_u8Value);

#endif
