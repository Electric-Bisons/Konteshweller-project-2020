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

extern volatile uint8_t vu8HCSR04Flag;

int main(void)
{
    // Enable global interrupt
    sei();
    
    // Initialize drivers
    USART0_init();
    HCSR04_init();
    
    while(1)
    {
        if(vu8HCSR04Flag == 0)
        {
            HCSR04_trigger();
        }
    } // End of main loop
    
    return 0;
} // End of main

ISR(INT4_vect)
{
    if(vu8HCSR04Flag == 2)
    {
        USART0_TX_data(returnHCSR04Value());
    }
    
    if(vu8HCSR04Flag == 1)
    {
        startHCSR04Counting();
    }
}

ISR(TIMER0_OVF_vect)
{
    overflowHCSR04();
}
