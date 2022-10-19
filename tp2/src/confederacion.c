#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"

void llenarArrayConfederacion(eConfederacion array[]){
	array[0].id = 100;
	strcpy(array[0].nombre,"CONMEBOL");
	strcpy(array[0].region, "SUDAMERICA");
	array[0].anioCreacion = 1916;

	array[1].id = 101;
	strcpy(array[1].nombre, "UEFA");
	strcpy(array[1].region,  "EUROPA");
	array[1].anioCreacion = 1954;

	array[2].id = 102;
	strcpy(array[2].nombre, "AFC");
	strcpy(array[2].region,  "ASIA");
	array[2].anioCreacion = 1954;

	array[3].id = 103;
	strcpy(array[3].nombre, "CAF");
	strcpy(array[3].region, "AFRICA");
	array[3].anioCreacion = 1957;

	array[4].id = 104;
	strcpy(array[4].nombre, "CONCACAF");
	strcpy(array[4].region, "NORTE Y CENTRO AMERICA");
	array[4].anioCreacion = 1961;

	array[5].id = 105;
	strcpy(array[5].nombre, "OFC");
	strcpy(array[5].region,  "OCEANIA");
	array[5].anioCreacion = 1966;

}


