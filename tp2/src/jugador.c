#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entradaDeDatos.h"
#include "jugador.h"


int altaJugador(eJugador jugadores[], int contador){
		int error = 0;
		eJugador aux;

		if(utn_getCharArray(aux.nombre, 50, "ingrese el nombre del jugador") == 1){
			if(utn_getCharArray(aux.posicion, 50, "ingrese la posicion del jugador") == 1){
				if(utn_getNumero(aux.numeroCamiseta, "ingrese numero de camiseta", "no se reconocio el numero", 1, 99, 2) == 1){

				}
			}
		}

}
