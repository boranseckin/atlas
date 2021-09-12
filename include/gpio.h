#pragma once

#include "peripherals/gpio.h"

/*
  5.2. Register View - BCM2711 ARM Peripherals

  GPIO Function Select
  000 = GPIO Pin [#] is an input
  001 = GPIO Pin [#] is an output
  100 = GPIO Pin [#] takes alternate function 0
  101 = GPIO Pin [#] takes alternate function 1
  110 = GPIO Pin [#] takes alternate function 2
  111 = GPIO Pin [#] takes alternate function 3
  011 = GPIO Pin [#] takes alternate function 4
  010 = GPIO Pin [#] takes alternate function 5

  Each function select has 3 bits and there are 10 of them in each register.
*/

typedef enum _GPIOFunc
{
  GFInptut = 0,
  GFOutput = 1,
  GFAlt0 = 4,
  GFAlt1 = 5,
  GFAlt2 = 6,
  GFAlt3 = 7,
  GFAlt4 = 3,
  GFAlt5 = 2
} GPIOFunc;

void GPIO_pin_set_func(unsigned char pinNumber, GPIOFunc func);
