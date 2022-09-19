#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "logica.h"

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int gastosIngresados = -1;
	int banderaGastos = -1;
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
	utn_getNumero(&opcion,"Ingrese opcion del menu \n","Numero no reconocido, ingrese otro \n", 0, 4, 2);
	switch(opcion){
		case 0:
			printf("se acabo2");
		break;
		case 1:
			gastosIngresados = montoGastos(gastos);
			if(gastosIngresados == 0){
				banderaGastos = 0;
				gastosIngresados =-1;
			}
		break;
		case 2:
			jugadorEntro = cantidadJugadores(jugadores,contadorDeJugadores,confederaciones);
			if(jugadorEntro == 0){
				jugadoresIngresados = 0;
				contadorDeJugadores++;
				jugadorEntro = -1;
			}
		break;
		case 3:
			if(jugadoresIngresados == 0 && banderaGastos == 0){
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
			printf("Debe ingresar datos en las opciones 1 y 2 antes de entrar a la opcion 3 \n");
			}
			break;
		case 4:
			if(banderaCalculos == 0){
				printf("Porcentaje de AFC: %.2f \n", mercado[0]);
				printf("Porcentaje de CAF: %.2f \n", mercado[1]);
				printf("Porcentaje de CONCACAF: %.2f \n", mercado[2]);
				printf("Porcentaje de CONMEBOL: %.2f \n", mercado[3]);
				printf("Porcentaje de UEFA: %.2f \n", mercado[4]);
				printf("Porcentaje de OFC: %.2f \n", mercado[5]);
				if(banderaAumento == 0){
					printf("Se recibio un aumento de $%.2f a el anterior valor de $%.2f. el costo total pasa a ser $%.2f \n",costoEuropeo,costoCalculoTotal,costoCalculoTotalEuropeo);
				}
				else{
					printf("El costo total ese de $.2%f \n",costoCalculoTotal);
				}
			}
			else{
				printf("Se deben realizar los calculos antes de imprimirlos \n");
			}
		break;
	}
	}
	return 0;

}
