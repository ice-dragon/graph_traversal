#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include <unordered_set>
#include <vector>

struct GraphNode;

class Traversal
{
public:
	virtual ~Traversal() {}
	int traverse(const GraphNode& node);

protected:
	virtual void seen(int id, int parent) {}
	virtual void alreadySeen(int id) {}

	virtual bool finished() { return false;}
	virtual int getNext() = 0;

	using NodeSet = std::unordered_set<int>;
	using NodeQueue = std::vector<int>;

	NodeSet m_seen;
	NodeQueue m_unprocessed;
};

#endif