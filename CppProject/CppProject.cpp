// CppProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"
#include "GraphBuilder.h"
#include "Pathfinder.h"


using namespace std;

int main() {

    GraphBuilder gb;
    Pathfinder pf;

    end_codes code; 
    Graph graph = gb.from_csv("C:\\Users\\crims\\Projects\\CppProject\\CppProject\\graph.csv", code);

    switch (code) {
    case success: 
        cout << "Graph Building Success!\n";
        graph.print();
        break;
    case failure:
        cout << "Graph Building Failure!\n";
        break;
    }



    char from, to;
    cout << "From: ";
    cin >> from;
    cout << "To: ";
    cin >> to;

    vector<char> path = pf.dijkstra_search(graph, from, to);

    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " => ";
        }

    }


}