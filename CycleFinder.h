#ifndef CYCLE_FINDER_H
#define CYCLE_FINDER_H

#include "DepthFirstSearch.h"

//Finding cycles is a pretty simple task
//If there is a back edge when doing a depth first traversal, 
// there must be a cycle between the target and the initial node.
//So if any node has already been seen there is a cycle.
class CycleFinder : public DepthFirstSearch
{
public:
	CycleFinder(int initial, int target) 
	{ 
		m_initial = initial; 
		m_target = target;
	}

	bool isCycle() { return m_isCycle; }
protected:
	void alreadySeen(int id, int parent) { m_isCycle = true; }
private:
	bool m_isCycle = false;
};

#endif