/*
* driver_timers.c - @Electric-Bisons
*/

#include <avr/io.h>

#include "driver_timers.h"

// init INT4 for rising edge
void INT4_init(void)
{
    EICRB |= (1 << ISC41) | (1 << ISC40);
    EIMSK |= (1 << INT4);
}
