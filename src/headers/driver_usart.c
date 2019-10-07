/*
* driver_usart.c - @Electric-Bisons
*/

#include <avr/io.h>

#include "driver_usart.h"

void USART0_init(void)
{
    // Set BAUD rate
    UBRR0H = (uint8_t)(MY_BRR >> 8);
    UBRR0L = (uint8_t)MY_BRR;
    // Enable TX0
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    // Set 8-bit data buffer
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void USART0_TX_data(uint8_t u8Data)
{
    // Wait for data buffer to empty
    while(!(UCSR0A & (1 << UDRE0)));
    // Send data
    UDR0 = u8Data;
}

uint8_t USART0_RX_data(void)
{
    // Wait for data to be received
    while(!(UCSR0A & (1 << RXC0)));
    // Return data
    return UDR0;
}

void USART0_TX_string(const char *dataString)
{
    // Char index in string
    uint8_t index = 0;
    
    // Read through string
    while(dataString[index] != '\n')
    {
        // Wait for data buffer to empty
        while(!(UCSR0A & (1 << UDRE0)));
        // Send data
        UDR0 = dataString[index];
        
        ++index;
    }
}
