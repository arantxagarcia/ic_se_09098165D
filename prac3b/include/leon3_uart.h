/*
 * leon3_uart.h

 *
 *  Created on: 19/02/2021
 *      Author: arantxa
 */


#ifndef LEON3_UART_H_
#define LEON3_UART_H_

#include "leon3_types.h"

int8_t leon3_putchar(char c);
char leon3_getchar();
uint8_t leon3_UART_TF_IS_EMPTY();
void leon3_UART_RX_ENABLE();
void leon3_UART_RX_IRQ_ENABLE();
void leon3_UART_ConfigRXTXLoop(uint8_t set_rxtxloop);

#endif /* LEON3_UART_H_ */







