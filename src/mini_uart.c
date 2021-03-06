#include "gpio.h"
#include "utils.h"
#include "peripherals/aux.h"
#include "mini_uart.h"

#define TXD 14
#define RXD 15

#define BAUD_RATE 115200

unsigned int calculate_baudrate_counter()
{
  // baudrate = system_clock_freq / (8 * (baudrate_reg + 1))
  return ((500000000 / BAUD_RATE) / 8) - 1;
}

void mini_uart_init() {
  GPIO_pin_set_func(TXD, GFAlt5);     // ALT5 = TXD1
  GPIO_pin_set_func(RXD, GFAlt5);     // ALT5 = RXD1

  put32(AUX_ENABLES,     1);      // Mini UART enable
  put32(AUX_MU_CNTL_REG, 0);      // Disable auto flow control and reciever/transmitter
  put32(AUX_MU_IER_REG,  0);      // Disable interrupts
  put32(AUX_MU_LCR_REG,  3);      // Enable 8-bit mode
  put32(AUX_MU_MCR_REG,  0);      // Set UART1_RTS line to high
  put32(                          // Set Baudrate to 115200 @ 500 MHz
    AUX_MU_BAUD_REG,
    calculate_baudrate_counter()
  );
  put32(AUX_MU_CNTL_REG, 3);      // Enable reciever/transmitter
}

char mini_uart_recv()
{
  // 1th bit @ MU_LSR says that there is at least 1 bit waiting to be read.
  while(!(get32(AUX_MU_LSR_REG) & 0x01));

  // MU_IO is a 32 bit register, we only want the first 8 bits.
	return (get32(AUX_MU_IO_REG) & 0xFF);
}

void mini_uart_send(char c)
{
  // 5th bit @ MU_LSR says that the transmitter can accept at least 1 bit
  while(!(get32(AUX_MU_LSR_REG) & 0x20));

	put32(AUX_MU_IO_REG, c);
}

void mini_uart_send_str(char *str)
{
  while(*str)
  {
    if (*str == '\n')
    {
      mini_uart_send('\r');
    }

    mini_uart_send(*str);
    str++;
  }
}

void mini_uart_send_hex(unsigned int hex)
{
	unsigned char c[2];

	c[0] = hex & 0xFF;
	c[1] = (hex>>8) & 0xFF;

	mini_uart_send(c[0]);
	mini_uart_send(c[1]);
}
