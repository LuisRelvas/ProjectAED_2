/**
 * @file Distances.cpp
 * @author
 * @brief
 * @version 0.1
 * @date 2023-01-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "Distances.h"

double distancia(double lat1, double lon1, double lat2, double lon2) {

    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);

    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

double distancia(pair<double, double> coord1, pair<double, double> coord2) {

    double dLat = (coord2.first - coord1.first) * M_PI / 180.0;
    double dLon = (coord2.second - coord1.second) * M_PI / 180.0;

    coord1.first = (coord1.first) * M_PI / 180.0;
    coord2.first = (coord2.first) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(coord1.first) * cos(coord2.first);

    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}