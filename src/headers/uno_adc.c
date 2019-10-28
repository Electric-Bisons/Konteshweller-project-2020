/*
 * uno_adc.c - @Stipl3x
 */

#include <avr/io.h>

#include "uno_adc.h"

void ADC_init()
{
    ADMUX = ADCTHERM;
    // Enable ADC, first conversion and interrupt
    ADCSRA = (1 << ADEN) | (1 << ADSC) | (1 << ADIE);
    // Set prescaler at 64
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1);
}
