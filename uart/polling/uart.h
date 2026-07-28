#ifndef UART_H //include guards
#define UART_H //definition

#include <stdint.h>

// uint8_t      unsigned 8-bit
// uint16_t     unsigned 16-bit
// uint32_t     unsigned 32-bit

// int8_t       signed 8-bit
// int16_t      signed 16-bit
// int32_t      signed 32-bit

void uart_init(void); // function void returns void/nothing

void uart_send_byte(uint8_t data); // send eight bit data and return nothing

uint8_t uart_receive_byte(void); // Receive one 8-bit byte with no input arguments

void uart_send_string(const char *str); // Send a string of characters and return nothing

#endif