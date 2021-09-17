#include "uart.h"

void kernel_main()
{
  uart_init();
  uart_send_str("\nDON'T PANIC\n");

  while(1)
  {
    uart_send(uart_recv());
  }
}
