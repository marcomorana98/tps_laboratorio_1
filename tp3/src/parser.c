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
	char* idStr;
	char* nombreCompletoStr;
	char* edadStr;
	char* posicionStr;
	char* nacionalidadStr;
	char* idSelccionStr;
	Jugador aux;
	Jugador pAux;

	fscanf(pFile,"%s,%s,%s,%s,%s,%s \n",idStr,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSelccionStr);
	while(feof(pFile) != 1){
		fscanf(pFile,"%s,%s,%s,%s,%s,%s \n",idStr,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSelccionStr);
		pAux = jug_newParametros(idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSelccionStr);
		ll_add(pFile, pAux);
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
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	char* idStr;
	char* paisStr;
	char* confederacionStr;
	char* convocadosStr;
	Seleccion aux;
	Seleccion* pAux;

	fscanf(pFile,"%s,%s,%s,%s \n",idStr,paisStr,confederacionStr,convocadosStr);
	while(feof(pFile) != 1){
		fscanf(pFile,"%s,%s,%s,%s \n",idStr,paisStr,confederacionStr,convocadosStr);
		pAux = jug_newParametros(idStr,paisStr,confederacionStr,convocadosStr);
		ll_add(pFile, pAux);
	}
    return 1;
    return 1;
}

