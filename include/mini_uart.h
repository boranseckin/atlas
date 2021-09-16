#pragma once

unsigned int calculate_baudrate_counter();
void uart_init();
char uart_recv();
void uart_send(char c);
void uart_send_str(char *str);
void uart_send_hex(unsigned int hex);
