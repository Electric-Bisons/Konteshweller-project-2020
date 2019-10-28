/*
 * driver_thermistor.c - @Stipl3x
 */

#include <avr/io.h>
#include <math.h>

#include "driver_thermistor.h"
#include "uno_adc.h"

// Convert the ADC value to Celsius
uint16_t thermConv(uint16_t u16RawADC)
{
    double d64Temperature = 0;
    
    d64Temperature = log10(10000.0 * (1024.0 / u16RawADC - 1));
    d64Temperature = 1 / (0.001129148 + (0.000234125 + 
                    (0.0000000876741 * d64Temperature * d64Temperature)) 
                    * d64Temperature);
    // Convert Kelvin to Celsius
    d64Temperature -= 273.15;
    d64Temperature *= 10;
    
    return (uint16_t)d64Temperature;
}
