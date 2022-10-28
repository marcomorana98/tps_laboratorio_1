#include <stdio.h>
#include <stdlib.h>
#include "confederacion.h"
#include "jugador.h"
#include <string.h>



void confederacionPorId(int id, eConfederacion confederaciones[],int cantidadConfederaciones,char confederacion[]){
	for(int i=0;i<cantidadConfederaciones;i++){
		if(id == confederaciones[i].id){
			strcpy(confederacion,confederaciones[i].nombre);
			return;
		}
	}
}

float promedioDeSalarios(eJugador jugadores[],int cantidadJugadores){
	float suma = 0;
	float total = 0;
	for(int i=0; i<cantidadJugadores; i++){
		suma = suma + jugadores[i].salario;
	}
	total = suma / cantidadJugadores;

	return total;
}

int mayorPromedio(eJugador jugadores[],int contadorJugadores,float promedio){
	int total = 0;
	for(int i=0;i<contadorJugadores;i++){
		if(jugadores[i].salario>promedio){
			total++;
		}
	}
	return total;
}

int mayorAnosProceso(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones, char confederacionAux[]){
	int mayor = 0;
	int aux = 0;
	for(int i = 0; i < contadorConfederaciones; i++){
		for(int j = 0; i < contadorJugadores; j++){
			if(jugadores[j].idConfederacion == confederaciones[i].id){
				aux = aux + jugadores[j].aniosContrato;
			}
		}
		if(aux > mayor){
			mayor = aux;
			confederacionAux = confederaciones[i].nombre;
		}
		aux = 0;
	}
	return mayor;
}
