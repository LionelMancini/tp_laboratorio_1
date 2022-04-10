/*
 * solicitardatos.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Lio
 */

#include "menuopciones.h"

float IngresarKMS (char mensaje[])
{
	float x;

	printf("%s", mensaje);
	scanf("%f", &x);

	while(x <= 0)
	{
		printf("ERROR! Por favor ingrese una distancia valida mayor a 0:");
		scanf("%f", &x);
	}
	return x;
}

float IngresarPrecioVuelo(char mensaje[])
{
	float y;

	printf("%s", mensaje);
	scanf("%f", &y);

	while(y <= 0)
		{
			printf("ERROR! Por favor ingrese un precio valido entre 0 y 10000000:");
			scanf("%f", &y);
		}
	return y;
}

void MostrarResultados(float x,float y,float z, float debitoAerolineas,float creditoAerolineas,float bitcoinAerolineas,float unitarioAerolineas,float debitoLATAM,float creditoLATAM,float bitcoinLATAM,float unitarioLATAM, float diferenciaPrecio)
{
	printf("KMs Ingresados: %.2f km \n", x);
	printf("\n");
	printf("Precio Aerolineas Argentinas: $%.2f \n", y);
	printf("a) Precio con tarjeta de debito: $%.2f \n", debitoAerolineas);
	printf("b) Precio con tarjeta de credito: $%.2f \n", creditoAerolineas);
	printf("c) Precio pagando con bitcoins: %.5f BTC \n", bitcoinAerolineas);
	printf("d) Precio Unitario: $%.2f \n", unitarioAerolineas);
	printf("\n");
	printf("Precio Latam: $%.2f \n",z);
	printf("a) Precio con tarjeta de debito: $%.2f \n", debitoLATAM);
	printf("b) Precio con tarjeta de credito: $%.2f \n", creditoLATAM);
	printf("c) Precio pagando con bitcoins: %.5f BTC \n", bitcoinLATAM);
	printf("d) Precio Unitario: $%.2f \n", unitarioLATAM);
	printf("\n");
	printf("La diferencia de precio es: $%.2f \n", diferenciaPrecio);
	printf("\n");
}

