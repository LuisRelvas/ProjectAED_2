/**
 * @file Airport.cpp
 * @author
 * @brief
 * @version 0.1
 * @date 2023-01-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "Airport.h"
/**
 * @brief Construir um novo Airport :: Airport object
 * Construtor parametrizado
 * @param name
 * @param code
 * @param city
 * @param country
 * @param latitude
 * @param longitude
*/
Airport::Airport(string code, string name, string city, string country, double latitude, double longitude) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}
/**
 * @brief
 * Getter do objeto code
 * @return string
 */
string Airport::getCode() const {
    return code;
}
/**
 * @brief
 * Getter do objeto name
 * @return string
 */
string Airport::getName() const {
    return name;
}
/**
 * @brief
 * Getter do objeto city
 * @return string
 */
string Airport::getCity() const {
    return city;
}
/**
 * @brief
 * Getter do objeto country
 * @return string
 */
string Airport::getCountry() const {
    return country;
}
/**
 * @brief
 * Getter do objeto latitude
 * @return double
 */
double Airport::getLatitude() const {
    return latitude;
}
/**
 * @brief
 * Getter do objeto longitude
 * @return double
 */
double Airport::getLongitude() const {
    return longitude;
}
/**
 * @brief Construir um novo Airport:: Airport object
 * Construtor default
 */
Airport::Airport() {

}
