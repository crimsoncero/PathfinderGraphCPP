#pragma once
#include "Graph.h"
#include <fstream>
#include <string>
using namespace std;


enum end_codes {
	success = 0,
	failure = 1
};

class GraphBuilder {
public:
	GraphBuilder() {};
	Graph from_csv(string file_path, end_codes& end_code);
	pair<char, vector<edge>> parse_node(string node_csv);

};

