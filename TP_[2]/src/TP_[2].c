/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Lionel Mancini
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Bibloteca1.0.h"
#define MAXPASSENGER 2000
#define EXIT 6

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int auxID;
	int auxOrder;
	int opcionMostrar;
	int banderaA=0;
	int banderaB=0;
	ePassenger arrayPassenger[MAXPASSENGER];

	initPassengers(arrayPassenger, MAXPASSENGER);


	do{
		OpcionesMenu();
		if(utn_getNumero("Por favor ingrese que desea hacer:", 2, 1, 6, "Error la opcion ingresada no pertenece al menu. Por favor reingrese que desea hacer: ", &opcion)==0)
		{
			opcion = EXIT;
			printf("-------------------------\n");
			printf("Aqui finalizo el programa\n");
			printf("-------------------------\n");
		}
		else
		{
			switch(opcion)
			{
			case 1:
				if(banderaB==0)
				{
					if(chargePassenger(arrayPassenger, MAXPASSENGER) != -1)
					{
						puts("SE HA DADO DE ALTA EXITOSAMENTE");
						banderaA=1;
						banderaB=1;
					}
					else
					{
						printf("Hubo un error en la ALTA\n");
					}
				}
				else
				{
					puts("No se puede cargar un ALTA si previamente se hardcodeo");
				}
				break;
			case 2:
				if(banderaA == 1)
				{
					if(modifyPassenger(arrayPassenger, MAXPASSENGER) != -1)
					{
						puts("SE HA DADO DE MODIFICADO EL DATO EXITOSAMENTE");
					}
				}
				else
				{
					printf("Por favor primero cargue los pasajeros.\n");
				}
				break;
			case 3:
				if(banderaA == 1)
				{
					printPassenger(arrayPassenger, MAXPASSENGER);
					utn_getNumero("Por favor ingrese el id que desea buscar para dar de baja:", 2, 0, 2000, "ERROR! El id ingresado no es valido! Reingrese nuevamente", &auxID);
					if(removePassenger(arrayPassenger, MAXPASSENGER, auxID) != -1)
					{
						puts("SE HA DADO DE BAJA EL ID EXITOSAMENTE\n");
					}
				}
				else
				{
					printf("Por favor primero cargue los pasajeros.\n");
				}
				break;
			case 4:
				if(banderaA == 1)
				{
					OpcionesMenu3();
					utn_getNumero("Informe como desea ver la lista de pasajeros", 2, 1, 3,"ERROR! Opcion fuera de rango. Reingrese su criterio de ordenamiento:", &opcionMostrar);
					switch(opcionMostrar)
					{
					case 1:
						utn_getNumero("Por favor ingrese si quiere ordenar según tipo ascendente(1) o si desea ordenar de forma descendente(0)", 2,0,1, "ERROR! Opcion fuera de rango. Reingrese nuevamente", &auxOrder);
						sortPassengers(arrayPassenger , MAXPASSENGER , auxOrder);
						break;
					case 2:
						printPricePassenger (arrayPassenger, MAXPASSENGER);
						break;
					case 3:
						utn_getNumero("Por favor ingrese si quiere ordenar según tipo ascendente(1) o si desea ordenar de forma descendente(0)", 2,0,1, "ERROR! Opcion fuera de rango. Reingrese nuevamente", &auxOrder);
						sortPassengersByCode(arrayPassenger , MAXPASSENGER , auxOrder);
						break;
					}
				}
				else
				{
					printf("No hay pasajeros que mostrar.\n");
				}
				break;
			case 5:
				if(banderaB==0)
				{
					if(ePassenger_HarcodeData (arrayPassenger , MAXPASSENGER ) !=-1)
					{
						puts("SE HA HARCODEADO\n");
						banderaA=1;
						banderaB=1;
					}
					else
					{
						printf("Ha habido un error en el Harcodeo\n");
					}
				}
				else
				{
					puts("No se puede hardcodear luego de ingresar un alta o volver a hardcodear!");
				}
				break;
			case 6:
				printf("-------------------------\n");
				printf("Aqui finalizo el programa\n");
				printf("-------------------------\n");
				break;
			}
		}


	}while(opcion != EXIT);

}
