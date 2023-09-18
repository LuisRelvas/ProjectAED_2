/**
 * @file Gestor.h
 * @author
 * @brief
 * @version 0.1
 * @date 2023-01-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef AED_PROJETO_2_GESTOR_H
#define AED_PROJETO_2_GESTOR_H

#include "Airport.h"
#include "Airline.h"
#include "Distances.h"
#include "Graph.h"

/**
 * @brief
 * Struct que permite usar pares de doubles como chave de um unordered_map
 * Contém um operador () que permite garantir que os elementos são diferentes
 */
struct hashpair{
    size_t operator()(const pair<double, double> &p) const {
        auto hash1 = hash<double>{}(p.first);
        auto hash2 = hash<double>{}(p.second);
        return hash1 ^ hash2;
    }
};

/**
* @brief
 * Struct que permite usar pares de strings como chave de um unordered_map
*Contém um operador () que permite garantir que os elementos são diferentes
*/
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

    /**
     * @brief
     * Função que lê os aeroportos do ficheiro 'airports.csv'
     * e os guarda no vetor de aeroportos
    *  Complexidade: O(n) onde n é o número de aeroportos
    */
    void Gestor_Airports();
    /** @brief
     * Função que lê as companhias aéreas do
     * ficheiro 'airlines.csv'
     * e as guarda no vetor de companhias aéreas
     * Complexidade: O(n) onde n é o número de companhias aéreas
 */
    void Gestor_Airlines();
    /** @brief Função que lê os voos do ficheiro 'flights.csv' e os guarda no grafo de voos
    * Complexidade: O(n) onde n é o número de voos
    * @param aux Grafo de voos

 */
    void Gestor_Flights(Graph &gh);
    /**
    * @brief
    * Complexidade: O(1)
    * Getter
    * @return unordered_map que associa o código de um aeroporto ao seu índice no vetor de aeroportos
    */
    unordered_map<string, int> getAirports_Codes() const;
    /**
   * @brief
   * Complexidade: O(1)
   * Getter
    * @return unordered_map que associa o índice de um aeroporto ao seu objeto Aeroporto
   */
    unordered_map<int, Airport> getAirports() const;
    /**
  * @brief
  * Complexidade: O(1)
  * Getter
   * @return unordered_map que associa as coordenadas de um aeroporto ao seu índice no vetor de aeroportos
  */
    unordered_map<pair<double, double>, int, hashpair> getAirports_Coords() const;
    /**
   * @brief
   * Complexidade: O(1)
   * Getter
    * @return unordered_map que associa o código de uma companhia aérea ao conjunto de índices dos aeroportos que a mesma serve
   */
    unordered_map<string, unordered_set<int>> getAirports_Airlines() const;
    /**
   * @brief
   * Complexidade: O(1)
   * Getter
    * @return unordered_map que associa o par de códigos de aeroportos de partida e chegada a um código de companhia aérea
   */
    unordered_map<pair<string, string>, string, hashpair_s> getArrival_Departure_Airline() const;
    /**
   * @brief
   * Complexidade: O(1)
   * Getter
 * @return unordered_map que associa o código de uma companhia aérea ao seu índice no vetor de companhias aéreas
   */
    unordered_map<string, int> getAirlines_Codes() const;
    /**
   * @brief
   * Complexidade: O(1)
   * Getter
    * @return unordered_map que associa o índice de uma companhia aérea ao seu objeto Companhia
   */
    unordered_map<int, Airline> getAirlines() const;
    /**
      * @brief
      * Complexidade: O(1)
      * Getter
    * @return unordered_map que associa o nome de uma cidade ao vetor de índices dos aeroportos dessa cidade
      */

    unordered_map<string, vector<int>> getCities_Airports() const;
    /**
      * @brief
      * Complexidade: O(1)
      * Getter
       * @return unordered_map que associa o nome de um país ao vetor de índices dos aeroportos desse país
      */
    unordered_map<string, vector<int>> getCountries_Airports() const;
    /**
    * @brief
            * Complexidade: O(1)
                            * Getter
                            * @return unordered_map que associa o código de uma companhia aérea ao vetor de índices dos aeroportos que a mesma serve
    */
    unordered_map<string, vector<int>> getAirlines_Airports() const;
    /**
      * @brief
      * Complexidade: O(1)
      * Getter
    * @return unordered_map que associa o nome de um país ao conjunto de nomes das cidades desse país
      */
    unordered_map<string, unordered_set<string>> getCountry_Cities() const;
    /**
      * @brief
      * Complexidade: O(1)
      * Getter
        * @return unordered_map que associa o índice de um aeroporto ao par de nomes do país e da cidade desse aeroporto
      */
    unordered_map<int, pair<string,string>> getId_Country_City() const;
    /**
      * @brief
      * Complexidade: O(1)
      * Getter
    * @return unordered_map que associa o par de nomes do país e da cidade de um aeroporto ao vetor de índices dos aeroportos dessa cidade desse país
      */
    unordered_map<pair<string,string>, vector<int>, hashpair_s> getCountry_City_Airports() const;

};


#endif //AED_PROJETO_2_GESTOR_H
