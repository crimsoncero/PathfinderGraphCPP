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
	
public:
	PathfinderApp();
	int Run();


};

