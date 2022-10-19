#include <stdio.h>
#include <stdlib.h>
#include "confederacion.h"
#include <string.h>



void confederacionPorId(int id, eConfederacion confederaciones[],int cantidadConfederaciones,char confederacion[]){
	for(int i=0;i<cantidadConfederaciones;i++){
		if(id == confederaciones[i].id){
			strcpy(confederacion,confederaciones[i].nombre);
		}
	}
}
