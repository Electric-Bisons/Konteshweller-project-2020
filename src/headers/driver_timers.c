/*
* driver_timers.c - @Electric-Bisons
*/

#include <avr/io.h>

#include "driver_timers.h"

void TIMER0_init(void)
{
    // Prescaler is 0 so the clock is stopped.
    TCCR0B = 0;
    // Should be started only when echo is starting.
    // Enable global interrupts
    TIMSK0 = (1 << TOIE0);
}

// Initialize INT4 for any change of voltage.
// 3 states: 0 for nothing, 1 for rising, 
// 2 for falling, all in IRS.
void INT4_init(void)
{
    // Change of voltage interrupt
    EICRB = (1 << ISC40);
    // Enable interrupt
    EIMSK |= (1 << INT4);
}
