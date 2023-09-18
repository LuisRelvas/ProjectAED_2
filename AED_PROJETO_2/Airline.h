//
// Created by LuisRelvas on 08/01/2023.
//

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


    Airline(string code, string name, string callsign, string country);

    string getCode() const;

    string getName() const;

    string getCallSign() const;

    string getCountry() const;

    bool operator<(const Airline &air) const;

};


#endif //AED_PROJETO_2_AIRLINE_H
