/*
* driver_hcsr04.c - @Electric-Bisons
*/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#include "driver_hcsr04.h"
#include "driver_timers.h"

// Flag for interrupt setup = no action for now
volatile uint8_t vu8HCSR04Flag = 0;

void HCSR04_init(void)
{
    // Set trigger pin as output and low
    DDRA |= (1 << PA0);
    PORTA &= ~(1 << PA0);
    // Enable INT4 external interrupt
    INT4_init();
    // Initialize TIMER0, but don't start it yet
    TIMER0_init();
}

void HCSR04_trigger(void)
{
    // Send a trigger pulse for 10us
    PORTA |= (1 << PA0);
    _delay_us(10);
    // Set pin low
    PORTA &= ~(1 << PA0);
    // Change to rising edge interrupt
    vu8HCSR04Flag = 1;
}

void startHCSR04Counting(void)
{
    // Start counting
    TCNT0 = 0;
    // Prescaler at 64
    TCCR0B |= (1 << CS01) | (1 << CS00);
    // Change to falling edge
    vu8HCSR04Flag = 2;
}

// This should be written before the set 
// of flag to 2 to avoid conflict
uint8_t returnHCSR04Value(void)
{
    // Stop TIMER0
    TCCR0B = 0;
    
    // Buffer for the distance value
    uint16_t tempU16Value = 0;
    
    // Value converted to cm
    tempU16Value = TCNT0 * 4 / 58;
    
    // Change back to trigger state
    _delay_ms(1000);
    vu8HCSR04Flag = 0;
    
    return (uint8_t)tempU16Value;
}

// In case of TCNT0 overflow
void overflowHCSR04(void)
{
    // Stop Timer0
    TCCR0B = 0;
    // Set flag to 0
    vu8HCSR04Flag = 0;
    // Wait to be sure
    _delay_ms(1000);
}
