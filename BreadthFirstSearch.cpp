#include "BreadthFirstSearch.h"

#include <algorithm>
#include <iostream>

//This is the difference between breadth first traversal and depth first traversal
//Breadth first uses FIFO processing. The nodes are placed into a queue to be evaluated which
// ensures that the search radiates out, evaluating the closest nodes first.
// While depth first operates on a FILO basis, and the nodes are placed on a stack, ensuring that the newest
// nodes are evaluated first
int BreadthFirstSearch::getNext()
{
	if (m_unprocessed.size() > 0)
	{
		int top = m_unprocessed.front();
		m_unprocessed.erase(m_unprocessed.begin());
		return top;
	}
	else 
		return -1; //finished
}

void ShortestPathFinder::seen(int id, int parent)
{
	m_parents[id] = parent; 
}

void ShortestPathFinder::dumpParents() const
{
	for (auto it : m_parents)
	{
		std::cout << "Node: " << it.first << " Parent: " << it.second << std::endl;
	}
}

std::vector<int> ShortestPathFinder::getTargetPath(int target) const
{
	std::vector<int> path;

	if (!isTargetFound(target))
		return path;

	path.push_back(target);
	int current = target;
	
	while (true)
	{
		NodeMap::const_iterator it = m_parents.find(current);

		if (it == m_parents.end())
			break;
		
		current = it->second;
		path.push_back(current);
	}

	std::reverse(path.begin(), path.end());

	return path;
}