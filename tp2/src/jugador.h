/*
 * jugador.h
 *
 *  Created on: 17 Oct 2022
 *      Author: TH
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "confederacion.h"

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

int altaJugador(eJugador jugadores[], int contador, eConfederacion confederaciones[],int contadorConfedereaciones);
int bajaJugador(eJugador jugadores[], int contador);
int modificarJugador(eJugador jugadores[], int contador, eConfederacion confederaciones[], int cantidadConfederaciones);
void iniCeroArrayJugadores(eJugador jugadores[]);

#endif /* JUGADOR_H_ */
