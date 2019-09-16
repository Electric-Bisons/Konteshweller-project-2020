/*
 * main.c
 *
 * Created: 16-Sep-19 11:15:08 AM
 * Author : Stipl3x
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "headers/driver_usart.h"

int main(void)
{
    USART0_init();
    
    while (1) 
    {
        USART0_TX_data('a');
        _delay_ms(1000);
    } // end of main loop
    
    return 0;
} // end of main
