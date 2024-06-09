#include "Graph.h"

Graph::Graph(unordered_map<char, vector<edge>> edges)
	: _edges(edges) {
}

vector<edge> Graph::neighbors(char id) {
	return _edges[id];
}

void Graph::print() {

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