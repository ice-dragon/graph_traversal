#include "Graph.h"
#include "DepthFirstSearch.h"
#include "BreadthFirstSearch.h"
#include "GraphNode.h"
#include "GraphLoader.h"

#include <vector>
#include <assert.h>
#include <functional>
#include <iostream>

void TestShortestPath(Graph&);
void TestCycleFinder(Graph&);
void TestCycleFinderOnNonCyclicGraph();
void TestGraphLoader(Graph&);
void CreateTestGraph(Graph&);
void CreateNonCycleGraph(Graph&);

int main()
{
	Graph testGraph;
	CreateTestGraph(testGraph);
	
	TestShortestPath(testGraph);

	TestCycleFinder(testGraph);

	TestCycleFinderOnNonCyclicGraph();

	TestGraphLoader(testGraph);
	
	std::cout << "All basic tests passed" << std::endl;

	return 0;
}

//Shortest path finder should find the shortest path between 1 and 5 which for the test graph is 1, 3, 4, 5
void TestShortestPath(Graph& testGraph)
{
	ShortestPathFinder spf(1, -1);

	testGraph.traverse(std::bind(&ShortestPathFinder::traverse, std::ref(spf), std::placeholders::_1));

	assert(spf.isTargetFound(5));

	std::vector<int> path = spf.getTargetPath(5);
	std::vector<int> test_path({1,3,4,5});

	assert(path.size() == test_path.size());

	for (int i = 0; i < path.size(); ++i)
	{
		assert(path[i] == test_path[i]);
	}
}

//Cycle finder should find a cycle in the test graph
void TestCycleFinder(Graph& testGraph)
{
	CycleFinder cf(1, -1);

	testGraph.traverse(std::bind(&CycleFinder::traverse, std::ref(cf), std::placeholders::_1));

	assert(cf.isCycle());
}

//Cycle finder shouldn't find a cycle in the non cyclic graph
void TestCycleFinderOnNonCyclicGraph()
{
	Graph nonCycleGraph;
	CreateNonCycleGraph(nonCycleGraph);

	CycleFinder cfNonCycle(1, -1);

	nonCycleGraph.traverse(std::bind(&CycleFinder::traverse, std::ref(cfNonCycle), std::placeholders::_1));

	assert(!cfNonCycle.isCycle());
}

//load graph should produce a graph which is the same as the test graph from graph_data.txt
void TestGraphLoader(Graph& testGraph)
{
	Graph loadedGraph;
	loadGraph(loadedGraph, "./graph_data.txt");

	assert(testGraph == loadedGraph);
}

void CreateTestGraph(Graph& testGraph)
{
	for (int i = 1; i < 6; ++i)
	{
		testGraph.addNode(GraphNode(i, nullptr));
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
		nonCycleGraph.addNode(GraphNode(i, nullptr));
	}

	nonCycleGraph.addEdge(1, 2);
	nonCycleGraph.addEdge(1, 3);
	nonCycleGraph.addEdge(2, 4);
	nonCycleGraph.addEdge(2, 5);
}