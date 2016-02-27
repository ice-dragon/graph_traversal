#include "GraphLoader.h"

#include "Graph.h"
#include "GraphNode.h"

#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>

void loadGraph(Graph& graph, const std::string& filename, NodeDataLoader nodeDataLoader)
{
	std::ifstream file(filename);

	while(file.good())
	{
		std::string line;
		getline(file, line);

		if (line.size() == 0)
			continue;

		//Edges should be in the format of id->id2
		std::size_t idxEdge = line.find("->");
		if (idxEdge != std::string::npos)
			loadEdge(line, idxEdge, graph);
		else
			loadNode(line, graph, nodeDataLoader);
	}
}

void loadEdge(const std::string& line, int idxEdgeSeparator, Graph& graph)
{
	int from = atoi(line.substr(0, idxEdgeSeparator).c_str());
	int to = atoi(line.substr(idxEdgeSeparator+2).c_str());

	if (from <= 0 || to <= 0)
	{
		std::cout << "Ids in edge weren't positive: " << line << std::endl;
		return; //ids must be positive integers.
	}

	graph.addEdge(from, to);
}

void loadNode(const std::string& line, Graph& graph, NodeDataLoader nodeDataLoader)
{
	if (line.size() == 0)
		return; //don't process blank lines

	//Otherwise for a node definition the format should be: id<space>data
	std::size_t idx = line.find(' ');

	std::string nodeId = line.substr(0, idx);
	if (nodeId.size() == 0)
	{
		std::cout << "Line started with a space: " << line << std::endl;
		return; //Space occured at start of line, not valid
	}

	if (!std::all_of(nodeId.begin(), nodeId.end(), [](char c) {return std::isdigit(c);}) )
	{
		std::cout << "First word isn't a number: " << line << std::endl;
		return; 	//Invalid. Not a numeric identifier
	}

	int id = atoi(nodeId.c_str());
		
	GraphNode graphNode(id, nodeDataLoader(line.substr(idx+1)));

	graph.addNode(graphNode);
}