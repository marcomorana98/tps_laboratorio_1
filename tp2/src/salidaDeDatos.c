#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"
#include "jugador.h"
#include "procesos.h"

void listaConfederacion(eConfederacion confederaciones[],int cantidad){
	printf("==================================\n");
	printf("|%-5s|%-20s|%-30s|%-25s|\n",
	"ID","NOMBRE","REGION","AÑOS CREACION");
	for(int i=0;i<cantidad;i++){
		printf("|%-5d|%-20s|%-30s|%-25d|\n",confederaciones[i].id,confederaciones[i].nombre,confederaciones[i].region,confederaciones[i].anioCreacion);
	}
}

void listaJugador(eJugador jugadores[],int cantidad, eConfederacion confederaciones[], int cantidadConfederaciones){
	char confederacionNombre [20];
	printf("==================================\n");
	printf("|%-5s|%-20s|%-30s|%-25s|%-25s|%-25s|\n",
	"ID","NOMBRE","POSICION","N CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS DE CONTRATO");
	for(int i=0;i<cantidad;i++){
		confederacionPorId(jugadores[i].idConfederacion,confederaciones,cantidadConfederaciones, confederacionNombre);
		printf("|%-5d|%-20s|%-30s|%-25d|%-25s|%-25d|\n",jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,confederacionNombre,jugadores[i].aniosContrato);
	}
};
