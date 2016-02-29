#include "BreadthFirstSearch.h"

#include <algorithm>
#include <iostream>

//This is the difference between breadth first traversal and depth first traversal.
//Breadth first uses FIFO processing. The nodes are placed into a queue to be evaluated which
// ensures that the search radiates out, evaluating the closest nodes first.
//For this implementation this means that we remove from the start of the unprocessed list
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

//Store the parent of each node in this traversal so it can be extracted later, to build up a 
// path to the desired node
void ShortestPathFinder::seen(int id, int parent)
{
	m_parents[id] = parent; 
}


//Debugging method, dump all parents to the console
void ShortestPathFinder::dumpParents() const
{
	for (auto it : m_parents)
	{
		std::cout << "Node: " << it.first << " Parent: " << it.second << std::endl;
	}
}


//Extract the target path, given the target.
//As the data we have stored is the parent of each node in relation to our starting node,
// we need to start at the target and work back to the parent and then reverse the path to
// find the shortest path.
std::vector<int> ShortestPathFinder::getTargetPath(int target) const
{
	std::vector<int> path;

	if (!isTargetFound(target))
		return path;

	path.push_back(target);
	int current = target;
	NodeMap::const_iterator it = m_parents.find(current);

	//The initial node isn't actually in the parent's map, as it doesn't have a parent.
	//Therefore not finding the entry means we have found the initial node
	while (it != m_parents.end())
	{
		current = it->second;
		path.push_back(current);

		it = m_parents.find(current);
	}

	std::reverse(path.begin(), path.end());

	return path;
}