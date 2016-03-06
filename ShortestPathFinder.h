#ifndef SHORTEST_PATH_FINDER_H
#define SHORTEST_PATH_FINDER_H

#include "BreadthFirstSearch.h"

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