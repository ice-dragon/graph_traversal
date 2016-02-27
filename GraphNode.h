#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <vector>
#include <memory>

struct GraphData
{
	virtual ~GraphData() = 0;
};

struct GraphNode
{
	GraphNode() {}
	GraphNode(int nodeId, std::shared_ptr<GraphData> nodeData) : id(nodeId), data(nodeData) {}

	int id = -1;
	std::shared_ptr<GraphData> data;

	std::vector<int> edges;

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