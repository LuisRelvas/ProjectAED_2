/**
 * @file Airline.h
 * @author
 * @brief
 * @version 0.1
 * @date 2023-01-08
 *
 * @copyright Copyright (c) 2023
 *
 */


#ifndef AED_PROJETO_2_AIRLINE_H
#define AED_PROJETO_2_AIRLINE_H
#include <bits/stdc++.h>
using namespace std;

class Airline {
    string code;

    string name;

    string callsign;

    string country;

public:

    /**
* @brief
* Construtor parametrizado
* @param code
* @param name
* @param callsign
* @param country
*/
    Airline(string code, string name, string callsign, string country);
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
   * Getter do objeto callsign
   * @return string
   */
    string getCallSign() const;
    /**
   * @brief
   * Getter do objeto country
   * @return country
   */
    string getCountry() const;
    /**
    * @brief
    * Operator Overload para comparar objetos do tipo Companhia.
    * A complexidade é O(1)
    * @param arl
    * @return true
    * @return false
    */
    bool operator<(const Airline &air) const;

};


#endif //AED_PROJETO_2_AIRLINE_H
