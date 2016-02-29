#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"

#include <functional>
#include <unordered_map>


//A Function that takes a graph Node and returns a node id for the next node
//Receiving a node with id 0 should return the initial node id
//Should return -1 when finished
using TraversalFunction = std::function<int(const GraphNode&)>;

using NodeMap = std::unordered_map<int, GraphNode>;

class Graph
{
public:
	void addNode(const GraphNode& graphNode);
	void addEdge(int id, int idTo);

	void traverse(TraversalFunction function) const;

	bool operator==(const Graph& rhs) const;
private:
	NodeMap m_nodes;
};

#endif