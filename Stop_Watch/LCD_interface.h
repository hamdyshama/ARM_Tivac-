

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

void LCD_voidInit(void);
void LCD_voidSendCommand(u8 cpy_u8Command);
void LCD_voidSendChar(u8 cpy_u8Char);
void LCD_voidPrintString(char arr[]);
void LCD_voidClearDisplay(void);
void LCD_voidPrintNumberwithoutarray(s32 num);
void LCD_voidPrintNumberwitharray(s32 num);
void LCD_VoidSaveCoustomChar(u8 u8_arr[],u8 cpy_u8cgram_add);
void LCD_voidSetCursorPosition(u8 cpy_u8LineNo,u8 cpy_u8Charpos);


#endif /* LCD_LCD_INTERFACE_H_ */
