/*
* driver_hcsr04.h - @Electric-Bisons
*/

/*
* pin configuration:
* echo: D2(PE4)
* trigger: D22(PA0)
*/

#ifndef DRIVER_HCSR04_H_
#define DRIVER_HCSR04_H_

void    HCSR04_init(void);
void    HCSR04_trigger(void);
void    startHCSR04Counting(void);
uint8_t returnHCSR04Value(void);
void    overflowHCSR04(void);

#endif /* DRIVER_HCSR04_H_ */
