/*
 * main.c


 *
 *  Created on: 26/02/2021
 *      Author: arantxa
 */

#include "../include/leon3_uart.h"
#include "../include/leon3_bprint.h"
#include "../include/leon3_ev_handling.h"
#include "../include/leon3_hw_irqs.h"

void hw_irq_vector_0x11_handler(void){
	leon3_print_string("handler hw irq vector 0x11 \n");
}


int main(){

	//Instalar como manejador del trap 0x83 la rutina
	// que habilita las interrupciones
	leon3_install_handler(0x83, leon3_trap_handler_enable_irqs);

	//Instalar el manejador del trap que 0x83 la rutina
	// que deshabilita las interrupciones
	leon3_install_handler(0x84, leon3_trap_handler_disable_irqs);

	//Deshabilitar las interrupciones
	leon3_sys_call_disable_irqs();

	//Instalar la función hw_irq_vector_0x11_handler como
	// manejador de la interrupción de nivel 1

	//COMPLETAR
	//OK
	leon3_install_handler(0x11,hw_irq_vector_0x11_handler);

	//Desenmascara la interrupcion de nivel 1( correspondiente
	// al vector 17, es decir el vector 0x11)
	//OK
	leon3_unmask_irq(1);

	//OK
	//Habilitar las interrupciones
	leon3_sys_call_enable_irqs();



	//Fuerza la interrupción
	leon3_sparc_force_irq(1);

	return 0;
}
