#include "Traversal.h"

#include "GraphNode.h"


int Traversal::traverse(const GraphNode& node)
{
	//add connections if not seen 
	for (auto i : node.edges)
	{
		if (m_seen.find(i) == m_seen.end())
		{
			m_seen.insert(i);
			m_unprocessed.push_back(i);
			seen(i, node.id);
		}
		else
		{
			alreadySeen(i);
		}
	}

	if (finished())
		return -1;

	int next = getNext();
	return next;
}