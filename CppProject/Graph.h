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

	Graph(unordered_map<char, vector<edge>> edges)
		: _edges(edges) {
	}

	vector<edge> neighbors(char id) {
		return _edges[id];
	}


	void print() {

		cout << "Graph Nodes:\n";
		
		for (auto n : _edges) {
			cout << n.first << ", ";
		}

		cout << "\n\n" << "Graph Edges:";

		for (auto n : _edges) {
			cout << "\nFrom Node " << n.first << ":\n";
			if (n.second.size() == 0) {
				cout << "No edges\n";
				continue;
			}
			for (edge e : n.second) {
				e.print();
				cout << '\n';
			}
		}
	}
};