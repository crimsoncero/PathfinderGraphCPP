#pragma once
#include "Graph.h"
#include "Pathfinder.h"
#include "GraphBuilder.h"

class PathfinderApp
{
private:
	Graph _graph;
	Pathfinder _pathfinder;
	GraphBuilder _graphBuilder;
	bool _graphDefined;

	int ImportGraph();
	int ViewGraph();
	int FindPath();
	void PrintFileRules();
	void PrintPath(vector<char> path);
	
public:
	PathfinderApp();
	int Run();


};

