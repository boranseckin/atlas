#include "gpio.h"
#include "utils.h"
#include "peripherals/aux.h"
#include "mini_uart.h"

#define TXD 14
#define RXD 15

void uart_init() {
  GPIO_pin_set_func(TXD, GFAlt5);     // ALT5 = TXD1
  GPIO_pin_set_func(RXD, GFAlt5);     // ALT5 = RXD1

  put32(AUX_ENABLES,     1);      // Mini UART enable
  put32(AUX_MU_CNTL_REG, 0);      // Disable auto flow control and reciever/transmitter
  put32(AUX_MU_IER_REG,  0);      // Disable interrupts
  put32(AUX_MU_LCR_REG,  3);      // Enable 8-bit mode
  put32(AUX_MU_MCR_REG,  0);      // Set UART1_RTS line to high
  put32(AUX_MU_BAUD_REG, 541);    // Set Baudrate to 115200 @ 500 MHz
  put32(AUX_MU_CNTL_REG, 3);      // Enable reciever/transmitter

  uart_send_str("Mini-UART is initialized.\n");
}

char uart_recv()
{
  // 1th bit @ MU_LSR says that there is at least 1 bit waiting to be read.
  while(!(get32(AUX_MU_LSR_REG) & 0x01));

  // MU_IO is a 32 bit register, we only want the first 8 bits.
	return (get32(AUX_MU_IO_REG) & 0xFF);
}

void uart_send(char c)
{
  // 5th bit @ MU_LSR says that the transmitter can accept at least 1 bit
  while(!(get32(AUX_MU_LSR_REG) & 0x20));

	put32(AUX_MU_IO_REG, c);
}

void uart_send_str(char *str)
{
  while(*str)
  {
    if (*str == '\n')
    {
      uart_send('\r');
    }

    uart_send(*str);
    str++;
  }
}

void uart_send_hex(unsigned int hex)
{
	unsigned char c[2];

	c[0] = hex & 0xFF;
	c[1] = (hex>>8) & 0xFF;

	uart_send(c[0]);
	uart_send(c[1]);
}
