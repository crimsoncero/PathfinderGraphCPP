#include "Graph.h"

Graph::Graph(unordered_map<char, vector<edge>> edges)
	: _edges(edges) {
}

vector<edge> Graph::neighbors(char id) {
	return _edges[id];
}

bool Graph::isNodeValid(char node)
{
	if (_edges.find(node) == _edges.end())
		return false;
	else
		return true;
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

void Graph::printNodes()
{
	bool flag = true;
	
	cout << "The nodes in the graph are: ";

	for (auto n : _edges) {
		if (flag == true) {
			cout << n.first;
			flag = false;
		}
		else {
			cout << ", " << n.first;
		}
	}

	cout << endl;
}
