/*
 * leon3_bprint.c
 *
 *  Created on: 26/02/2021
 *      Author: arantxa
 */


#include "../include/leon3_bprint.h"
#define LEON3_UART_TFF (0x400)

int8_t leon3_print_string(char* str)
{

	char *tmp;
	for(tmp  = str; *tmp !='\0'; tmp++){
		leon3_putchar(*tmp);
	}
	leon3_putchar('\0');
	return 0;
}

int8_t leon3_print_uint8(uint8_t i)
{
	int8_t cent, dec, uni;
	cent = i/100;
	dec = (i - cent*100)/10;
	uni = i - cent*100 - dec*10;

	if(cent == 0){
		if(dec == 0){
			leon3_putchar('0' + uni);
		}
		else {
			leon3_putchar( '0' + dec);
			leon3_putchar('0' + uni);
		}
	}
	else {

	leon3_putchar('0'+ cent );
	leon3_putchar( '0' + dec);
	leon3_putchar('0' + uni);
	leon3_putchar('\0');

	}
	return 0;

}
	int8_t leon3_print_uint32(uint32_t i)
	{

		int8_t a,b,c,d;
		a = i/1000000000;

		b = (i-a*1000000000)/1000000;

		c = (i-b*1000000-a*1000000000)/1000;

		d = i-c*1000-b*1000000-a*1000000000;

		leon3_print_uint8(a);
		leon3_print_uint8(b);
		leon3_print_uint8(c);
		leon3_print_uint8(d);

		leon3_print_string("\n");
		return 0;

	}


