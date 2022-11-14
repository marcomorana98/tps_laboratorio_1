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
	char nombreCompletoStr[100];
	char edadStr[20];
	char posicionStr[30];
	char nacionalidadStr[30];
	char idSeleccionStr[20];
	Jugador* pAux = NULL;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%s",idStr,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSeleccionStr);
	while(!feof(pFile)){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%s",idStr,nombreCompletoStr,edadStr,posicionStr,nacionalidadStr,idSeleccionStr);
		pAux = jug_newParametros(idStr, nombreCompletoStr, edadStr, posicionStr, nacionalidadStr, idSeleccionStr);
		ll_add(pArrayListJugador, pAux);
		pAux = NULL;
	}
	free(pAux);
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
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	char idString[10];
	char edadString[10];
	char idSeleccionString[10];

	Jugador* jugPAux = NULL;
	jugPAux = (Jugador*)malloc(sizeof(Jugador));
	while(!feof(pFile)){

		fread(&id,sizeof(int),1,pFile);
		fread(&nombreCompleto,sizeof(char)*100,1,pFile);
		fread(&edad,sizeof(int),1,pFile);
		fread(&posicion,sizeof(char)*30,1,pFile);
		fread(&nacionalidad,sizeof(char)*30,1,pFile);
		fread(&idSeleccion,sizeof(int),1,pFile);
		if(feof(pFile)){return 1;};
		sprintf(idString,"%d",id);
		sprintf(edadString,"%d",edad);
		sprintf(idSeleccionString,"%d",idSeleccion);
		jugPAux = jug_newParametros(idString, nombreCompleto, edadString, posicion, nacionalidad, idSeleccionString);
		ll_add(pArrayListJugador, jugPAux);

	}
	free(jugPAux);
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
	Seleccion* pAux = NULL;

	fscanf(pFile,"%[^,],%[^,],%[^,],%s",idStr,paisStr,confederacionStr,convocadosStr);

	while(!feof(pFile)){
		fscanf(pFile,"%[^,],%[^,],%[^,],%s",idStr,paisStr,confederacionStr,convocadosStr);
		pAux = selec_newParametros(idStr,paisStr,confederacionStr,convocadosStr);
		ll_add(pArrayListSeleccion, pAux);
	}
	free(pAux);
    return 1;
}
