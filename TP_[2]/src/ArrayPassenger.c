/*
 * listPassenger.c
 *
 *  Created on: 3 may. 2022
 *      Author: Lio
 */

#include "ArrayPassenger.h"
static int ePassenger_GiveID(void);
static void ePassenger_ShowOne(ePassenger Passenger);
static int ePassenger_FreeIndex(ePassenger* list, int len);
static float ePassenger_CalculateCosts (ePassenger* list, int len);
static int ePassenger_Counter(ePassenger* list, int len);
static int ePassenger_AverageCost(float totalPasajes,int totalPasajeros);
static int ePassenger_MoreAvgCost(ePassenger* list, int len,float promedio);


static int ePassenger_GiveID(void) {
	static int Passenger_idIncremental = 0;
	return Passenger_idIncremental++;
}

int initPassengers(ePassenger* list, int len)
{
	int rtn = -1;
	int i;

	if(list != NULL && len>0)
	{
		for(i = 0; i<len ; i++ )
		{
			list[i].isEmpty = LIBRE;
		}
		rtn = 0;
	}

	return rtn;
}

static int ePassenger_FreeIndex(ePassenger* list, int len)
{
	int rtn = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}


int findPassengerbyId(ePassenger* list, int len, int id){
	int rtn = -1;
	int i;

	//SI EXISTE EL list Y EL LIMITE ES VALidO
	if (list != NULL && len > 0) {
		//RECORRO TODO EL list
		for (i = 0; i < len; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCidA EL id QUE ESTOY BUSCANDO
			if (list[i].id == id && list[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL id
				//DEVUELVO EL INDEX DE DONDE ESTA EL id BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

static void ePassenger_ShowOne(ePassenger Passenger) {

	printf("|  ID:%2d  |  NAME:%-10s | LASTNAME:%-10s | PRICE:%-10.2f | FLYCODE: %-7s  | TYPE: %1d | STATUS:%1d | \n", Passenger.id, Passenger.name, Passenger.lastName, Passenger.price, Passenger.flyCode, Passenger.typePassenger, Passenger.statusFlight);

}

int printPassenger(ePassenger* list, int len) {
	int i;
	int rtn = -1;
	int cantidad = 0;

	//SI EXISTE EL list Y EL LIMITE ES VALidO
	if (list != NULL && len > 0) {
		//RECORRO TODO EL list
		printf("\nPASAJEROS\n");
		for (i = 0; i < len; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (list[i].isEmpty == OCUPADO ) {;
			//MUESTRO UN SOLO Passenger
			ePassenger_ShowOne(list[i]);
			//CONTADOR DE Passenger
			cantidad++;
			}
		}
	}

	//SI CANTidAD == 0 - NO HUBO Passenger PARA MOSTRAR (list SIN ALTAS)
	if (cantidad > 0) {
		rtn = 0;
	}

	return rtn;
}

int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[], int statusFlight)
{
	int rtn = -1;
	ePassenger Passenger;

	int index = ePassenger_FreeIndex(list, len);

	if(list != NULL && len > 0 && id >= 0 && name != NULL && lastName != NULL && price > 0 && typePassenger > 0 && flyCode != NULL && statusFlight > 0){
		//COPIA ID DEL AUX AL PASAJERO NUEVO
		Passenger.id = id;
		//COPIA NOMBRE DEL AUX AL PASAJERO NUEVO
		strcpy(Passenger.name, name);
		//COPIA APELLIDO DEL AUX AL PASAJERO NUEVO
		strcpy(Passenger.lastName, lastName);
		//COPIA PRECIO DEL AUX AL PASAJERO NUEVO
		Passenger.price = price;
		//COPIA TIPO DEL AUX AL PASAJERO NUEVO
		Passenger.typePassenger = typePassenger;
		//COPIA CODIGO DE VUELO DEL AUX AL PASAJERO NUEVO
		strcpy(Passenger.flyCode, flyCode);
		//COPIA ESTADO DE VUELO DEL AUX AL PASAJERO NUEVO
		Passenger.statusFlight = statusFlight;
		//CAMBIO SU ESTADO A "OCUPADO"
		Passenger.isEmpty = OCUPADO;
		//SETEO EL list CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		list[index] = Passenger;
		//RETORNO 0 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 0;
	}

	return rtn;
}

int chargePassenger(ePassenger* list,int len)
{
	int rtn = -1;
	ePassenger auxPassenger;

	if (list != NULL && len > 0) {

		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxPassenger.id = ePassenger_GiveID();
		//PIDO AL USUARIO QUE INGRESE SUS DATOS
		if(utn_getString("\nIngrese nombre del pasajero:", "ERROR, el nombre ingresado no es valido.", 2,51, auxPassenger.name)!=0)
		{

			if(utn_getString("\nIngrese apellido del pasajero:", "ERROR, el apellido ingresado no es valido", 2, 51, auxPassenger.lastName)!=0)
			{
				if(utn_getNumeroFlotante ("\nIngrese el precio del pasaje (25000-500000):", 2, 25000, 500000, "ERROR, el monto ingresado no es valido. Por favor reingrese el monto (25000-500000).", &auxPassenger.price)!=0)
				{
					if(utn_getNumero("\nTipo de pasaje (1- Primera Clase | 2- Ejecutivo | 3- Turista):", 2, 1,3, "ERROR por favor reingrese su tipo de pasaje", &auxPassenger.typePassenger) !=0)
					{
						if(utn_getStringNumber("\nPor favor ingrese el codigo de vuelo:", "\nERROR en el codigo de vuelo. Por favor reingrese el codigo de vuelo:", 10, auxPassenger.flyCode)!=0)
						{
							if(utn_getNumero("\nEstado de vuelo (1-ACTIVO | 2- DEMORADO | 3- CANCELADO | 4- REPROGRAMADO):", 2, 1, 4, "ERROR el numero ingresado no corresponde a un pasaje", &auxPassenger.statusFlight)!=0)
							{
								// LLAMO A LA FUNCION PARA CARGAR EL PASAJERO NUEVO
								addPassenger(list, len, auxPassenger.id, auxPassenger.name, auxPassenger.lastName, auxPassenger.price, auxPassenger.typePassenger,auxPassenger.flyCode, auxPassenger.statusFlight);
								rtn = 0;
							}
						}
					}
				}
			}
		}


	}

	return rtn;
}

int removePassenger(ePassenger* list, int len, int id){
	int rtn = -1;
	int index;
	int flag = 0;

	if(list != NULL && len > 0)
	{
		//LISTO TODOS LOS Passenger
		if (printPassenger(list, len)!= -1){
			//BANDERA EN 1 SI HAY Passenger DADOS DE ALTA PARA LISTAR
			flag = 1;
		}
		//SI HAY Passenger PARA DAR DE BAJA
		if (flag) {
			//OBTENGO INDEX DEL list DE Passenger A DAR DE BAJA
			index = findPassengerbyId(list, len, id);

			//VALIDO QUE EL ID EXISTA Y ESTE OCUPADO
			if(index >= 0 && index < len && list[index].isEmpty == OCUPADO)
			{
				list[index].isEmpty = BAJA;
				//RETORNO 0 SI SE DIO DE BAJA CORRECTAMENTE
				rtn = 0;
			}
			else
			{
				puts("Se ha cancelado la operacion");
			}
		}
	}


	return rtn;
}

int modifyPassenger(ePassenger* list, int len) {
	int rtn = -1;
	int idPassenger;
	int index;
	int opcion;
	int flag = 0;

	if(list != NULL && len > 0 )
	{
		//LISTO TODOS LOS Passenger
		if (printPassenger(list, len) != -1) {
			//BANDERA EN 1 SI HAY Passenger DADOS DE ALTA PARA LISTAR
			flag = 1;
		}

		//SI HAY Passenger PARA MODIFICAR
		if (flag) {
			//PidO id A MODIFICAR
			utn_getNumero("Por favor ingrese el ID a modificar", 2, 0, 2000, "ERROR! El id ingresado no esta en el sistema", &idPassenger );
		}

		//OBTENGO INDEX DEL list DE Passenger A MODIFICAR
		index = findPassengerbyId(list, len, idPassenger);

		//VALIDO QUE EL ID EXISTA Y ESTE OCUPADO
		if(index >= 0 && index < len && list[index].isEmpty == OCUPADO)
		{
			//MENSAJE DE CONFIRMACION
			/*if(ValidateSN("Desea ejecutar la opcion de moficar este id en el sistema? Presione 's' en caso afirmativo o 'n' en caso contrario") != -1)
			{*/
			ePassenger_ShowOne(list[index]);

			OpcionesMenu2();
			if(utn_getNumero ("Por favor ingrese campo a modificar: ", 2, 1, 7, "ERROR! Reingrese el campo a modificar:", &opcion)!=0)
			{
				switch(opcion)
				{
				case 1:
					utn_getString("Ingrese nombre del pasajero:", "ERROR, el nombre ingresado no es valido.", 2,51, list[index].name);
					break;
				case 2:
					utn_getString("Ingrese apellido del pasajero:", "ERROR, el apellido ingresado no es valido.", 2,51, list[index].lastName);
					break;
				case 3:
					utn_getNumeroFlotante ("Ingrese el precio del pasaje:", 2, 25000, 500000, "ERROR, el monto ingresado no es valido.", &list[index].price);
					break;
				case 4:
					utn_getNumero("Tipo de pasaje (1- Primera Clase | 2- Ejecutivo | 3- Turista):", 2, 1,3, "ERROR, por favor reingrese su tipo de pasaje.", &list[index].typePassenger);
					break;
				case 5:
					utn_getStringNumber("Por favor ingrese el codigo de vuelo:", "Error en el codigo de vuelo", 10, list[index].flyCode);
					break;
				case 6:
					utn_getNumero("Estado de vuelo (1-ACTIVO | 2- DEMORADO | 3- CANCELADO | 4- REPROGRAMADO)", 2, 1, 4, "ERROR el numero ingresado no corresponde a un pasaje.", &list[index].statusFlight);
					break;
				case 7:
					puts("Salio con exito");
				}
				rtn = 0;
			}
		}
	}
	return rtn;
}
int sortPassengers(ePassenger* list, int len, int order){
	int rtn;
	int i;
	int j;
	ePassenger aux;

	/*
	    CASE 1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE 0 -> MAYOR A MENOR (DESCENDENTE)
	 */

	//SI EXISTE EL list Y EL LIMITE ES VALIDO
	if (list != NULL && len > 0) {
		switch (order) {
		case 1:
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (strcmp(list[i].lastName,list[j].lastName) >0) {
							//INTERCAMBIO POSICIONES EN list
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
						// EN CASO DE SER IGUALES LAS COMPARA SEGUN EL TIPO DE PASAJE
						else if(strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].typePassenger > list[j].typePassenger){
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}

					}
				}
			}
			rtn = 0;
			printPassenger(list, len);
			break;
		case 0:
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if  (strcmp(list[i].lastName,list[j].lastName) < 0) {
							//INTERCAMBIO POSICIONES EN list
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
						// EN CASO DE SER IGUALES LAS COMPARA SEGUN EL TIPO DE PASAJE
						else if(strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].typePassenger < list[j].typePassenger){
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			rtn = 0;
			printPassenger(list, len);
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = -1;
			break;
		}
	}
	return rtn;
}

int sortPassengersByCode (ePassenger* list, int len, int order)
{
	int rtn=-1;
	int i;
	int j;
	ePassenger aux;

	/*
	    CASE 1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE 0 -> MAYOR A MENOR (DESCENDENTE)
	 */

	//SI EXISTE EL list Y EL LIMITE ES VALIDO
	if (list != NULL && len > 0) {
		switch (order) {
		case 1:
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (strcmp(list[i].flyCode,list[j].flyCode) >0) {
							//INTERCAMBIO POSICIONES EN list
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
						else if(strcmp(list[i].flyCode,list[j].flyCode) == 0 && list[i].statusFlight >= list[j].statusFlight){
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}

					}
				}
			}
			rtn = 0;
			printPassenger(list, len);
			break;
		case 0:
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if  (strcmp(list[i].flyCode,list[j].flyCode) < 0) {
							//INTERCAMBIO POSICIONES EN list
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
						else if(strcmp(list[i].flyCode,list[j].flyCode) == 0 && list[i].statusFlight < list[j].statusFlight){
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			rtn = 0;
			printPassenger(list, len);
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = -1;
			break;
		}
	}
	return rtn;
}

int printPricePassenger (ePassenger* list, int len)
{
	int rtn = -1;
	float totalPasajes;
	int totalPasajeros;
	int mayorAlPromedio;
	float promedio;

	if(list != NULL && len > 0)
	{
		//CALCULO EL PRECIO TOTAL DE LOS PASAJES
		totalPasajes= ePassenger_CalculateCosts(list,len);
		//CUENTO EL TOTAL DE PASAJEROS;
		totalPasajeros=ePassenger_Counter(list,len);
		//CALCULO EL PROMEDIO DE PRECIO DE LOS PASAJES
		promedio = ePassenger_AverageCost(totalPasajes, totalPasajeros);
		printf("El promedio de precio por pasaje es: %.2f\n", promedio);
		//CALCULO EL TOTAL DE PASAJEROS CON PASAJES MAYOR AL PROMEDIO
		mayorAlPromedio= ePassenger_MoreAvgCost(list, len, promedio);
		printf("La cantidad de pasajeros con pasajes mayor al promedio es: %d\n", mayorAlPromedio);
		rtn = 0;
	}

	return rtn;
}

int ePassenger_HarcodeData (ePassenger* list, int len)
{
	int rtn = -1;

	if(addPassenger(list , len,1,"Abercio","Mansinelli",100000.20,1,"RYR6375",1)==0)
	{
		if(addPassenger(list , len,2,"Adonai","Eufrathes", 120000.32,3,"LGL7585",2)==0)
		{
			if(addPassenger(list , len,3,"Faustino","Molinari", 190000.55,2,"RYR2917",3)==0)
			{
				if(addPassenger(list , len,4,"Jan", "Fernandez", 350000.00,1,"EZY1065",1)==0)
				{
					if(addPassenger(list , len,5,"Janet", "Dokwon", 72932.03,2,"AR9029",4)==0)
					{
						rtn = 0;
					}
				}
			}
		}
	}

	return rtn;
}

static float ePassenger_CalculateCosts (ePassenger* list, int len)
{
	int acumuladorPasajes;
	int i;

	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].price > 0)
			{
				acumuladorPasajes += list[i].price;
			}
		}
	}

	return acumuladorPasajes;
}

static int ePassenger_Counter(ePassenger* list, int len)
{
	float acumuladorPasajeros;
	int i;

	if(list != NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].price > 0)
			{
				acumuladorPasajeros ++;
			}
		}
	}

	return acumuladorPasajeros;
}

static int ePassenger_AverageCost(float totalPasajes,int totalPasajeros)
{
	int promedioPasaje;

	if(totalPasajes>0 && totalPasajeros>0)
	{
		promedioPasaje = totalPasajes / totalPasajeros;
	}
	return promedioPasaje;
}

static int ePassenger_MoreAvgCost(ePassenger* list, int len,float promedio)
{
	int mayorAlPromedio=0;
	int i;

	if(list != NULL && len > 0 && promedio>0)
	{
		for(i=0; i<len;i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].price > promedio)
			{
				mayorAlPromedio++;
			}
		}
	}

	return mayorAlPromedio;

}

void OpcionesMenu(){
	printf("\n-----MENU AEROLINEA-----");
	printf("\n 1. ALTA DE PASAJEROS    ");
	printf("\n 2. MODIFICAR PASAJERO ");
	printf("\n 3. ELIMINAR PASAJEROS ");
	printf("\n 4. INFORMES PASAJEROS ");
	printf("\n 5. HARDCODEO PASAJEROS");
	printf("\n 6. SALIR DEL MENU     \n");

}

void OpcionesMenu2(){
	printf("\n--ELIJA DATO A MODIFICAR:--\n");
	printf("\n 1. NOMBRE DEL PASAJERO    \n");
	printf("\n 2. APELLIDO DEL PASAJERO  \n");
	printf("\n 3. PRECIO DEL VUELO       \n");
	printf("\n 4. TIPO DE PASAJE         \n");
	printf("\n 5. CODIGO DE VUELO        \n");
	printf("\n 6. ESTADO DEL VUELO       \n");
	printf("\n 7. SALIR DEL MENU         \n");
}

void OpcionesMenu3(){
	printf("\n-------------------------------INFORMAR---------------------------------\n");
	printf("\n 1. LISTADO DE PASAJEROS ORDENADOS ALFABETICAMENTE POR APELLIDO Y TIPO  \n");
	printf("\n 2. TOTAL Y PROMEDIO DE PASAJES Y CUANTOS PASAJEROS SUPERAN EL PROMEDIO \n");
	printf("\n 3. LISTADO DE PASAJEROS CON CODIGO DE VUELO Y ESTADO ACTIVO            \n");
}
