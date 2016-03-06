#include "BreadthFirstSearch.h"

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
