/*
 * main.c
 *
 *  Created on: 2021 june 29 17:31:26
 *  Author: bandari karthik
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include"xmc_gpio.h"
#include"xmc4_gpio.h"
#include"XMC4400.h"

#define PIN 6


/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

void delay(void);



XMC_GPIO_CONFIG_t pin =
{
		.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
		.output_level= XMC_GPIO_OUTPUT_LEVEL_LOW,
		.output_strength=  XMC_GPIO_OUTPUT_STRENGTH_STRONG_SOFT_EDGE

};


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

  XMC_GPIO_Init(XMC_GPIO_PORT0 ,PIN, &pin);

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

	  XMC_GPIO_ToggleOutput(XMC_GPIO_PORT0, PIN);
	  delay();

  }
}



void delay(void)
{
	int i;
	for(i=0;i<500000;i++);
}


