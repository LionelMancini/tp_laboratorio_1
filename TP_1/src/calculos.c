/*
 * calculos.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Lio
 */
#include "calculos.h"
#define BITCOIN 4606954.55

float CalculoTarjeta(float precio)
{
	float descuento;

	descuento = precio * 0.1;
	precio = precio - descuento;

	return precio;
}

float CalculoTarjetaC(float precio)
{
	float resultado;
	resultado = precio * 1.25;

	return resultado;
}

float CalculoBitcoin(float precio)
{
	float precioBitcoin;
	precioBitcoin = precio / BITCOIN;

	return precioBitcoin;
}


float CalculoUnitario(float precio, float x)
{
	float precioKM;

	precioKM = precio / x;

	return precioKM;
}

float CalculoDiferencia(float y, float z)
{
	float diferencia;

	if(z>y)
	{
		diferencia = z - y;
	}
	else if( z < y)
	{
		diferencia = y - z;
	}
	else
	{
		diferencia = 0;
	}


	return diferencia;
}
