#include "DepthFirstSearch.h"

//This is the difference between breadth first traversal and depth first traversal
//Depth first operates on a FILO basis. The nodes are placed on a stack, ensuring that the newest
// nodes are evaluated first
//For this implementation that means that we remove from the back
int DepthFirstSearch::getNext()
{
	if (m_unprocessed.size() > 0)
	{
		int next = m_unprocessed.back();
		m_unprocessed.pop_back();
		return next;
	}
	else 
		return -1; //No more to process
}