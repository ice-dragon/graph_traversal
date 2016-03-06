#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H

#include "Traversal.h"

//Base class for Depth first traversal algorithms
class DepthFirstSearch : public Traversal
{
protected:
	int getNext();
};

#endif