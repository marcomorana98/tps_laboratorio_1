#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <string.h>

int montoGastos(int gastos[]){
	int result = -1;
	int opcion;
	utn_getNumero(&opcion,"Seleccione uno de los tipos de gastos: Hospedaje(1) - Comida (2) - Transporte (3) \n","error", 1, 3, 2);
	switch(opcion){
	case 1:
		result = utn_getNumero(&gastos[0],"Ingrese gasto del hospedaje","error", 1, 999999999, 2);
		return result;
		break;
	case 2:
		result = utn_getNumero(&gastos[1],"Ingrese gasto de la comida","error", 1, 999999999, 2);
		return result;
		break;
	case 3:
		result = utn_getNumero(&gastos[2],"Ingrese gasto del transporte","error", 1, 999999999, 2);
		return result;
		break;
	default:
		return result;
	}

}

int verificarPosicion(int posicion,int jugadores[][2]);
void arrayCero(int array[][2], int primeraLongitud, int segundaLongitud);
int cargarJugador(int jugadores[][2],int posicion, int contadorDeJugadores);
int cargarConfederaciones(char confederaciones[][9], int contadorDeJugadores);

int cantidadJugadores(int jugadores[][2], int contadorDeJugadores, char confederaciones[][9]){
	int opcion = 0;
	int aux;
	int error;
	int errorConfed;


	utn_getNumero(&opcion,"Ingrese tipo de jugador: Arquero(1) - Defensor(2) - Mediocampista(3) - Delantero(4) \n","Numero no reconocido, ingrese otro", 0, 4, 2);
	switch(opcion){

	case 1:
		aux = verificarPosicion(1,jugadores);
		if(aux < 2){
			error = cargarJugador(jugadores,1,contadorDeJugadores);
			errorConfed = cargarConfederaciones(confederaciones,contadorDeJugadores);
		}
		else{
			printf("a llegado al limite de arqueros");
			return -1;
		}
		if(error == -1 || errorConfed == -1){
			return -1;
		}
		return 0;
		break;
	case 2:
		aux = verificarPosicion(2,jugadores);
		if(aux < 8){
			error = cargarJugador(jugadores,2,contadorDeJugadores);
			errorConfed = cargarConfederaciones(confederaciones,contadorDeJugadores);
		}
		else{
			printf("a llegado al limite de defensores");
			return -1;
		}
		if(error == -1 || errorConfed == -1){
			return -1;
		}
		return 0;
		break;
	case 3:
		aux = verificarPosicion(3,jugadores);
		if(aux < 8){
			error = cargarJugador(jugadores,1,contadorDeJugadores);
			errorConfed = cargarConfederaciones(confederaciones,contadorDeJugadores);
		}
		else{
			printf("a llegado al limite de mediocampistas");
			return -1;
		}
		if(error == -1 || errorConfed == -1){
			return -1;
		}
		return 0;
		break;
	case 4:
		aux = verificarPosicion(4,jugadores);
		if(aux < 4){
			error = cargarJugador(jugadores,4,contadorDeJugadores);
			errorConfed = cargarConfederaciones(confederaciones,contadorDeJugadores);
		}
		else{
			printf("a llegado al limite de delanteros");
			return -1;
		}
		if(error == -1 || errorConfed == -1){
			return -1;
		}
		return 0;
		break;
	default:
		return -1;
		break;
	}
}

int cargarJugador(int jugadores[][2],int posicion, int contadorDeJugadores){
	int camiseta;
	int aux;
	aux = utn_getNumero(&camiseta,"Ingrese numero de camiseta de 1 a 99 \n","Numero no reconocido, ingrese otro", 1, 99, 2);
	jugadores[contadorDeJugadores][0] = camiseta;
	jugadores[contadorDeJugadores][1] = posicion;
	return aux;
}

int cargarConfederaciones(char confederaciones[][9], int contadorDeJugadores){
	int aux;
	aux = utn_getCharArray(confederaciones,"INGRESE CONFEDERACION \n","Numero no reconocido, ingrese otro", 2,contadorDeJugadores);
	printf("%s", confederaciones[contadorDeJugadores]);
	return aux;
}

int verificarPosicion(int posicion,int jugadores[][2]){
	int contador=0;
	for(int i=0;i<21;i++){
		if(jugadores[i][1]==posicion){
			contador++;
		}
	}
	return contador;
}

void arrayCero(int array[][2], int primeraLongitud, int segundaLongitud){
	for(int i=0; i<primeraLongitud;i++){
		for(int j=0; j<segundaLongitud;j++){
			array[i][j] = 0;
		}
	}
}

void calcularPromedios(char confederaciones[][9],float mercado[],int contadorDeJugadores){
	for(int i=0;i<contadorDeJugadores;i++){
		if(strcmp(confederaciones[i], "AFC")==0){

			mercado[0]+= 100/contadorDeJugadores;
		}
		if(strcmp(confederaciones[i], "CAF")==0){
			mercado[1]+= 100/contadorDeJugadores;
		}
		if(strcmp(confederaciones[i], "CONCACAF")==0){
			mercado[2]+= 100/contadorDeJugadores;
		}
		if(strcmp(confederaciones[i], "CONMEBOL")==0){
			mercado[3]+= 100/contadorDeJugadores;
		}
		if(strcmp(confederaciones[i], "UEFA")==0){
			mercado[4] = 100/contadorDeJugadores;
		}
		if(strcmp(confederaciones[i], "OFC")==0){
			mercado[5]+= 100/contadorDeJugadores;
		}
	}

}

float calcularCosto(int gastos[]){
	float total = 0;
	for(int i = 0; i<3; i++){
		total += gastos[i];
	}
	return total;
}
