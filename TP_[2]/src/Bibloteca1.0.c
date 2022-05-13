/*
 * Liberaria1.0.c
 *
 *  Created on: 3 may. 2022
 *      Author: Lio
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Bibloteca1.0.h"

int utn_getNumeroFlotante (char mensaje[], int reintentos, float minimo, float maximo, char mensajeError[], float *pnumeroIngresado )
{
	int rtn=0;
	float auxiliarFloat;
	int retornoGetFloat;

	if(mensaje != NULL && reintentos > 0 && maximo > minimo && mensajeError != NULL && pnumeroIngresado != NULL )
	{
		printf("%s", mensaje);
		retornoGetFloat= getFloat(&auxiliarFloat);
		do{
			if(retornoGetFloat !=1  || auxiliarFloat > maximo || auxiliarFloat < minimo)
			{
				reintentos--;
				printf("%s", mensajeError);
				retornoGetFloat= getFloat(&auxiliarFloat);
				fflush(stdin); //Porque si ingresan una letra nunca más entro en el do while.
				if(reintentos == 0)
				{
					puts("Se ha superado la cantidad maxima de reintentos");
				}
			}
			else
			{
				reintentos = 0;
				*pnumeroIngresado = auxiliarFloat;
				rtn = 1;
			}



		}while(reintentos>0);
	}

	return rtn;
}

int getFloat(float *pnumeroIngresado)
{
	int rtn = 0;
	char bufferString[50];

	if( pnumeroIngresado != NULL ) // CHEQUEO QUE EL VALOR DE PUNTERO SEA DIF. DE NULL
	{
		if(myGets(bufferString,sizeof(bufferString))== 1) // VALIDO DE QUE LA FUNCION myGets FUNCIONE CORRECTAMENTE
		{
			if(esFlotante(bufferString)) // VALIDA QUE LA FUNCION ESNUMERICA RECIBIO UN NUMERO
			{
				rtn = 1;
				*pnumeroIngresado = atof(bufferString); // Si todo es correcto se guarda en el puntero el numero que es la transformación de el atoi (que pasa de cadena a un numero)
			}
		}
	}

	return rtn;
}

int esFlotante(char* cadena)
{
	int rtn = 1;
	int i;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena)>0 )
	{
		for(i=0; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i] == '-'))
			{
				continue;
			}
			if( cadena [i] > '9' || cadena [i] < '0')
			{
				if(cadena[i]=='.')
				{
					contadorPuntos++;
				}
				else
				{
					rtn = 0;
					break;
				}
			}
		}
	}

	return rtn;
}


int utn_getNumero (char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int *pnumeroIngresado )
{
	int rtn=0;
	int auxiliarInt;
	int retornoGetInt;

	if(mensaje != NULL && reintentos > 0 && maximo > minimo && mensajeError != NULL && pnumeroIngresado != NULL )
	{
		printf("%s", mensaje);
		retornoGetInt= getInt(&auxiliarInt);
		do{
			if(retornoGetInt !=1  || auxiliarInt > maximo || auxiliarInt < minimo)
			{
				reintentos--;
				printf("%s", mensajeError);
				retornoGetInt= getInt(&auxiliarInt);
				fflush(stdin); //Porque si ingresan una letra nunca más entro en el do while.
				if(reintentos == 0)
				{
					puts("Se ha superado la cantidad maxima de reintentos");
				}
			}
			else
			{
				reintentos = 0;
				*pnumeroIngresado = auxiliarInt;
				rtn = 1;
			}


		}while(reintentos>0);
	}

	return rtn;
}

int getInt(int *pnumeroIngresado)
{
	int rtn = 0;
	char bufferString[50];

	if( pnumeroIngresado != NULL ) // CHEQUEO QUE EL VALOR DE PUNTERO SEA DIF. DE NULL
	{
		if(myGets(bufferString,sizeof(bufferString))== 1) // VALIDO DE QUE LA FUNCION myGets FUNCIONE CORRECTAMENTE
		{
			if(esNumerica(bufferString)) // VALIDA QUE LA FUNCION ESNUMERICA RECIBIO UN NUMERO
			{
				rtn = 1;
				*pnumeroIngresado = atoi(bufferString); // Si todo es correcto se guarda en el puntero el numero que es la transformación de el atoi (que pasa de cadena a un numero)
			}
		}
	}

	return rtn;
}


int myGets(char* cadena, int longitud) // FUNCION PARA PEDIR AL USUARIO QUE INGRESE ALGO CON UN LIMITE MÁXIMO ESTABLECIDO POR EL USUARIO EN EL LLAMADO DE LA FUNCIÓN
{
	char bufferString[4096]; // Se le da un valor al buffer lo suficientemente largo como para almacenar el valor de la cadena.
	int rtn = 0;

	if(cadena!= NULL && longitud > 0 )// Validacion de datos que vienen desde donde se llama la función.
	{
		fflush(stdin);
		//fgets(bufferString, sizeof(bufferString), stdin); | 1- Lugar donde se almacena el fgets | 2- N° máximo de caracteres que se leeran | 3- Lugar de donde lo leé |
		if(fgets(bufferString, sizeof(bufferString), stdin))
		{
			if(bufferString[strlen(bufferString)-1] == '\n') // Valido que si el usuario realiza un \n no le piso el ultimo dato ingresado con un \0
			{
				bufferString[strlen(bufferString)-1] = '\0'; // Establezco el limite hasta donde quiero que almacene la cadena, en este caso hasta el \0. El -1 le roba un lugar de memoria al buffer para el \0.
			}
			if(strlen(bufferString) <= longitud) // Verificacion de que la cadena ingresada es menor que la longitud establecida por el usuario en la llamada a la función
			{
				strncpy(cadena, bufferString, longitud); // Si todo esta ok, se realiza el reemplazo del buffer en el puntero *cadena.
				rtn = 1; //Returna TRUE salio todo ok.
			}
		}
	}

	return rtn;
}

int esNumerica(char* cadena)
{
	int rtn = 1;
	int i;

	if(cadena != NULL && strlen(cadena)>0 )
	{
		for(i=0; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i] == '-'))
			{
				continue;
			}
			if( cadena [i] > '9' || cadena [i] < '0')
			{
				rtn = 0;
				break;
			}
		}
	}

	return rtn;
}


int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

int getNombre(char* pResultado, int longitud)
{
	int retorno=-1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(	getString(buffer,sizeof(buffer))==0 &&
				esNombre(buffer, sizeof(buffer)) &&
				strnlen(buffer,sizeof(buffer))<longitud)
		{
			strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
	}
	return retorno;
}

int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
					(cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getString(char* mensaje, char* mensajeError, int reintentos,  int longitud, char* pResultado)
{
	char bufferString[4096];
	int retorno = 0;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&
				strnlen(bufferString,sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 1;
			break;
		}
		printf("%s",mensajeError);
	}
	if(reintentos==0)
	{
		puts("Se ha superado la cantidad maxima de reintentos");
	}
	return retorno;
}

int utn_getStringNumber(char* mensaje, char* mensajeError, int longitud, char *pResultado)
{
	char bufferString[50];
	int retorno = -1;

	if(mensaje !=NULL && mensajeError != NULL && longitud >0 && pResultado != NULL)
	{
		printf("%s", mensaje);
		if(getStringNumber(bufferString,sizeof(bufferString)) == 0  &&	strnlen(bufferString,sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
		}
	}
	return retorno;
}

int getStringNumber(char* pResultado, int longitud)
{
	int retorno=-1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(	getSN(buffer,sizeof(buffer))==0 &&
				esStringNumber(buffer, sizeof(buffer)) &&
				strnlen(buffer,sizeof(buffer))<longitud)
		{
			strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
	}
	return retorno;
}

int getSN(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

int esStringNumber(char* cadena,int longitud)
{
	int retorno = -1;
	int i = 0;

	if(cadena != NULL && cadena > 0)
	{
		for(i=0; cadena[i] !='\0'; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i]  < '0' || cadena[i] > '9'))
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

