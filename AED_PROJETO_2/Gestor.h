//
// Created by LuisRelvas on 08/01/2023.
//

#ifndef AED_PROJETO_2_GESTOR_H
#define AED_PROJETO_2_GESTOR_H

#include "Airport.h"
#include "Airline.h"
#include "Distances.h"
#include "Graph.h"


struct hashpair{
    size_t operator()(const pair<double, double> &p) const {
        auto hash1 = hash<double>{}(p.first);
        auto hash2 = hash<double>{}(p.second);
        return hash1 ^ hash2;
    }
};


struct hashpair_s{
    size_t operator()(const pair<string, string> &p) const {
        auto hash1 = hash<string>{}(p.first);
        auto hash2 = hash<string>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Gestor {
    unordered_map<string, int> Airports_Codes;

    unordered_map<int, Airport> Airports;

    unordered_map<pair<double, double>, int, hashpair> Airports_Coords;

    unordered_map<string, unordered_set<int>> Airports_Airlines;

    unordered_map<pair<string, string>, string, hashpair_s> Arrival_Departure_Airline;

    unordered_map<string, int> Airlines_Codes;

    unordered_map<int, Airline> Airlines;

    unordered_map<string, vector<int>> Cities_Airports;

    unordered_map<string, vector<int>> Countries_Airports;

    unordered_map<string, vector<int>> Airlines_Airports;

    unordered_map<string, unordered_set<string>> Country_Cities;

    unordered_map<int, pair<string,string>> Id_Country_City;

    unordered_map<pair<string,string>, vector<int>, hashpair_s> Country_City_Airports;

public:


    void Gestor_Airports();

    void Gestor_Airlines();

    void Gestor_Flights(Graph &gh);

    unordered_map<string, int> getAirports_Codes() const;

    unordered_map<int, Airport> getAirports() const;

    unordered_map<pair<double, double>, int, hashpair> getAirports_Coords() const;

    unordered_map<string, unordered_set<int>> getAirports_Airlines() const;

    unordered_map<pair<string, string>, string, hashpair_s> getArrival_Departure_Airline() const;

    unordered_map<string, int> getAirlines_Codes() const;

    unordered_map<int, Airline> getAirlines() const;

    unordered_map<string, vector<int>> getCities_Airports() const;

    unordered_map<string, vector<int>> getCountries_Airports() const;

    unordered_map<string, vector<int>> getAirlines_Airports() const;

    unordered_map<string, unordered_set<string>> getCountry_Cities() const;

    unordered_map<int, pair<string,string>> getId_Country_City() const;

    unordered_map<pair<string,string>, vector<int>, hashpair_s> getCountry_City_Airports() const;

};


#endif //AED_PROJETO_2_GESTOR_H
