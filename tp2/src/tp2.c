#include <stdio.h>
#include <stdlib.h>
#include "entradaDeDatos.h"
#include "salidaDeDatos.h"
#include "jugador.h"
#include "confederacion.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcion = 0;
	int totalConfederaciones = 6;
	int contadorJugadores = 0;
	eJugador jugadores[20];
	eConfederacion confederaciones[20];
	llenarArrayConfederacion(confederaciones);
	listaConfederacion(confederaciones,6);

	utn_getNumero(&opcion, "ingrese opcion del menu", "no se reconocio la opcion", 0, 5, 2);
	switch(opcion){
		case 1:
			altaJugador(jugadores, contadorJugadores);
			break;
	}

	return 0;
}
