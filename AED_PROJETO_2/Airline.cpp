//
// Created by LuisRelvas on 08/01/2023.
//

#include "Airline.h"

Airline::Airline(string code, string name, string callsign, string country) {
    this->code = code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}

string Airline::getCode() const {
    return code;
}

string Airline::getName() const {
    return name;
}

string Airline::getCallSign() const {
    return callsign;
}

string Airline::getCountry() const {
    return country;
}

bool Airline::operator<(const Airline &c1) const {
    return code < c1.code;
}

