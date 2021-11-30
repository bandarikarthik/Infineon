
/* This application is for on board debugger Uart you can establish this communication with usb debugger cable which come with the board */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include"xmc_uart.h"
#include"xmc_gpio.h"
#include"xmc4_gpio.h"

 char data[] = "Hello_world!!\r\n";

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

XMC_GPIO_CONFIG_t uart_Tx =
{
		.mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT4,
		.output_level     = XMC_GPIO_OUTPUT_LEVEL_HIGH,
		.output_strength  = XMC_GPIO_OUTPUT_STRENGTH_STRONG_SOFT_EDGE

};

const XMC_UART_CH_CONFIG_t UARTconfig =
{
  .baudrate      = 115200U,
  .data_bits     = 8U,
  .frame_length  = 8U,
  .stop_bits     = 1U,
  .oversampling  = 16U,
  .parity_mode   = XMC_USIC_CH_PARITY_MODE_NONE
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

  XMC_GPIO_Init(XMC_GPIO_PORT1, 15U, &uart_Tx);
  XMC_UART_CH_Init(XMC_UART1_CH0, &UARTconfig);
  XMC_UART_CH_Start(XMC_UART1_CH0);

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	  for (int i = 0; i < sizeof(data) - 1; i++)
      {
	  XMC_UART_CH_Transmit(XMC_UART1_CH0,data[i]);
      }

      for(int j=0;j<1000000;j++);

  }
}
