#pragma once
#include <string>
#include "Graph.h"
#include <queue>
#include <unordered_set>
#include <iostream>
#include "PriorityQueue.h"
using namespace std;


static class Pathfinder {

public:

	static vector<char> breadth_first_search(Graph graph, char start, char goal);

	static vector<char> dijkstra_search(Graph graph, char start, char goal);

	static vector<char> reconstruct_path(char start, char goal, unordered_map<char, char> came_from);
};
