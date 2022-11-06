#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaJugadores = ll_newLinkedList();

    puts("funciona ok");

    do{
        switch(option)
        {
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);

                break;

            case 2:
            	controller_agregarJugador(listaJugadores);

                break;

            case 3:
            	controller_listarJugadores(listaJugadores);
            	controller_editarJugador(listaJugadores);

        }
    }while(option != 10);

    return 0;
}

