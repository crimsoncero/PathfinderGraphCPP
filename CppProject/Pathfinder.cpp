#include "Pathfinder.h"

vector<char> Pathfinder::breadth_first_search(Graph graph, char start, char goal) {

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
		for (edge next : graph.neighbors(current)) {
			if (came_from.find(next.to) == came_from.end()) {
				frontier.push(next.to);
				came_from[next.to] = current;
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


vector<char> Pathfinder::dijkstra_search(Graph graph, char start, char goal) {

	vector<char> path;
	bool reached_goal = false;


	PriorityQueue<char, int> frontier;
	frontier.put(start, 0);

	unordered_map<char, char> came_from;
	came_from[start] = start;

	unordered_map<char, int> cost_so_far;
	cost_so_far[start] = 0;

	while (!frontier.empty()) {

		// set current to the first location in the frontier.
		char current = frontier.get();

		if (current == goal) {
			reached_goal = true;
			break;
		}

		// Add neighbors to the frontier, and also sets where they came from to the came_from map 
		for (edge next : graph.neighbors(current)) {
			// calculate new cost.
			int new_cost = cost_so_far[current] + next.cost;

			// check if the new location is missing or got better cost.
			if (cost_so_far.find(next.to) == cost_so_far.end()
				|| new_cost < cost_so_far[next.to]) {
				cost_so_far[next.to] = new_cost;
				came_from[next.to] = current;
				frontier.put(next.to, new_cost);
			}
		}

	}

	if (reached_goal) {
		path = reconstruct_path(start, goal, came_from);
	}


	return path;
}



vector<char> Pathfinder::reconstruct_path(char start, char goal, unordered_map<char, char> came_from) {

	vector<char> path;
	path.emplace_back(goal);
	char current_reached = came_from[goal];
	while (current_reached != start) {
		path.emplace_back(current_reached);
		current_reached = came_from[current_reached];
	}

	path.emplace_back(start);
	reverse(path.begin(), path.end());

	return path;

}