#include <iostream>

#include "graph.h"


using namespace std;

int main()
{

	Graph graph;
	size_t n, v1, v2;
	cin>>n;
	graph.setNumberOfVertexes(n);
	while( std::cin >> v1 >> v2 )
	{
		graph.addEdge(v1, v2);
	}

	graph.printExtensiveBridges(std::cout);
	graph.printEdges(std::cout);

	return 0;
}