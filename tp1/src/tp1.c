#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "logica.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int jugadorEntro = -1;
	int jugadoresIngresados = -1;
	int gastos[3] = {0};
	float costoCalculoTotal = 0;
	int jugadores[22][2];
	char confederaciones[22][9];
	int contadorDeJugadores = 0;
	arrayCero(jugadores, 22, 2);
	float mercado[6] = {0};
	int banderaAumento = -1;
	int banderaCalculos = -1;
	float costoCalculoTotalEuropeo;
	float costoEuropeo;
	while(opcion!=0){
		printf("1. Ingreso de los costos de Mantenimiento \n");
		printf("Costo de Hospedaje -> %d \n", gastos[0]);
		printf("Costo de Comida -> %d \n",gastos[1]);
		printf("Costo de Transporte -> %d \n",gastos[2]);
		printf("2. Carga de jugadores \n");
		printf("Arqueros --> %d \n", verificarPosicion(1,jugadores));
		printf("Defensores --> %d \n", verificarPosicion(2,jugadores));
		printf("Mediocampistas --> %d \n", verificarPosicion(3,jugadores));
		printf("Delanteros --> %d \n", verificarPosicion(4,jugadores));
		printf("3. Realizar calculos \n");
		printf("4. Imprimir calculos \n");
		printf("0. Salir \n");
		utn_getNumero(&opcion,"Ingrese opcion del menu \n","Numero no reconocido, ingrese otro \n", 0, 4, 2);
		switch(opcion){
		case 0:
			printf("Adios");
		break;
		case 1:
			montoGastos(gastos);
		break;
		case 2:
			jugadorEntro = cantidadJugadores(jugadores,contadorDeJugadores,confederaciones);
			if(jugadorEntro == 0){
				contadorDeJugadores++;
				if(equipoMinimo(jugadores, contadorDeJugadores) == 0){
						jugadoresIngresados = 0;
				}
				jugadorEntro = -1;
			}
		break;
		case 3:
			if(jugadoresIngresados == 0 && gastos[0] > 0 && gastos[1] > 0 && gastos[2] > 0){
				calcularPromedios(confederaciones,mercado,contadorDeJugadores);
				costoCalculoTotal = calcularCosto(gastos);
				if(mercado[4] > 50){
					costoCalculoTotalEuropeo = costoCalculoTotal*1.35;
					costoEuropeo = costoCalculoTotal*1.35-costoCalculoTotal;
					banderaAumento = 0;

				}
				banderaCalculos = 0;
			}
			else{
			printf("Debe ingresar todos los gastos y al menos la composicion minima para el equipo antes de entrar a la opcion 3 \n");
			}
			break;
		case 4:
			if(banderaCalculos == 0){
				imprimirResultados(mercado,banderaAumento,costoEuropeo, costoCalculoTotal, costoCalculoTotalEuropeo);

			}
			else{
				printf("Se deben realizar los calculos antes de imprimirlos \n");
			}
		break;
		default:
			printf("La opcion no fue reconocida, por favor ingrese otra opcion \n");
		break;
	}
	}
	return 0;

}
