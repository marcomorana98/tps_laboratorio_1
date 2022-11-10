#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"



int jug_setId(Jugador* this,int id){
	this->id = id;
	return 1;
}

int jug_getId(Jugador* this,int* id){
	*id = this->id;
	return 1;
}

int jug_setNombreCompleto(Jugador* this,char nombreCompleto[]){
	strcpy(this->nombreCompleto,nombreCompleto);
	return 1;
}

int jug_getNombreCompleto(Jugador* this,char** nombreCompleto){
	*nombreCompleto = this->nombreCompleto;
	return 1;
}

int jug_setPosicion(Jugador* this,char posicion[]){
	strcpy(this->posicion,posicion);
	return 1;
}

int jug_getPosicion(Jugador* this,char** posicion){
	*posicion = this->posicion;
	return 1;
}

int jug_setNacionalidad(Jugador* this,char nacionalidad[]){
	strcpy(this->nacionalidad,nacionalidad);
	return 1;
}

int jug_getNacionalidad(Jugador* this,char** nacionalidad){
	*nacionalidad = this->nacionalidad;
	return 1;
}

int jug_setEdad(Jugador* this,int edad){
	this->edad = edad;
	return 1;
}

int jug_getEdad(Jugador* this,int* edad){
	*edad = this->edad;
	return 1;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion){
	this->idSeleccion = idSeleccion;
	return 1;
}

int jug_getSIdSeleccion(Jugador* this,int* idSeleccion){
	*idSeleccion = this->idSeleccion;
	return 1;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr){
	Jugador* pjugador = (Jugador*)malloc(sizeof(Jugador));
	jug_setId(pjugador,atoi(idStr));
	jug_setNombreCompleto(pjugador,nombreCompletoStr);
	jug_setPosicion(pjugador,posicionStr);
	jug_setEdad(pjugador,atoi(edadStr));
	jug_setNacionalidad(pjugador,nacionalidadStr);
	jug_setIdSeleccion(pjugador,atoi(idSelccionStr));
	return pjugador;
}
