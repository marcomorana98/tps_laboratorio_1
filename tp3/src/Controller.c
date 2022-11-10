#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "entradaDeDatos.h"
#include "parser.h"


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
		printf("carga de datos");
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
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	char idSeleccionString[10] = "0";
	char edadString[10];
	char idString[10];
	Jugador* newJugador;
	fscanf(f, "%d", &id);
	int error = 0;
	fclose(f);
	sprintf(idString,"%d",id);

	if(utn_getCharArray(nombreCompleto, 100, "Ingrese el nombre completo del jugador") == 1){
		if(utn_getNumero(&edad,"Ingrese la edad del jugador","Incorrecto el ingreso de datos",18,55,2) == 1){
			sprintf(edadString,"%d",edad);
			if(utn_getCharArray(posicion, 30, "Ingrese la posicion del jugador") == 1){
				if(utn_getCharArray(nacionalidad, 30, "Ingrese la nacionalidad del jugador") == 1){
					error = 1;
				}
			}
		}
	}

	if(error == 1){
		newJugador = jug_newParametros(idString,nombreCompleto,edadString,posicion ,nacionalidad , idSeleccionString);
		ll_add(pArrayListJugador, newJugador);
		w = fopen("contador.txt","w");
		fprintf(w,"%d",id+1);
		fclose(w);
	    return 1;
	}
	return 0;
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

	utn_getNumero(&posicion,"Ingrese la posicion en el array del jugador que desea editar o ingrese 0 para volver \n","no se a encontrado la posicion \n",0,ll_len(pArrayListJugador)+1,2);
	if(posicion != 0){
		aux = ll_get(pArrayListJugador, posicion-1);
		while(opcion != 0){
			opcion = 0;
			printf("que dato desesa editar? \n 1.Nombre \n 2.Edad \n 3.Posicion \n 4.Nacionalidad \n 0.Regresar");
			utn_getNumero(&opcion,"Ingrese una opcion \n","no se a encontrado la opcion \n",0,4,2);
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
					if(utn_getNumero(&edad,"Ingrese la edad del jugador","Incorrecto el ingreso de datos",18,55,2) == 1){
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
					ll_set(pArrayListJugador, posicion-1,aux);
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
	controller_listarJugadores(pArrayListJugador);

	FILE* f = NULL;
	FILE* w = NULL;
	int posicion = 0;
	int contador;

	utn_getNumero(&posicion,"Ingrese la posicion del jugador que desea borrar o ingrese 0 para volver para atras \n","no se reconocio la posicion \n",0,ll_len(pArrayListJugador)+1,2);
	if(posicion == 0){
		return 0;
	}
	f = fopen("contador.txt","r");
	fscanf(f, "%d", &contador);
	fclose(f);

	ll_remove(pArrayListJugador,posicion-1);


	w = fopen("contador.txt","f");
	fprintf(w,"%d",contador-1);
	fclose(w);
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
	char* nombreCompleto;
	int edad;
	char* posicion;
	char* nacionalidad;
	int idSeleccion;
	Jugador* jugador;
	printf("| %-10s| %-5s| %-100s| %-10s| %-30s | %-40s| %-10s|\n","NUMERO", "ID", "NOMBRE COMPLETO", "EDAD", "POSICION", "NACIONALIDAD", "ID DE SELECCION");
	for(int i=0;i<length;i++){
		jugador = ll_get(pArrayListJugador, i);
		jug_getId(jugador, &id);
		jug_getNombreCompleto(jugador, &nombreCompleto);
		jug_getPosicion(jugador, &posicion);
		jug_getNacionalidad(jugador, &nacionalidad);
		jug_getEdad(jugador, &edad);
		jug_getSIdSeleccion(jugador, &idSeleccion);
		printf("| %-10d| %-5d| %-100s| %-10d| %-30s | %-40s| %-10d|\n",i+1, id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
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
	FILE* f = NULL;
	    f = fopen(path, "r");
	    if(f != NULL){
		    printf("Lee el archivo correctamente seleccion.");
		    parser_SeleccionFromText(f, pArrayListSeleccion);
		    return 1;
	    }
	    else{
	    	printf("SALIO MAL.");
	    }

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
	int length = ll_len(pArrayListSeleccion);
	int id;
	char* pais = (char*)malloc(sizeof(char)*30);
	char* Confederacion = (char*)malloc(sizeof(char)*30);
	int Convocados;
	Seleccion* seleccion;
	printf("| %-10s| %-5s| %-30s| %-25s| %-10s|\n","NUMERO", "ID", "PAIS", "CONFEDERACION", "CONVOCADOS");
	for(int i=0;i<length-1;i++){
		seleccion = ll_get(pArrayListSeleccion, i);
		selec_getId(seleccion, &id);
		selec_getPais(seleccion, pais);
		selec_getConfederacion(seleccion, Confederacion);
		selec_getConvocados(seleccion, &Convocados);

		printf("| %-10d| %-5d| %-30s| %-25s| %-10d|\n",i+1, id, pais, Confederacion, Convocados);
	}
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

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador){
	int length = ll_len(pArrayListJugador);
	int id;
	char* nombreCompleto[100];
	int edad;
	char* posicion[30];
	char* nacionalidad[30];
	int idSeleccion;
	Jugador* jugador;
	printf("| %-10s| %-5s| %-100s| %-10s| %-30s | %-30s| %-10s|\n","NUMERO", "ID", "NOMBRE COMPLETO", "EDAD", "POSICION", "NACIONALIDAD", "ID DE SELECCION");
	for(int i=0;i<length;i++){
		jugador = ll_get(pArrayListJugador, i);
		jug_getSIdSeleccion(pArrayListJugador,&idSeleccion);
		if(idSeleccion>0){
			jug_getId(jugador, &id);
			jug_getNombreCompleto(jugador, nombreCompleto);
			jug_getPosicion(jugador, posicion);
			jug_getNacionalidad(jugador, nacionalidad);
			jug_getEdad(jugador, &edad);
			jug_getSIdSeleccion(jugador, &idSeleccion);
			printf("| %-5d| %-100s| %-10d| %-30s | %-30s| %-10d|\n",id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
		}
	}

    return 1;
}

int controller_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){
	int posicion = -1;
	int idSeleccionAux;
	int convocadosAux;
	int opcionSeleccion = -1;
	int idAux;
	Jugador* aux;
	Seleccion* auxSeleccion = NULL;
	controller_listarJugadores(pArrayListJugador);
	while(posicion!=0){
		utn_getNumero(&posicion,"Ingrese la posicion del jugador que desea convocar o 0 para retornar \n","no se reconocio la posicion \n",0,ll_len(pArrayListJugador)+1,2);
		if(posicion == 0){
			return 0;
		}
		aux = ll_get(pArrayListJugador, posicion-1);
		jug_getSIdSeleccion(aux,&idSeleccionAux);
		if(idSeleccionAux!=0){
			printf("El jugador ya esta convocado, debe seleccionar uno que no este convocado \n");
			posicion = -1;
		}
		else{
			controller_listarSelecciones(pArrayListSeleccion);
			while(opcionSeleccion != 0){
				utn_getNumero(&opcionSeleccion,"Ingrese la seleccion que le desea asignar al jugador o 0 para retornar \n","no se reconocio la posicion \n",0,ll_len(pArrayListSeleccion)+1,2);
				if(opcionSeleccion == 0){
					return 0;
				}
				auxSeleccion = ll_get(pArrayListSeleccion, opcionSeleccion-1);
				selec_getConvocados(auxSeleccion,&convocadosAux);
				if(convocadosAux > 21){
					printf("esta seleccion ya a llegado a su limite, por favor eliga otra \n");
				}
				else{
					selec_getId(auxSeleccion,&idAux);
					selec_setConvocados(auxSeleccion,convocadosAux+1);
					jug_setIdSeleccion(aux,idAux);
					return 1;
				}
			}
		}
	}
	return 1;


}
