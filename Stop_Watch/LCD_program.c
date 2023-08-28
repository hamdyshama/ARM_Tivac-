

#include"STD_TYPE.h"
#include"BIT_MATH.h"
#include "tm4c123gh6pm.h"
#include "../SYSTICK_driver/SYSTICK_Interface.h"

#include "../GPIO_driver/GPIO_Interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"



void LCD_voidInit(void)
{
    GPIO_void_Init();
	// RS
	GPIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,GPIO_OUTPUT);
	// RW
	GPIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,GPIO_OUTPUT);
	// E
	GPIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_OUTPUT);
	// Data Pins

#if    LCD_Mode == LCD_8_Bit_Mode
	GPIO_voidSetPortDirection(LCD_DATA_PORT,GPIO_OUTPUT);
	delay_SYSTICK_ms(5);
	LCD_voidSendCommand(LCD_Function_Set); // Function Set 0b00111000
	delay_SYSTICK_ms(1);
	LCD_voidSendCommand(LCD_ON_OFF); // ON/OFF Control
	delay_SYSTICK_ms(1);
	LCD_voidSendCommand(0x01); // Display Clear  0b00000001
	delay_SYSTICK_ms(2);
	LCD_voidSendCommand(LCD_Entry_Mode_Set); // Entry Mode Set  0b00000110
	delay_SYSTICK_ms(5);
#elif  LCD_Mode == LCD_4_Bit_Mode

		GPIO_voidSetPinDirection(LCD_DATA_PORT, PIN0, GPIO_OUTPUT);
		GPIO_voidSetPinDirection(LCD_DATA_PORT, PIN1, GPIO_OUTPUT);
		GPIO_voidSetPinDirection(LCD_DATA_PORT, PIN2, GPIO_OUTPUT);
		GPIO_voidSetPinDirection(LCD_DATA_PORT, PIN3, GPIO_OUTPUT);
		delay_SYSTICK_ms(50);
	    LCD_voidSendCommand(0x33);
	    delay_SYSTICK_ms(1);
	    LCD_voidSendCommand(0x32);	// Send for 4 bit initialization of LCD
	    delay_SYSTICK_ms(1);
	    LCD_voidSendCommand(0x28);	// 2 line, 5*7 matrix in 4-bit mode
	    delay_SYSTICK_ms(1);
	    LCD_voidSendCommand(0x0c);	// Display on cursor off
	    delay_SYSTICK_ms(1);
	    LCD_voidSendCommand(0x06);	// Increment cursor (shift cursor to right)
	    delay_SYSTICK_ms(2);
	    LCD_voidSendCommand(0x01);	// Clear display screen
	    delay_SYSTICK_ms(5);

#endif


}


void LCD_voidSendCommand(u8 cpy_u8Command)
{
        GPIO_void_Init();
		// RS -> LOW
		GPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,GPIO_LOW);
		// RW -> LOW
		GPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,GPIO_LOW);
		// DB Pins -> command
#if     LCD_Mode == LCD_8_Bit_Mode

		GPIO_voidSetPortValue(LCD_DATA_PORT,cpy_u8Command);// 0b01010011

#elif      LCD_Mode == LCD_4_Bit_Mode
		// Send most significant Bits first
		GPIO_voidSetPortValue(LCD_DATA_PORT,(LCD_DATA_PORT & 0x0F)|(cpy_u8Command & 0xF0));// 0b01010011
		// Pulse Enable
		GPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_HIGH);
		delay_SYSTICK_ms(1);
		GPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_LOW);
		delay_SYSTICK_ms(1);
		// Send Lowest significant Bits
		GPIO_voidSetPortValue(LCD_DATA_PORT,(cpy_u8Command << 4)|(LCD_DATA_PORT & 0x0F));

#endif
	// Pulse Enable
    GPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_HIGH);
	delay_SYSTICK_ms(1);
	GPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_LOW);
	delay_SYSTICK_ms(1);

}

void LCD_voidSendChar(u8 cpy_u8Char)
{
       GPIO_void_Init();
	    // RS -> HIGH
       GPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,GPIO_HIGH);
		// RW -> LOW
       GPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,GPIO_LOW);
		// DB Pins -> command

#if     LCD_Mode == LCD_8_Bit_Mode

       GPIO_voidSetPortValue(LCD_DATA_PORT,cpy_u8Char);

#elif   LCD_Mode == LCD_4_Bit_Mode
		// Send most significant Bits first
		MGPIO_voidWritePort(LCD_DATA_PORT,(LCD_DATA_PORT & 0x0F)|(cpy_u8Char & 0xF0));// 0b01010011
		// Pulse Enable
		MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_EN_PIN,1);
		delay_SYSTICK_ms(1);
		MGPIO_voidWriteData(LCD_CTRL_PORT,LCD_EN_PIN,0);
		delay_SYSTICK_ms(1);
		// Send Lowest significant Bits
		MGPIO_voidWritePort(LCD_DATA_PORT,(cpy_u8Char << 4)|(LCD_DATA_PORT & 0x0F));

#endif
		// Pulse Enable
		GPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_HIGH);
		delay_SYSTICK_ms(1);
		GPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_LOW);
		delay_SYSTICK_ms(1);

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



