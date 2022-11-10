#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	char idStr[20];
	char nombreCompletoStr[50];
	char edadStr[20];
	char posicionStr[40];
	char nacionalidadStr[20];
	char idSeleccionStr[20];
	Jugador aux;
	Jugador* pAux = NULL;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%s",idStr,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSeleccionStr);
	while(!feof(pFile)){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%s",idStr,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSeleccionStr);
		pAux = jug_newParametros(idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSeleccionStr);
		ll_add(pArrayListJugador, pAux);
		pAux = NULL;
	}
    return 1;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
    return 1;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion){
	char idStr[20];
	char paisStr[20];
	char confederacionStr[20];
	char convocadosStr[20];
	Seleccion aux;
	Seleccion* pAux;

	fscanf(pFile,"%[^,],%[^,],%[^,],%s",idStr,paisStr,confederacionStr,convocadosStr);

	while(!feof(pFile)){
		fscanf(pFile,"%[^,],%[^,],%[^,],%s",idStr,paisStr,confederacionStr,convocadosStr);
		pAux = selec_newParametros(idStr,paisStr,confederacionStr,convocadosStr);
		ll_add(pArrayListSeleccion, pAux);
	}
    return 1;
}
