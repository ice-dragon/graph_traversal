#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include "Traversal.h"

#include <unordered_map>

//Base class for algorithms that need breadth first traversal
class BreadthFirstSearch : public Traversal
{
protected:
	int getNext();
};

//Shortest path search algorithm for unweighted graphs
class ShortestPathFinder : public BreadthFirstSearch
{
public:
	//Can use -1 for target to get the entire graph tree
	ShortestPathFinder(int start, int target) 
	{
		m_initial = start; 
		m_target = target; 
	}

	bool isTargetFound(int target) const { return m_parents.find(target) != m_parents.end(); }
	std::vector<int> getTargetPath(int target) const;
	void dumpParents() const;

protected:
	void seen(int id, int parent);

private:
	using NodeMap = std::unordered_map<int, int>;
	NodeMap m_parents;
};

#endif