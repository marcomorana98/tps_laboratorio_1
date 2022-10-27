/*
 * entradaDeDatos.h
 *
 *  Created on: 17 Oct 2022
 *      Author: TH
 */

#ifndef ENTRADADEDATOS_H_
#define ENTRADADEDATOS_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getShort(short* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

int utn_getCharArray(char* pResultado, int maxLen, char* mensaje);


#endif /* ENTRADADEDATOS_H_ */
