# graph_traversal

This is a graph traversal framework for experimenting with graph traversal algorithms. At the moment it only represents directed non-weighted graphs. You can easily represent non-directed graphs by doubling up the edges

The only 2 algorithms implemented are shortest path, and a cycle detector, more will come.

`loadGraph` (from **GraphLoader.h/cpp**) will load graphs of the form node definitions followed by edges, like this example:

    1
    2
    3
    4
    5
    
    1->2
    1->3
    2->3
    3->4
    4->5

Or you can construct a Graph by using `Graph::addNode` and `Graph::addEdge`.

Once constructed you can use `Graph::traverse` to traverse the graph. It takes something that it can use operator () passing a node and returning the id of the next node. `Graph::traverse` initially passes a node with id 0, and expects to receive the first node id in return. `Graph::traverse` stops when it gets a node id of -1.

The basic depth first search and breadth first search are implementing using `Traverse` (from **Traverse.h/cpp**) and are available in **DepthFirstSearch.h/cpp** and **BreadthFirstSearch.h/cpp**. As examples also included are the implementations of a shortest path finder and a cycle finder which use respectively breadth first search and depth first search.