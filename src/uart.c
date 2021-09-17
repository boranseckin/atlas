#include "gpio.h"
#include "utils.h"
#include "peripherals/uart.h"
#include "uart.h"

#define TXD 14
#define RXD 15

void uart_init()
{
  GPIO_pin_set_func(TXD, GFAlt0);     // ALT0 = TXD0
  GPIO_pin_set_func(RXD, GFAlt0);     // ALT0 = RXD0

  /*
    11.5 Register View - BCM2711 ARM Peripherals

    CR Register

    Program the control registers as follows:
      1. Disable the UART.
      2. Wait for the end of transmission or reception of the current character.
      3. Flush the transmit FIFO by setting the FEN bit to 0 in the Line Control Register, UART_LCRH.
      4. Reprogram the Control Register, UART_CR.
      5. Enable the UART.
  */

  put32(UART_CR,   0);                               // Disable UART
  put32(UART_LCRH, (0 << 4));                        // Flush FIFO
  put32(UART_IMSC, 0);                               // Disable interupts
  put32(UART_IBRD, UART_IBRD_VAL);                   // Set integer part of the baudrate
  put32(UART_FBRD, UART_FBRD_VAL);                   // Set fraction part of the baudrate
  put32(UART_LCRH, (1 << 4) | (3 << 5));             // Enable FIFO and set 8 bit mode with no parity
  put32(UART_CR,   (1 << 0) | (1 << 8) | (1 << 9));  // Enable UART, RX and TX
}

char uart_recv()
{
  // RXFF @ UART_FR is 1 if receive FIFO is full.
  while (get32(UART_FR) & (1 << 4));

  // UART_DR is a 16 bit register, we only want the first 8 bits.
  return (get32(UART_DR) & 0xFF);
}

void uart_send(char c)
{
  // TXFF @ UART_FR is 1 if transmit FIFO is full.
  while (get32(UART_FR) & (1 << 5));

  put32(UART_DR, c);
}

void uart_send_str(char *str)
{
  while (*str)
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
	c[1] = (hex >> 8) & 0xFF;

	uart_send(c[0]);
	uart_send(c[1]);
}
