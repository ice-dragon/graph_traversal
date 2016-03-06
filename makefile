CC = clang++
CFLAGS  = -g -Wall -std=c++1y

default: graph_test

graph_test: testing.o BreadthFirstSearch.o DepthFirstSearch.o Graph.o Traversal.o GraphLoader.o ShortestPathFinder.o
	$(CC) $(CFLAGS) -o graph_test BreadthFirstSearch.o DepthFirstSearch.o Graph.o testing.o Traversal.o GraphLoader.o ShortestPathFinder.o

testing.o: testing.cpp BreadthFirstSearch.o DepthFirstSearch.o Graph.o
	$(CC) $(CFLAGS) -c testing.cpp

BreadthFirstSearch.o:  BreadthFirstSearch.cpp BreadthFirstSearch.h GraphNode.h Traversal.o
	$(CC) $(CFLAGS) -c BreadthFirstSearch.cpp

DepthFirstSearch.o:  DepthFirstSearch.cpp DepthFirstSearch.h GraphNode.h Traversal.o
	$(CC) $(CFLAGS) -c DepthFirstSearch.cpp

Traversal.o: Traversal.cpp Traversal.h GraphNode.h
	$(CC) $(CFLAGS) -c Traversal.cpp

ShortestPathFinder.o: BreadthFirstSearch.o ShortestPathFinder.h ShortestPathFinder.cpp
	$(CC) $(CFLAGS) -c ShortestPathFinder.cpp	

GraphLoader.o: GraphLoader.cpp GraphLoader.h Graph.o GraphNode.h
	$(CC) $(CFLAGS) -c GraphLoader.cpp	

Graph.o:  Graph.cpp Graph.h GraphNode.h
	$(CC) $(CFLAGS) -c Graph.cpp

clean: 
	$(RM) graph_test *.o *~