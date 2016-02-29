#ifndef GRAPH_LOADER_H
#define GRAPH_LOADER_H

#include <string>
#include <functional>
#include <memory>

class Graph;
struct GraphData;

using NodeDataLoader = std::function<GraphData*(const std::string&)>;

void loadGraph(Graph& graph, const std::string& filename, 
	NodeDataLoader nodeDataLoader=[](const std::string&){return nullptr;});
void loadEdge(const std::string& line, int idxEdgeSeparator, Graph& graph);
void loadNode(const std::string& line, Graph& graph, NodeDataLoader nodeDataLoader);

#endif