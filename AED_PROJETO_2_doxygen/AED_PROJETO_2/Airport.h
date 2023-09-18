/**
 * @file Airport.h
 * @author
 * @brief
 * @version 0.1
 * @date 2023-01-08
 *
 * @copyright Copyright (c) 2023
 *
 */


#ifndef AED_PROJETO_2_AIRPORT_H
#define AED_PROJETO_2_AIRPORT_H
#include <string>
using namespace std;

class Airport {

    string code;

    string name;

    string city;

    string country;

    double latitude;

    double longitude;


public:

/**
    * @brief Construct a new Airport object
    * Construtor default
    */
Airport();
    /**
       * @brief Construct a new Airport object
       * Construtor parametrizado
       * @param name
       * @param code
       * @param city
       * @param country
       * @param latitude
       * @param longitude
       */

Airport(string code, string name, string city, string country, double latitude, double longitude);

/**
    * @brief
    * Getter do objeto code
    * @return string
    */
string getCode() const;

/**
    * @brief
    * Getter do objeto name
    * @return string
    */
string getName() const;

/**
    * @brief
    * Getter do objeto city
    * @return string
    */
string getCity() const;

/**
    * @brief
    * Getter do objeto country
    * @return string
    */
string getCountry() const;

/**
    * @brief
    * Getter do objeto latitude
    * @return double
    */
double getLatitude() const;

/**
    * @brief
    * Getter do objeto longitude
    * @return double
    */
double getLongitude() const;

};


#endif //AED_PROJETO_2_AIRPORT_H
