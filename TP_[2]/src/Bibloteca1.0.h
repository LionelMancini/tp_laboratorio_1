/*
 * Libreria1.0.h
 *
 *  Created on: 3 may. 2022
 *      Author: Lio
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef BIBLOTECA1_0_H_
#define BIBLOTECA1_0_H_

//-----------------------------------------------GET FLOAT------------------------------------------------------------//
int utn_getNumeroFlotante (char mensaje[], int reintentos, float minimo, float maximo, char mensajeError[], float* pnumeroIngresado);
int getFloat(float *pnumeroIngresado);
int esFlotante(char* cadena);


//-----------------------------------------------GET NUMERO------------------------------------------------------------//
int utn_getNumero (char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int* pnumeroIngresado );
int getInt(int* pnumeroIngresado);
int myGets(char* cadena, int longitud);
int esNumerica(char* cadena);

//-----------------------------------------------GET STRING------------------------------------------------------------//
int getString(char* cadena, int longitud);
int getNombre(char *pResultado, int longitud);
int esNombre(char* cadena,int longitud);
int utn_getString(char* mensaje, char* mensajeError, int reintentos,  int longitud, char *pResultado);

//----------------------------------------------GET NUMBER / STRING---------------------------------------------------//
int utn_getStringNumber(char* mensaje, char* mensajeError, int longitud, char *pResultado);
int getStringNumber(char* pResultado, int longitud);
int getSN(char* cadena, int longitud);
int esStringNumber(char* cadena,int longitud);

#endif /* BIBLOTECA1_0_H_ */
