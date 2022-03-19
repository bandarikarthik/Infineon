/*
 * systick.h
 *
 *  Created on: 19-Mar-2022
 *      Author: Admin
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_



#define MCU_CLK 120000000
#define ms 		120000
#define us 		120


extern void init_systick_timer(void);
extern void delay_ms(uint16_t delay);
extern void delay_us(uint16_t delay);
extern void SysTick_Handler(void);



#endif /* SYSTICK_H_ */
