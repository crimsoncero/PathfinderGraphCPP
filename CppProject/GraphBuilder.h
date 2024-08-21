#pragma once
#include "Graph.h"
#include <fstream>
#include <string>
using namespace std;


enum end_codes {
	success = 0,
	failure = 1,
	partialSuccess = 2,
};

class GraphBuilder {
public:
	GraphBuilder() {};
	Graph from_csv(string file_path, end_codes& end_code);


	bool does_edge_exist(edge new_edge, unordered_map< char, vector<edge>> map);
};

