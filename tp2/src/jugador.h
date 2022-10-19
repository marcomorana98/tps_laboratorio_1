/*
 * jugador.h
 *
 *  Created on: 17 Oct 2022
 *      Author: TH
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

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


#endif /* JUGADOR_H_ */
