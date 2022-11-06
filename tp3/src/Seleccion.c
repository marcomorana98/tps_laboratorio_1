#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Seleccion.h"

Seleccion* selec_new();


int selec_getId(Seleccion* this,int* id){
	id = this->id;
	return 1;
}
int selec_getPais(Seleccion* this,char* pais){
	pais = this->pais;
	return 1;
}

int selec_getConfederacion(Seleccion* this,int* confederacion){
	confederacion = this->confederacion;
	return 1;
}

int selec_setConvocados(Seleccion* this,int convocados){
	this->convocados = convocados;
	return 1;
}
int selec_getConvocados(Seleccion* this,int* convocados){
	convocados = this->convocados;
	return 1;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	Seleccion* seleccionAux;
	seleccionAux -> id = atoi(idStr);
	seleccionAux -> pais = paisStr;
	seleccionAux -> confederacion = confederacionStr;
	selec_setConvocados(seleccionAux,atoi(convocadosStr));


	return seleccionAux;
}
