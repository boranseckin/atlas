#include "mm.h"

.section ".text.boot"

.globl _start
_start:
  mrs x0, mpidr_el1   // Get processor id
  and x0, x0, #0xFF   // And it with FF to strip the last byte
  cbz x0, master      // Compare to 0 and branch to master
  b proc_hang         // branch to proc_hang

proc_hang:
  wfe                 // Wait for event
  b proc_hang         // Branch to proc_hang

master:
  adr x0, bss_begin   // Get bss_begin
  adr x1, bss_end     // Get bss_end
  sub x1, x1, x0      // Substract the values
  bl memzero          // Branch with link to memzero

  mov sp, #LOW_MEMORY // Move the stack pointer to LOW_MEMORY
  bl kernel_main      // Branch with link to kernel_main
  b proc_hang         // Branch to proc_hang
