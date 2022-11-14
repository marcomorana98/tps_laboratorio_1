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
    LinkedList* listaJugadores = NULL;
    LinkedList* listaSelecciones = NULL;
	LinkedList* listaConvocados = NULL;
	listaJugadores = ll_newLinkedList();
	listaSelecciones = ll_newLinkedList();
	listaConvocados = ll_newLinkedList();

    do{
    	utn_getNumero(&option,"Menu principal: \n 1. Cargar los datos de las listas de excel \n 2. Ingresar un nuevo jugador \n 3. Modificar un jugador en la tabla \n 4. Dar de baja un jugador en la tabla \n 5. Menu de listados \n 6. Menu de convocaciones \n 7. Menu de ordenar y listar \n 8. Generar archivo binario de jugadores convocados con una confederacion a eleccion \n 9. Cargar archivo binario ya creado de jugadores convocados \n 10. Guardar archivo .csv de jugadores y confederaciones cargados \n 11. Salir del programa \n Ingrese opcion \n","Incorrecto el ingreso de datos \n",1,11,2);
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
                	utn_getNumero(&optionListados,"Menu de listados: \n 1. Listar todos los jugadores \n 2. Listar todas las selecciones \n 3. Listar solo los jugadores convocados \n 0. Volver al menu principal \n Ingrese opcion de listado \n","Incorrecto el ingreso de datos \n",0,3,2);
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
                    case 0:
                    	printf("volviendo al menu principal... \n");
                    default:
                    	break;
                    }}while(optionListados != 0);
                break;
            case 6:

            	do{
                utn_getNumero(&optionConvocados,"Menu de convocar: \n 1. Convocar un jugador de la lista \n 2. Quitar un jugador convocado de su seleccion \n 0. Volver al menu principal \n Ingrese opcion de listado \n","Incorrecto el ingreso de datos \n",0,2,2);
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
            	utn_getNumero(&optionOrden,"Menu de Ordenar y Listar: \n 1. Ordenar y listar jugadores por nacionalidad \n 2. Ordenar y listar Selecciones por confederacion \n 3. Ordenar y listar jugadores por edad \n 4. Ordenar y listar jugadores por nombre \n 0. Volver al menu principal \n Ingrese opcion de listado \n","Incorrecto el ingreso de datos \n",0,4,2);
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

