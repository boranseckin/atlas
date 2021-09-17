#include "mini_uart.h"
#include "utils.h"
#include "peripherals/aux.h"

void kernel_main()
{
  mini_uart_init();
  mini_uart_send_str("\nDON'T PANIC\n");

  while(1)
  {
    unsigned char c = mini_uart_recv();
    switch (c)
    {
    case 'i':
      mini_uart_send_hex(get32(AUX_MU_BAUD_REG));
      break;

    default:
      mini_uart_send(c);
      break;
    }
  }
}
