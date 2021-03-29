/*
 * leon3_uart.c

 *
 *  Created on: 19/02/2021
 *      Author: arantxa
 */


#include "../include/leon3_uart.h"

//! LEON3 UART A Transmit FIFO is FILL
#define LEON3_UART_TFF (0x200)



#define leon3_UART_TF_IS_FULL() ((*pLEON3_UART_REGS).Status & LEON3_UART_TFF)


struct UART_regs
{

	/** \brief UART  Data Register */
	volatile uint32_t Data; /* 0x80000100 */
	/** \brief UART  Status Register */
	volatile uint32_t Status; /* 0x80000104 */
	/** \brief UART  Control Register */
	volatile uint32_t Ctrl; /* 0x80000108 */
	/** \brief UART  Scaler Register */
	volatile uint32_t Scaler; /* 0x8000010C */


};



struct UART_regs * pLEON3_UART_REGS = 0x80000100;



int8_t leon3_putchar(char c)
{
	uint32_t write_timeout=0;

	while(leon3_UART_TF_IS_FULL() && (write_timeout < 0xAAAAA))
	{
			write_timeout++;
	}

	if(write_timeout < 0xAAAAA){

		(*pLEON3_UART_REGS).Data = c;

	}
	return (write_timeout == 0xAAAAA);
}







