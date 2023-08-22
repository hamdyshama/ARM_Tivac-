/*
 * LCD_program.c
 *
 *  Created on: ???/???/????
 *      Author: walee
 */

#include"STD_TYPE.h"
#include"BIT_MATH.h"

#include "LCD_interface.h"
#include "GPIO_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"



void LCD_voidInit(void)
{
	// RS
	MGOIP_voidSetPinDir(LCD_CTRL_PORT,LCD_RS_PIN,1);
	// RW
	MGOIP_voidSetPinDir(LCD_CTRL_PORT,LCD_RW_PIN,1);
	// E
	MGOIP_voidSetPinDir(LCD_CTRL_PORT,LCD_EN_PIN,1);
	// Data Pins
	MGPIO_voidPortDir(LCD_DATA_PORT,0xFF);
#if    LCD_Mode == LCD_8_Bit_Mode
	MGPIO_voidPortDir(LCD_DATA_PORT,0xFF);
	delay_ms(50);
	LCD_voidSendCommand(LCD_Function_Set); // Function Set 0b00111000
	delay_ms(1);
	LCD_voidSendCommand(LCD_ON_OFF); // ON/OFF Control
	delay_ms(1);
	LCD_voidSendCommand(0b00000001); // Display Clear  0b00000001
	delay_ms(2);
	LCD_voidSendCommand(LCD_Entry_Mode_Set); // Entry Mode Set  0b00000110
	delay_ms(5);
#elif  LCD_Mode == LCD_4_Bit_Mode
		/*MGOIP_voidSetPinDir(LCD_DATA_PORT,DIO_PIN0,1);
		MGOIP_voidSetPinDir(LCD_DATA_PORT,DIO_PIN1,1);
		MGOIP_voidSetPinDir(LCD_DATA_PORT,DIO_PIN2,1);
		MGOIP_voidSetPinDir(LCD_DATA_PORT,DIO_PIN3,1);*/
		delay_ms(50);
	    LCD_voidSendCommand(0x33);
	    delay_ms(1);
	    LCD_voidSendCommand(0x32);	// Send for 4 bit initialization of LCD
	    delay_ms(1);
	    LCD_voidSendCommand(0x28);	// 2 line, 5*7 matrix in 4-bit mode
	    delay_ms(1);
	    LCD_voidSendCommand(0x0c);	// Display on cursor off
	    delay_ms(1);
	    LCD_voidSendCommand(0x06);	// Increment cursor (shift cursor to right)
	    delay_ms(2);
	    LCD_voidSendCommand(0x01);	// Clear display screen
	    delay_ms(5);

#endif


}


void LCD_voidSendCommand(u8 cpy_u8Command)
{
		// RS -> LOW
		MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_RS_PIN,0);
		// RW -> LOW
		MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_RW_PIN,0);
		// DB Pins -> command
#if     LCD_Mode == LCD_8_Bit_Mode

		MGPIO_voidWritePort(LCD_DATA_PORT,cpy_u8Command);// 0b01010011

#elif      LCD_Mode == LCD_4_Bit_Mode
		// Send most significant Bits first
		MGPIO_voidWritePort(LCD_DATA_PORT,(LCD_DATA_PORT & 0x0F)|(cpy_u8Command & 0xF0));// 0b01010011
		// Pulse Enable
		MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_EN_PIN,1);
		delay_ms(1);
		MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_EN_PIN,0);
		delay_ms(1);
		// Send Lowest significant Bits
		MGPIO_voidWritePort(LCD_DATA_PORT,(cpy_u8Command << 4)|(LCD_DATA_PORT & 0x0F));

#endif
	// Pulse Enable
	MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_EN_PIN,1);
	delay_ms(1);
	MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_EN_PIN,0);
	delay_ms(1);

}

void LCD_voidSendChar(u8 cpy_u8Char)
{
	    // RS -> HIGH
		MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_RS_PIN,1);
		// RW -> LOW
		MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_RW_PIN,0);
		// DB Pins -> command

#if     LCD_Mode == LCD_8_Bit_Mode

		MGPIO_voidWritePort(LCD_DATA_PORT,cpy_u8Char);

#elif   LCD_Mode == LCD_4_Bit_Mode
		// Send most significant Bits first
		MGPIO_voidWritePort(LCD_DATA_PORT,(LCD_DATA_PORT & 0x0F)|(cpy_u8Char & 0xF0));// 0b01010011
		// Pulse Enable
		MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_EN_PIN,1);
		delay_ms(1);
		MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_EN_PIN,0);
		delay_ms(1);
		// Send Lowest significant Bits
		MGPIO_voidWritePort(LCD_DATA_PORT,(cpy_u8Char << 4)|(LCD_DATA_PORT & 0x0F));

#endif
		// Pulse Enable
		MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_EN_PIN,1);
		delay_ms(1);
		MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_EN_PIN,0);
		delay_ms(1);

}


void LCD_voidPrintString(char arr[])
{

	for(u8 i=0;arr[i]!='\0';i++)
	{
		LCD_voidSendChar(arr[i]);

	}

}

void LCD_voidClearDisplay(void)
{

	LCD_voidSendCommand(LCD_Clear);

}


void LCD_voidPrintNumberwithoutarray(s32 num)
{
	u32 rev = 0;

	while(num<0)  // Negative Number
	{
		LCD_voidSendChar('-');
		num *= -1;
	}
	while(num>0)
	{
		rev = rev*10 + (num%10);
		num /= 10;

	}
	while(rev>0)
	{
		LCD_voidSendChar((rev%10)+'0');
		rev /=10;
	}

}

void LCD_voidPrintNumberwitharray(s32 num)
{

	u8 arr[12]="";// {0}
	u8 i = 0;

	while(num<0) // Negative Number
	{
		LCD_voidSendChar('-');
		num *= -1;
	}
	while(num>0)
	{

		arr[i]=(num%10);
		num /= 10;
		i++;
	}

	for (s8 j=i-1;j>=0;j--)
	{
		LCD_voidSendChar(arr[j]+'0');
	}
}

void LCD_VoidSaveCoustomChar(u8 u8_arr[],u8 cpy_u8cgram_add)
{
	if(cpy_u8cgram_add < 8)
	{
		// Set CGRAM Address to Create A custom Char first and write on CGRAM
		LCD_voidSendCommand(0x40+(8*cpy_u8cgram_add));

		for(u8 i=0;i<8;i++)
		{
			// write the data from array which I created to the CGRAM
			LCD_voidSendChar(u8_arr[i]);
		}
		// Set DDRAM Address again to Display the Data from the CGRAM (0->7) which I created Before
		LCD_voidSendCommand(0x80);
	}


}

void LCD_voidSetCursorPosition(u8 cpy_u8LineNo,u8 cpy_u8Charpos)
{
	switch(cpy_u8LineNo)
	{
	case 0:
		LCD_voidSendCommand(0x80+cpy_u8Charpos+0);// first Line from 0 to 39
		break;
	case 1:
		LCD_voidSendCommand(0x80+cpy_u8Charpos+64);// Second Line from 64 to 103
		break;

	}
}

void delay_ms(unsigned int n )
{
	int j ;
	for(j=0;j<3180*n;j++) ;
	
}



