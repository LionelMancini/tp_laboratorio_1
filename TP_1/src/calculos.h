/*
 * calculos.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Lio
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

float CalculoTarjeta(float);
/// @fn  CalculoTarjeta(float)
/// @brief Se encarga de calcular el costo de la tarjeta de débito con un 10% de descuento.
/// @param Envia el precio del pasaje
/// @return

float CalculoTarjetaC(float);
/// @fn  CalculoTarjeta(float)
/// @brief  Se encarga de calcular el costo de la tarjeta de credito con un recargo del 25%.
/// @param
/// @return

float CalculoBitcoin(float);
/// @fn  CalculoBitcoin(float, float)
/// @brief Se encarga de calcular el precio en Bitcoin (BTC).
/// @param x
/// @return

float CalculoUnitario(float, float);
/// @fn  CalculoUnitario(float, float)
/// @brief
/// @param x
/// @return

float CalculoDiferencia(float, float);
/// @fn  CalculoUnitario(float, float)
/// @brief
/// @param x
/// @return
#endif /* CALCULOS_H_ */
