#include "DepthFirstSearch.h"

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