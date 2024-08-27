#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class edge {
public:
	char from;
	char to;
	int cost;

	edge(char from, char to, int cost)
		: from(from), to(to), cost(cost) {
	} 

	void print() {
		cout << from << " => " << to << '(' << cost << ')';
	}
};

class Graph {
private:
	unordered_map<char, vector<edge>> _edges;

public:
	Graph() {};
	Graph(unordered_map<char, vector<edge>> edges);
	vector<edge> neighbors(char id);
	bool isNodeValid(char node);
	void print();
	void printNodes();
};