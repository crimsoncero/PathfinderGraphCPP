#include "GraphBuilder.h"



Graph GraphBuilder::from_csv(string file_path, end_codes& end_code) {
	fstream file;
	unordered_map<char, vector<edge>> map;
	string line = "";
	Graph error_graph;

	cout << "Building Graph" << '\n';
	file.open(file_path);
	if (!file.is_open()) {
		cout << "Invalid path!" << '\n';
	}
	else {
		cout << "Valid path" << '\n';
		int row = 0;
		while (getline(file, line)) 
		{
			cout << "Parsing row " << row << "..." << '\n';
			pair<char, vector<edge>> node_pair = parse_node(line);
			if (node_pair.first == '*') {
				cout << "Parsing row " << row << " failed" << '\n';
				end_code = failure;
				return error_graph;
			}
			
			cout << "Parsing row " << row << " succeded" << '\n';
			
			// check if a node exist in the map already
			if (map.find(node_pair.first) == map.end()) {
				map[node_pair.first] = node_pair.second;
			}
			else {
				cout << "Node already exist in the graph\n";
				cout << "Parsing row " << row << " failed" << '\n';
				end_code = failure;
				return error_graph;
			}
			row++;
		}

		file.close();
	}


	end_code = success;
	Graph graph(map);
	return graph;

}

pair<char, vector<edge>> GraphBuilder::parse_node(string node_csv)
{
	char node_name = ' ';
	vector<edge> edges;
	pair<char, vector<edge>> node;
	
	node.first = '*'; // For checking errors, if still * then the methods ended prematurly

	int index = 0;

	if (node_csv.size() == 0) {
		cout << "Line is empty" << '\n';
		return node;
	}


	string w = "";
	for (int i = 0; i < node_csv.size(); i++) {
		if (node_csv[i] == ',') {
			// Node case:
			if (index == 0) {
				// Node is one character long.
				if (w.size() != 1) {
					cout << "Node name must only be a single char!" << '\n';
					return node;
				}
				char n = w[0];
				if (n < 'A' || n > 'Z') {
					cout << "Node name can only be a letter from A to Z (uppercase only)" << '\n';
					return node;
				}
				node_name = n;
			}
			// Edge case:
			else {
				if (w.size() < 2) {
					// At minimum edge has two parameters - name(char) and number;
					cout << "Edge paramaters are missing at edge index " << index << '\n';
					return node;
				}
				
				char e_name = w[0];
				int cost = 0;
				string cost_string = w.substr(1);
				try {
					cost = stoi(cost_string);
				}
				catch (exception e) {
					cout << "Invalid parsing of cost for edge to " << e_name << " at index " << index << '\n';
					return node;
				}

				if (e_name == node_name) {
					cout << "Self pointing edge at index " << index << '\n';
					return node;
				}
				
				edge edge(node_name, e_name, cost);
				edges.emplace_back(edge);
			}

			w = "";
			index++;
		}
		else {
			// Create the comma seperated value.
			w += node_csv[i];
		}
	}

	node.first = node_name;
	node.second = edges;
	return node;
}
