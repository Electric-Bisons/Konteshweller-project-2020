/*
* driver_timers.c - @Electric-Bisons
*/

#include <avr/io.h>

#include "driver_timers.h"

// Initialize INT4 for rising edge
void INT4_init(void)
{
    // Rising edge interrupt
    EICRB |= (1 << ISC41) | (1 << ISC40);
    // Enable interrupt
    EIMSK |= (1 << INT4);
}
