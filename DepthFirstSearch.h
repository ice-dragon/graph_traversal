#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H

#include "Traversal.h"

class DepthFirstSearch : public Traversal
{
protected:
	int getNext();
};

class CycleFinder : public DepthFirstSearch
{
public:
	bool isCycle() { return m_isCycle; }
protected:
	void alreadySeen(int id) { m_isCycle = true; }
private:
	bool m_isCycle = false;
};

#endif