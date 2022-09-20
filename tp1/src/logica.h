/*
 * logica.h
 *
 *  Created on: 17 Sept 2022
 *      Author: TH
 */

#ifndef LOGICA_H_
#define LOGICA_H_

int montoGastos(int gastos[]);
int cantidadJugadores(int jugadores[][2], int contadorDeJugadores, char confederaciones[][9]);
void arrayCero(int array[][2], int primeraLongitud, int segundaLongitud);
int verificarPosicion(int posicion,int jugadores[][2]);
void calcularPromedios(char confederaciones[][9],float mercado[],int contadorDeJugadores);
float calcularCosto(int gastos[]);
void imprimirResultados(float mercado[],int banderaAumento,float costoEuropeo,float costoCalculoTotal,float costoCalculoTotalEuropeo);
#endif /* LOGICA_H_ */
