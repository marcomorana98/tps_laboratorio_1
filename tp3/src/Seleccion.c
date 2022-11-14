#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "Seleccion.h"


int selec_getId(Seleccion* this,int* id){
	*id = this->id;
	return 1;
}
int selec_getPais(Seleccion* this,char* pais){
	strcpy(pais, this->pais);
	return 1;
}

int selec_getConfederacion(Seleccion* this,char* confederacion){
	strcpy(confederacion, this->confederacion);
	return 1;
}

int selec_setConvocados(Seleccion* this,int convocados){
	this->convocados = convocados;
	return 1;
}
int selec_getConvocados(Seleccion* this,int* convocados){
	*convocados = this->convocados;
	return 1;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	Seleccion* seleccionAux = (Seleccion*)malloc(sizeof(Seleccion));
	seleccionAux -> id = atoi(idStr);
	strcpy(seleccionAux->pais,paisStr);
	strcpy(seleccionAux->confederacion,confederacionStr);
	selec_setConvocados(seleccionAux,atoi(convocadosStr));


	return seleccionAux;
}

int selec_buscarIdConfederacion(LinkedList* pArrayListSeleccion,int id){
	Seleccion* seleccionAux = NULL;
	int idAux;
	if(id == 0){
		return -1;
	}
	for(int i = 0; i < ll_len(pArrayListSeleccion);i++){
		seleccionAux = ll_get(pArrayListSeleccion,i);
		selec_getId(seleccionAux,&idAux);
		if(id == idAux){
			return i;
		}
	}
	return -1;
}

int selec_descontarJugadorPorId(LinkedList* pArrayListSeleccion,int id){
	Seleccion* pSeleccion = NULL;
	int indiceSeleccion = selec_buscarIdConfederacion(pArrayListSeleccion,id);
	int aux;
	if(indiceSeleccion != -1){
		pSeleccion = ll_get(pArrayListSeleccion,indiceSeleccion);
		selec_getConvocados(pSeleccion,&aux);
		selec_setConvocados(pSeleccion, aux-1);
		return 1;
	}
	return 0;
}
