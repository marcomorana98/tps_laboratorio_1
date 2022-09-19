/*
 * input.h
 *
 *  Created on: 17 Sept 2022
 *      Author: TH
 */

#ifndef INPUT_H_
#define INPUT_H_

int utn_getNumero(int* pResultado,
char* mensaje,
char* mensajeError,
int minimo,
int maximo,
int reintentos);

int utn_getCharArray(char array[][9],char* mensaje,char* mensajeError,int reintentos, int contadorDeArray);

#endif /* INPUT_H_ */
