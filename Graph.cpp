#include "Graph.h"

#include <iostream>

void Graph::addNode(const GraphNode& graphNode)
{
	m_nodes[graphNode.id] = graphNode;
}

//Find the node that the edge starts at and add the end node to its list of nodes it connects to
void Graph::addEdge(int id, int idTo)
{
	NodeMap::iterator it = m_nodes.find(id);
	if (it == m_nodes.end())
	{
		std::cout << "Add Edge Error: Couldn't find start node (" << id << ") in pair (" << id << ", " << idTo << ")" << std::endl;
		return;
	}

	if (m_nodes.find(idTo) == m_nodes.end())
	{
		std::cout << "Add Edge Error: Couldn't find end node (" << idTo << ") in pair (" << id << ", " << idTo << ")" << std::endl;
		return;
	}

	it->second.edges.push_back(idTo);
}

//Using the provided function traverse the graph.
//The function takes a node and returns the next id.
//When passed a node with id of 0 (which is invalid) the function should return the initial node id.
//Then passing each subsequent node that it asks for until it returns a requested node id of -1
void Graph::traverse(TraversalFunction func) const
{
	int idCurrent = func(GraphNode(0, nullptr));
	int idPrevious = 0;//Used for debugging, knowing where the invalid id came from helps a lot
	//Possibly not that useful when the previous represents a leaf, and the algorithm
	//has backtracked, but better than nothing.

	while (idCurrent != -1)
	{
		NodeMap::const_iterator it = m_nodes.find(idCurrent);
		if (it == m_nodes.end())
		{
			std::cout << "Traversal Error: Couldn't find node (" << idCurrent << ") from (" << idPrevious << ")" << std::endl;
			return;
		}
		idPrevious = idCurrent;
		idCurrent = func(it->second);
	}
}

//Compare 2 graphs. They are equal when they have the same number of nodes and each node in order is also equal
bool Graph::operator==(const Graph& rhs) const
{
	if (m_nodes.size() != rhs.m_nodes.size())
		return false;

	NodeMap::const_iterator rhs_it = rhs.m_nodes.begin();
	for (NodeMap::const_iterator it = m_nodes.begin(); it != m_nodes.end(); ++it, ++ rhs_it)
	{

		if (it->first != rhs_it->first || it->second != rhs_it->second)
			return false;
	}

	return true;
}