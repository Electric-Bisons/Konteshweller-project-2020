/* 
* main.c - @Electric-Bisons
*/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "headers/driver_usart.h"
#include "headers/driver_timers.h"
#include "headers/driver_hcsr04.h"

volatile uint8_t vu8Flag = 0;

int main(void)
{
    // enable global interrupt
    sei();
    
    // init drivers
    USART0_init();
    HCSR04_init();
    
    HCSR04_trigger();
    
    while(1)
    {
        // execute only after measure is complete
        if( vu8Flag )
        {
            vu8Flag = 0;
            HCSR04_trigger();
        }
    } // end of main loop
    
    return 0;
} // end of main

ISR(INT4_vect)
{
    // send cm value over USART0
    USART0_TX_data(HCSR04_echo_cm());
    _delay_ms(1000);
    vu8Flag = 1;
}
