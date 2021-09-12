#pragma once

#include "peripherals/base.h"

/*
  2.1. Overview - BCM2711 ARM Peripherals

  Starts at 0x7e215000 but 0x7e000000 translates to 0xfe000000

  0x00 AUX_IRQ         Auxiliary Interrupt status
  0x04 AUX_ENABLES     Auxiliary enables
  0x40 AUX_MU_IO_REG   Mini UART I/O Data
  0x44 AUX_MU_IER_REG  Mini UART Interrupt Enable
  0x48 AUX_MU_IIR_REG  Mini UART Interrupt Identify
  0x4c AUX_MU_LCR_REG  Mini UART Line Control
  0x50 AUX_MU_MCR_REG  Mini UART Modem Control
  0x54 AUX_MU_LSR_REG  Mini UART Line Status
  0x58 AUX_MU_MSR_REG  Mini UART Modem Status
  0x5c AUX_MU_SCRATCH  Mini UART Scratch
  0x60 AUX_MU_CNTL_REG Mini UART Extra Control
  0x64 AUX_MU_STAT_REG Mini UART Extra Status
  0x68 AUX_MU_BAUD_REG Mini UART Baudrate
*/

#define AUX_IRQ         (AUX_BASE + 0x00)
#define AUX_ENABLES     (AUX_BASE + 0x04)
#define AUX_MU_IO_REG   (AUX_BASE + 0x40)
#define AUX_MU_IER_REG  (AUX_BASE + 0x44)
#define AUX_MU_IIR_REG  (AUX_BASE + 0x48)
#define AUX_MU_LCR_REG  (AUX_BASE + 0x4c)
#define AUX_MU_MCR_REG  (AUX_BASE + 0x50)
#define AUX_MU_LSR_REG  (AUX_BASE + 0x54)
#define AUX_MU_MSR_REG  (AUX_BASE + 0x58)
#define AUX_MU_SCRATCH  (AUX_BASE + 0x5c)
#define AUX_MU_CNTL_REG (AUX_BASE + 0x60)
#define AUX_MU_STAT_REG (AUX_BASE + 0x64)
#define AUX_MU_BAUD_REG (AUX_BASE + 0x68)

// struct AuxRegs
// {
//   volatile unsigned long IRQ;
//   volatile unsigned long ENABLES;
//   volatile unsigned long RESERVED[14];   // Reserved space between 0x04 and 0x40
//   volatile unsigned long MU_IO;
//   volatile unsigned long MU_IER;
//   volatile unsigned long MU_IIR;
//   volatile unsigned long MU_LCR;
//   volatile unsigned long MU_MCR;
//   volatile unsigned long MU_LSR;
//   volatile unsigned long MU_MSR;
//   volatile unsigned long MU_SCRATCH;
//   volatile unsigned long MU_CNTL;
//   volatile unsigned long MU_STAT;
//   volatile unsigned long MU_BAUD;
// };

// // Pointer to the struct starting from auxiliary base
// #define REGS_AUX ((struct AuxRegs *)(AUX_BASE))
