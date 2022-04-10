/*
 * menuopciones.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Lio
 */

#include "menuopciones.h"


int MenuOpciones( float x, float y, float z )
{
	int opcion;

	printf("1. Ingresar cantidad de kilometros: (km= %f)\n", x);
	printf("2. Ingresar precio segun aerolinea: (Aerolineas = %.2f, Latam = %.2f)\n", y, z);
	printf("3. Calcular todos los costos.\n");
	printf("4. Informar resultados\n");
	printf("5. Utilizar carga forzada\n");
	printf("6. Salir\n");

	printf("Ingrese una opcion:");
	scanf("%d", &opcion);

    while (opcion < 1|| opcion>6)
    {
        printf("ERROR! Ingrese una opcion entre 1-6:");
        scanf("%d", &opcion);
    }

	return opcion;
}
