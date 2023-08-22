/*************************************************************************************************
 Author     : Hamdy Al Sayed                                                                         *
 Data         :  13/8/2023                                                                              *
 Version    :  01                                                                                     *
************** ***************************************************************************************/


#include"STD_TYPE.h"
#include"BIT_MATH.h"
#include "tm4c123gh6pm.h"
#include"GPIO_config.h"


// Function Init  of GPIO PORT
void MGIO_voidInitPort(u8 Copy_u8Port)
{
    switch (port) {
        case PORTA:
            SYSCTL_RCGCGPIO_R |= 0x00000001;
            while(SYSCTL_RCGCGPIO_R & 0x00000001 == 0);
            GPIO_PORTA_LOCK_R = 0x4C4F434B;
            GPIO_PORTA_CR_R = 0xFF;
            break;
        case PORTB:
            SYSCTL_RCGCGPIO_R |= 0x00000002;
            while(SYSCTL_RCGCGPIO_R & 0x00000002 == 0);
            GPIO_PORTB_LOCK_R = 0x4C4F434B;
            GPIO_PORTB_CR_R = 0xFF;
            break;
        case PORTC:
            SYSCTL_RCGCGPIO_R |= 0x00000004;
            while(SYSCTL_RCGCGPIO_R & 0x00000004 == 0);
            GPIO_PORTC_LOCK_R = 0x4C4F434B;
            GPIO_PORTC_CR_R = 0xFF;
            break;
        case PORTD:
            SYSCTL_RCGCGPIO_R |= 0x00000008;
            while(SYSCTL_RCGCGPIO_R & 0x00000008 == 0);
            GPIO_PORTD_LOCK_R = 0x4C4F434B;
            GPIO_PORTD_CR_R = 0xFF;
            break;
        case PORTE:
            SYSCTL_RCGCGPIO_R |= 0x00000010;
            while(SYSCTL_RCGCGPIO_R & 0x00000010 == 0);
            GPIO_PORTE_LOCK_R = 0x4C4F434B;
            GPIO_PORTE_CR_R = 0xFF;
            break;
        case PORTF:
            SYSCTL_RCGCGPIO_R |= 0x00000020;
            while(SYSCTL_RCGCGPIO_R & 0x00000020 == 0);
            GPIO_PORTF_LOCK_R = 0x4C4F434B;
            GPIO_PORTF_CR_R = 0xFF;
            break;
        default:
            break;
    }
}
    
// Function Set The Direction of Pin
void MGOIP_voidSetPinDir(u8 Copy_u8Port ,u8 copy_u8Pin,u8 Copy_Direction)
{
   if(Copy_Direction == DIR_OUT )
  { 
    switch(Copy_u8Port)
    {
    case GPIOA_PORT :  SET_BIT(GPIO_PORTA_DIR_R,Copy_Direction);               break ;
    case GPIOB_PORT :  SET_BIT(GPIO_PORTB_DIR_R,Copy_Direction);               break ;
    case GPIOC_PORT :  SET_BIT(GPIO_PORTC_DIR_R,Copy_Direction);               break ;
    case GPIOD_PORT :  SET_BIT(GPIO_PORTD_DIR_R,Copy_Direction);               break ;
    case GPIOE_PORT :  SET_BIT(GPIO_PORTE_DIR_R,Copy_Direction);               break ;
    case GPIOF_PORT :  SET_BIT(GPIO_PORTF_DIR_R,Copy_Direction);               break ;
    default :                                                                      break ;
    }                   
  }                     
  else                  
  {                     
    switch(Copy_u8Port)
    {                   
    case GPIOA_PORT :  CLR_BIT(GPIO_PORTA_DIR_R,Copy_Direction);               break ;
    case GPIOB_PORT :  CLR_BIT(GPIO_PORTB_DIR_R,Copy_Direction);               break ;
    case GPIOC_PORT :  CLR_BIT(GPIO_PORTC_DIR_R,Copy_Direction);               break ;
    case GPIOD_PORT :  CLR_BIT(GPIO_PORTD_DIR_R,Copy_Direction);               break ;
    case GPIOE_PORT :  CLR_BIT(GPIO_PORTE_DIR_R,Copy_Direction);               break ;
    case GPIOF_PORT :  CLR_BIT(GPIO_PORTF_DIR_R,Copy_Direction);               break ;
    default :                                                                      break ;
    }
  }
  
  
}

//   Function Set The corresponding pin's weak pull-up resistor is enabled.	
void MGPIO_voidSetPullUp(u8 copy_u8Port ,u8 Copy_u8Pin)
{
   switch(Copy_u8Port)
    {
          case GPIOA_PORT :  SET_BIT(GPIO_PORTA_PUR_R,Copy_u8Pin);         break ;
          case GPIOB_PORT :  SET_BIT(GPIO_PORTB_PUR_R,Copy_u8Pin);         break ;
          case GPIOC_PORT :  SET_BIT(GPIO_PORTC_PUR_R,Copy_u8Pin);         break ;
          case GPIOD_PORT :  SET_BIT(GPIO_PORTD_PUR_R,Copy_u8Pin);         break ;
          case GPIOE_PORT :  SET_BIT(GPIO_PORTE_PUR_R,Copy_u8Pin);         break ;
          case GPIOF_PORT :  SET_BIT(GPIO_PORTF_PUR_R,Copy_u8Pin);         break ;
          default :                                                             break ;
    }
  
}

 //  Function Set The corresponding pin's weak pull-Down resistor is enabled.	
void MGPIO_voidSetPullDown(u8 Copy_u8ort ,u8 Copy_u8Pin)
{
     switch(Copy_u8PORT)
    {
          case GPIOA_PORT :  SET_BIT(GPIO_PORTA_PDR_R,Copy_u8Pin);         break ;
          case GPIOB_PORT :  SET_BIT(GPIO_PORTB_PDR_R,Copy_u8Pin);         break ;
          case GPIOC_PORT :  SET_BIT(GPIO_PORTC_PDR_R,Copy_u8Pin);         break ;
          case GPIOD_PORT :  SET_BIT(GPIO_PORTD_PDR_R,Copy_u8Pin);         break ;
          case GPIOE_PORT :  SET_BIT(GPIO_PORTE_PDR_R,Copy_u8Pin);         break ;
          case GPIOF_PORT :  SET_BIT(GPIO_PORTF_PDR_R,Copy_u8Pin);         break ;
          default :                                        break ;
    }
  
}

// Function To Write Data At DATA  = High |  LOW

void MGPIO_voidWriteData(u8 Copy_u8port ,u8 Copy_u8Pin , u8 Copy_u8Value )
{
  if(Copy_u8Value == HIGH )
  {
     switch (Copy_u8Port)
    {
          case GPIOA_PORT :  SET_BIT(GPIO_PORTA_DATA_R,Copy_u8Value);       break ;
          case GPIOB_PORT :  SET_BIT(GPIO_PORTB_DATA_R,Copy_u8Value);       break ;
          case GPIOC_PORT :  SET_BIT(GPIO_PORTC_DATA_R,Copy_u8Value);       break ;
          case GPIOD_PORT :  SET_BIT(GPIO_PORTD_DATA_R,Copy_u8Value);       break ;
          case GPIOE_PORT :  SET_BIT(GPIO_PORTE_DATA_R,Copy_u8Value);       break ;
          case GPIOF_PORT :  SET_BIT(GPIO_PORTF_DATA_R,Copy_u8Value);       break ;
          default :                                                      break ;
    }           
  }             
  else          
  {             
       switch Ccopy_u8PORT)
    {           
          case GPIOA_PORT :  CLR_BIT(GPIO_PORTA_DATA_R,Copy_u8Value);         break ;
          case GPIOB_PORT :  CLR_BIT(GPIO_PORTB_DATA_R,Copy_u8Value);         break ;
          case GPIOC_PORT :  CLR_BIT(GPIO_PORTC_DATA_R,Copy_u8Value);         break ;
          case GPIOD_PORT :  CLR_BIT(GPIO_PORTD_DATA_R,Copy_u8Value);         break ;
          case GPIOE_PORT :  CLR_BIT(GPIO_PORTE_DATA_R,Copy_u8Value);         break ;
          case GPIOF_PORT :  CLR_BIT(GPIO_PORTF_DATA_R,Copy_u8Value);         break ;
          default :                                                          break ;
    }
    
  }
}
    

// Function To Read Data From Data REG
u8 MGPIO_u8ReadData(u8 Copy_u8Port ,u8 Copy_u8Pin)
{
  u8 u8Local_Data = 0 ;
  switch (Copy_u8Port)
  {
        case GPIOA_PORT : u8Local_Data = GET_BIT(GPIO_PORTA_DATA_R,Copy_u8Pin);  break ;
        case GPIOB_PORT : u8Local_Data = GET_BIT(GPIO_PORTB_DATA_R,Copy_u8Pin);  break ;
        case GPIOC_PORT : u8Local_Data = GET_BIT(GPIO_PORTC_DATA_R,Copy_u8Pin);  break ;
        case GPIOD_PORT : u8Local_Data = GET_BIT(GPIO_PORTD_DATA_R,Copy_u8Pin);  break ;
        case GPIOE_PORT : u8Local_Data = GET_BIT(GPIO_PORTE_DATA_R,Copy_u8Pin);  break ;
        case GPIOF_PORT : u8Local_Data = GET_BIT(GPIO_PORTF_DATA_R,Copy_u8Pin);  break ;
        default :                                                               break ;
  }
  return u8Local_Data ;
}
  
// Function  to write  Port  Direction
void MGPIO_voidPortDir(u8 Copy_u8Port ,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{                                    
		case GPIOA_PORT : GPIO_PORTA_DIR_R =  Copy_u8Value;   break ;
		case GPIOB_PORT : GPIO_PORTB_DIR_R =  Copy_u8Value;   break ;
		case GPIOC_PORT : GPIO_PORTC_DIR_R =  Copy_u8Value;   break ;
		case GPIOD_PORT : GPIO_PORTD_DIR_R =  Copy_u8Value;   break ;
		case GPIOE_PORT : GPIO_PORTE_DIR_R =  Copy_u8Value;   break ;
		case GPIOF_PORT : GPIO_PORTF_DIR_R =  Copy_u8Value;   break ;
        default :                                             break ;
		
	}
	
	
}
// Function  to write  Port  Value
void MGPIO_voidWritePort(u8 Copy_u8Port ,u8 Copy_u8Value)
{
    switch(Copy_u8PORT)
    {
        case GPIOA_PORT : GPIO_PORTA_DATA_R =  Copy_u8Value ;   break ;
        case GPIOB_PORT : GPIO_PORTB_DATA_R =  Copy_u8Value ;   break ;
        case GPIOC_PORT : GPIO_PORTC_DATA_R =  Copy_u8Value ;   break ;
        case GPIOD_PORT : GPIO_PORTD_DATA_R =  Copy_u8Value ;   break ;
        case GPIOE_PORT : GPIO_PORTE_DATA_R =  Copy_u8Value ;   break ;
        case GPIOF_PORT : GPIO_PORTF_DATA_R =  Copy_u8Value ;   break ;
        default :                                               break ;

    }


}

// Function  to make  Port --> Pull Up ( Now  Pins --> High
void MGPIO_voidSetPullUp(u8 copy_u8PORT ,u8 copy_u8PVal)  
{
   switch(copy_u8PORT)
    {
          case GPIOA_PORT :  GPIO_PORTA_PDR_R =copy_u8PVal;         break ;
          case GPIOB_PORT :  GPIO_PORTB_PDR_R =copy_u8PVal;         break ;
          case GPIOC_PORT :  GPIO_PORTC_PDR_R =copy_u8PVal;         break ;
          case GPIOD_PORT :  GPIO_PORTD_PDR_R =copy_u8PVal;         break ;
          case GPIOE_PORT :  GPIO_PORTE_PDR_R =copy_u8PVal;         break ;
          case GPIOF_PORT :  GPIO_PORTF_PDR_R =copy_u8PVal;         break ;
          default :                                                 break ;
    }
  
}
