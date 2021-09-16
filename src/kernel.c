#include "mini_uart.h"
#include "utils.h"
#include "peripherals/aux.h"

void kernel_main()
{
  uart_init();
  uart_send_str("\nDON'T PANIC\n");

  while(1)
  {
    unsigned char c = uart_recv();
    switch (c)
    {
    case 'i':
      uart_send_hex(get32(AUX_MU_BAUD_REG));
      break;

    default:
      uart_send(c);
      break;
    }
  }
}
