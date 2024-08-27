#include "PathfinderApp.h"

int PathfinderApp::ImportGraph()
{
	string path = "";
	end_codes endCode = failure;
	
	PrintFileRules();


	while (endCode != success) {
		cout << "Please enter the path to the graph file. Make sure to use an extra '\\' before every '\\':\n";
		path = "";
		cin >> path;
		_graph = _graphBuilder.from_csv(path, endCode);

		if (endCode == failure) {
			string input = "";
			cout << "1. Try Again\n" << "2. Return\n";
			cin >> input;
			_graphDefined = false;

			if (input == "2")
				return 1;
		}
		if (endCode == partialSuccess) {
			string input = "";
			cout << "1. Continue with errors\n" << "2. Try Again\n" << "3. Return\n";
			cin >> input;
			_graphDefined = false;
			
			if (input == "1")
				endCode = success;
			if (input == "3")
				return 1;
		}
	}

	if(endCode == success)
		_graphDefined = true;
	return 0;
}

int PathfinderApp::ViewGraph()
{
	if (!_graphDefined)
		return 1;

	_graph.print();

	return 0;
}

/// <summary>
/// Prompts the user to look for a path in the graph.
/// </summary>
/// <returns>0 - Valid operation, 1 - No graph defined, 2 - Non valid arguments entered.</returns>
int PathfinderApp::FindPath()
{
	if (!_graphDefined) {
		cout << "You must first define a graph.\n";
		return 1;
	}

	_graph.printNodes();

	char from, to;
	cout << "Enter From Node and To Node:\n";
	cout << "From: ";
	cin >> from;
	cout << "To: ";
	cin >> to;

	// Check if the nodes are valid.
	if (!_graph.isNodeValid(from)) {
		cout << "Node doesn't exist!\n";
		return 2;
	}

	if (!_graph.isNodeValid(to)) {
		cout << "Node doesn't exist!\n";
		return 2;
	}


	vector<char> path = _pathfinder.dijkstra_search(_graph, from, to);

	if (path.size() > 0) {
		
		cout << "The best path from " << from << " to " << to << "is: \n";
		
		PrintPath(path);
		cout << "\n";
		
		return 0;
	}
	

	cout << "No path between " << from << " and " << to << " was found.\n";
	return 0;

	
}


void PathfinderApp::PrintFileRules()
{
	cout << "GUIDELINES FOR GRAPH FILE IMPORT" << endl;
	cout << "1. Nodes are represented by a single character from A to Z, capital letters only." << endl;
	cout << "2. Define the nodes in the graph in the first row. fe - \"A,E,G,\"" << endl;
	cout << "3. Define each edge in a row after the first one using three elements: Node, Node, Cost. fe - \"A,E,3\"" << endl;
	cout << "4. Invalid entries or duplicates will be skipped" << endl;

}
void PathfinderApp::PrintPath(vector<char> path)
{
	for (int i = 0; i < path.size(); i++) {
		cout << path[i];
		if (i < path.size() - 1) {
			cout << " => ";
		}
	}
}
;

PathfinderApp::PathfinderApp()
	: _graphBuilder(), _pathfinder(), _graphDefined(false)
{
}
int PathfinderApp::Run()
{
	string input = "";
	while (true) {
		cout << "Actions:\n";
		cout << "1. Build Graph\n";
		cout << "2. View Graph\n";
		cout << "3. Find Path\n";
		cout << "4. Exit\n";

		cout << "Enter Action Number: ";
		cin >> input;
		int inputNum = stoi(input);
		switch (inputNum) {
		case 1: 
			ImportGraph();
			break;
		case 2: 
			if (!_graphDefined)
				cout << "Graph not defined yet!\n";
			else
				ViewGraph();
			break;
		case 3:
			if (!_graphDefined)
				cout << "Graph not defined yet!\n";
			else
				FindPath();
			break;
		case 4:
			cout << "Goodbye!\n";
			return 0;
			break;
		default:
			cout << "Not a valid action input.\n";
		}
	}

	return 0;
}
;

