/*
* main.c - @Stipl3x
*/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Custom drivers
#include "headers/uno_usart.h"
#include "headers/uno_adc.h"
#include "headers/driver_thermistor.h"

volatile uint8_t vu8ADCflag = 0;
volatile uint16_t vu16ThermoData = 250;

int main(void)
{
    // Enable global interrupts
    sei();
    
    // Initialize the drivers
    USART_init();
    ADC_init();
    
    uint8_t u8ThermoDataH;
    uint8_t u8ThermoDataL;
    
    // Main loop of program
    while (1) 
    {
        vu8ADCflag = 1;
        
        u8ThermoDataH = (uint8_t)(vu16ThermoData >> 8);
        u8ThermoDataL = (uint8_t)vu16ThermoData;
        
        USART_TX(u8ThermoDataH);
        USART_TX(u8ThermoDataL);
        
        _delay_ms(2000);
    } // End of main loop
    
    return 0;
} // End of main


ISR(ADC_vect)
{
    if (vu8ADCflag && (ADMUX == ADCTHERM))
    {
        vu8ADCflag = 0;
        vu16ThermoData = thermConv(ADC);
        ADMUX = ADCTHERM;
    }
    ADCSRA |= (1 << ADSC);
}
