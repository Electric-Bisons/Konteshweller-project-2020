/*
 * driver_usart.h
 *
 * Created: 16-Sep-19 11:19:58 AM
 *  Author: black
 */ 

#ifndef DRIVER_USART_H_
#define DRIVER_USART_H_

#define BAUD        9600
#define MY_F_CPU    16000000UL
#define MY_BRR      ( ( MY_F_CPU / 16 / BAUD ) - 1 )

void USART0_init(void)
{
    // set BAUD rate
    UBRR0H = (uint8_t) (MY_BRR >> 8);
    UBRR0L = (uint8_t) MY_BRR;
    // enable TX0
    UCSR0B = (1 << TXEN0);
    // set 8-bit data buffer
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void USART0_TX_data(uint8_t u8Data)
{
    // wait for data buffer to empty
    while ( !( UCSR0A & (1 << UDRE0) ) )
                    ;
    UDR0 = u8Data;
}

#endif /* DRIVER_USART_H_ */