/*
 * procesos.h
 *
 *  Created on: 19 Oct 2022
 *      Author: TH
 */

#ifndef PROCESOS_H_
#define PROCESOS_H_
#include "confederacion.h"
#include "jugador.h"

int confederacionPorId(int id, eConfederacion confederaciones[],int cantidadConfederaciones,char confederacion[]);
float promedioDeSalarios(eJugador jugadores[],int cantidadJugadores);
int mayorAnosProceso(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones, char confederacionAux[]);
int mayorPromedio(eJugador jugadores[],int contadorJugadores,float promedio);
int encontrarConfederacionMasGrande(eJugador jugadores[], int contadorJugadores, eConfederacion confederaciones[], int contadorConfederaciones, char regionMasGrande[]);

#endif /* PROCESOS_H_ */
