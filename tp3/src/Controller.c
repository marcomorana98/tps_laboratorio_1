#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "entradaDeDatos.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE* f = NULL;
	f = fopen(path, "r");
	if (f != NULL){
		parser_JugadorFromText(f, pArrayListJugador);
	}
	else{
		return 0;
	}
    return 1;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	FILE* f = NULL;
		f = fopen(path, "r");
		if (f != NULL){
			parser_JugadorFromBinary(f, pArrayListJugador);
		}
		else{
			return 0;
		}
	    return 1;
    return 1;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	FILE* f = NULL;
	FILE* w = NULL;
	f = fopen("contador.txt","r");
	w = fopen("contador.txt","w");
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	Jugador* newJugador;
	fscanf(f, "%d", id);
	int error = 0;
	fclose(f);

	if(utn_getCharArray(nombreCompleto, 100, "Ingrese el nombre completo del jugador") == 1){
		if(utn_getNumero(edad,"Ingrese la edad del jugador","Incorrecto el ingreso de datos",18,55,2) == 1){
			if(utn_getCharArray(posicion, 30, "Ingrese la posicion del jugador") == 1){
				if(utn_getCharArray(nacionalidad, 30, "Ingrese la nacionalidad del jugador") == 1){
					error = 1;
				}
			}
		}
	}

	if(error == 1){
		newJugador = jug_newParametros(itoa(id),nombreCompleto,itoa(edad),posicion ,nacionalidad , 0);
		ll_add(pArrayListJugador, newJugador);
		fprintf(w,"%d",id+1);
		fclose(w);
	    return 1;
	}

}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int opcion = 1;
	int posicion;
	char nombreCompleto[100];
	int edad;
	char posicionCancha[30];
	char nacionalidad[30];
	Jugador* aux;

	utn_getNumero(posicion,"Ingrese la posicion en el array del jugador que desea editar o ingrese 0 para volver \n","no se a encontrado la posicion \n",0,ll_len(pArrayListJugador)+1,2);
	if(posicion != 0){
		aux = ll_get(pArrayListJugador, posicion-1);
		while(opcion != 0){
			opcion = 0;
			printf("que dato desesa editar? \n 1.Nombre \n 2.Edad \n 3.Posicion \n 4.Nacionalidad \n 0.Regresar");
			utn_getNumero(opcion,"Ingrese una opcion \n","no se a encontrado la opcion \n",0,4,2);
			switch(opcion){
				case 1:
					if(utn_getCharArray(nombreCompleto, 100, "Ingrese el nombre completo del jugador \n") == 1){
						jug_setNombreCompleto(aux,nombreCompleto);
					}
					else{
						printf("error al editar el jugador volviendo al menu... \n");
					}
					break;
				case 2:
					if(utn_getNumero(edad,"Ingrese la edad del jugador","Incorrecto el ingreso de datos",18,55,2) == 1){
						jug_setEdad(aux,edad);
					}
					else{
						printf("error al editar el jugador volviendo al menu... \n");
					}
					break;
				case 3:
					if(utn_getCharArray(posicionCancha, 30, "Ingrese la posicion del jugador") == 1){
						jug_setPosicion(aux,posicionCancha);
					}
					else{
						printf("error al editar el jugador volviendo al menu... \n");
					}
					break;
				case 4:
					if(utn_getCharArray(nacionalidad, 30, "Ingrese la nacionalidad del jugador") == 1){
						jug_setNacionalidad(aux,nacionalidad);
					}
					else{
						printf("error al editar el jugador volviendo al menu... \n");
					}
					break;
				case 0:
					printf("Volviendo al menu principal... \n");
					return 1;
			}
		}
	}
    return 0;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int length = ll_len(pArrayListJugador);
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	Jugador* jugador;
	printf("| %-10s| %-5s| %-100s| %-10s| %-30s | %-30s| %-10s|\n","NUMERO", "ID", "NOMBRE COMPLETO", "EDAD", "POSICION", "NACIONALIDAD", "ID DE SELECCION");
	for(int i=0;i<length;i++){
		jugador = ll_get(pArrayListJugador, i);
		jug_getId(jugador, id);
		jug_getNombreCompleto(jugador, nombreCompleto);
		jug_getPosicion(jugador,posicion);
		jug_getNacionalidad(jugador,nacionalidad);
		jug_getEdad(jugador,edad);
		jug_getSIdSeleccion(jugador,idSeleccion);
		printf("| %-10d| %-5d| %-100s| %-10d| %-30s | %-30s| %-10d|\n",i+1, id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
	}

    return 1;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}


