/*
 ============================================================================
 Name        : TP_1.c
 Author      : Lionel Mancini
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menuopciones.h"
#include "calculos.h"
#include "solicitarmostrardatos.h"

#define EXIT 6

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	float x;
	float y;
	float z;
	float debitoAerolineas;
	float creditoAerolineas;
	float bitcoinAerolineas;
	float unitarioAerolineas;
	float debitoLATAM;
	float creditoLATAM;
	float bitcoinLATAM;
	float unitarioLATAM;
	float diferenciaPrecio;
	int banderaA;
	int banderaB;
	int banderaResultados;

	banderaA= 0;
	banderaB= 0;
	banderaResultados=0;

	do{

		opcion = MenuOpciones( x, y ,z );

		switch(opcion)
		{
			case 1:
				x = IngresarKMS("Ingrese cantidad de kilometros:");
				banderaA=1;
			break;
			case 2:
				y= IngresarPrecioVuelo("Ingrese precio del vuelo de Aerolineas:");
				z= IngresarPrecioVuelo("Ingrese precio del vuelo de LATAM:");
				banderaB=1;
			break;
			case 3:
				if(banderaA == 0)
				{
					printf("ERROR! Por favor primero ejecute la opci?n de carga de los kilometros\n");
					system("pause");
				}
				else if( banderaB == 0)
				{
					printf("ERROR! Por favor primero ejecute la opci?n de carga de los precios de los vuelos\n");
					system("pause");
				}
				else
				{
					debitoAerolineas = CalculoTarjeta(y);
					creditoAerolineas = CalculoTarjetaC(y);
					bitcoinAerolineas= CalculoBitcoin(y);
					unitarioAerolineas= CalculoUnitario(y,x);
					debitoLATAM= CalculoTarjeta(z);
					creditoLATAM= CalculoTarjetaC(z);
					bitcoinLATAM= CalculoBitcoin(z);
					unitarioLATAM=  CalculoUnitario(z,x);
					diferenciaPrecio = CalculoDiferencia(y,z);
					printf("--------------------------------\n");
				    printf("YA SE REALIZARON LAS OPERACIONES\n");
				    printf("--------------------------------\n");
				    system("pause");
				    banderaResultados=1;
				}
			break;
			case 4:
				if(banderaResultados == 0)
				{
					printf("Por favor, primero calcule las operaciones antes de mostrar los resultados\n");
					system("pause");
				}
				else
				{
					MostrarResultados(x, y, z,debitoAerolineas, creditoAerolineas, bitcoinAerolineas, unitarioAerolineas, debitoLATAM, creditoLATAM, bitcoinLATAM, unitarioLATAM, diferenciaPrecio);
					system("pause");
				}
			break;
			case 5:
					debitoAerolineas = CalculoTarjeta(162965);
					creditoAerolineas = CalculoTarjetaC(162965);
					bitcoinAerolineas= CalculoBitcoin(162965);
					unitarioAerolineas= CalculoUnitario(162965, 7090);
					debitoLATAM= CalculoTarjeta(159339);
					creditoLATAM= CalculoTarjetaC(159339);
					bitcoinLATAM= CalculoBitcoin(159339);
					unitarioLATAM=  CalculoUnitario (159339, 7090);
					diferenciaPrecio = CalculoDiferencia(162965,159339);
					MostrarResultados(7090, 162965, 159339, debitoAerolineas, creditoAerolineas, bitcoinAerolineas, unitarioAerolineas, debitoLATAM, creditoLATAM, bitcoinLATAM, unitarioLATAM, diferenciaPrecio);
					system("pause");
			break;
			case 6:
					printf("-------------------------\n");
					printf("Aqui finalizo el programa\n");
					printf("-------------------------\n");
			break;

		}

	}while(opcion != EXIT);

	return EXIT_SUCCESS;
}
