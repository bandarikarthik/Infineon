/*
 * systick.c
 *
 *  Created on: 19-Mar-2022
 *      Author: Admin
 */

/*
 * systick.c
 *
 *  Created on: 19-Nov-2021
 *      Author: Admin
 */
 //This project was implemented on STM32f401RB custom board and infenion XMC4400 platform to kit to toggle the led with delay
// generic for any cortex M4 series MCU
// just change the Mcu clock in systick.h file according to our MCU clk speed
/*
 * systick.c
 *
 *  Created on: 19-Nov-2021
 *      Author: Admin
 */
#include<stdint.h>
#include"systick.h"


uint32_t *pSRVR = (uint32_t*)0xE000E014;    //load value
uint32_t *pSCSR = (uint32_t*)0xE000E010;    //status and control registers
uint32_t *pCVR  = (uint32_t*)0xE000E018;      //systick current value register

void init_systick_timer(void)
{
	*pSCSR  = 0x0;
	*pCVR  = 0x0;
	*pSRVR = 120000;
	*pSCSR |= 0x7;

}

void delay_ms(uint16_t delay)
{
	*pSRVR = (ms*delay)-1;
	*pCVR  = 0x0;
	while((*pSCSR & 0x10000)==0)
	{
		;
	}

}


void delay_us(uint16_t delay)
{
	*pSRVR = (us*delay)-1;
	*pCVR  = 0x0;
	while((*pSCSR & 0x10000)==0)
	{
		;
	}

}

