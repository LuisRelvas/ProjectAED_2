//
// Created by LuisRelvas on 08/01/2023.
//

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

Airport();


Airport(string code, string name, string city, string country, double latitude, double longitude);


string getCode() const;


string getName() const;


string getCity() const;


string getCountry() const;


double getLatitude() const;


double getLongitude() const;

};


#endif //AED_PROJETO_2_AIRPORT_H
