#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int ret;
	int num;
	while(reintentos>0){
		printf(mensaje);
		scanf("%d",&num);
		if(num<=maximo && num>=minimo)
			break;
		reintentos--;
		printf(mensajeError);}
	if(reintentos==0){
		ret=-1;
		}
	else{
		ret=0;
		*pResultado = num;
	}
return ret;
}

int utn_getCharArray(char array[][9],char* mensaje,char* mensajeError,int reintentos, int contadorDeArray){
	int ret;
	char aux[9] = {0};
	gets(aux);
	while(reintentos>0){
		printf(mensaje);
		gets(aux);
		if(strcmp(aux, "AFC")==0 || strcmp(aux, "CAF")==0 || strcmp(aux, "CONCACAF")==0 || strcmp(aux, "CONMEBOL")==0 || strcmp(aux, "UEFA")==0 || strcmp(aux, "OFC")==0)
			break;
		reintentos--;
		printf(mensajeError);}
	if(reintentos==0){
		printf("ULTRA ERROR");
		ret=-1;
		}
	else{
		printf("paso bien");
		ret=0;
		strcpy(array[contadorDeArray],aux);
	}
return ret;
}
