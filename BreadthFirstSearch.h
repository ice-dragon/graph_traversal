#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include "Traversal.h"

#include <unordered_map>

class BreadthFirstSearch : public Traversal
{
protected:
	int getNext();
};

class ShortestPathFinder : public BreadthFirstSearch
{
public:
	//Can use -1 to get the entire graph tree
	ShortestPathFinder(int target) : m_target(target) {}

	bool isTargetFound(int target) const { return m_parents.find(target) != m_parents.end(); }
	std::vector<int> getTargetPath(int target) const;
	void dumpParents() const;

protected:
	void seen(int id, int parent);
	bool finished() { return isTargetFound(m_target); }

private:
	using NodeMap = std::unordered_map<int, int>;
	NodeMap m_parents;

	int m_target;
};

#endif