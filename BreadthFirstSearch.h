#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H

#include "Traversal.h"

#include <unordered_map>

//Base class for algorithms that need breadth first traversal
class BreadthFirstSearch : public Traversal
{
protected:
	int getNext();
};

#endif