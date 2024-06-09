#pragma once
#include "Graph.h"
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>
#include "PriorityQueue.h"
using namespace std;


class Pathfinder {

public:
	Pathfinder() {};
	vector<char> reconstruct_path(char start, char goal, unordered_map<char, char> came_from);

	vector<char> breadth_first_search(Graph graph, char start, char goal);

	vector<char> dijkstra_search(Graph graph, char start, char goal);

	
};
