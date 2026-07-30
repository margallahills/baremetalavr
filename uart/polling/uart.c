#include <avr/io.h>
#include "uart.h"

#define BAUD 9600UL

#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)

// UBRR0H,UBRR0L
// This is a 12-bit register which contains the USART baud rate. The UBRRnH contains the four 
// most significant bits, and the UBRRnL contains the eight least significant bits of the USART
// baud rate. Ongoing transmissions by the transmitter and receiver will be corrupted if the
// baud rate is changed. Writing UBRRnL will trigger an immediate update of the baud rate
// prescaler.



void uart_init(void)
{
    UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
    UBRR0L = (uint8_t)UBRR_VALUE;

// UCSR0B
// 7 6 5 4 3 2 1 0
// RXCIEn TXCIEn UDRIEn RXENn TXENn UCSZn2 RXB8n TXB8n

    UCSR0B =
        (1 << TXEN0) |
        (1 << RXEN0);

//UCSR0C
// 7 6 5 4 3 2 1 0
// UMSELn1 UMSELn0 UPMn1 UPMn0 USBSn UCSZn1 UCSZn0 UCPOLn

// Bit 3 – TXENn: Transmitter Enable n
// Writing this bit to one enables the USART transmitter. The transmitter will override
//normal port operation for the TxDn pin when enabled. The disabling of the transmitter
// (writing TXENn to zero) will not become effective until ongoing and pending transmissions
// are completed, i.e., when the transmit shift register and transmit buffer register do not
// contain data to be transmitted. When disabled, the transmitter will no longer override
// the TxDn port.

    UCSR0C =
        (1 << UCSZ01) |
        (1 << UCSZ00);
}

// UDR0
// The USART transmit data buffer register and USART receive data buffer registers share
// the same I/O address referred to as USART data register or UDRn. The transmit data buffer
// register (TXB) will be the destination for data written to the UDRn register location. 
// Reading the UDRn register location will return the contents of the receive data buffer
// register (RXB).

void uart_send_byte(uint8_t data)
{
    while (!(UCSR0A & (1 << UDRE0)))
    {

    }

    UDR0 = data;
}



uint8_t uart_receive_byte(void)
{
    while (!(UCSR0A & (1 << RXC0)))
    {

    }

    return UDR0;
}



void uart_send_string(const char *str)
{
    while (*str)
    {
        uart_send_byte(*str);
        str++;
    }
}