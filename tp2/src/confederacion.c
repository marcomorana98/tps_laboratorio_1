#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"
#include "entradaDeDatos.h"
#include "salidaDeDatos.h"
#include "procesos.h"

void llenarArrayConfederacion(eConfederacion array[]){
	array[0].id = 100;
	strcpy(array[0].nombre,"CONMEBOL");
	strcpy(array[0].region, "SUDAMERICA");
	array[0].anioCreacion = 1916;

	array[1].id = 101;
	strcpy(array[1].nombre, "UEFA");
	strcpy(array[1].region,  "EUROPA");
	array[1].anioCreacion = 1954;

	array[2].id = 102;
	strcpy(array[2].nombre, "AFC");
	strcpy(array[2].region,  "ASIA");
	array[2].anioCreacion = 1954;

	array[3].id = 103;
	strcpy(array[3].nombre, "CAF");
	strcpy(array[3].region, "AFRICA");
	array[3].anioCreacion = 1957;

	array[4].id = 104;
	strcpy(array[4].nombre, "CONCACAF");
	strcpy(array[4].region, "NORTE Y CENTRO AMERICA");
	array[4].anioCreacion = 1961;

	array[5].id = 105;
	strcpy(array[5].nombre, "OFC");
	strcpy(array[5].region,  "OCEANIA");
	array[5].anioCreacion = 1966;

}

int altaConfederacion(eConfederacion confederaciones[],int contadorConfedereaciones){
		int error = 0;
		eConfederacion aux;

		if(contadorConfedereaciones == 0){
			aux.id = 1;
		}
		else{
			aux.id = confederaciones[contadorConfedereaciones-1].id+1;
		}

		if(utn_getCharArray(aux.nombre, 50, "ingrese el nombre de la confederacion \n") == 1){
			if(utn_getCharArray(aux.region, 50, "ingrese el nombre de la region de la confederacion \n") == 1){
				if(utn_getNumero(&aux.anioCreacion, "Ingrese el id de la confederacion \n", "no se reconocio el numero \n", 100, 100000, 2) == 1){
					error = 1;
				}
			}
		}
		if(error == 1){
			confederaciones[contadorConfedereaciones]=aux;

			return 1;
		}
		return 0;
}

int bajaConfederacion(eConfederacion confederaciones[],int contadorConfedereaciones){
	int opcion = 0;
	if(utn_getNumero(&opcion, "ingrese el id de la confederacion que se desea borrar, ingrese 0 para regresar \n", "no se reconocio el numero \n", 0, 99, 2) == 1){
		for(int i=0; i<contadorConfedereaciones;i++){
			if(confederaciones[i].id == opcion){
				for(int j=i;j<=contadorConfedereaciones;j++){
					confederaciones[j].id = confederaciones[j+1].id;
					strcpy(confederaciones[j].nombre,confederaciones[j+1].nombre);
					strcpy(confederaciones[j].region,confederaciones[j+1].region);
					confederaciones[j].anioCreacion = confederaciones[j+1].anioCreacion;
				}
				return 1;
			}
		}
	}
	return 0;
}

int modificarConfederacion(eConfederacion confederaciones[], int cantidadConfederaciones){
	int id;
	int opcion = 8;
	eConfederacion aux;
	char auxNobreConfederacion[50];

	listaConfederacion(confederaciones,cantidadConfederaciones);
	utn_getNumero(&id, "Ingrese el id de la confederacion que desea modficiar \n", "no se reconocio el id \n", 1, 3000, 2);
	if(confederacionPorId( id, confederaciones, cantidadConfederaciones,auxNobreConfederacion) == 1){
		while(opcion != 0){
		printf("Que se desea modificar? \n 1. Nombre \n 2. Region \n 3. Numero de camiseta \n 0. Salir \n");
		utn_getNumero(&opcion, "ingrese opcion del menu \n", "no se reconocio la opcion \n", 0, 3, 2);
		switch(opcion){
			case 1:
				if(utn_getCharArray(aux.nombre, 50, "ingrese el nombre del jugador \n") == 1){
					printf("El jugador a sido modificado correctamente, volviendo al menu... \n");
					strcpy(confederaciones[id].nombre, aux.nombre);
				}
				else{
					printf("El jugador NO a sido modificado, volviendo al menu... \n");
				}
				break;
			case 2:
				if(utn_getCharArray(aux.region, 50, "ingrese la posicion del jugador \n") == 1){
					printf("El jugador a sido modificado correctamente, volviendo al menu... \n");
					strcpy(confederaciones[id].region, aux.region);
				}
				else{
					printf("El jugador NO a sido modificado, volviendo al menu... \n");
				}
				break;
			case 3:
				if(utn_getNumero(&aux.anioCreacion, "Ingrese el id de la confederacion \n", "no se reconocio el numero \n", 100, 100000, 2) == 1){
					printf("El jugador a sido modificado correctamente, volviendo al menu... \n");
					confederaciones[id].anioCreacion = aux.anioCreacion;
				}
				else{
					printf("El jugador NO a sido modificado, volviendo al menu... \n");
				}
				break;
			case 0:
				printf("Volviendo al menu... \n");
				return 0;
				break;
			}
		}
	}
	else{
		printf("no se encontro ese id, volviendo al menu... \n");
		return 0;
}
	return 0;
}
