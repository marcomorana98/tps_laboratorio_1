
#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;

}eConfederacion;


#endif /* CONFEDERACION_H_ */

void llenarArrayConfederacion(eConfederacion array[]);
