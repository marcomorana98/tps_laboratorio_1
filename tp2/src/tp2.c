#include <stdio.h>
#include <stdlib.h>
#include "entradaDeDatos.h"
#include "salidaDeDatos.h"
#include "jugador.h"
#include "confederacion.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcion = -1;
	int opcionInformes = -1;
	int totalConfederaciones = 6;
	int contadorJugadores = 0;
	int aux;
	eJugador jugadores[3000];
	eConfederacion confederaciones[20];
	llenarArrayConfederacion(confederaciones);
	iniCeroArrayJugadores(jugadores);
	listaConfederacion(confederaciones,6);

	while(opcion !=0){
		printf("Menu principal: \n 1. Alta de jugador \n 2. Baja de jugador \n 3. Modificar jugador \n 4. Menu de informes \n");
		utn_getNumero(&opcion, "ingrese opcion del menu \n", "no se reconocio la opcion \n", 0, 4, 2);
		switch(opcion){
			case 1:
				aux = altaJugador(jugadores, contadorJugadores ,confederaciones ,totalConfederaciones );
				if(aux == 1){
					contadorJugadores++;
				}
				break;
			case 2:
				if(contadorJugadores > 0){
					aux = bajaJugador(jugadores, contadorJugadores);
					if(aux == 1){
						contadorJugadores--;
					}
				}
				else{
					printf("no hay jugadores para borrar \n");
				}
				break;

			case 3:
				if(contadorJugadores > 0){
					modificarJugador(jugadores, contadorJugadores ,confederaciones ,totalConfederaciones );
				}
				else{
					printf("no hay jugadores para modificar \n");
				}
				break;

			case 4:
				while(opcionInformes != 0){
					printf("Menu de informes: \n 1.Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador. \n 2.Listado de confederaciones con sus jugadores. \n 3.Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio. \n 4.Informar la confederación con mayor cantidad de años de contratos total. \n 5.Informar porcentaje de jugadores por cada confederación. \n 6.Informar cual es la región con más jugadores y el listado de los mismos. \n");
					utn_getNumero(&opcionInformes, "ingrese opcion del menu \n", "no se reconocio la opcion \n", 0, 6, 2);
					switch(opcionInformes){
					case 1:
						listarAlfabeticamente(jugadores, contadorJugadores, confederaciones, totalConfederaciones);
						break;
					case 2:
						listarConfederacionesConJugadores(jugadores, contadorJugadores, confederaciones, totalConfederaciones);
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
					case 0:
						break;
					}
				}
				opcionInformes = -1;
				break;
			case 0:
				return 0;
		}
	}

	return 0;
}
