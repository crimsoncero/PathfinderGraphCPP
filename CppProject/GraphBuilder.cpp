#include "GraphBuilder.h"



Graph GraphBuilder::from_csv(string file_path, end_codes& end_code) {
	fstream file;
	unordered_map<char, vector<edge>> map;
	string line = "";
	Graph error_graph;
	end_code = success;

	cout << "Building Graph" << '\n';
	file.open(file_path);
	if (!file.is_open()) {
		cout << "Invalid path!" << '\n';
		end_code = failure;
	}
	else {
		cout << "Valid path" << '\n';
		int row = 0;
		while (getline(file, line)) 
		{
			if (row == 0) {
				// Parse Nodes to the map
				cout << "Parsing nodes..." << '\n';
				string w = "";
				for (int i = 0; i < line.size(); i++) {
					if (line[i] == ',') {
						if (w.size() > 1) {
							cout << "Invalid Node " << w << " Node Skipped" << ": Not a char" << '\n';
							end_code = partialSuccess;
						}
						else if (w[0] > 'Z' || w[0] < 'A') {
							cout << "Invalid Node " << w << " Node Skipped" << ": Not between A - Z" << '\n';
							end_code = partialSuccess;
						}
						else if (map.find(w[0]) != map.end()) {
							cout << "Invalid Node " << w << " Node Skipped" << ": Already defined" << '\n';
							end_code = partialSuccess;
						}
						else {
							vector<edge> edges;
							map[w[0]] = edges;
						}

						w = "";
					}
					else {
						w += line[i];
					}
				}
			}
			else {
				// Parse Edge
				cout << "Parsing edge " << row << "..." << '\n';
				string w = "";
				char from = '*';
				char to = '*';
				int cost = 0;

				bool failed = false;

				int col = 0;
				for (int i = 0; i < line.size(); i++) {
					if (line[i] == ',') {
						if (col > 2) {
							failed = true;
						}
						if (col < 2) {
							if (w.size() > 1) {
								cout << "Invalid Node " << w << " Edge Skipped" << ": Node not a char" << '\n';
								failed = true;
							}
							else if (w[0] > 'Z' || w[0] < 'A') {
								cout << "Invalid Node " << w << " Edge Skipped" << ": Node not between A - Z" << '\n';
								failed = true;
							}
							else if (map.find(w[0]) == map.end()) {
								cout << "Invalid Node " << w << " Edge Skipped" << ": Node doesn't Exist" << '\n';
								failed = true;
							}
							else if (col == 0) {
								from = w[0];
							}
							else {
								to = w[0];
							}
						}
						if (col == 2) {
							try {
								cost = stoi(w);
							}
							catch (exception e) {
								cout << "Invalid Cost " << w << " Edge Skipped" << ": Not a number" << '\n';
								failed = true;
							}
						}

						w = "";
						col++;
					}
					else {
						w += line[i];
					}

					

					
				}
				if (failed) {
					end_code = partialSuccess;
				}
				else {
					edge forwardEdge(from, to, cost);
					edge reverseEdge(to, from, cost);

					if (does_edge_exist(forwardEdge, map)) {
						cout << "Edge already exists - skipped" << '\n';
						end_code = partialSuccess;
					}
					else {
						map[forwardEdge.from].emplace_back(forwardEdge);
						map[reverseEdge.from].emplace_back(reverseEdge);
					}
				}

			}
		
			row++;
		}

		file.close();
	}


	Graph graph(map);
	return graph;

}




//pair<char, vector<edge>> GraphBuilder::parse_node(string node_csv)
//{
//	char node_name = ' ';
//	vector<edge> edges;
//	pair<char, vector<edge>> node;
//	
//	node.first = '*'; // For checking errors, if still * then the methods ended prematurly
//
//	int index = 0;
//
//	if (node_csv.size() == 0) {
//		cout << "Line is empty" << '\n';
//		return node;
//	}
//
//
//	string w = "";
//	for (int i = 0; i < node_csv.size(); i++) {
//		if (node_csv[i] == ',') {
//			// Node case:
//			if (index == 0) {
//				// Node is one character long.
//				if (w.size() != 1) {
//					cout << "Node name must only be a single char!" << '\n';
//					return node;
//				}
//				char n = w[0];
//				if (n < 'A' || n > 'Z') {
//					cout << "Node name can only be a letter from A to Z (uppercase only)" << '\n';
//					return node;
//				}
//				node_name = n;
//			}
//			// Edge case:
//			else {
//				if (w.size() < 2) {
//					// At minimum edge has two parameters - name(char) and number;
//					cout << "Edge paramaters are missing at edge index " << index << '\n';
//					return node;
//				}
//				
//				char e_name = w[0];
//				int cost = 0;
//				string cost_string = w.substr(1);
//				try {
//					cost = stoi(cost_string);
//				}
//				catch (exception e) {
//					cout << "Invalid parsing of cost for edge to " << e_name << " at index " << index << '\n';
//					return node;
//				}
//
//				if (e_name == node_name) {
//					cout << "Self pointing edge at index " << index << '\n';
//					return node;
//				}
//				
//				edge edge(node_name, e_name, cost);
//				edges.emplace_back(edge);
//			}
//
//			w = "";
//			index++;
//		}
//		else {
//			// Create the comma seperated value.
//			w += node_csv[i];
//		}
//	}
//	
//
//	node.first = node_name;
//	node.second = edges;
//	return node;
//}

bool GraphBuilder::does_edge_exist(edge new_edge, unordered_map<char, vector<edge>> map)
{

	vector<edge> edges = map[new_edge.from];

	// Check if there is an edge with the same end point;
	for (edge next : edges) {
		if (next.to == new_edge.to) {
			return true;
		}
	}

	// Check for the end node
	edges = map[new_edge.to];
	for (edge next : edges) {
		if (next.to == new_edge.to) {
			return true;
		}
	}

	return false;
}
