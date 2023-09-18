#include <iostream>
#include "Gestor.h"
#include <bits/stdc++.h>
using namespace std;

Gestor auxfile;
Graph help;

void clearScreen();
void wait();


bool valid_int(const string& s);
bool valid_airport(const string& s);
bool valid_city(const string& s);
bool valid_country(const string& s);
bool valid_coord(double latitude, double longitude);
bool valid_radius(const string& s);
bool valid_double(const string& s);
vector<int> valid_country_city(const string& city);

// Other Menu Functions
void menu_dest(const string& sign);
vector<int> airports_country(const string& country);
string airport_closer(double latitude, double longitude);
vector<int> airports_radius_x(double latitude, double longitude, double radius);

// Prints de Menu Informacao
void info_airport(int id, const Airport& airport, string sign);
void info_city(const string& city);
void info_airport_city(const string& city);
void info_airport_city_country(const string& city, const string& country);
void info_country(const string& country);
void info_airport_country(const string& country, vector<int> airports);
void info_airport_radius_x(double latitude, double longitude, double radius);
void info_flights(int from, int to);

int main() {
    system("Color 07");
    auxfile.Gestor_Airports();
    help = Graph((int) auxfile.getAirports().size());
    auxfile.Gestor_Airlines();
    auxfile.Gestor_Flights(help);

    int diametro = help.diametro();

    // vector<int> aeroportos com maximo de voos
    vector<pair<int, int>> airports_max_flights; //partida e chegada

    for (int x = 1; x <= help.n; x++) {
        help.bfs(x);
        for (int i = 1; i <= help.n; i++) {
            if (help.nodes[i].distance == diametro) {
                pair<int, int> airport = make_pair(x, i);
                airports_max_flights.push_back(airport);
            }
        }
    }


    int choice;
    string op_menu;
    string sign, city, country;

// Variaveis para o menu 1 - 1
    Airport airport;
    int id;

// Variaveis para o menu 1 - 4
    double lat, lon;
    double radius;
    string radius_s;

    string ajuda;

    vector<int> country_city;
    vector<int> airports_country_x;
    vector<int> airports_radius;

    vector<pair<int, string>> airports_airlines;

    vector<pair<string, int>> flights_airport_x;

    unordered_set<int> airlines_country;

    vector<string> sign_code_tmp;

    int cont_airlines_country;
    int cont_departure_flights;
    int cont_arrival_flights;
    int cont_voos_departure_temp, cont_flights_arrival_temp;

    unordered_map<string, int> countries_in_airport;

    string country_est_temp;
    int froms_est_temp = 0;
    int countries_tmp_total = 0;
    int airlines_est_temp = 0;

    int rnd;

    string flights_n;

    vector<int> flights_n_dist;

    set<int> ye;

    int index = 1;
    stack<int> node_stack;
    list<list<int>> sccs;
    int scc = 0;
    int min = INT_MAX;
    int max = 0;


    do {

        clearScreen();
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << "||------------------------ MENU -------------------------||" << endl;
        cout << "|| Escolha uma opcao:                                    ||" << endl;
        cout << "||_______________________________________________________||" << endl;
        cout << "||                                                       ||" << endl;
        cout << "||   1 - Informacoes                                     ||" << endl;
        cout << "||   2 - Pesquisa                                        ||" << endl;
        cout << "||   3 - Estatisticas                                    ||" << endl;
        cout << "||                                                       ||" << endl;
        cout << "||   0 - Sair                                            ||" << endl;
        cout << "||                                                       ||" << endl;
        cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        cout << endl;


        cin >> op_menu;

        while (!valid_int(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 3) {
            cout << endl;
            cout << "Opcao invalida! Tente novamente: ";
            cin >> op_menu;
            cout << endl;
        }

        choice = stoi(op_menu);
        cout << endl;


        switch (choice) {

            case 0:

                choice = 0;

                break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            case 1:

                int ch1;
                choice = 1;


                do {

                    clearScreen();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||------------------------ INFO -------------------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - De um Aeroporto                                 ||" << endl;
                    cout << "||   2 - De uma Cidade                                   ||" << endl;
                    cout << "||   3 - De um Pais                                      ||" << endl;
                    cout << "||   4 - De um raio de X Km de uma coordenada            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Sair                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;


                    cin >> op_menu;


                    while (!valid_int(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 4) {
                        cout << endl;
                        cout << "Opcao invalida! Tente novamente: ";
                        cin >> op_menu;
                        cout << endl;
                    }

                    ch1 = stoi(op_menu);

                    switch (ch1) {

                        case 0:

                            ch1 = 0;

                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 1:


                            cout << "Aeroporto: ";
                            cin >> sign;


                            while (!valid_airport(sign)) {
                                clearScreen();
                                cout << endl;
                                cout << "Aeroporto invalido! Tente novamente: ";
                                cin >> sign;
                                cout << endl;
                            }

                            transform(sign.begin(), sign.end(), sign.begin(), ::toupper);

                            id = auxfile.getAirports_Codes()[sign];
                            airport = auxfile.getAirports().at(id);


                            info_airport(id, airport, sign);

                            ch1 = 1;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 2:

                            cout << "Cidade: ";
                            getline(cin >> ws, city);


                            while (!valid_city(city)) {
                                clearScreen();
                                cout << endl;
                                cout << "Cidade invalida! Tente novamente: ";
                                getline(cin >> ws, city);
                                cout << endl;
                            }

                            transform(city.begin(), city.end(), city.begin(), ::toupper);


                            info_city(city);

                            ch1 = 2;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 3:

                            cout << "Pais: ";
                            getline(cin >> ws, country);

                            while (!valid_country(country)) {
                                clearScreen();
                                cout << endl;
                                cout << "Pais invalido! Tente novamente: ";
                                getline(cin >> ws, country);
                                cout << endl;
                            }

                            transform(country.begin(), country.end(), country.begin(), ::toupper);


                            info_country(country);

                            ch1 = 3;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 4:

                            cout << "Coordenadas: " << endl;
                            cout << "  - Latitude: ";
                            cin >> lat;
                            cout << endl;
                            cout << "  - Longitude: ";
                            cin >> lon;


                            while (!valid_coord(lat, lon)) {
                                clearScreen();
                                cout << endl;
                                cout << "Coordenadas invalidas! Tente novamente: " << endl;
                                cout << "  - Latitude: ";
                                cin >> lat;
                                cout << endl;
                                cout << "  - Longitude: ";
                                cin >> lon;
                            }

                            cout << endl;
                            cout << "  - Raio a pesquisar (Km): ";
                            cin >> radius;

                            radius_s = to_string(radius);

                            while (!valid_radius(radius_s)) {
                                clearScreen();
                                cout << endl;
                                cout << "Raio invalido! Tente novamente: " << endl;
                                cout << "  - Raio a pesquisar (Km): ";
                                cin >> radius_s;
                            }

                            radius = stoi(radius_s);

                            info_airport_radius_x(lat, lon, radius);


                            ch1 = 4;
                            break;

/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        default:
                            clearScreen();
                            cout << "Opcao invalida! Tente novamente." << endl;
                            wait();
                            break;

                    }

                } while (ch1 != 0);
                break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


            case 2:


                int ch2;
                choice = 2;

                do {

                    clearScreen();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||---------------------- PESQUISA -----------------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Rota com menos escalas                          ||" << endl;
                    cout << "||   2 - Destinos com menos de n voos                    ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Sair                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> op_menu;


                    while (!valid_int(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 2) {
                        cout << endl;
                        cout << "Opcao invalida! Tente novamente: ";
                        cin >> op_menu;
                        cout << endl;
                    }


                    ch2 = stoi(op_menu);

                    switch (ch2) {

                        case 0:

                            ch2 = 0;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                        case 1:

                            ch2 = 1;
                            int ch2_1;

                            do {


                                clearScreen();
                                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                cout << "||---------------------- PESQUISA -----------------------||" << endl;
                                cout << "|| Origem do Voo:                        (Menos Escalas) ||" << endl;
                                cout << "||_______________________________________________________||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   1 - Um Aeroporto                                    ||" << endl;
                                cout << "||   2 - Uma Cidade                                      ||" << endl;
                                cout << "||   3 - Um Pais                                         ||" << endl;
                                cout << "||   4 - O Aeroporto mais proximo de umas coordenadas    ||" << endl;
                                cout << "||   5 - Todos os pontos num raio de X Km                ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "||   0 - Sair                                            ||" << endl;
                                cout << "||                                                       ||" << endl;
                                cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                                cout << endl;

                                cin >> op_menu;

                                while (!valid_int(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 5) {
                                    cout << endl;
                                    cout << "Opcao invalida! Tente novamente: ";
                                    cin >> op_menu;
                                    cout << endl;
                                }

                                ch2_1 = stoi(op_menu);

                                switch (ch2_1) {

                                    case 0:


                                        ch2_1 = 0;
                                        break;

/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 1:


                                        cout << "Aeroporto: ";
                                        cin >> sign;


                                        while (!valid_airport(sign)) {
                                            clearScreen();
                                            cout << endl;
                                            cout << "Aeroporto invalido! Tente novamente: ";
                                            cin >> sign;
                                            cout << endl;
                                        }


                                        transform(sign.begin(), sign.end(), sign.begin(), ::toupper);

                                        menu_dest(sign);


                                        ch2_1 = 1;
                                        break;

/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 2:


                                        cout << "Cidade: ";
                                        getline(cin >> ws, city);


                                        while (!valid_city(city)) {
                                            clearScreen();
                                            cout << endl;
                                            cout << "Cidade invalida! Tente novamente: ";
                                            getline(cin >> ws, city);
                                            cout << endl;
                                        }


                                        transform(city.begin(), city.end(), city.begin(), ::toupper);

                                        country_city = valid_country_city(city);


                                        if (auxfile.getCities_Airports().find(city)->second.size() == 1) {
                                            sign = auxfile.getAirports().find(auxfile.getCities_Airports().find(
                                                    city)->second[0])->second.getCode();
                                            menu_dest(sign);
                                        } else {
                                            clearScreen();
                                            cout << "==========================================================="
                                                 << endl;
                                            cout << "  Cidade com mais de um aeroporto. Escolha um: " << endl;
                                            for (auto i: country_city) {
                                                cout << auxfile.getAirports().find(i)->second.getCode() << " - "
                                                     << auxfile.getAirports().find(i)->second.getName() << endl;
                                            }
                                            cout << "==========================================================="
                                                 << endl;
                                            cout << endl;
                                            cout << "Aeroporto: ";
                                            cin >> sign;


                                            while (!valid_airport(sign)) {
                                                clearScreen();
                                                cout << endl;
                                                cout << "Aeroporto invalido! Tente novamente: ";
                                                cin >> sign;
                                                cout << endl;
                                            }


                                            transform(sign.begin(), sign.end(), sign.begin(), ::toupper);

                                            menu_dest(sign);

                                        }

                                        ch2_1 = 2;
                                        break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 3:

                                        cout << "Pais: ";
                                        getline(cin >> ws, country);


                                        while (!valid_country(country)) {
                                            clearScreen();
                                            cout << endl;
                                            cout << "Pais invalido! Tente novamente: ";
                                            getline(cin >> ws, country);
                                            cout << endl;
                                        }


                                        transform(country.begin(), country.end(), country.begin(), ::toupper);

                                        airports_country_x = airports_country(country);

                                        if (airports_country_x.size() == 1) {
                                            sign = to_string(airports_country_x[0]);
                                            menu_dest(sign);
                                        } else {
                                            clearScreen();
                                            cout << "==========================================================="
                                                 << endl;
                                            cout << "  Pais com mais de um aeroporto. Escolha um: " << endl;
                                            for (auto i: airports_country_x) {
                                                cout << auxfile.getAirports().find(i)->second.getCode() << " - "
                                                     << auxfile.getAirports().find(i)->second.getName() << endl;
                                            }
                                            cout << "==========================================================="
                                                 << endl;
                                            cout << endl;
                                            cout << "Aeroporto: ";
                                            cin >> sign;


                                            while (!valid_airport(sign)) {
                                                clearScreen();
                                                cout << endl;
                                                cout << "Aeroporto invalido! Tente novamente: ";
                                                cin >> sign;
                                                cout << endl;
                                            }

                                            transform(sign.begin(), sign.end(), sign.begin(), ::toupper);

                                            menu_dest(sign);
                                        }

                                        ch2_1 = 3;
                                        break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 4:

                                        cout << "Coordenadas: " << endl;
                                        cout << "  - Latitude: ";
                                        cin >> lat;
                                        cout << endl;
                                        cout << "  - Longitude: ";
                                        cin >> lon;


                                        while (!valid_coord(lat, lon)) {
                                            clearScreen();
                                            cout << endl;
                                            cout << "Coordenadas invalidas! Tente novamente: " << endl;
                                            cout << "  - Latitude: ";
                                            cin >> lat;
                                            cout << endl;
                                            cout << "  - Longitude: ";
                                            cin >> lon;
                                        }

                                        sign = airport_closer(lat, lon);

                                        clearScreen();
                                        cout << "===========================================================" << endl;
                                        cout << "  Cidade mais proxima: " << auxfile.getAirports().find(
                                                auxfile.getAirports_Codes().find(sign)->second)->second.getCity()
                                             << endl;
                                        cout << endl;
                                        cout << "  Aeroporto mais proximo: " << endl;
                                        cout << "  [" << auxfile.getAirports().find(
                                                auxfile.getAirports_Codes().find(sign)->second)->second.getCode()
                                             << "] - " << auxfile.getAirports().find(
                                                auxfile.getAirports_Codes().find(sign)->second)->second.getName()
                                             << endl;
                                        cout << endl;
                                        cout << "  Distancia: " << distancia(lat, lon, auxfile.getAirports().find(
                                                                                     auxfile.getAirports_Codes().find(sign)->second)->second.getLatitude(),
                                                                             auxfile.getAirports().find(
                                                                                     auxfile.getAirports_Codes().find(
                                                                                             sign)->second)->second.getLongitude());
                                        cout << " km" << endl;
                                        cout << "===========================================================" << endl;

                                        wait();

                                        menu_dest(sign);

                                        ch2_1 = 4;
                                        break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/
                                    case 5:

                                        cout << "Coordenadas: " << endl;
                                        cout << "  - Latitude: ";
                                        cin >> lat;
                                        cout << endl;
                                        cout << "  - Longitude: ";
                                        cin >> lon;


                                        while (!valid_coord(lat, lon)) {
                                            clearScreen();
                                            cout << endl;
                                            cout << "Coordenadas invalidas! Tente novamente: " << endl;
                                            cout << "  - Latitude: ";
                                            cin >> lat;
                                            cout << endl;
                                            cout << "  - Longitude: ";
                                            cin >> lon;
                                        }

                                        cout << endl;
                                        cout << "  - Raio a pesquisar (Km): ";
                                        cin >> radius;

                                        radius_s = to_string(radius);

                                        while (!valid_radius(radius_s)) {
                                            clearScreen();
                                            cout << endl;
                                            cout << "Raio invalido! Tente novamente: " << endl;
                                            cout << "  - Raio a pesquisar (Km): ";
                                            cin >> radius_s;
                                        }
                                        radius = stoi(radius_s);

                                        airports_radius = airports_radius_x(lat, lon, radius);

                                        if (airports_radius.empty()) {
                                            clearScreen();
                                            cout << "==========================================================="
                                                 << endl;
                                            cout << "  Nao existem aeroportos no raio indicado!" << endl;
                                            cout << "==========================================================="
                                                 << endl;
                                            wait();
                                            ch2_1 = 5;
                                            break;
                                        }

                                        clearScreen();
                                        cout << "===========================================================" << endl;
                                        cout << "  Aeroportos no raio de " << radius << " km: " << endl;
                                        cout << endl;
                                        for (auto i: airports_radius) {
                                            cout << "  [" << auxfile.getAirports().find(i)->second.getCode()
                                                 << "] - " << auxfile.getAirports().find(i)->second.getName() << endl;
                                        }
                                        cout << endl;
                                        cout << "===========================================================" << endl;
                                        cout << "|  Escollha um aeroporto:                                 |" << endl;
                                        cout << "===========================================================" << endl;
                                        cout << endl;
                                        cout << "Aeroporto: ";
                                        cin >> sign;
/** Leitura do input do utilizador */

                                        while (!valid_airport(sign)) {
                                            clearScreen();
                                            cout << endl;
                                            cout << "Aeroporto invalido! Tente novamente: ";
                                            cin >> sign;
                                            cout << endl;
                                        }

                                        transform(sign.begin(), sign.end(), sign.begin(), ::toupper);

                                        menu_dest(sign);

                                        ch2_1 = 5;
                                        break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/

                                    default:
                                        clearScreen();
                                        cout << "Opcao invalida! Tente novamente." << endl;
                                        wait();
                                        break;


                                }

                            } while (ch2_1 != 0);

                            break;

                        case 2:


                            cout << "Aeroporto de partida: ";
                            cin >> sign;
                            cout << endl;


                            while (!valid_airport(sign)) {
                                clearScreen();
                                cout << endl;
                                cout << "Aeroporto invalido! Tente novamente: ";
                                cin >> sign;
                                cout << endl;
                            }

                            transform(sign.begin(), sign.end(), sign.begin(), ::toupper);

                            cout << "Numero de voos: ";
                            cin >> flights_n;


                            while (!valid_int(flights_n)) {
                                clearScreen();
                                cout << endl;
                                cout << "Numero de voos invalido! Tente novamente: ";
                                cin >> flights_n;
                                cout << endl;
                            }

                            help.bfs((int) auxfile.getAirports_Codes().find(sign)->second);

                            for (int i = 1; i <= help.n; i++) {
                                if (help.nodes[i].distance <= stoi(flights_n)) {
                                    flights_n_dist.push_back(i);
                                }
                            }

                            clearScreen();
                            cout << "===========================================================" << endl;
                            cout << "|------------------------- INFO --------------------------|" << endl;
                            cout << "|  Aeroporto de origem: " + sign + "                               |" << endl;
                            cout << "|=========================================================|" << endl;
                            cout << "   Consegue chegar a " << flights_n_dist.size() << " aeroportos em " << flights_n
                                 << " voos ou menos." << endl;
                            cout << endl;
                            cout << "   Aeroportos:" << endl;
                            cout << endl;
                            for (int i: flights_n_dist) {
                                cout << "    - [" << auxfile.getAirports().at(i).getCode() << "] -> "
                                     << auxfile.getAirports().at(i).getName() << endl;
                            }
                            cout << endl;
                            cout << "|                                                         |" << endl;
                            cout << "===========================================================" << endl;

                            flights_n_dist.clear();

                            wait();

                            ch1 = 5;
                            break;
/*---------------------------------------------------------------------------------------------------------------------------------------*/

                        default:
                            clearScreen();
                            cout << "Opcao invalida!" << endl;
                            wait();
                            break;

                    }

                } while (ch2 != 0);

                break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            case 3:


                choice = 3;
                int ch3;

                do {
                    clearScreen();
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << "||-------------------- ESTATISTICAS ---------------------||" << endl;
                    cout << "|| Escolha uma opcao:                                    ||" << endl;
                    cout << "||_______________________________________________________||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   1 - Globais                                         ||" << endl;
                    cout << "||   2 - De um Pais                                      ||" << endl;
                    cout << "||   3 - De um Aeroporto                                 ||" << endl;
                    cout << "||   4 - Pontos de Articulacao                           ||" << endl;
                    cout << "||   5 - Componentes Fortemente Conexos                  ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "||   0 - Sair                                            ||" << endl;
                    cout << "||                                                       ||" << endl;
                    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                    cout << endl;

                    cin >> op_menu;


                    while (!valid_int(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 5) {
                        cout << endl;
                        cout << "Opcao invalida! Tente novamente: ";
                        cin >> op_menu;
                        cout << endl;
                    }

                    ch3 = stoi(op_menu);

                    switch (ch3) {

                        case 1:


                            rnd = (rand() % (10 - 3 + 1) + 3);


                            clearScreen();
                            cout << "===========================================================" << endl;
                            cout << "|--------------------- ESTATISTICAS ----------------------|" << endl;
                            cout << "|                        Globais                          |" << endl;
                            cout << "|=========================================================|" << endl;
                            cout << "                                                           " << endl;
                            cout << "    Paises com aeroportos: " << auxfile.getCountry_Cities().size()
                                 << "                             " << endl;
                            cout << "    Aeroportos totais: " << auxfile.getAirports().size()
                                 << "                                " << endl;
                            cout << "    Companhias: " << auxfile.getAirlines().size()
                                 << "                                        " << endl;
                            cout << "    Diametro da Rede: " << diametro
                                 << "                                                   " << endl;
                            cout << endl;
                            cout << "    Top " << rnd << " Aeroportos com mais companhias aereas:           " << endl;
                            for (auto &elem: auxfile.getAirports_Airlines()) {
                                airports_airlines.emplace_back(elem.second.size(), elem.first);
                            }
                            sort(airports_airlines.begin(), airports_airlines.end(),
                                 [](const pair<int, string> &a, const pair<int, string> &b) {
                                     return a.first > b.first;
                                 });

                            for (int i = 0; i < rnd; i++) {
                                cout << "      " << i + 1 << " -> "
                                     << auxfile.getAirports().find(auxfile.getAirports_Codes().find(
                                             airports_airlines[i].second)->second)->second.getName() << ", "
                                     << auxfile.getAirports().find(auxfile.getAirports_Codes().find(
                                             airports_airlines[i].second)->second)->second.getCountry()
                                     << " - " << airports_airlines[i].first << endl;
                            }
                            cout << endl;
                            if (airports_max_flights.size() > 1) {
                                if (airports_max_flights.size() > 5) rnd = (rand() % (5 - 2 + 1) + 2);
                                else (rand() % (airports_max_flights.size() - 2 + 1) + 2);
                                cout << "    As " << rnd << " maiores viagens na rede global:           " << endl;
                                for (int i = 0; i < rnd; i++) {
                                    cout << "      " << i + 1
                                         << " -> ["
                                         << auxfile.getAirports().find(airports_max_flights[i].first)->second.getCode()
                                         << "] -> [" << auxfile.getAirports().find(
                                            airports_max_flights[i].second)->second.getCode() << "]" << endl
                                         << "        "
                                         << auxfile.getAirports().find(airports_max_flights[i].first)->second.getName()
                                         << ", "
                                         << auxfile.getAirports().find(airports_max_flights[i].first)->second.getCountry()
                                         << " - "
                                         << auxfile.getAirports().find(airports_max_flights[i].second)->second.getName()
                                         << ", "
                                         << auxfile.getAirports().find(airports_max_flights[i].second)->second.getCountry();
                                    cout << endl;
                                }
                            } else {
                                cout << "    A maiore viagem na rede global:           " << endl;
                                cout << "      " << 1
                                     << " -> ["
                                     << auxfile.getAirports().find(airports_max_flights[0].first)->second.getCode()
                                     << "] -> ["
                                     << auxfile.getAirports().find(airports_max_flights[0].second)->second.getCode()
                                     << "]" << endl
                                     << "        "
                                     << auxfile.getAirports().find(airports_max_flights[0].first)->second.getName()
                                     << ", "
                                     << auxfile.getAirports().find(airports_max_flights[0].first)->second.getCountry()
                                     << " -> "
                                     << auxfile.getAirports().find(airports_max_flights[0].second)->second.getName()
                                     << ", "
                                     << auxfile.getAirports().find(airports_max_flights[0].second)->second.getCountry();
                                cout << endl;
                            }

                            cout << "|                                                         |" << endl;
                            cout << "===========================================================" << endl;
                            cout << endl;

                            airports_airlines.clear();

                            wait();
                            break;

                        case 2:


                            cout << "Pais: ";
                            getline(cin >> ws, country);

                            while (!valid_country(country)) {
                                clearScreen();
                                cout << endl;
                                cout << "Pais invalido! Tente novamente: ";
                                getline(cin >> ws, country);
                                cout << endl;
                            }

                            transform(country.begin(), country.end(), country.begin(), ::toupper);

                            airports_country_x = airports_country(country);


                            if (airports_country_x.size() < 5) {
                                rnd = (rand() % (airports_country_x.size() - 1 + 1) + 1);
                            } else {
                                rnd = (rand() % (5 - 3 + 1) + 3);
                            }


                            cont_airlines_country = 0;

                            for (const auto &c: auxfile.getAirlines()) {
                                ajuda = c.second.getCountry();
                                transform(ajuda.begin(), ajuda.end(), ajuda.begin(), ::toupper);
                                if (ajuda == country) {
                                    cont_airlines_country++;
                                }
                            }


                            for (auto asd: airports_country_x) {
                                sign_code_tmp.push_back(auxfile.getAirports().find(asd)->second.getCode());
                                cout << auxfile.getAirports().find(asd)->second.getCode() << endl;
                            }

                            cont_departure_flights = 0;
                            cont_arrival_flights = 0;
                            cont_flights_arrival_temp = 0;
                            cont_voos_departure_temp = 0;

                            flights_airport_x.clear();

                            for (const auto &a: sign_code_tmp) {

                                for (const auto &v: auxfile.getArrival_Departure_Airline()) {
                                    if (v.first.first == a) {
                                        cont_departure_flights++;
                                        cont_voos_departure_temp++;
                                    }
                                    if (v.first.second == a) {
                                        cont_arrival_flights++;
                                        cont_flights_arrival_temp++;
                                    }
                                }
                                flights_airport_x.emplace_back(a, cont_arrival_flights + cont_departure_flights);
                                cont_departure_flights = 0;
                                cont_arrival_flights = 0;
                            }

                            sort(flights_airport_x.begin(), flights_airport_x.end(),
                                 [](const pair<string, int> &a, const pair<string, int> &b) {
                                     return a.second > b.second;
                                 });

                            clearScreen();
                            cout << "===========================================================" << endl;
                            cout << "|--------------------- ESTATISTICAS ----------------------|" << endl;
                            cout << "|                          Pais                           |" << endl;
                            cout << "|=========================================================|" << endl;
                            cout << "                                                           " << endl;
                            cout << "    Pais - " << country << "                                        " << endl;
                            cout << "    Existem " << airports_country_x.size() << " Aeroportos   " << endl;
                            cout << "    Existem " << cont_airlines_country << " companhias de " << country
                                 << "                                      " << endl;
                            cout << "    Partem " << cont_voos_departure_temp << " voos de " << country
                                 << "                             " << endl;
                            cout << "    Chegam " << cont_flights_arrival_temp << " voos a " << country
                                 << "                             " << endl;
                            cout << endl;
                            cout << "    Top " << rnd << " Aeroportos com mais voos:           " << endl;

                            for (int i = 0; i < rnd; i++) {
                                cout << "      " << i + 1 << " -> "
                                     << auxfile.getAirports().find(auxfile.getAirports_Codes().find(
                                             flights_airport_x[i].first)->second)->second.getName() << ", "
                                     << " - " << flights_airport_x[i].second << endl;
                            }
                            cout << "|                                                         |" << endl;
                            cout << "===========================================================" << endl;
                            cout << endl;

                            flights_airport_x.clear();
                            airports_country_x.clear();

                            wait();

                            break;


                        case 3:

                            cout << "Aeroporto: ";
                            cin >> sign;

                            while (!valid_airport(sign)) {
                                clearScreen();
                                cout << endl;
                                cout << "Aeroporto invalido! Tente novamente: ";
                                cin >> sign;
                                cout << endl;
                            }

                            transform(sign.begin(), sign.end(), sign.begin(), ::toupper);


                            froms_est_temp = 0;
                            countries_tmp_total = 0;
                            airlines_est_temp = 0;
                            cont_departure_flights = 0;
                            cont_arrival_flights = 0;

                            airport = auxfile.getAirports().find(
                                    auxfile.getAirports_Codes().find(sign)->second)->second;


                            for (const auto &v: auxfile.getArrival_Departure_Airline()) {
                                if (v.first.first == sign) {
                                    cont_departure_flights++;
                                    cont_voos_departure_temp++;
                                }
                                if (v.first.second == sign) {
                                    cont_arrival_flights++;
                                    cont_flights_arrival_temp++;
                                }
                            }


                            for (auto &ligacao: help.nodes[auxfile.getAirports_Codes().find(sign)->second].adj) {
                                country_est_temp = auxfile.getAirports().find(ligacao.dest)->second.getCountry();
                                countries_in_airport[country_est_temp]++;
                            }
                            countries_tmp_total = (int) countries_in_airport.size();

                            airlines_est_temp = (int) auxfile.getAirports_Airlines()[sign].size();
                            froms_est_temp = (int) help.nodes[auxfile.getAirports_Codes().find(
                                    sign)->second].adj.size();


                            clearScreen();
                            cout << "===========================================================" << endl;
                            cout << "|--------------------- ESTATISTICAS ----------------------|" << endl;
                            cout << "|  Aeroporto escolhido: " + sign + "                               |" << endl;
                            cout << "===========================================================" << endl;
                            cout << "|                                                         |" << endl;
                            cout << "   Nome:   " + airport.getName() << endl;
                            cout << "   Cidade: " + airport.getCity() << endl;
                            cout << "   Pais:   " + airport.getCountry() << endl;
                            cout << "   Numero total de voos: " << cont_departure_flights + cont_arrival_flights << endl;
                            cout << "   Numero de Voos de chegada: " << cont_arrival_flights << endl;
                            cout << "   Numero de Voos de partida: " << cont_departure_flights << endl;
                            cout << "   Numero de Companhias aereas: " << airlines_est_temp << endl;
                            cout << "   Existem " << froms_est_temp << " destinos: " << endl;
                            cout << "   Pode chegar ate " << countries_tmp_total << " paises" << endl;

                            cout << "|                                                         |" << endl;
                            cout << "===========================================================" << endl;
                            cout << endl;

                            wait();

                            break;

                        case 4:

                            ye = help.getArticulationPoints();
                            if (ye.empty()) {
                                cout << "Sem pontos de articulacao" << endl;
                            } else {
                                clearScreen();
                                cout << "===========================================================" << endl;
                                cout << "|--------------------- ESTATISTICAS ----------------------|" << endl;
                                cout << "|                  Pontos de Articulacao                  |" << endl;
                                cout << "|=========================================================|" << endl;
                                cout << endl;
                                cout << "    Existem " << ye.size() << " pontos de articulacao" << endl;
                                cout << endl;
                                cout << "    Aeroportos com pontos de articulacao:                 " << endl;
                                for (auto &elem: ye) {
                                    cout << "      [" << auxfile.getAirports().find(elem)->second.getCode() << "] -> "
                                         << auxfile.getAirports().find(elem)->second.getName() << ", "
                                         << auxfile.getAirports().find(elem)->second.getCountry() << endl;
                                }
                                cout << endl;
                                cout << "|                                                         |" << endl;
                                cout << "===========================================================" << endl;
                                cout << endl;
                            }
                            wait();
                            break;

                        case 5:

                            for (auto &node: help.nodes) {
                                node.visited = false;
                                node.in_stack = false;
                            }

                            for (int v = 1; v <= help.n; v++) {
                                if (!help.nodes[v].visited) {
                                    scc += help.dfs_scc(v, index);
                                }
                            }

                            for (auto &node: help.nodes) {
                                node.visited = false;
                                node.in_stack = false;
                            }

                            for (int v = 1; v <= help.n; v++) {
                                if (!help.nodes[v].visited) {
                                    help.dfs_scc2(v, index, &node_stack, &sccs);
                                }
                            }

                            for (auto &comp: sccs) {
                                if (comp.size() < min) {
                                    min = comp.size();
                                } else if (comp.size() > max) {
                                    max = comp.size();
                                }
                            }

                            clearScreen();
                            cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
                            cout << "||-------------------- ESTATISTICAS ---------------------||" << endl;
                            cout << "||_______________________________________________________||" << endl;
                            cout << "     Numero de componentes fortemente conexos: " << scc << endl;
                            cout << "                                                           " << endl;
                            cout << "     Menor componentes fortemente conexo: " << min << endl;
                            cout << "     Maior componentes fortemente conexo: " << max << endl;
                            cout << "|                                                         |" << endl;
                            cout << "||_______________________________________________________||" << endl;

                            wait();

                            ch3 = 6;
                            break;

                        default:
                            break;
                    }

                } while (ch3 != 0);

                break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            default:
                clearScreen();
                cout << "Opcao invalida!" << endl;
                wait();
                break;
        }


    }while (choice != 0);


    return 0;
}

bool valid_int(const string& s){

    for(auto y : s){
        if(!isdigit(y)){
            return false;
        }
    }
    return true;
}

bool valid_airport(const string& s){

    string aerop = s;

    transform(aerop.begin(), aerop.end(), aerop.begin(), ::toupper);

    unordered_map<string, int> check = auxfile.getAirports_Codes();

    if(check.find(aerop) == check.end()){
        clearScreen();
        cout << "Aeroporto nao existe!" << endl;
        wait();
        return false;
    }

    return true;
}

bool valid_city(const string& s){

    string cidade = s;

    transform(cidade.begin(), cidade.end(), cidade.begin(), ::toupper);

    unordered_map<string, vector<int>> check = auxfile.getCities_Airports();

    if(check.find(cidade) == check.end()){
        clearScreen();
        cout << "Cidade nao existe!" << endl;
        wait();
        return false;
    }

    return true;
}

bool valid_country(const string& s){

    string pais = s;

    transform(pais.begin(), pais.end(), pais.begin(), ::toupper);

    unordered_map<string, unordered_set<string>> check = auxfile.getCountry_Cities();

    if(check.find(pais) == check.end()){
        clearScreen();
        cout << "Pais nao existe!" << endl;
        wait();
        return false;
    }

    return true;
}

bool valid_coord(double lat, double lon) {

    if(lat < -90 || lat > 90 || lon < -180 || lon > 180){
        clearScreen();
        cout << "Coordenadas invalidas!" << endl;
        wait();
        return false;
    }

    return true;
}

bool valid_radius(const string& s){

    if(!valid_double(s)){
        return false;
    }

    double raio = stod(s);

    if(raio < 0){
        clearScreen();
        cout << "Raio invalido!" << endl;
        wait();
        return false;
    }

    return true;
}

bool valid_double(const string& s){

    int count = 0;

    for(auto y : s){
        if(!isdigit(y) && y != '.' && y != ','){
            return false;
        }
        if(y == '.' || y == ','){
            count++;
        }
    }

    if(count > 1){
        return false;
    }

    return true;
}

vector<int> valid_country_city(const string& cidade) {

    string opcao;
    int pais_escolhido;
    vector<int> aeroportos;
    string nome_pais;
    vector<string> countries;

    for (auto &elem: auxfile.getCountry_Cities()) {
        for (auto &city: elem.second) {
            if (city == cidade) {
                countries.push_back(elem.first);
            }
        }
    }

    //Quando existem cidades com o mesmo nome em paises diferentes
    if(countries.size() > 1){
        clearScreen();
        cout << "===========================================================" << endl;
        cout << "|----------------------- PESQUISA ------------------------|" << endl;
        cout << "  Existem " << countries.size() << " paises com a cidade " + cidade + "                  " << endl;
        cout << "===========================================================" << endl;
        cout << "                                                       " << endl;
        cout << "  Escolha o pais:                                      " << endl;
        cout << "                                                       " << endl;
        for (int i = 0; i < countries.size(); i++) {
            cout << "  " << i + 1 << " - " << countries[i] << endl;
        }
        cout << "                                                       " << endl;
        cout << "===========================================================" << endl;
        cout << endl;

        cout << "Opcao: ";
        cin >> pais_escolhido;

        while (!valid_int(to_string(pais_escolhido)) || pais_escolhido < 1 || pais_escolhido > countries.size()) {
            cout << endl;
            cout << "Opcao invalida! Tente novamente: ";
            cin >> pais_escolhido;
            cout << endl;
        }

        nome_pais = countries[pais_escolhido - 1];

        pair<string, string> pais_cidade = make_pair(nome_pais, cidade);

        aeroportos = auxfile.getCountry_City_Airports().find(pais_cidade)->second;

        return aeroportos;
    }
    else{
        nome_pais = countries[0];
        pair<string, string> pais_cidade = make_pair(nome_pais, cidade);

        aeroportos = auxfile.getCountry_City_Airports().find(pais_cidade)->second;

        return aeroportos;
    }
}



// Other Menu Functions

void menu_dest(const string& aerop) {

    string op_menu;
    string cidade;
    vector<int> pais_cidade;
    string pais;
    vector<int> aeroportos_pais_v;
    double lat, lon, raio;
    string raio_s;
    vector<int> aeroportos_raio;




    string aerop_destino;
    int origem = auxfile.getAirports_Codes().find(aerop)->second;
    int destino;

    clearScreen();
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << "||---------------------- PESQUISA -----------------------||" << endl;
    cout << "|| Destino do Voo:                       (Menos Escalas) ||" << endl;
    cout << "||_______________________________________________________||" << endl;
    cout << "||                                                       ||" << endl;
    cout << "||   1 - Um Aeroporto                                    ||" << endl;
    cout << "||   2 - Uma Cidade                                      ||" << endl;
    cout << "||   3 - Um Pais                                         ||" << endl;
    cout << "||   4 - O Aeroporto mais proximo de umas coordenadas    ||" << endl;
    cout << "||   5 - Todos os pontos num raio de X Km                ||" << endl;
    cout << "||                                                       ||" << endl;
    cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
    cout << endl;

    cin >> op_menu;

    while (!valid_int(op_menu) || stoi(op_menu) < 0 || stoi(op_menu) > 5) {
        cout << endl;
        cout << "Opcao invalida! Tente novamente: ";
        cin >> op_menu;
        cout << endl;
    }

    int ch = stoi(op_menu);

    switch (ch) {

        case 1:

            cout << "Aeroporto: ";
            cin >> aerop_destino;

            while (!valid_airport(aerop_destino)) {
                clearScreen();
                cout << endl;
                cout << "Aeroporto invalido! Tente novamente: ";
                cin >> aerop_destino;
                cout << endl;
            }

            transform(aerop_destino.begin(), aerop_destino.end(), aerop_destino.begin(), ::toupper);

            destino = auxfile.getAirports_Codes().find(aerop_destino)->second;
            info_flights(origem, destino);

            break;

        case 2:

            cout << "Cidade: ";
            getline(cin >> ws, cidade);

            while (!valid_city(cidade)) {
                clearScreen();
                cout << endl;
                cout << "Cidade invalida! Tente novamente: ";
                getline(cin >> ws, cidade);
                cout << endl;
            }

            transform(cidade.begin(), cidade.end(), cidade.begin(), ::toupper);

            pais_cidade = valid_country_city(cidade);

            if (auxfile.getCities_Airports().find(cidade)->second.size() == 1) {
                aerop_destino = auxfile.getAirports().find(
                        auxfile.getCities_Airports().find(cidade)->second[0])->second.getCode();
                destino = auxfile.getAirports_Codes().find(aerop_destino)->second;
                info_flights(origem, destino);
            } else {
                clearScreen();
                cout << "===========================================================" << endl;
                cout << "  Cidade com mais de um aeroporto. Escolha um: " << endl;
                for (auto i: pais_cidade) {
                    cout << auxfile.getAirports().find(i)->second.getCode() << " - "
                         << auxfile.getAirports().find(i)->second.getName() << endl;
                }
                cout << "===========================================================" << endl;
                cout << endl;
                cout << "Aeroporto: ";
                cin >> aerop_destino;

                while (!valid_airport(aerop_destino)) {
                    clearScreen();
                    cout << endl;
                    cout << "Aeroporto invalido! Tente novamente: ";
                    cin >> aerop_destino;
                    cout << endl;
                }

                transform(aerop_destino.begin(), aerop_destino.end(), aerop_destino.begin(), ::toupper);

                destino = auxfile.getAirports_Codes().find(aerop_destino)->second;
                info_flights(origem, destino);


            }

            break;


        case 3:

            cout << "Pais: ";
            getline(cin >> ws, pais);

            while(!valid_country(pais)){
                clearScreen();
                cout << endl;
                cout << "Pais invalido! Tente novamente: ";
                getline(cin >> ws, pais);
                cout << endl;
            }

            transform(pais.begin(), pais.end(), pais.begin(), ::toupper);

            aeroportos_pais_v = airports_country(pais);

            if(aeroportos_pais_v.size() == 1){
                aerop_destino = to_string(aeroportos_pais_v[0]);
                destino = auxfile.getAirports_Codes().find(aerop_destino)->second;
                info_flights(origem, destino);
            }
            else{
                clearScreen();
                cout << "===========================================================" << endl;
                cout << "  Pais com mais de um aeroporto. Escolha um: " << endl;
                for(auto i : aeroportos_pais_v){
                    cout << auxfile.getAirports().find(i)->second.getCode() << " - " << auxfile.getAirports().find(i)->second.getName() << endl;
                }
                cout << "===========================================================" << endl;
                cout << endl;
                cout << "Aeroporto: ";
                cin >> aerop_destino;

                while(!valid_airport(aerop_destino)){
                    clearScreen();
                    cout << endl;
                    cout << "Aeroporto invalido! Tente novamente: ";
                    cin >> aerop_destino;
                    cout << endl;
                }

                transform(aerop_destino.begin(), aerop_destino.end(), aerop_destino.begin(), ::toupper);

                destino = auxfile.getAirports_Codes().find(aerop_destino)->second;
                info_flights(origem, destino);


            }
            break;

        case 4:

            cout << "Coordenadas: " << endl;
            cout << "  - Latitude: ";
            cin >> lat;
            cout << endl;
            cout << "  - Longitude: ";
            cin >> lon;

            while(!valid_coord(lat, lon)){
                clearScreen();
                cout << endl;
                cout << "Coordenadas invalidas! Tente novamente: " << endl;
                cout << "  - Latitude: ";
                cin >> lat;
                cout << endl;
                cout << "  - Longitude: ";
                cin >> lon;
            }

            aerop_destino = airport_closer(lat, lon);

            clearScreen();
            cout << "===========================================================" << endl;
            cout << "  Cidade mais proxima: " << auxfile.getAirports().find(auxfile.getAirports_Codes().find(aerop_destino)->second)->second.getCity() << endl;
            cout << endl;
            cout << "  Aeroporto mais proximo: " << endl;
            cout << "  [" << auxfile.getAirports().find(auxfile.getAirports_Codes().find(aerop_destino)->second)->second.getCode()
                 << "] - " << auxfile.getAirports().find(auxfile.getAirports_Codes().find(aerop_destino)->second)->second.getName() << endl;
            cout << endl;
            cout << "  Distancia: " << distancia(lat, lon, auxfile.getAirports().find(auxfile.getAirports_Codes().find(aerop_destino)->second)->second.getLatitude(),auxfile.getAirports().find(auxfile.getAirports_Codes().find(aerop_destino)->second)->second.getLongitude());
            cout << " km" << endl;
            cout << "===========================================================" << endl;

            wait();

            destino = auxfile.getAirports_Codes().find(aerop_destino)->second;
            info_flights(origem, destino);

            break;

        case 5:

            cout << "Coordenadas: " << endl;
            cout << "  - Latitude: ";
            cin >> lat;
            cout << endl;
            cout << "  - Longitude: ";
            cin >> lon;

            while(!valid_coord(lat, lon)){
                clearScreen();
                cout << endl;
                cout << "Coordenadas invalidas! Tente novamente: " << endl;
                cout << "  - Latitude: ";
                cin >> lat;
                cout << endl;
                cout << "  - Longitude: ";
                cin >> lon;
            }

            cout << endl;
            cout << "  - Raio a pesquisar (Km): ";
            cin >> raio;

            raio_s = to_string(raio);

            while(!valid_radius(raio_s)){
                clearScreen();
                cout << endl;
                cout << "Raio invalido! Tente novamente: " << endl;
                cout << "  - Raio a pesquisar (Km): ";
                cin >> raio_s;
            }
            raio = stoi(raio_s);

            aeroportos_raio = airports_radius_x(lat, lon, raio);

            clearScreen();
            cout << "===========================================================" << endl;
            cout << "  Aeroportos no raio de " << raio << " km: " << endl;
            cout << endl;
            for(auto i : aeroportos_raio){
                cout << "  [" << auxfile.getAirports().find(i)->second.getCode()
                     << "] - " << auxfile.getAirports().find(i)->second.getName() << endl;
            }
            cout << endl;
            cout << "===========================================================" << endl;
            cout << "|  Escollha um aeroporto:                                 |" << endl;
            cout << "===========================================================" << endl;
            cout << endl;
            cout << "Aeroporto: ";
            cin >> aerop_destino;

            while(!valid_airport(aerop_destino)){
                clearScreen();
                cout << endl;
                cout << "Aeroporto invalido! Tente novamente: ";
                cin >> aerop_destino;
                cout << endl;
            }

            transform(aerop_destino.begin(), aerop_destino.end(), aerop_destino.begin(), ::toupper);

            destino = auxfile.getAirports_Codes().find(aerop_destino)->second;
            info_flights(origem, destino);

        default:
            break;


    }
}

string airport_closer(double lat, double lon){

    double latitude = lat, longitude = lon;

    double aeroporto_mais_proximo = INT_MAX;

    int aeroporto_mais_proximo_id;

    for (const auto &aerop: auxfile.getAirports_Coords()) {
        if (distancia(latitude, longitude, aerop.first.first, aerop.first.second) < aeroporto_mais_proximo) {
            aeroporto_mais_proximo = distancia(latitude, longitude, aerop.first.first, aerop.first.second);
            aeroporto_mais_proximo_id = aerop.second;
        }
    }

    for(const auto& x : auxfile.getAirports()){
        if(aeroporto_mais_proximo_id == x.first){
            return x.second.getCode();
        }
    }

    return "";

}

vector<int> airports_country(const string& pais){

    unordered_set<string> cidades = auxfile.getCountry_Cities().find(pais)->second;

    vector<string> cidades_v(cidades.begin(), cidades.end());

    vector<int> aeroportos;

    vector<pair<string, string>> pais_cidade;

    for(auto & i : cidades_v){
        pais_cidade.emplace_back(pais, i);
    }

    for(const auto& i : pais_cidade){
        vector<int> tmp = auxfile.getCountry_City_Airports().find(i)->second;
        aeroportos.insert(aeroportos.end(), tmp.begin(), tmp.end());
    }

    return aeroportos;
}

vector<int> airports_radius_x(double lat, double lon, double raio){

    double latitude = lat, longitude = lon;

    vector<int> aeroportos;

    for (const auto &aerop: auxfile.getAirports_Coords()) {
        if (distancia(latitude, longitude, aerop.first.first, aerop.first.second) <= raio) {
            aeroportos.push_back(aerop.second);
        }
    }

    return aeroportos;
}

// Prints de Menu Informacao

void info_airport(int id, const Airport& aeroporto, string aerop){

    int companhias;

    transform(aerop.begin(), aerop.end(), aerop.begin(), ::toupper);


    companhias = (int) auxfile.getAirports_Airlines()[aerop].size();


    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "|  Aeroporto escolhido: " + aerop + "                               |" << endl;
    cout << "|=========================================================|" << endl;
    cout << "                                                           " << endl;
    cout << "   Nome:   " + aeroporto.getName()                         << endl;
    cout << "   Cidade: " + aeroporto.getCity()                       << endl;
    cout << "   Pais:   " + aeroporto.getCountry()                         << endl;
    cout << "   Numero de Companhias aereas: " << companhias            << endl;
    cout << "|                                                         |" << endl;
    cout << "===========================================================" << endl;
    cout << endl;

    wait();
}

void info_city(const string& cidade){


    string opcao;
    int pais_escolhido;
    int num_aeroportos;
    string nome_pais;
    vector<string> countries;

    for(auto& elem : auxfile.getCountry_Cities()) {
        for(auto& city : elem.second) {
            if(city == cidade) {
                countries.push_back(elem.first);
            }
        }
    }

    //Quando existem cidades com o mesmo nome em paises diferentes
    if (countries.size() > 1) {
        clearScreen();
        cout << "===========================================================" << endl;
        cout << "|------------------------- INFO --------------------------|" << endl;
        cout << "  Existem " << countries.size() << " paises com a cidade " + cidade + "                  " << endl;
        cout << "===========================================================" << endl;
        cout << "                                                       " << endl;
        cout << "  Escolha o pais:                                      " << endl;
        cout << "                                                       " << endl;
        for(int i = 0; i < countries.size(); i++) {
            cout << "  " << i+1 << " - " << countries[i] << endl;
        }
        cout << "                                                       " << endl;
        cout << "===========================================================" << endl;
        cout << endl;

        cout << "Opcao: ";
        cin >> pais_escolhido;

        while(!valid_int(to_string(pais_escolhido)) || pais_escolhido < 1 || pais_escolhido > countries.size()){
            cout << endl;
            cout << "Opcao invalida! Tente novamente: ";
            cin >> pais_escolhido;
            cout << endl;
        }

        nome_pais = countries[pais_escolhido-1];

        pair<string, string> pais_cidade = make_pair(nome_pais, cidade);

        num_aeroportos = (int) auxfile.getCountry_City_Airports().find(pais_cidade)->second.size();

        clearScreen();
        cout << "===========================================================" << endl;
        cout << "|------------------------- INFO --------------------------|" << endl;
        cout << "   Cidade escolhido: " + cidade +     "                                 " << endl;
        cout << "===========================================================" << endl;
        cout << "                                                       " << endl;
        cout << "   Pais: " + nome_pais << endl;
        cout << "   Numero de aeroportos: " << num_aeroportos << endl;
        cout << "                                                       " << endl;
        cout << "===========================================================" << endl;
        cout << "|                                                         |" << endl;
        cout << "|   Deseja listar os aeroportos? s/n                      |" << endl;
        cout << "|                                                         |" << endl;
        cout << "===========================================================" << endl;
        cout << endl;

        cout << "Opcao: ";
        cin >> opcao;

        while(opcao != "s" && opcao != "n" && opcao != "S" && opcao != "N"){
            cout << endl;
            cout << "Opcao invalida! Tente novamente: ";
            cin >> opcao;
            cout << endl;
        }

        if(opcao == "s" || opcao == "S") info_airport_city_country(cidade, nome_pais);
    }
    else {
        nome_pais = countries[0];

        num_aeroportos = (int) auxfile.getCities_Airports().find(cidade)->second.size();

        clearScreen();
        cout << "===========================================================" << endl;
        cout << "|------------------------- INFO --------------------------|" << endl;
        cout << "   Cidade escolhido: " + cidade + "                                 " << endl;
        cout << "===========================================================" << endl;
        cout << "                                                       " << endl;
        cout << "   Pais: " + nome_pais << endl;
        cout << "   Numero de aeroportos: " << num_aeroportos << endl;
        cout << "                                                       " << endl;
        cout << "===========================================================" << endl;
        cout << "|                                                         |" << endl;
        cout << "|   Deseja listar os aeroportos? s/n                      |" << endl;
        cout << "|                                                         |" << endl;
        cout << "===========================================================" << endl;
        cout << endl;

        cout << "Opcao: ";
        cin >> opcao;

        while(opcao != "s" && opcao != "n" && opcao != "S" && opcao != "N"){
            cout << endl;
            cout << "Opcao invalida! Tente novamente: ";
            cin >> opcao;
            cout << endl;
        }

        if(opcao == "s" || opcao == "S") info_airport_city(cidade);

    }

}

void info_airport_city_country(const string& cidade, const string& pais){

    pair<string, string> pais_cidade = make_pair(pais, cidade);

    vector<int> aeroportos = auxfile.getCountry_City_Airports().find(pais_cidade)->second;

    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "   Cidade escolhida: " + cidade + ", do pais : "+ pais + "                               " << endl;
    cout << "===========================================================" << endl;
    cout << "                                                       " << endl;
    cout << "   Numero de aeroportos: " << aeroportos.size() << endl;
    cout << "                                                       " << endl;

    for(int i = 0; i < aeroportos.size(); i++){
        cout << "   Aeroporto " << i+1 << ": " << auxfile.getAirports().find(aeroportos[i])->second.getCode() << " - "  << auxfile.getAirports().find(aeroportos[i])->second.getName() << endl;
    }

    cout << "                                                           " << endl;
    cout << "===========================================================" << endl;

    wait();

}

void info_airport_city(const string& cidade){

    vector<int> aeroportos = auxfile.getCities_Airports().find(cidade)->second;

    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "   Cidade escolhida: " + cidade + "                                 " << endl;
    cout << "===========================================================" << endl;
    cout << "                                                       " << endl;
    cout << "   Numero de aeroportos: " << aeroportos.size() << endl;
    cout << "                                                       " << endl;

    for(int i = 0; i < aeroportos.size(); i++){
        cout << "   Aeroporto " << i+1 << ": " << auxfile.getAirports().find(aeroportos[i])->second.getCode() << " - "  << auxfile.getAirports().find(aeroportos[i])->second.getName() << endl;
    }

    cout << "                                                           " << endl;
    cout << "===========================================================" << endl;

    wait();

}

void info_country(const string& pais){

    string opcao;

    unordered_set<string> cidades = auxfile.getCountry_Cities().find(pais)->second;

    vector<string> cidades_v(cidades.begin(), cidades.end());

    vector<int> aeroportos;

    vector<pair<string, string>> pais_cidade;

    for(int i = 0; i < cidades_v.size(); i++){
        pais_cidade.emplace_back(pais, cidades_v[i]);
        cout<<pais_cidade[i].first<<" "<<pais_cidade[i].second<<endl;
    }

    for(const auto& i : pais_cidade){
        vector<int> tmp = auxfile.getCountry_City_Airports().find(i)->second;
        aeroportos.insert(aeroportos.end(), tmp.begin(), tmp.end());
    }

    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "   Pais escolhido: " + pais + "                                 " << endl;
    cout << "===========================================================" << endl;
    cout << "                                                       " << endl;
    cout << "   Numero de cidades: " << cidades.size() << endl;
    cout << "   Numero de aeroportos: "  << aeroportos.size() << endl;
    cout << "                                                           " << endl;
    cout << "===========================================================" << endl;
    cout << "|                                                         |" << endl;
    cout << "|   Deseja listar os aeroportos? s/n                      |" << endl;
    cout << "|                                                         |" << endl;
    cout << "===========================================================" << endl;
    cout << endl;


    cout << "Opcao: ";
    cin >> opcao;

    while(opcao != "s" && opcao != "n" && opcao != "S" && opcao != "N"){
        cout << endl;
        cout << "Opcao invalida! Tente novamente: ";
        cin >> opcao;
        cout << endl;
    }

    if(opcao == "s" || opcao == "S") info_airport_country(pais, aeroportos);

}

void info_airport_country(const string& pais, vector<int> aeroportos){

    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "   Pais escolhido: " + pais + "                                 " << endl;
    cout << "===========================================================" << endl;
    cout << "                                                       " << endl;
    cout << "   Numero de aeroportos: " << aeroportos.size() << endl;
    cout << "                                                       " << endl;

    for(int i = 0; i < aeroportos.size(); i++){
        cout << "   Aeroporto " << i+1 << ": " << auxfile.getAirports().find(aeroportos[i])->second.getCode() << " - "  << auxfile.getAirports().find(aeroportos[i])->second.getName() << endl;
    }

    cout << "                                                           " << endl;
    cout << "===========================================================" << endl;

    wait();

}


void info_airport_radius_x(double latitude, double longitude, double raio) {

    vector<int> aeroportos;
    set<pair<string, string>> pais_cidade;
    string opcao;
    unordered_set<string> pais;

    for (const auto &aerop: auxfile.getAirports_Coords()) {
        if (distancia(latitude, longitude, aerop.first.first, aerop.first.second) <= raio) {
            aeroportos.push_back(aerop.second);
        }
    }

    for(auto x : aeroportos){
        for(const auto& y : auxfile.getCountry_City_Airports()){
            for(auto z : y.second){
                if(z == x){
                    pais_cidade.insert(y.first);
                }
            }
        }
    }

    for(const auto& i : pais_cidade){
        pais.insert(i.first);
    }

    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|------------------------- INFO --------------------------|" << endl;
    cout << "   Latitude: " << latitude << "                                 " << endl;
    cout << "   Longitude: " << longitude << "                                 " << endl;
    cout << "   Raio: " << raio << "                                 " << endl;
    cout << "===========================================================" << endl;
    cout << "                                                       " << endl;
    cout << "   Numero de Paises: " << pais.size() << endl;
    cout << "   Numero de Cidades: " << pais_cidade.size() << endl;
    cout << "   Numero de aeroportos: " << aeroportos.size() << endl;
    cout << "                                                       " << endl;
    cout << "===========================================================" << endl;
    cout << "|                                                         |" << endl;
    cout << "|   Deseja listar os aeroportos? s/n                      |" << endl;
    cout << "|                                                         |" << endl;
    cout << "===========================================================" << endl;
    cout << endl;

    cout << "Opcao: ";
    cin >> opcao;

    while (opcao != "s" && opcao != "n" && opcao != "S" && opcao != "N") {
        cout << endl;
        cout << "Opcao invalida! Tente novamente: ";
        cin >> opcao;
        cout << endl;
    }

    if (opcao == "s" || opcao == "S") {
        clearScreen();
        cout << "===========================================================" << endl;
        cout << "|------------------------- INFO --------------------------|" << endl;
        cout << "   Latitude: " << latitude << "                                 " << endl;
        cout << "   Longitude: " << longitude << "                                 " << endl;
        cout << "   Raio: " << raio << "                                 " << endl;
        cout << "===========================================================" << endl;
        cout << "                                                       " << endl;

        for (int i = 0; i < aeroportos.size(); i++) {
            cout << "   Aeroporto " << i + 1 << ": " << auxfile.getAirports().find(aeroportos[i])->second.getCode()
                 << " - " << auxfile.getAirports().find(aeroportos[i])->second.getName() << endl;
        }

        cout << "                                                           " << endl;
        cout << "===========================================================" << endl;

        wait();

    }
}

void info_flights(int origem, int destino){

    string op_menu;

    clearScreen();
    cout << "===========================================================" << endl;
    cout << "|                                                         |" << endl;
    cout << "|   Deseja viajar em alguma Companhia especifica? s/n     |" << endl;
    cout << "|                                                         |" << endl;
    cout << "===========================================================" << endl;
    cout << endl;
    cout << "Opcao: ";
    cin >> op_menu;

    while(op_menu != "s" && op_menu != "n" && op_menu != "S" && op_menu != "N"){
        cout << endl;
        cout << "Opcao invalida! Tente novamente: ";
        cin >> op_menu;
        cout << endl;
    }

    if(op_menu == "s" || op_menu == "S"){
        set<string> companhias;
        string companhia;

        cout << "Indique as companhias que deseja, no fim escreva done: " << endl;
        while(cin >> companhia && companhia != "done" && companhia != "DONE"){
            if(auxfile.getAirlines_Codes().find(companhia) != auxfile.getAirlines_Codes().end()){
                companhias.insert(companhia);
            }
            else{
                cout << "Companhia nao existe! Tente novamente: ";
            }
        }

        vector<int> voo_companhia = help.bfs_airlines(origem, destino, companhias);

        if(voo_companhia.empty()){
            clearScreen();
            cout << "===========================================================" << endl;
            cout << "Nao existe voo entre os aeroportos indicados usando estas companhias: " << endl;
            cout << endl;
            cout << "Aeroporto de Origem: ["<< auxfile.getAirports().find(origem)->second.getCode() << "] - " << auxfile.getAirports().find(origem)->second.getName() << endl;
            cout << "Aeroporto de Destino: ["<< auxfile.getAirports().find(destino)->second.getCode() << "] - " << auxfile.getAirports().find(destino)->second.getName() << endl;
            cout << endl;
            cout << "Companhias: " << endl;
            for(const auto & comp : companhias){
                cout << "  -> [" << comp << "] - " << auxfile.getAirlines().find(auxfile.getAirlines_Codes().find(comp)->second)->second.getName(
                        ) << endl;
            }
            cout << "===========================================================" << endl;
            wait();
        }
        else{

            clearScreen();
            cout << "===========================================================" << endl;
            cout << "Aeroporto de Origem: [" << auxfile.getAirports().find(origem)->second.getCode() << "] - "
                 << auxfile.getAirports().find(origem)->second.getName() << endl;
            cout << "Aeroporto de Destino: [" << auxfile.getAirports().find(destino)->second.getCode() << "] - "
                 << auxfile.getAirports().find(destino)->second.getName() << endl;
            cout << endl;
            cout << "Um dos caminhos possiveis com companhias especificas:" << endl;
            cout << endl;
            cout << auxfile.getAirports().find(origem)->second.getCode() << " -> ";
            for (int i = (int) voo_companhia.size() - 1; i >= 0; i--) {
                if (i == 0) {
                    cout << auxfile.getAirports().find(destino)->second.getCode() << endl;
                } else {
                    cout << auxfile.getAirports().find(voo_companhia[i])->second.getCode() << " -> ";
                }
            }
            cout << endl;
            cout << "Companhias especificadas: " << endl;

            for(auto & comp : companhias){
                cout << "  -> [" << comp << "] - " << auxfile.getAirlines().find(auxfile.getAirlines_Codes().find(comp)->second)->second.getName() << endl;
            }
            cout << "===========================================================" << endl;
            wait();

        }

    }
    else {

        vector<int> voo = help.bfs_me(origem, destino);

        if(voo.empty()){
            clearScreen();
            cout << "===========================================================" << endl;
            cout << "Nao existe voo entre os aeroportos indicados usando estas companhias: " << endl;
            cout << endl;
            cout << "Aeroporto de Origem: ["<< auxfile.getAirports().find(origem)->second.getCode() << "] - " << auxfile.getAirports().find(origem)->second.getName() << endl;
            cout << "Aeroporto de Destino: ["<< auxfile.getAirports().find(destino)->second.getCode() << "] - " << auxfile.getAirports().find(destino)->second.getName() << endl;
            cout << endl;
            cout << "===========================================================" << endl;
            wait();

        }
        else{

            clearScreen();
            cout << "===========================================================" << endl;
            cout << "Aeroporto de Origem: [" << auxfile.getAirports().find(origem)->second.getCode() << "] - "
                 << auxfile.getAirports().find(origem)->second.getName() << endl;
            cout << "Aeroporto de Destino: [" << auxfile.getAirports().find(destino)->second.getCode() << "] - "
                 << auxfile.getAirports().find(destino)->second.getName() << endl;
            cout << endl;
            cout << "Um dos caminhos possiveis sem companhias especificas:" << endl;
            cout << endl;
            cout << auxfile.getAirports().find(origem)->second.getCode() << " -> ";
            for (int i = (int) voo.size() - 1; i >= 0; i--) {
                if (i == 0) {
                    cout << auxfile.getAirports().find(destino)->second.getCode() << endl;
                } else {
                    cout << auxfile.getAirports().find(voo[i])->second.getCode() << " -> ";
                }
            }
            cout << "===========================================================" << endl;

            wait();
        }
    }
}




// Funcoes de clear screen e wait
void clearScreen() {
    for (int i = 0; i < 50; i++) {
        cout << endl;
    }
}

void wait() {
    cout << endl;
    int c; do c = getchar(); while ((c != '\n') && (c != EOF));
    cout << "Pressione ENTER para continuar...";
    cout << endl;
    do{ c = getchar(); }while ((c != '\n') && (c != EOF));
}
