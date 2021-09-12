#pragma once

#include "peripherals/base.h"

/*
  5.2. Register View - BCM2711 ARM Peripherals

  0x00 GPFSEL0                 GPIO Function Select 0
  0x04 GPFSEL1                 GPIO Function Select 1
  0x08 GPFSEL2                 GPIO Function Select 2
  0x0c GPFSEL3                 GPIO Function Select 3
  0x10 GPFSEL4                 GPIO Function Select 4
  0x14 GPFSEL5                 GPIO Function Select 5
  0x1c GPSET0                  GPIO Pin Output Set 0
  0x20 GPSET1                  GPIO Pin Output Set 1
  0x28 GPCLR0                  GPIO Pin Output Clear 0
  0x2c GPCLR1                  GPIO Pin Output Clear 1
  0x34 GPLEV0                  GPIO Pin Level 0
  0x38 GPLEV1                  GPIO Pin Level 1
  0x40 GPEDS0                  GPIO Pin Event Detect Status 0
  0x44 GPEDS1                  GPIO Pin Event Detect Status 1
  0x4c GPREN0                  GPIO Pin Rising Edge Detect Enable 0
  0x50 GPREN1                  GPIO Pin Rising Edge Detect Enable 1
  0x58 GPFEN0                  GPIO Pin Falling Edge Detect Enable 0
  0x5c GPFEN1                  GPIO Pin Falling Edge Detect Enable 1
  0x64 GPHEN0                  GPIO Pin High Detect Enable 0
  0x68 GPHEN1                  GPIO Pin High Detect Enable 1
  0x70 GPLEN0                  GPIO Pin Low Detect Enable 0
  0x74 GPLEN1                  GPIO Pin Low Detect Enable 1
  0x7c GPAREN0                 GPIO Pin Async. Rising Edge Detect 0
  0x80 GPAREN1                 GPIO Pin Async. Rising Edge Detect 1
  0x88 GPAFEN0                 GPIO Pin Async. Falling Edge Detect 0
  0x8c GPAFEN1                 GPIO Pin Async. Falling Edge Detect 1
  0xe4 GPIO_PUP_PDN_CNTRL_REG0 GPIO Pull-up / Pull-down Register 0
  0xe8 GPIO_PUP_PDN_CNTRL_REG1 GPIO Pull-up / Pull-down Register 1
  0xec GPIO_PUP_PDN_CNTRL_REG2 GPIO Pull-up / Pull-down Register 2
  0xf0 GPIO_PUP_PDN_CNTRL_REG3 GPIO Pull-up / Pull-down Register 3
*/

#define GPFSEL0 (GPIO_BASE + 0x00)
#define GPFSEL1 (GPIO_BASE + 0x04)
#define GPFSEL2 (GPIO_BASE + 0x08)
#define GPFSEL3 (GPIO_BASE + 0x0c)
#define GPFSEL4 (GPIO_BASE + 0x10)
#define GPFSEL5 (GPIO_BASE + 0x14)
#define GPSET1  (GPIO_BASE + 0x20)
#define GPCLR0  (GPIO_BASE + 0x28)
#define GPPUPD0 (GPIO_BASE + 0xe4)
#define GPPUPD1 (GPIO_BASE + 0xe8)
#define GPPUPD2 (GPIO_BASE + 0xec)
#define GPPUPD3 (GPIO_BASE + 0xf0)

// struct GPIOPinData
// {
//   volatile unsigned long reserved;
//   volatile unsigned long data[2];
// };

// struct GPIORegs
// {
//   volatile unsigned long FUNC_SELECT[6];
//   struct GPIOPinData OUTPUT_SET;
//   struct GPIOPinData OUTPUT_CLEAR;
//   struct GPIOPinData LEVEL;
//   struct GPIOPinData EV_DETECT_STATUS;
//   struct GPIOPinData RE_DETECT_ENABLE;
//   struct GPIOPinData FE_DETECT_ENABLE;
//   struct GPIOPinData HE_DETECT_ENABLE;
//   struct GPIOPinData LE_DETECT_ENABLE;
//   struct GPIOPinData ASYNC_RE_DETECT;
//   struct GPIOPinData ASYNC_FE_DETECT;
//   volatile unsigned long RESERVED[11];
//   volatile unsigned long PUPD_CNTRL[4];
//   // volatile unsigned long reserved;
//   // volatile unsigned long PUPD_ENABLE;
//   // volatile unsigned long PUPD_ENABLE_CLOCKS[2];
// };

// #define REGS_GPIO ((struct GPIORegs *)(GPIO_BASE))
