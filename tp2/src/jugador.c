#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entradaDeDatos.h"
#include "jugador.h"
#include "salidaDeDatos.h"


void iniCeroArrayJugadores(eJugador jugadores[]){
	for(int i=0;i<3000;i++){
		jugadores[i].id = 0;
		jugadores[i].isEmpty = 1;
	}
}

int altaJugador(eJugador jugadores[], int contador, eConfederacion confederaciones[],int contadorConfedereaciones){
		int error = 0;
		eJugador aux;
		int posicion;
		if(contador == 0){
			aux.id = 1;
			posicion = 0;
		}
		else{
			for(int i = 1; i<=contador;i++){
				if(jugadores[i].isEmpty == 1){
					aux.id = jugadores[i-1].id+1;
					posicion = i;
					break;
				}
			}
		}

		if(utn_getCharArray(aux.nombre, 50, "ingrese el nombre del jugador \n") == 1){
			if(utn_getCharArray(aux.posicion, 50, "ingrese la posicion del jugador \n") == 1){
				if(utn_getShort(&aux.numeroCamiseta, "ingrese numero de camiseta \n", "no se reconocio el numero \n", 1, 99, 2) == 1){
					printf("cosa");
					listaConfederacion(confederaciones,contadorConfedereaciones);
					if(utn_getNumero(&aux.idConfederacion, "Ingrese el id de la confederacion \n", "no se reconocio el numero \n", 100, contadorConfedereaciones+100, 2) == 1){
						if(utn_getFloat(&aux.salario, "Ingrese el salario del jugador \n", "no se reconocio el numero \n", 0, 999999999, 2) == 1){
							if(utn_getShort(&aux.aniosContrato, "Ingrese los años de contrato del jugador \n", "no se reconocio el numero \n", 0, 32767, 2) == 1){
								error = 1;
								aux.isEmpty = 0;
							}
						}
					}
				}
			}
		}
		if(error == 1){
			printf("ENTRO");
			contador++;
			jugadores[posicion]=aux;

			return 1;
		}
		return 0;
}

int bajaJugador(eJugador jugadores[], int contador){
	int opcion = 0;
	if(utn_getNumero(&opcion, "ingrese el id del jugador que se desea borrar, ingrese 0 para regresar \n", "no se reconocio el numero \n", 0, 99, 2) == 1){
		for(int i=0; i<contador;i++){
			if(jugadores[i].id == opcion){
				for(int j=i;j<=contador;j++){
				jugadores[j].id = jugadores[j+1].id;
				strcpy(jugadores[j].nombre,jugadores[j+1].nombre);
				strcpy(jugadores[j].posicion,jugadores[j+1].posicion);
				jugadores[j].numeroCamiseta = jugadores[j+1].numeroCamiseta;
				jugadores[j].idConfederacion = jugadores[j+1].idConfederacion;
				jugadores[j].salario = jugadores[j+1].salario;
				jugadores[j].aniosContrato = jugadores[j+1].aniosContrato;
				jugadores[j].isEmpty = jugadores[j+1].isEmpty;
				}
				return 1;
			}
		}
	}
	return 0;
}

int modificarJugador(eJugador jugadores[], int contador, eConfederacion confederaciones[], int cantidadConfederaciones){
	int id;
	int opcion;
	int bandera = 0;
	eJugador aux;

	listaJugador( jugadores, contador, confederaciones, cantidadConfederaciones);
	utn_getNumero(&id, "Ingrese el id del jugador que se desea modificar \n", "no se reconocio el id \n", 1, 3000, 2);
	for(int i=0;i<3000;i++){
		if(jugadores[i].id == id){
			bandera = 1;
			aux = jugadores[i];
			break;
		}
	}
	if(bandera == 1){
		while(opcion != 0){
		printf("Que se desea modificar? \n 1. Nombre \n 2. Posicion \n 3. Numero de camiseta \n 4. Confederacion \n 5. Salario \n 6. Años de contrato \n");
		utn_getNumero(&opcion, "ingrese opcion del menu \n", "no se reconocio la opcion \n", 0, 5, 2);
		switch(opcion){
			case 1:
				if(utn_getCharArray(aux.nombre, 50, "ingrese el nombre del jugador \n") == 1){
					printf("El jugador a sido modificado correctamente, volviendo al menu... \n");
				}
				else{
					printf("El jugador NO a sido modificado, volviendo al menu... \n");
				}
				break;
			case 2:
				if(utn_getCharArray(aux.posicion, 50, "ingrese la posicion del jugador \n") == 1){
					printf("El jugador a sido modificado correctamente, volviendo al menu... \n");
				}
				else{
					printf("El jugador NO a sido modificado, volviendo al menu... \n");
				}
				break;
			case 3:
				if(utn_getShort(&aux.numeroCamiseta, "ingrese numero de camiseta \n", "no se reconocio el numero \n", 1, 99, 2) == 1){
					printf("El jugador a sido modificado correctamente, volviendo al menu... \n");
				}
				else{
					printf("El jugador NO a sido modificado, volviendo al menu... \n");
				}
				break;

			case 0:
				return 0;
				break;
			}
		}
	}
	else{
		printf("no se a encontrado el id del jugador, volviendo al menu... \n");
		return 0;
	}
	return 0;
}
