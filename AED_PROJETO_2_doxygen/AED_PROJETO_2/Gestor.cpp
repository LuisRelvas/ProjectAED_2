/**
 * @file Gestor.cpp
 * @author
 * @brief
 * @version 0.1
 * @date 2023-01-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Gestor.h"
#include <bits/stdc++.h>

using namespace std;

void Gestor::Gestor_Airports() {

    ifstream airport_file("../data/airports.csv");

    string line;
    int i = 1;
    getline(airport_file, line);
    while (getline(airport_file, line)) {
        istringstream ss(line);
        string code, name ,city,country;
        double latitude, longitude;
        getline(ss, code, ',');
        getline(ss, name, ',');
        getline(ss, city, ',');
        getline(ss, country, ',');
        ss >> latitude;
        ss.ignore();
        ss >> longitude;


        Airport airport(code, name, city, country, latitude, longitude);

        Airports_Codes.insert({code, i});
        Airports.insert({i, airport});
        Airports_Coords.insert({{latitude, longitude}, i});

        transform(city.begin(), city.end(), city.begin(), ::toupper);
        transform(country.begin(), country.end(), country.begin(), ::toupper);

        pair<string,string> country_city = make_pair(country,city);
        Id_Country_City.insert({i, country_city});

        if(Country_City_Airports.find(country_city) == Country_City_Airports.end()){
            vector<int> air_city;
            air_city.push_back(i);
            Country_City_Airports.insert({country_city, air_city});
        }
        else{
            Country_City_Airports.at(country_city).push_back(i);
        }


        if (Cities_Airports.find(city) == Cities_Airports.end()) {
            vector<int> aeroportos_cidade;
            aeroportos_cidade.push_back(i);
            Cities_Airports.insert({city, aeroportos_cidade});
        } else {
            Cities_Airports.at(city).push_back(i);
        }

        if (Countries_Airports.find(country) == Countries_Airports.end()) {
            vector<int> airports_country;
            airports_country.push_back(i);
            Countries_Airports.insert({country, airports_country});
        } else {
            Countries_Airports.at(country).push_back(i);
        }

        if (Country_Cities.find(country) == Country_Cities.end()) {
            unordered_set<string> cities_country;
            cities_country.insert(city);
            Country_Cities.insert({country, cities_country});
        } else {
            Country_Cities.at(country).insert(city);
        }

        i++;
    }
}


void Gestor::Gestor_Airlines() {

    ifstream airline_f("../data/airlines.csv");

    string line;
    int i = 1;
    getline(airline_f, line);
    while (getline(airline_f, line)) {
        istringstream iss(line);
        string code, name, callsign, country;
        getline(iss, code, ',');
        getline(iss, name, ',');
        getline(iss, callsign, ',');
        getline(iss, country);

        Airline airline(code, name, callsign, country);

        Airlines_Codes.insert({code, i});
        Airlines.insert({i, airline});

        i++;
    }
}


void Gestor::Gestor_Flights(Graph &g) {

    ifstream flights_f("../data/flights.csv");

    string line;
    getline(flights_f, line);
    while (getline(flights_f, line)) {
        istringstream ss(line);
        string code_airport_from, code_airport_to, code_airline;

        getline(ss, code_airport_from, ',');
        getline(ss, code_airport_to, ',');
        getline(ss, code_airline);

        Airport aeroporto_origem = Airports.at(Airports_Codes.at(code_airport_from));
        Airport aeroporto_destino = Airports.at(Airports_Codes.at(code_airport_to));

        int dist = (int) distancia(aeroporto_origem.getLatitude(), aeroporto_origem.getLongitude(),
                                   aeroporto_destino.getLatitude(), aeroporto_destino.getLongitude());

        g.addEdge(Airports_Codes.at(code_airport_from), Airports_Codes.at(code_airport_to),
                   code_airline, dist);

        if (Airlines_Airports.find(code_airline) == Airlines_Airports.end()) {
            vector<int> airports_airline;
            airports_airline.push_back(Airports_Codes.at(code_airport_from));
            Airlines_Airports.insert({code_airline, airports_airline});
        }
        else {
            Airlines_Airports.at(code_airline).push_back(Airports_Codes.at(code_airport_from));
        }

        if(Airports_Airlines.find(code_airport_from) == Airports_Airlines.end()){
            unordered_set<int> airlines_airport;
            airlines_airport.insert(Airlines_Codes.at(code_airline));
            Airports_Airlines.insert({code_airport_from, airlines_airport});
        }
        else{
            Airports_Airlines.at(code_airport_from).insert(Airlines_Codes.at(code_airline));
        }

        Arrival_Departure_Airline.insert({make_pair(code_airport_from, code_airport_to), code_airline});

    }
}



unordered_map<string, int> Gestor::getAirports_Codes() const {
    return Airports_Codes;
}

unordered_map<int, Airport> Gestor::getAirports() const {
    return Airports;
}

unordered_map<pair<double, double>, int, hashpair> Gestor::getAirports_Coords() const {
    return Airports_Coords;
}

unordered_map<string, int> Gestor::getAirlines_Codes() const {
    return Airlines_Codes;
}

unordered_map<int, Airline> Gestor::getAirlines() const {
    return Airlines;
}

unordered_map<string, vector<int>> Gestor::getCities_Airports() const {
    return Cities_Airports;
}

unordered_map<string, vector<int>> Gestor::getCountries_Airports() const {
    return Countries_Airports;
}

unordered_map<string, vector<int>> Gestor::getAirlines_Airports() const {
    return Airlines_Airports;
}

unordered_map<string, unordered_set<string>> Gestor::getCountry_Cities() const {
    return Country_Cities;
}

unordered_map<string, unordered_set<int>> Gestor::getAirports_Airlines() const {
    return Airports_Airlines;
}

unordered_map<int, pair<string, string>> Gestor::getId_Country_City() const {
    return Id_Country_City;
}

unordered_map<pair<string, string>, vector<int>, hashpair_s> Gestor::getCountry_City_Airports() const {
    return Country_City_Airports;
}

unordered_map<pair<string, string>, string, hashpair_s> Gestor::getArrival_Departure_Airline() const {
    return Arrival_Departure_Airline;
}
