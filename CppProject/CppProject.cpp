// CppProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"
#include "Pathfinder.h"

using namespace std;

int main() {


    


    unordered_map<char, vector<edge>> map{
        {'A', {edge('A','B',2)}},
        {'B', {edge('B','C',4)}},
        {'C', {edge('C','B',4), edge('C','D',3), edge('C','F',10)}},
        {'D', {edge('D','C',3), edge('D','E',2)}},
        {'E', {edge('E','F',1)}},
        {'F', {}},
    };



    Graph graph(map);

    graph.print();
    cout << '\n';
    vector<char> path = Pathfinder::dijkstra_search(graph, 'A', 'F');

    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " => ";
        }

    }


}