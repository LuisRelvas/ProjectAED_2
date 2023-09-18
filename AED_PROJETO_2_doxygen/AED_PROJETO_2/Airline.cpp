/**
 * @file Airline.cpp
 * @author
 * @brief
 * @version 0.1
 * @date 2023-01-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <string>
#include "Airline.h"

/**
 * @brief Construir um novo Airline :: Airline object
 * Construtor parametrizado
 * @param code
 * @param name
 * @param callsign
 * @param country
*/

Airline::Airline(string code, string name, string callsign, string country) {
    this->code = code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}

/**
 * @brief
 * Getter do objeto code
 * @return string
 */

string Airline::getCode() const {
    return code;
}
/**
 * @brief
 * Getter do objeto name
 * @return string
 */

string Airline::getName() const {
    return name;
}
/**
 * @brief
 * Getter do objeto callsign
 * @return string
 */
string Airline::getCallSign() const {
    return callsign;
}
/**
 * @brief
 * Getter do objeto country
 * @return string
 */
string Airline::getCountry() const {
    return country;
}
/**
 * @brief
 * Operator overloader
 * @param helper
 * @return true
 * @return false
 */
bool Airline::operator<(const Airline &c1) const {
    return code < c1.code;
}

