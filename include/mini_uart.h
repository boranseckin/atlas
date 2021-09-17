#pragma once

unsigned int calculate_baudrate_counter();
void mini_uart_init();
char mini_uart_recv();
void mini_uart_send(char c);
void mini_uart_send_str(char *str);
void mini_uart_send_hex(unsigned int hex);
