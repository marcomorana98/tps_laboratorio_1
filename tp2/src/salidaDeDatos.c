#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"
#include "jugador.h"
#include "procesos.h"



void listaConfederacion(eConfederacion confederaciones[], int contadorConfedereaciones){

	printf("####################################################################### \n");
	printf("| %-5s| %-30s| %-25s| %-20s|\n", "ID", "NOMBRE", "REGION", "AÑO DE CREACION");
	for(int i = 0; i < contadorConfedereaciones; i++){
		printf("| %-5d| %-30s| %-25s| %-20d|\n", confederaciones[i].id, confederaciones[i].nombre, confederaciones[i].region, confederaciones[i].anioCreacion);
	}
	printf("####################################################################### \n\n");
	return;
}

void listaJugador(eJugador jugadores[],int cantidad, eConfederacion confederaciones[], int cantidadConfederaciones){
	char confederacionAux[50];
	printf("###################################################################################################################### \n");
	printf("| %-5s| %-30s| %-25s| %-25s| %-15s| %-20s| %-20s|\n", "ID", "NOMBRE", "POSICION", "N° DE CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");
	for(int i = 0; i <cantidad; i++){
		if(jugadores[i].isEmpty == 0){
			confederacionPorId(jugadores[i].idConfederacion, confederaciones, cantidadConfederaciones, confederacionAux);
			printf("| %-5d| %-30s| %-25s| %-25d| %-15f| %-20s| %-20d|\n", jugadores[i].id, jugadores[i].nombre, jugadores[i].posicion, jugadores[i].numeroCamiseta, jugadores[i].salario, confederacionAux, jugadores[i].aniosContrato);
		}
	}
	printf("###################################################################################################################### \n\n");
	return;
}

void listarConfederacionesConJugadores(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones){
	printf("###################################################################################################################### \n");
	for(int i = 0; i < contadorConfederaciones; i++){
		printf("| %-115s|\n", confederaciones[i].nombre);
		printf("| %-5s| %-30s| %-25s| %-25s| %-15s| %-20s|\n", "ID", "NOMBRE", "POSICION", "N° DE CAMISETA", "SUELDO", "AÑOS DE CONTRATO");
		for(int j = 0; j < contadorJugadores; j++){
			if(jugadores[j].isEmpty == 0 && jugadores[j].idConfederacion == confederaciones[i].id){
				printf("| %-5d| %-30s| %-25s| %-25hu| %-15f| %-20d|\n", jugadores[i].id, jugadores[i].nombre, jugadores[i].posicion, jugadores[i].numeroCamiseta, jugadores[i].salario, jugadores[i].aniosContrato);
			}
		}
		printf("###################################################################################################################### \n");
	}
	printf("###################################################################################################################### \n");
}

void listarAlfabeticamente(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones){
	eJugador auxArray[3000];
	eJugador aux;
	for(int i=0; i<3000;i++){
		auxArray[i] = jugadores[i];
	}
	char auxConfederacion1[50];
	char auxConfederacion2[50];

	for(int i = 0; i < contadorJugadores; i++){
		for(int j = i+1; j < contadorJugadores; j++){
			confederacionPorId(confederaciones[i].id, confederaciones ,contadorConfederaciones, auxConfederacion1);
			confederacionPorId(confederaciones[j].id, confederaciones ,contadorConfederaciones, auxConfederacion2);
			if(strcmp(auxConfederacion2, auxConfederacion1) < 0){
				aux = auxArray[i];
				auxArray[i] = auxArray[j];
				auxArray[j] = aux;
			}
			if(strcmp(auxConfederacion2, auxConfederacion1) == 0){
				if(strcmp(auxArray[j].nombre, auxArray[i].nombre) < 0){
					aux = auxArray[i];
					auxArray[i] = auxArray[j];
					auxArray[j] = aux;
				}
			}
		}
	}

	listaJugador(auxArray,contadorJugadores, confederaciones, contadorConfederaciones);
	return;
}

void informePromedio(eJugador jugadores[],int contadorJugadores){
	printf("El promedio del salario es: %f \n", promedioDeSalarios(jugadores,contadorJugadores));
	printf("Existen %d jugadores los cuales el salario es mayor al promedio",mayorPromedio( jugadores, contadorJugadores,promedioDeSalarios(jugadores,contadorJugadores)));
}

void informeMayorAnosConfederacion(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones){
	char confederacionAux[50];
	int cantidadAnos = mayorAnosProceso(jugadores,contadorJugadores,confederaciones,contadorConfederaciones,confederacionAux);
	printf("La confederacion con mayor cantidad de años en contrato es %s con %d años",confederacionAux, cantidadAnos);
}

void porcentajeJugadoresPorConfederacion(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones){
	float suma = 0;

	for(int i = 0; i < contadorConfederaciones; i++){
		for(int j = 0; j < contadorJugadores; j++){
			if(confederaciones[i].id == jugadores[j].idConfederacion){
					suma = suma + 1 ;
			}
		}
		printf("############################## \n");
		printf("Confederacion: %-30s \n", confederaciones[i].nombre);
		printf("Porcentaje de jugadores: %-30f \n", suma / contadorJugadores * 100);

		suma = 0;
	}
	printf("############################## \n");
}
