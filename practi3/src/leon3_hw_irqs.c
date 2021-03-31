/*
 * leon_irqs.c
 *
 *  Created on: Feb 28, 2013
 *      Author: user
 */
//no hace falta si incluyes el directorio include en el path del proyecto 
#include "../include/leon3_types.h"

//Utilizad estos punteros para acceder a los registros
uint32_t * LEON3_ICLEAR =  (uint32_t *) (0x80000000 + 0x20c);
uint32_t * LEON3_IMASK =  (uint32_t *) (0x80000000 + 0x240);
uint32_t * LEON3_IFORCE =  (uint32_t *) (0x80000000 + 0x208);

/** Pone a 1 el bit del irq_level indicado en el registro de forzado de irq,
 * forzando la interrupción del irq_level indicado.*/
uint8_t leon3_sparc_force_irq (uint8_t irq_level) {
	uint8_t error=0;
	if(irq_level >0 && irq_level <16){
		// COMPLETAR Poniendo a 1 SOLO el bit de LEON3_IFORCE correspondiente al irq_level
		//OK
		*LEON3_IFORCE=(1<<irq_level);
		//Permite forzar el disparo de uno de los 15 niveles de interrupcion externa
		// poniendo a 1 en el refistro IFORCE el bit correspondiente (irq_level)
	}else
		error=1;

	return error;

}

/** Pone a 1 el bit del irq_level indicado en el registro de mascara,
 * desenmascarando dicha interrupcion. irq_level(0-15).*/
uint8_t leon3_unmask_irq (uint8_t irq_level){
	uint8_t error=0;
	if(irq_level >0 && irq_level <16){
		uint32_t bit = (1 << irq_level); // La mascara del bit a modificar
		*LEON3_ICLEAR = bit;	// clear any pending irq of that level

		// COMPLETAR Poniendo a 1 SOLO el bit de LEON3_IMASK correspondiente al irq_level
		//Puedes usar bit otra vez. Está bien de cualquier manera
		*LEON3_IMASK=(1<<irq_level);
	}else
		error=1;
	return error;

}

/** Pone a 0 el bit del irq_level indicado en el registro de mascara,
 * enmascarando dicha interrupción. irq_level(0-15)*/
uint8_t leon3_mask_irq (uint8_t irq_level) {
	uint8_t error=0;
	if(irq_level >0 && irq_level <16){

		// COMPLETAR Poniendo a 0 SOLO el bit de LEON3_IMASK correspondiente al irq_level
		//Error. No guardas el valor que tiene *LEON3_IMASK para el resto de bits
		//Modificas todos los bits poniendolos a 0
		//Desplazar un cero, además, no sirve para nada.
		LEON3_IMASK=(0<<irq_level); //irq_level corresponde al bit de menor peso,
		//irq_level = 15 al bit de mayor peso
	}else
		error=1;
	return error;

}
