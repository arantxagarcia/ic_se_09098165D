/*
 * leon3_uart.c

 *
 *  Created on: 19/02/2021
 *      Author: arantxa
 */

#include "../include/leon3_uart.h"
#define LEON3_UART_TFF (0x200)
#define LEON3_UART_TFE (0x4)
#define LEON3_UART_RX (0x1)
#define LEON3_UART_LOOP_BACK (0x80)


struct UART_regs
{
	// Data Reg
	volatile uint32_t Data;
	// Status Reg
	volatile uint32_t Status;
	// Control Reg
	volatile uint32_t Ctrl;
	// Scaler Reg
	volatile uint32_t Scaler;
};

struct UART_regs * pLEON3_UART_REGS= 0x80000100;


uint8_t leon3_UART_TF_IS_FULL()
{
	uint8_t uart_tf_is_full;

	uart_tf_is_full = pLEON3_UART_REGS->Status & LEON3_UART_TFF;

	return uart_tf_is_full;
}

int8_t leon3_putchar(char c)
{
	uint32_t write_timeout=0;

	while(leon3_UART_TF_IS_FULL() && (write_timeout < 0xAAAAA))
	{
		write_timeout++;
	}

	if(write_timeout < 0xAAAAA)
	{
		pLEON3_UART_REGS->Data = c;
	}
	return (write_timeout == 0xAAAAA);
}

char leon3_getchar()
{
	uint8_t getchar;
	getchar =  pLEON3_UART_REGS->Data;
	return getchar;
}

uint8_t leon3_UART_TF_IS_EMPTY()
{
	uint8_t uart_tf_is_empty;

	uart_tf_is_empty = pLEON3_UART_REGS->Status & LEON3_UART_TFE;

	return uart_tf_is_empty;
}

void leon3_UART_RX_ENABLE()
{
	pLEON3_UART_REGS->Ctrl |= LEON3_UART_RX;
}

void leon3_UART_RX_IRQ_ENABLE()
{
	pLEON3_UART_REGS->Ctrl |= LEON3_UART_TFE;
}

void leon3_UART_ConfigRXTXLoop(uint8_t set_rxtxloop)
{
	if (set_rxtxloop ==1){
		pLEON3_UART_REGS->Ctrl |= LEON3_UART_LOOP_BACK;
	}else {
		pLEON3_UART_REGS->Ctrl &= ~LEON3_UART_LOOP_BACK;
	}
}




