#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include <unordered_set>
#include <vector>

struct GraphNode;

//Base class for traversal algorithms, contains the basics of the traversal algorithm
//Maintains a list of seen and unprocessed nodes and adds unseen nodes to the unprocessed list
// as they are found in the nodes handed it by the graph.
//The derived classes determine what node is processed next and extract any info about the nodes processed
//as the traversal discovers nodes
class Traversal
{
public:
	virtual ~Traversal() {}
	int traverse(const GraphNode& node);

protected:
	virtual void seen(int id, int parent) {}
	virtual void alreadySeen(int id, int parent) {}

	virtual int getNext() = 0;

	using NodeSet = std::unordered_set<int>;
	using NodeQueue = std::vector<int>;

	NodeSet m_seen;
	NodeQueue m_unprocessed;
	int m_initial; //What to return if provided a current id of 0
	int m_target; //when to stop
};

#endif