#include "Traversal.h"

#include "GraphNode.h"

//Traverse the graph by adding all unseen nodes to a list of unseen nodes
//then asking the derived algorithm for the next node
//Allow the derived algorithm to react to finding nodes whether or not they are 
int Traversal::traverse(const GraphNode& node)
{
	if (node.id == 0)
		return m_initial;
	//add connections to unprocessed if not seen 
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
			alreadySeen(i, node.id);
		}
	}

	if (node.id == m_target)
		return -1;

	int next = getNext();
	return next;
}