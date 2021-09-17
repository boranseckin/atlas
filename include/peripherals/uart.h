#pragma once

#include "peripherals/base.h"

/*
  11.5 Register View - BCM2711 ARM Peripherals

  FOR UART0
  Starts at 0x7e201000 but 0x7e000000 translates to 0xfe000000

  0x00 DR     Data Register
  0x04 RSRECR
  0x18 FR     Flag register
  0x20 ILPR   not in use
  0x24 IBRD   Integer Baud rate divisor
  0x28 FBRD   Fractional Baud rate divisor
  0x2c LCRH   Line Control register
  0x30 CR     Control register
  0x34 IFLS   Interrupt FIFO Level Select Register
  0x38 IMSC   Interrupt Mask Set Clear Register
  0x3c RIS    Raw Interrupt Status Register
  0x40 MIS    Masked Interrupt Status Register
  0x44 ICR    Interrupt Clear Register
  0x48 DMACR  DMA Control Register
  0x80 ITCR   Test Control register
  0x84 ITIP   Integration test input reg
  0x88 ITOP   Integration test output reg
  0x8c TDR    Test Data reg
*/

#define UART_DR     (UART_BASE + 0x00)
#define UART_RSRECR (UART_BASE + 0x04)
#define UART_FR     (UART_BASE + 0x18)
#define UART_ILPR   (UART_BASE + 0x20)
#define UART_IBRD   (UART_BASE + 0x24)
#define UART_FBRD   (UART_BASE + 0x28)
#define UART_LCRH   (UART_BASE + 0x2c)
#define UART_CR     (UART_BASE + 0x30)
#define UART_IFLS   (UART_BASE + 0x34)
#define UART_IMSC   (UART_BASE + 0x38)
#define UART_RIS    (UART_BASE + 0x3c)
#define UART_MIS    (UART_BASE + 0x40)
#define UART_ICR    (UART_BASE + 0x44)
#define UART_DMACR  (UART_BASE + 0x48)
#define UART_ITCR   (UART_BASE + 0x80)
#define UART_ITIP   (UART_BASE + 0x84)
#define UART_ITOP   (UART_BASE + 0x88)
#define UART_TDR    (UART_BASE + 0x8c)
