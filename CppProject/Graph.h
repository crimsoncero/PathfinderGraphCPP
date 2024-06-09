#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

class Graph {
private:
	unordered_map<char, vector<char>> _edges;

public:

	Graph(unordered_map<char, vector<char>> edges)
		: _edges(edges) {
	}

	vector<char> neighbors(char id) {
		return _edges[id];
	}
};