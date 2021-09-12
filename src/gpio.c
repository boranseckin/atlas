#include "gpio.h"
#include "utils.h"

void GPIO_pin_set_func(unsigned char pinNumber, GPIOFunc func)
{
  // Get the starting pin number by multiplying by 3 because each pin has 3 bits,
  // and modulus by 30 because each register has upto 30 bits.
  // This is the starting bit of the function inside a register.
  unsigned char startingBit = (pinNumber * 3) % 30;
  
  // To get the actual register, divide by 10 beacuse each register has upto 10 functions.
  // This is the register number where the pin is in.
  unsigned int reg = pinNumber / 10;

  unsigned long address;
  if      (reg == 0) address = GPFSEL0;
  else if (reg == 1) address = GPFSEL1;
  else if (reg == 2) address = GPFSEL2;
  else if (reg == 3) address = GPFSEL3;
  else if (reg == 4) address = GPFSEL4;
  else if (reg == 5) address = GPFSEL5;

  unsigned int selector = get32(address);
  
  // Reset the function on the selector, then set the provided func.
  selector &= ~(7 << startingBit);
  selector |= (func << startingBit);

  put32(address, selector);
}
