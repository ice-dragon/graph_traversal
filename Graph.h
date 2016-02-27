#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"

#include <functional>
#include <unordered_map>


//A Function that takes a graph Node and returns a node id for the next node
using TraversalFunction = std::function<int(const GraphNode&)>;
using NodeMap = std::unordered_map<int, GraphNode>;

class Graph
{
public:
	void addNode(const GraphNode& graphNode);
	void addEdge(int id, int idTo);

	void traverse(int idStart, TraversalFunction function);

	bool operator==(const Graph& rhs) const;
private:
	NodeMap m_nodes;
};

#endif