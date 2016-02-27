#include "Graph.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "GraphNode.h"
#include "GraphLoader.h"

#include <vector>
#include <assert.h>
#include <functional>
#include <iostream>


void CreateTestGraph(Graph&);
void CreateNonCycleGraph(Graph&);

int main()
{
	Graph testGraph;
	CreateTestGraph(testGraph);
	
	ShortestPathFinder spf(-1);

	testGraph.traverse(1, std::bind(&ShortestPathFinder::traverse, std::ref(spf), std::placeholders::_1));

	assert(spf.isTargetFound(5));

	std::vector<int> path = spf.getTargetPath(5);
	std::vector<int> test_path({1,3,4,5});

	assert(path.size() == test_path.size());

	for (int i = 0; i < path.size(); ++i)
	{
		assert(path[i] == test_path[i]);
	}

	CycleFinder cf;

	testGraph.traverse(1, std::bind(&CycleFinder::traverse, std::ref(cf), std::placeholders::_1));

	assert(cf.isCycle());

	Graph nonCycleGraph;
	CreateNonCycleGraph(nonCycleGraph);

	CycleFinder cfNonCycle;

	nonCycleGraph.traverse(1, std::bind(&CycleFinder::traverse, std::ref(cfNonCycle), std::placeholders::_1));

	assert(!cfNonCycle.isCycle());

	Graph loadedGraph;
	loadGraph(loadedGraph, "./graph_data.txt");

	assert(testGraph == loadedGraph);

	std::cout << "All basic tests passed" << std::endl;
	
	return 0;
}

void CreateTestGraph(Graph& testGraph)
{
	for (int i = 1; i < 6; ++i)
	{
		testGraph.addNode(GraphNode(i, std::shared_ptr<GraphData>(nullptr)));
	}

	testGraph.addEdge(1, 2);
	testGraph.addEdge(1, 3);
	testGraph.addEdge(2, 3);
	testGraph.addEdge(3, 4);
	testGraph.addEdge(4, 5);
}

void CreateNonCycleGraph(Graph& nonCycleGraph)
{
	for (int i = 1; i < 6; ++i)
	{
		nonCycleGraph.addNode(GraphNode(i, std::shared_ptr<GraphData>(nullptr)));
	}

	nonCycleGraph.addEdge(1, 2);
	nonCycleGraph.addEdge(1, 3);
	nonCycleGraph.addEdge(2, 4);
	nonCycleGraph.addEdge(2, 5);
}