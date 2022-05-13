/*
 * ArrayPassenger.h
 *
 *  Created on: 3 may. 2022
 *      Author: Lio
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "Bibloteca1.0.h"
#include "FuncionesMenu.h"
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct
{

   int id;
   char name[51];
   char lastName[51];
   float price;
   char flyCode[10];
   int typePassenger;
   int statusFlight;
   int isEmpty;

} ePassenger;


/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array.
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return rtn int (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(ePassenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters in the first empty position.
*
* \param list passenger*: Pointer to array of passenger
* \param len int: array length
* \param id int: automatic brinding id for each passenger
* \param name[] char: name of passenger
* \param lastName[] char: last name of passenger.
* \param price float: fly price
* \param typePassenger int: 1 = First Class | 2 = Ejecutive | 3- Tourist
* \param flycode [] char: code fly
* \return rtn int (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[], int statusFlight);

/** \brief allow the user enter the values of a passenger in an auxiliary to later be added by the addPassenger function
* \param list passenger*: Pointer to array of passenger
* \param len int: array length
* \return rtn int (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int chargePassenger(ePassenger* list,int len);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*: Pointer to array of passenger
* \param len int: array length
* \param id int: automatic brinding id for each passenger
* \return rtn int: passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*
*/
int findPassengerById(ePassenger* list, int len, int id);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1).
*
* \param list Passenger*: Pointer to array of passenger
* \param len int: array length
* \param id int: automatic brinding id for each passenger
* \return rtn int: (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok.
*
*/
int removePassenger(ePassenger* list, int len, int id);

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*: Pointer to array of passenger
* \param len int: array length
* \param order int: [1] indicate UP - [0] indicate DOWN.
* \return rtn int: passenger index position or (-1) if [Invalid length or NULL pointer] - (0) if Ok.
*
*/
int sortPassengers(ePassenger* list, int len, int order);

/** \brief print the content of passengers array
*
* \param list Passenger*: Pointer to array of passenger
* \param len int: array length
* \return rtn int: (-1) if can't show the passengers array - (0) if Ok.
*
*/
int printPassenger(ePassenger* list, int len);

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*: Pointer to array of passenger
* \param len int: array length
* \param order int: [1] indicate UP - [0] indicate DOWN.
* \return rtn int:(-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
*
*/

int sortPassengersByCode (ePassenger* list, int len, int order);

/** \brief The user enters an id number, chooses the same. Within that id it asks you to enter which field you want to modify
*
* \param list Passenger*: Pointer to array of passenger
* \param len int: array length
* \return rtn int:(-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
*
*/
int modifyPassenger(ePassenger* list, int len);

/** \brief
 *
 * \param list Passenger*: Pointer to array of passenger
 * \param len int: array length
 * \return rtn int:(-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 */
int printPricePassenger (ePassenger* list, int len);

/** \brief Calculates the average price of the tickets and then shows the number of passengers with a ticket higher than the average
 *
 * \param list Passenger*: Pointer to array of passenger
 * \param len int: array length
 * \return rtn int:(-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 */
int ePassenger_HarcodeData (ePassenger* list, int len);

#endif /* ARRAYPASSENGER_H_ */
