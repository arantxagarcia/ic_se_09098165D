/*
 * main.c


 *
 *  Created on: 26/02/2021
 *      Author: arantxa
 */

#include "../include/leon3_uart.h"
#include "../include/leon3_bprint.h"
#include "../include/leon3_hw_irqs.h"
#include "../include/leon3_ev_handling.h"

uint8_t irq_counter=0;
char RxChars[8];
/*Esta función se utilizará como manejador de la interrupción
que genera la recepción de un dato por el puerto serie.
La función almacena en RxChars los primeros 8 carateres que se
reciben, reenviando, además el sucesor por el mismo canal Tx*/
void uart_rx_irq_handler(void){
 char aux;
 aux=leon3_getchar();

 if(irq_counter<7){
 RxChars[irq_counter]=aux;
 aux++;
 leon3_putchar(aux);
 }
 irq_counter++;
}
int main()
{
 uint8_t i;
 leon3_install_handler(LEON3_SPARC_ENABLE_IRQ_TRAPVECTOR,
leon3_trap_handler_enable_irqs);
 leon3_install_handler(LEON3_SPARC_DISABLE_IRQ_TRAPVECTOR ,
leon3_trap_handler_disable_irqs);
 leon3_sys_call_disable_irqs(); //Deshabilito interrupciones
//COMPLETAR instalando como manejador de la interrupción de
 //nivel 2 la rutina uart_rx_irq_handler
 leon3_install_handler(0x12, uart_rx_irq_handler);

//Habilito loop-back
 leon3_UART_ConfigRXTXLoop(1);

 //Habilito interrupción de recepción por la UART
 leon3_UART_RX_IRQ_ENABLE();

 //Habilito la recepción por la UART
 leon3_UART_RX_ENABLE();

//COMPLETAR habilitando las interrupciones y
//desenmascarando la interrupción de nivel 2
 leon3_unmask_irq(2);
 leon3_sys_call_enable_irqs();

 leon3_putchar('A');//7b cambio A por 1                                    // PREGUNTA 7B cambiamos la 'A' por un '1'
 //Miro si los 8 caracteres se han recibido
 while(irq_counter < 8)
 ;

 //Tras recibir los 8 caracteres, configuro la UART
 //sin loop-back
 leon3_UART_ConfigRXTXLoop(0);
 //Envío de nuevo los 8 caracteres que se recibieron,
 //pero sin loop-back, por lo que aparecerán por pantalla
 for(i=0;i<8;i++)
 leon3_putchar(RxChars[i]);
 leon3_putchar('\n');
 //Espero a que todos los caracteres se hayan enviado.
 while(!leon3_UART_TF_IS_EMPTY())
 ;
 return 0;
}
