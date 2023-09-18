/**
 * @file Distances.h
 * @author
 * @brief
 * @version 0.1
 * @date 2023-01-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef AED_PROJETO_2_DISTANCES_H
#define AED_PROJETO_2_DISTANCES_H

#include <bits/stdc++.h>
using namespace std;
/**
* @brief
* Função que calcula a distância entre dois pontos
* A complexidade é O(1)
 * @param lat1 Double com a latitude do primeiro ponto
 * @param lon1 Double com a longitude do primeiro ponto
 * @param lat2 Double com a latitude do segundo ponto
 * @param lon2 Double com a longitude do segundo ponto
* @return Double com a distância entre os pontos
*/

double distancia(double lat1, double lon1, double lat2, double lon2);
/**
* @brief
* Função que calcula a distância entre dois pontos
* A complexidade é O(1)
 * @param coord1 Par de doubles com as coordenadas do primeiro ponto
 * @param coord2 Par de doubles com as coordenadas do segundo ponto
* @return Double com a distância entre os pontos
*/

double distancia(pair<double, double> coord1, pair<double, double> coord2);


#endif //AED_PROJETO_2_DISTANCES_H
