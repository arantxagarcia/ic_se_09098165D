4) Salta a la función retl
5) No se genera ninún mensaje
6) No se genera ningún mensaje
7) Hay que instalar como manejador del trap, la rutina que deshabilita las interrupciones
#define LEON3_SPARC_DIV_0_TRAPVECTOR 0x82
leon3_install_handler(0x82, leon3_trap_handler_disable_irqs);
leon3_print_string("división por cero");

6b) Sale por pantalla dicha cadena
7b) Hay que cambiar en el main.c la línea de leon3_putchar('A'); por una que sea leon3_putchar('1'); 
