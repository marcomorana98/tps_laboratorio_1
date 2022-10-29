#include <stdio.h>
#include <stdlib.h>
#include "confederacion.h"
#include "jugador.h"
#include <string.h>


//Esta funcion encuentra una confederacion por el id y le asigna el valor del nombre a un array
int confederacionPorId(int id, eConfederacion confederaciones[],int cantidadConfederaciones,char confederacion[]){
	for(int i=0;i<cantidadConfederaciones;i++){
		if(id == confederaciones[i].id){
			strcpy(confederacion,confederaciones[i].nombre);
			return 1;
		}
	}
	return 0;
}

//Esta funcion calcula el promedio de los salarios de los jugadores
float promedioDeSalarios(eJugador jugadores[],int cantidadJugadores){
	float suma = 0;
	float total = 0;
	for(int i=0; i<cantidadJugadores; i++){
		suma = suma + jugadores[i].salario;
	}
	total = suma / cantidadJugadores;

	return total;
}

//Esta funcion calcula cuantos jugadores superan el promedio del salario
int mayorPromedio(eJugador jugadores[],int contadorJugadores,float promedio){
	int total = 0;
	for(int i=0;i<contadorJugadores;i++){
		if(jugadores[i].salario>promedio){
			total++;
		}
	}
	return total;
}

//Esta funcion calcula cual confederacion posee mayor cantidad de años de contrato y lo asigna a un array, tambien devuelve la suma de los años de la confederacion con mas años de contrato
int mayorAnosProceso(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones, char confederacionAux[]){
	int mayor = 0;
	int aux = 0;
	for(int i = 0; i < contadorConfederaciones; i++){
		for(int j = 0; j < contadorJugadores; j++){
			if(jugadores[j].idConfederacion == confederaciones[i].id){
				aux = aux + jugadores[j].aniosContrato;
			}
		}
		if(aux > mayor){
			mayor = aux;
			strcpy(confederacionAux, confederaciones[i].nombre);
		}
		aux = 0;
	}
	return mayor;
}


//Esta funcion encuentra la confederacion con mas jugadores y le asigna el valor de la region a un array y devuelve la posicion en el array de la confederacion con mas jugadores
int encontrarConfederacionMasGrande(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones, char regionMasGrande[]){
	int mayor = 0;
	int aux = 0;
	int lugar;
	for(int i = 0; i < contadorConfederaciones; i++){
		for(int j = 0; j < contadorJugadores; j++){
			if(jugadores[j].idConfederacion == confederaciones[i].id){
				aux++;
			}
		}
		if(aux > mayor){
			mayor = aux;
			strcpy(regionMasGrande, confederaciones[i].region);
			lugar = i;
		}
		aux = 0;
	}
	return lugar;
}
