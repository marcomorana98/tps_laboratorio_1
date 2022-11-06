#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int ret;
	int num;
	while(reintentos>0){
		setbuf(stdout, NULL);
		printf(mensaje);
		fflush(stdin);
		if(scanf("%d",&num)){
			if(num<=maximo && num>=minimo)
				break;}
		reintentos--;
		printf(mensajeError);

	}
	if(reintentos==0){
		ret=-0;
		}
	else{
		ret=1;
		*pResultado = num;
	}
return ret;
}

int utn_getShort(short* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos){
	int ret;
	short num;
	while(reintentos>0){
		setbuf(stdout, NULL);
		printf(mensaje);
		fflush(stdin);
		if(scanf("%hu",&num)){
			if(num<=maximo && num>=minimo)
				break;}
		reintentos--;
		printf(mensajeError);

	}
	if(reintentos==0){
		ret=0;
		}
	else{
		ret=1;
		*pResultado = num;
	}
return ret;
}

int utn_getFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos){
	int ret;
	float num;
	while(reintentos>0){
		setbuf(stdout, NULL);
		printf(mensaje);
		fflush(stdin);
		if(scanf("%f",&num)){
			if(num<=maximo && num>=minimo)
				break;}
		reintentos--;
		printf(mensajeError);

	}
	if(reintentos==0){
		ret=0;
		}
	else{
		ret=1;
		*pResultado = num;
	}
return ret;
}


int myGets(char* cadena,int largo)
{
    int retorno=-1;

    fflush(stdin);
    fgets(cadena,largo,stdin);
    (*(cadena+strlen(cadena)-1))='\0';


    return retorno;
}

int esAlfabetica(char cadena[]){
    int retorno=1;

    for(int i=0;*(cadena+i)!='\0';i++){
        if(((*(cadena+i))>'z'||(*(cadena+i))<'a') && ((*(cadena+i))>'Z'||(*(cadena+i))<'A')){
            if((*(cadena+i))!=' '){
                retorno=0;
                break;
            }

        }
    }

    return retorno;
}

int utn_getCharArray(char* pResultado, int maxLen, char* mensaje){
    int retorno = 0;
    char buffer[maxLen];
    printf(mensaje);
    if(myGets(buffer,sizeof(buffer)) && esAlfabetica(buffer)){
            retorno=1;

            strcpy(pResultado,buffer);


    }

    return retorno;
}
