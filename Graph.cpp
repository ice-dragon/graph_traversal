#include "Graph.h"

#include <iostream>

void Graph::addNode(const GraphNode& graphNode)
{
	m_nodes[graphNode.id] = graphNode;
}

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

void Graph::traverse(int idStart, TraversalFunction func)
{
	int idCurrent = idStart;
	int idPrevious = 0;

	while (idCurrent != -1)
	{
		NodeMap::iterator it = m_nodes.find(idCurrent);
		if (it == m_nodes.end())
		{
			std::cout << "Traversal Error: Couldn't find node (" << idCurrent << ") from (" << idPrevious << ")" << std::endl;
			return;
		}
		idPrevious = idCurrent;
		idCurrent = func(it->second);
	}
}

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