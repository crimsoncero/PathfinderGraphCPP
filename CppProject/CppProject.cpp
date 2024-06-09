// CppProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"
#include "Pathfinder.h"

using namespace std;

int main() {

    unordered_map<char, vector<char>> map{
        {'A', {'B'}},
        {'B', {'C'}},
        {'C', {'B', 'D', 'F'}},
        {'D', {'C', 'E'}},
        {'E', {'F'}},
        {'F', {}},
    };

    Graph graph(map);

    vector<char> path = Pathfinder::breadth_first_search(graph, 'A', 'D');

    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " => ";
        }

    }



}