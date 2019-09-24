/*
* driver_usart.h - @Electric-Bisons
*/

#ifndef DRIVER_USART_H_
#define DRIVER_USART_H_

#define BAUD        9600
#define MY_F_CPU    16000000UL
#define MY_BRR      ( ( MY_F_CPU / 16 / BAUD ) - 1 )

void USART0_init(void);
void USART0_TX_data(uint8_t u8Data);

#endif /* DRIVER_USART_H_ */
