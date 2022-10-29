#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"
#include "jugador.h"
#include "procesos.h"


//Esta funcion lista las confederaciones
void listaConfederacion(eConfederacion confederaciones[], int contadorConfedereaciones){

	printf("############################################################################################## \n");
	printf("| %-5s| %-30s| %-25s| %-25s |\n", "ID", "NOMBRE", "REGION", "AÑO DE CREACION");
	for(int i = 0; i < contadorConfedereaciones; i++){
		printf("| %-5d| %-30s| %-25s| %-25d|\n", confederaciones[i].id, confederaciones[i].nombre, confederaciones[i].region, confederaciones[i].anioCreacion);
	}
	printf("############################################################################################## \n");
	return;
}

//Esta funcion lista los jugadores
void listaJugador(eJugador jugadores[],int cantidad, eConfederacion confederaciones[], int cantidadConfederaciones){
	char confederacionAux[50];
	printf("###########################################################################################################################################################\n");
	printf("| %-5s| %-30s| %-25s| %-25s | %-15s| %-20s| %-20s |\n", "ID", "NOMBRE", "POSICION", "N° DE CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");
	for(int i = 0; i <cantidad; i++){
		if(jugadores[i].isEmpty == 0){
			confederacionPorId(jugadores[i].idConfederacion, confederaciones, cantidadConfederaciones, confederacionAux);
			printf("| %-5d| %-30s| %-25s| %-25d| %-15.2f| %-20s| %-20d|\n", jugadores[i].id, jugadores[i].nombre, jugadores[i].posicion, jugadores[i].numeroCamiseta, jugadores[i].salario, confederacionAux, jugadores[i].aniosContrato);
		}
	}
	printf("###########################################################################################################################################################\n");
	return;
}

//Esta funcion lista una confederacion con sus respectivos jugadores
void listarConfederacionConJugadores(eJugador jugadores[], int contadorJugadores, eConfederacion confederacion, int contadorConfederaciones){

	printf("| %-5s| %-30s| %-25s| %-25s | %-15s| %-20s |\n", "ID", "NOMBRE", "POSICION", "N° DE CAMISETA", "SUELDO", "AÑOS DE CONTRATO");
	for(int i = 0; i < contadorJugadores; i++){
		if(jugadores[i].isEmpty == 0 && jugadores[i].idConfederacion == confederacion.id){
			printf("| %-5d| %-30s| %-25s| %-25hu| %-15.2f| %-20d|\n", jugadores[i].id, jugadores[i].nombre, jugadores[i].posicion, jugadores[i].numeroCamiseta, jugadores[i].salario, jugadores[i].aniosContrato);
		}}
	printf("##################################################################################################################################### \n");
}


//Esta funcion lista varias confederaciones con sus respectivos jugadores
void listarConfederacionesConJugadores(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones){
	printf("################################################################################################################################### \n");
	for(int i = 0; i < contadorConfederaciones; i++){
		printf("| %-130s|\n", confederaciones[i].nombre);
		listarConfederacionConJugadores(jugadores, contadorJugadores, confederaciones[i], contadorConfederaciones);
	}
}

//Esta funcion lista los jugadores ordenados alfabeticamente por su confederacion y su region
void listarAlfabeticamente(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones){
	eJugador auxArray[3000];
	eJugador aux;
	for(int i=0; i<contadorJugadores;i++){
		auxArray[i] = jugadores[i];
	}
	char auxConfederacion1[50];
	char auxConfederacion2[50];
	printf("%d\n",contadorJugadores);
	for(int i = 0; i < contadorJugadores; i++){
		for(int j = i+1; j < contadorJugadores; j++){
			confederacionPorId(auxArray[i].idConfederacion, confederaciones ,contadorConfederaciones, auxConfederacion1);
			confederacionPorId(auxArray[j].idConfederacion, confederaciones ,contadorConfederaciones, auxConfederacion2);
			if(strcmp(auxConfederacion1, auxConfederacion2) > 0){
				aux = auxArray[i];
				auxArray[i] = auxArray[j];
				auxArray[j] = aux;
			}
			else{
				if(strcmp(auxConfederacion1, auxConfederacion2) == 0){
					if(strcmp(auxArray[i].nombre, auxArray[j].nombre) > 0){
						aux = auxArray[i];
						auxArray[i] = auxArray[j];
						auxArray[j] = aux;
					}
				}
			}
		}
	}

	for(int i=0; i<contadorJugadores;i++){
		printf("%d \n", auxArray[i].idConfederacion);
	}

	listaJugador(auxArray,contadorJugadores, confederaciones, contadorConfederaciones);
	return;
}

//Esta funcion informa el promedio de los sueldos de los jugadores y informa cuantos superan este
void informePromedio(eJugador jugadores[],int contadorJugadores){
	printf("El promedio del salario es: %.2f \n", promedioDeSalarios(jugadores,contadorJugadores));
	printf("Existen %d jugadores los cuales el salario es mayor al promedio \n",mayorPromedio( jugadores, contadorJugadores,promedioDeSalarios(jugadores,contadorJugadores)));
}

//Esta funcion informa cual es la confederacion con mayor cantidad de años de contrato
void informeMayorAnosConfederacion(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones){
	char confederacionAux[50];
	int cantidadAnos = mayorAnosProceso(jugadores,contadorJugadores,confederaciones,contadorConfederaciones,confederacionAux);
	printf("La confederacion con mayor cantidad de años en contrato es %s con %d años \n",confederacionAux, cantidadAnos);
}

//Esta funcion muestra las confederaciones y el porcentaje de jugadores que poseen sobre el total
void porcentajeJugadoresPorConfederacion(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones){
	float suma = 0;

	for(int i = 0; i < contadorConfederaciones; i++){
		for(int j = 0; j < contadorJugadores; j++){
			if(confederaciones[i].id == jugadores[j].idConfederacion){
					suma = suma + 1 ;
			}
		}
		printf("################################################ \n");
		printf("|Confederacion: %-30s |\n", confederaciones[i].nombre);
		printf("|Porcentaje de jugadores: %-20.2f |\n", suma / contadorJugadores * 100);

		suma = 0;
	}
	printf("################################################ \n");
}

//Esta funcion muestra la region con mas jugadores y lista los mismos
void informeConfederacionConMasJugadores(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones){
	char regionMasGrande[50];
	int posicionMayorArray;

	posicionMayorArray = encontrarConfederacionMasGrande(jugadores, contadorJugadores, confederaciones, contadorConfederaciones, regionMasGrande);
	printf("La region mas grande es: %s\n Y sus jugadores son: \n",regionMasGrande);
	printf("##################################################################################################################################### \n");
	listarConfederacionConJugadores(jugadores, contadorJugadores,confederaciones[posicionMayorArray], contadorConfederaciones);
	return;
}


