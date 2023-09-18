//
// Created by LuisRelvas on 08/01/2023.
//

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

    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
        set<string> airlines;
    };



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

    Graph();

    explicit Graph(int nodes);

    void addEdge(int src, int dest, string companhia, int weight = 1);

    vector<int> bfs_me(int origem, int destino);

    vector<int> bfs_airlines(int origem, int destino, const set<string>& companhias);

    void dfs_art(int v, int index, vector<int>& num, vector<int>& low, stack<int>& s, set<int>& ap, bool first);

    set<int> getArticulationPoints();

    int dfs_scc(int v, int index);

    void dfs_scc2(int v, int index, stack<int> *node_stack, list<list<int>> *answer);

    void bfs(int a);

    int diametro();

    int bfs_max_distance(int a);

};


#endif //AED_PROJETO_2_GRAPH_H
