/**
 * @file Graph.h
 * @author
 * @brief
 * @version 0.1
 * @date 2023-01-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef AED_PROJETO_2_GRAPH_H
#define AED_PROJETO_2_GRAPH_H
#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <stack>
using namespace std;


class Graph {
public:
    /**
     * @brief Struct que representa uma aresta do grafo
     * Contém o vértice de destino, o peso da aresta e um set de companhias aéreas que realizam voos nessa aresta
     */
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
        set<string> airlines;
    };

    /**
    * @brief Struct que representa um node do grafo
    * Contém uma lista de arestas que saem desse node
    * um booleano que indica se o node já foi visitado
    * um inteiro que indica a distância do node ao node
     * de origem da pesquisa
    */

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        int distance;
        bool in_stack;
        int num;
        int low;
    };

    int n;

    vector<Node> nodes;
    /** Default Constructor
   * @brief
   * Complexidade O(1)
   */
    Graph();
    /**
     * @brief
     * Complexidade O(1)
     * Constructor
    * @param nodes Número de nós
       */
    explicit Graph(int nodes);
    /**
     * @brief
     * Complexidade O(|V|+|E|)
     * Função que realiza uma pesquisa em largura no grafo e retorna um vetor com o caminho com menos escalas entre dois nós
 * @param origem Nó de origem
 * @param destino Nó de destino
 * @return Vector com os caminhos com menos escalas realizadas entre o nó de origem e o nó de destino

 */

    void addEdge(int src, int dest, string companhia, int weight = 1);

    vector<int> bfs_me(int origem, int destino);
    /**
     * @brief
     * Complexidade O(|V|+|E|)
     * Função que realiza uma pesquisa em largura no grafo e retorna um vetor com o caminho com menos escalas entre dois nós, passando por companhias aéreas específicas
 * @param origem Nó de origem
 * @param destino Nó de destino
 * @param companhias Set de companhias aéreas
 * @return Vector com os caminhos com menos escalas realizadas entre o nó de origem e o nó de destino

 */
    vector<int> bfs_airlines(int origem, int destino, const set<string>& companhias);
    /**
     *@brief
     * Complexidade O(|V|+|E|)
     * Função que realiza uma pesquisa em profundidade no grafo e retorna um set com os pontos de articulação
 * @param v Nó de origem
 * @param index Número de nós visitados
 * @param num Vector com o número de nós visitados
 * @param low Vector com o menor número de nós visitados
 * @param s Stack com os nós visitados
 * @param ap Set com os nós de articulação
 * @param first Booleano que indica se é a primeira chamada à função

 */
    void dfs_art(int v, int index, vector<int>& num, vector<int>& low, stack<int>& s, set<int>& ap, bool first);
    /**
    * @brief
    * Complexidade O(|V|+|E|)
    * Função que retorna um set com os pontos de articulação
     * @return Set com os pontos de articulação

    */
    set<int> getArticulationPoints();
    /**
     * @brief
     * Complexidade O(|V|+|E|)
     * Função que realiza uma pesquisa em profundidade no grafo e retorna um inteiro com o número de componentes fortemente conexos
    * @param v Nó de origem
    * @param index Número de nós visitados
    * @return Número de componentes fortemente conexos
     */
    int dfs_scc(int v, int index);
    /**
    *  @brief
    *  Complexidade O(|V|+|E|)
    *  Função que realiza uma pesquisa em profundidade no grafo e retorna um inteiro com o número de componentes fortemente conexos
* @param v Nó de origem
* @param index Número de nós visitados
* @param node_stack Stack com os nós visitados
* @param answer Lista de listas com os nós visitados

*/
    void dfs_scc2(int v, int index, stack<int> *node_stack, list<list<int>> *answer);
    /**
     * @brief
     * Função que realiza uma pesquisa em largura no grafo
     * Complexidade O(|V|+|E|)
    * @param a Nó de origem
    */
    void bfs(int a);
    /**
    * @brief
     * Função que retorna o diâmetro do grafo
     * Complexidade O(|V|+|E|)
      * @return Diâmetro do grafo
    */
    int diametro();
    /**
    * @brief
     *   Função que realiza uma
     *    pesquisa em largura no grafo e
     *    retorna a distância máxima entre um nó e os restantes nós
     *   Complexidade O(|V|+|E|)
     * @param a Nó de origem
    * @return Distância máxima entre um nó e os restantes nós
    */
    int bfs_max_distance(int a);

};


#endif //AED_PROJETO_2_GRAPH_H
