


#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

// 11 Pins
// 8-Bit Mode : 8 data Pins + 3 Control Pins

// 7 Pins
// 4-Bit Mode : 4 data Pins + 3 control Pins
// D4->D7



#define  LCD_Mode       LCD_8_Bit_Mode
#define  LCD_CTRL_PORT  GPIOE_PORT
#define  LCD_DATA_PORT  GPIOB_PORT
#define  LCD_RS_PIN      PIN0
#define  LCD_RW_PIN      PIN1
#define  LCD_EN_PIN      PIN2

#endif /* LCD_LCD_CONFIG_H_ */
