#pragma once
#include <string>
#include "Graph.h"
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;


static class Pathfinder {

public:

	static vector<char> breadth_first_search(Graph graph, char start, char goal) {
		
		vector<char> path;
		bool reached_goal = false;


		queue<char> frontier;
		frontier.push(start);

		unordered_map<char, char> came_from;
		came_from[start] = start;

		while (!frontier.empty()) {
			
			// set current to the first location in the frontier.
			char current = frontier.front();
			frontier.pop();

			if (current == goal) {
				reached_goal = true;
				break;
			}

			// Add neighbors to the frontier, and also sets where they came from to the came_from map 
			for (char next : graph.neighbors(current)) {
				if (came_from.find(next) == came_from.end()) {
					frontier.push(next);
					came_from[next] = current;
				}
			}

		}

		if (reached_goal) {
			vector<char> reverse_path;
			reverse_path.emplace_back(goal);
			char current_reached = came_from[goal];
			while (current_reached != start) {
				reverse_path.emplace_back(current_reached);
				current_reached = came_from[current_reached];
			}

			reverse_path.emplace_back(start);

			for (int i = reverse_path.size() - 1; i >= 0; i--) {
				path.emplace_back(reverse_path[i]);
			}
		}


		return path;
	}
};
