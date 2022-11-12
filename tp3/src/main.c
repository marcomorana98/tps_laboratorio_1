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
    int optionConvocados = -1;
    int optionOrden = -1;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
	LinkedList* listaConvocados = ll_newLinkedList();


    puts("funciona ok");

    do{
    	utn_getNumero(&option,"Ingrese opcion","Incorrecto el ingreso de datos",1,11,2);
        switch(option)
        {

            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones);
                break;

            case 2:
            	controller_agregarJugador(listaJugadores);

                break;

            case 3:
            	controller_listarJugadores(listaJugadores);
            	controller_editarJugador(listaJugadores);

            	break;

            case 4:
            	controller_removerJugador(listaJugadores,listaSelecciones);

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

            	do{
                utn_getNumero(&optionConvocados,"Ingrese opcion de listado","Incorrecto el ingreso de datos",0,5,2);
                switch(optionConvocados){
                case 1:
                	controller_convocar(listaJugadores, listaSelecciones);
                	break;
                case 2:
                	controller_quita_seleccion(listaJugadores,listaSelecciones);
                	break;
                case 0:
                	printf("volviendo al menu principal... \n");
                	break;
                default:
                	printf("no se reconocio la opcion, por favor ingrese otra \n");
                	break;
                }

            	break;
            	}while(optionConvocados != 0);
            	break;
            case 7:

            	do{
            	utn_getNumero(&optionOrden,"Ingrese opcion de listado","Incorrecto el ingreso de datos",0,4,2);
            	switch(optionOrden){
            		case 1:
            			controller_ordenarJugadores(listaJugadores, 1);
            		break;
            		case 2:
            			controller_ordenarSelecciones(listaSelecciones);
            		break;
            		case 3:
            			controller_ordenarJugadores(listaJugadores, 2);
            		break;
            		case 4:
            			controller_ordenarJugadores(listaJugadores, 3);
            		break;

            	}}while(optionConvocados != 0);
            	break;

            case 8:
            	;
            	controller_convocadosDeSeleccion(listaJugadores,listaSelecciones,listaConvocados);
            	controller_guardarJugadoresModoBinario("Confederacion binario", listaConvocados);
            	ll_clear(listaConvocados);
            	break;
            case 9:
            	controller_cargarJugadoresDesdeBinario("Confederacion binario", listaConvocados);
            	controller_listarJugadores(listaConvocados);
            	break;
            case 10:
            	controller_guardarJugadoresModoTexto("jugadores.csv" , listaJugadores);
            	controller_guardarSeleccionesModoTexto("selecciones.csv" , listaSelecciones);

            	break;

        }

    }while(option != 11);

    return 0;
}

