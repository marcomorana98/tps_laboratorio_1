/*
 * salidaDeDatos.h
 *
 *  Created on: 17 Oct 2022
 *      Author: TH
 */

#ifndef SALIDADEDATOS_H_
#define SALIDADEDATOS_H_
#include "confederacion.h"
#include "jugador.h"


void listaConfederacion(eConfederacion confederaciones[],int cantidad);
void listaJugador(eJugador jugadores[],int cantidad, eConfederacion confederaciones[], int cantidadConfederaciones);
void listarAlfabeticamente(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones);
void listarConfederacionesConJugadores(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones);

#endif /* SALIDADEDATOS_H_ */
