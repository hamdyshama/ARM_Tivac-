
#ifndef SYSTICK_DRIVER_SYSTICK_INTERFACE_H_
#define SYSTICK_DRIVER_SYSTICK_INTERFACE_H_


void SYSTICK_void_INIT(void);
void delay_SYSTICK_ms(int n);     // delay milli second
void delay_SYSTICK_MS(int n);    //  delay micro second
void stop_timer(void);
#endif /* SYSTICK_DRIVER_SYSTICK_INTERFACE_H_ */
