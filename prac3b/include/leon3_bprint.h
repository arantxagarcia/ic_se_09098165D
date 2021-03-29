/*
 * leon3_bprint.h
 *
 *  Created on: 26/02/2021
 *      Author: arantxa
 */

#ifndef LEON3_BPRINT_H_
#define LEON3_BPRINT_H_

#include "leon3_types.h"
#include "leon3_uart.h"

//para transimitir una cadena de caracteres
int8_t leon3_print_string(char* str);

//para transmitir un entero de 8 bits
int8_t leon3_print_uint8(uint8_t i);

//definimos el nuevo subprograma ahora para transmitir un entero de 32 bits
int8_t leon3_print_uint32(uint32_t i);

#endif /* LEON3_BPRINT_H_ */
