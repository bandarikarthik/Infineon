/*
 * main.c
 *
 *  Created on: 2021 Dec 04 10:14:10
 *  Author: Admin
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include <stdio.h>
#include"systick.h"
/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */
int a;
int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */


  init_systick_timer();


  while(1U)
  {

  }
}
/*
 *
 * 1ms value count ticks 1000 will be equal to 1sec the LED will toggle ON/OFF 1sec
 *
 */
void SysTick_Handler(void)
{

	a++;
	if(a==1000)
	{
		DIGITAL_IO_ToggleOutput(&DIGITAL_IO_0);
		a=0;
	}

}
