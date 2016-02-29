#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <vector>
#include <memory>

struct GraphData
{
	virtual ~GraphData() = 0;
};

//A Node in the graph
//Each node has an id, a list of edges and optionally some data

struct GraphNode
{
	GraphNode() {}
	GraphNode(int nodeId, GraphData* nodeData) : id(nodeId), data(nodeData) {}
	
	//Valid ids are positive integers. -1 is the finished id and 0 is the initial id
	int id = -1;
	std::shared_ptr<GraphData> data;

	std::vector<int> edges;

	//A node is equal if the id is equal
	//and the edges are the same.
	//At the moment I'm not worried about data equality. 
	//If I need to I'll add a data comparison functor
	bool operator==(const GraphNode& rhs) const 
	{
		if (id != rhs.id)
			return false;
		if (edges.size() != rhs.edges.size())
			return false;

		for (int i = 0; i < edges.size(); ++i)
		{
			if (edges[i] != rhs.edges[i])
				return false;
		}

		return true;
	}

	bool operator!=(const GraphNode& rhs) const
	{
		return !(*this == rhs);
	}
};

#endif