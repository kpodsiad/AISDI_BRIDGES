#include <iostream>

#include "graph.h"


using namespace std;

int main()
{

	Graph graph;
	size_t n, v1, v2;
//	cin>>n;
//
//
//	while( std::cin >> v1 >> v2 )
//	{
//		graph.addEdge(v1, v2);
//	}

	graph.setNumberOfVertexes(6);
	graph.addEdge(0 , 1);
	graph.addEdge(1 ,2 );
	graph.addEdge( 1,3 );
	graph.addEdge( 2,4 );
	graph.addEdge( 3, 4);
	graph.addEdge( 0,5);
	graph.addEdge( 3,5);
	graph.printExtensiveBridges(std::cout);


	graph.printEdges();

	return 0;
}