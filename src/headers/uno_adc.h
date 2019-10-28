/*
* uno_adc.h - @Stipl3x
*/

#ifndef UNO_ADC_H_
#define UNO_ADC_H_

// Defines for ADMUX register representing REFS0 and MUX bits
#define ADCTHERM    0x40
#define ADCMQ2      0x41
#define ADCMQ7      0x42

void ADC_init();

#endif /* UNO_ADC_H_ */
