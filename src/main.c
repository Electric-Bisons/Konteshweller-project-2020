/* 
* main.c - @Electric-Bisons
*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "headers/driver_usart.h"

int main(void)
{
    USART0_init();
    uint8_t u8Data = 0;
    
    while(1)
    {
        USART0_TX_data('a');
        _delay_ms(1000);
        u8Data = USART0_RX_data();
        _delay_ms(1000);
        USART0_TX_data(u8Data);
        _delay_ms(1000);
        USART0_TX_data('\n');
    } // end of main loop
    
    return 0;
} // end of main
