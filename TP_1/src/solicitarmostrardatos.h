/*
 * solicitardatos.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Lio
 */

#ifndef SOLICITARMOSTRARDATOS_H_
#define SOLICITARMOSTRARDATOS_H_


float IngresarKMS (char mensaje[]);
/// @fn float IngresarKMS(char[])
/// @brief Se utiliza para ingresar los KMS de distancia.
/// @param mensaje Se solicita para pedir la distancia.
/// @return Retorna la distancia solicitada.

float IngresarPrecioVuelo(char mensaje[]);
/// @fn IngresarPrecioVuelo(char mensaje[])
/// @brief Se utiliza para ingresar el precio del vuelo;
/// @param mensaje Se solicita para que el usuario ingrese el precio.
/// @return Retorna el precio ingresado.

void MostrarResultados(float x,float y,float z,float debitoAerolineas,float creditoAerolineas,float bitcoinAerolineas,float unitarioAerolineas,float debitoLATAM,float creditoLATAM,float bitcoinLATAM,float unitarioLATAM, float diferenciaPrecio);
/// @fn
/// @brief
/// @param

#endif /* SOLICITARMOSTRARDATOS_H_ */
