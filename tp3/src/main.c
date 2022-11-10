#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "entradaDeDatos.h"

int main()
{
	setbuf(stdout,NULL);
    int option = -1;
    int optionListados = -1;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    puts("funciona ok");

    do{
    	utn_getNumero(&option,"Ingrese opcion","Incorrecto el ingreso de datos",0,6,2);
        switch(option)
        {

            case 1:
            	controller_cargarJugadoresDesdeTexto("./jugadores.csv",listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("./selecciones.csv",listaSelecciones);
                break;

            case 2:
            	controller_agregarJugador(listaJugadores);

                break;

            case 3:
            	controller_listarJugadores(listaJugadores);
            	controller_editarJugador(listaJugadores);

            	break;

            case 4:
            	controller_removerJugador(listaJugadores);

            	break;

            case 5:
                do{
                	utn_getNumero(&optionListados,"Ingrese opcion de listado","Incorrecto el ingreso de datos",0,5,2);
                    switch(optionListados)
                    {
                    case 1:
                    	controller_listarJugadores(listaJugadores);
                    break;
                    case 2:
                    	controller_listarSelecciones(listaSelecciones);
                    break;
                    case 3:
                    	controller_listarJugadoresConvocados(listaJugadores);
                    break;
                    default:
                    	break;
                    }}while(optionListados != 0);
                break;
            case 6:
            	controller_convocar(listaJugadores, listaSelecciones);
            	break;
        }

    }while(option != 0);

    return 0;
}

