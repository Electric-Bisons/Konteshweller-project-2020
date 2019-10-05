/*
* driver_hcsr04.c - @Electric-Bisons
*/

#include <avr/io.h>
#include <util/delay.h>

#include "driver_hcsr04.h"
#include "driver_timers.h"

void HCSR04_init(void)
{
    // Set trigger pin as output and low
    DDRA |= (1 << PA0);
    PORTA &= ~(1 << PA0);
    // Enable INT4 external interrupt
    INT4_init();
}

void HCSR04_trigger(void)
{
    // Send a trigger pulse for 10us
    PORTA |= (1 << PA0);
    _delay_us(10);
    // Set pin low
    PORTA &= ~(1 << PA0);
}

uint8_t HCSR04_echo_cm(void)
{
    uint8_t u8CMvalue = 0;
    uint16_t u16EchoPulse = 0;
    
    // Increase echo pulse every uS while pin stays high
    while(PINE & (1 << PE4))
    {
        ++u16EchoPulse;
        _delay_us(1);
    }
    
    // Convert into cm
    u8CMvalue = u16EchoPulse / 58;
    
    return u8CMvalue;
}
