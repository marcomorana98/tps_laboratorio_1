#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED


typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

typedef struct
{
	int id;
	char pais[30];
}Naciones;

typedef struct
{
	int id;
	char posicion[30];
}Posiciones;



Jugador* jug_new();
Jugador* jug_newParametros(char idStr[],char nombreCompletoStr[],char edadStr[], char posicionStr[], char nacionalidadStr[], char idSelccionStr[]);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char** nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char** posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char** nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

int jug_setIsEmpty(Jugador* this,int isEmpty);
int jug_getIsEmpty(Jugador* this,int* isEmpty);

int listarPosiciones(Posiciones totalPosiciones[]);
int listarNaciones(Naciones totalNaciones[]);
int elegirPosiciones(Posiciones* totalPosiciones, char posicion[]);
int elegirNacion(Naciones* totalNaciones, char nacion[]);


#endif // jug_H_INCLUDED
