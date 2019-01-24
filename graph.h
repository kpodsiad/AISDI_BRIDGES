//
// Created by kamil on 1/23/19.
//

#ifndef AISDI_BRIDGES_GRAPH_H
#define AISDI_BRIDGES_GRAPH_H

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>


class Graph
{
private:
	size_t numberOfVertexes = 0;
	size_t numberOfEdges = 0;
	std::vector< std::vector<size_t> > adjacencyList;

	bool DFS(size_t toSkip1, size_t toSkip2)
	{
		bool visited[numberOfVertexes];
		size_t visitedCount = 0;

		for(int a=0; a < numberOfVertexes; ++a)
			visited[a] = false;

		visited[toSkip1] = true;
		visited[toSkip2] = true;

		std::stack< size_t > vertexesStack;
		size_t currentVertex = 0;

		if(currentVertex == toSkip1)
			++currentVertex;
		if(currentVertex == toSkip2)
			++currentVertex;

		vertexesStack.push(currentVertex);

		while( !vertexesStack.empty() )
		{
			++visitedCount;
			size_t vertex = vertexesStack.top();
			vertexesStack.pop();
			if( !visited[vertex] )
			{
				visited[vertex] = true;
				for(auto v : adjacencyList[vertex])
					if( !visited[v] )
						vertexesStack.push(v);
			}
		}

		for (int i = 0; i < numberOfVertexes ; ++i)
		{
			if(!visited[i])
				return true;
		}
		return false;
	}

	void findBridges(std::vector<std::pair<size_t ,size_t >> &extensiveBridges)
	{
		bool visited[numberOfVertexes];
		size_t vertexToSkip1;
		size_t vertexToSkip2;

		for(int a=0; a < numberOfVertexes; ++a)
			visited[a] = false;

		for (size_t i = 0; i < numberOfVertexes; ++i)
		{
			vertexToSkip1 = i;
			for (unsigned long v : adjacencyList[i])
			{
				if(visited[v])
					continue;
				vertexToSkip2 = v;

				if(DFS(vertexToSkip1, vertexToSkip2))
					extensiveBridges.emplace_back(std::make_pair(vertexToSkip1, vertexToSkip2));
			}
			visited[i] = true;
		}
	}

public:
	void addEdge(size_t vertex1, size_t vertex2)
	{
		if(vertex1 == vertex2)
			throw std::logic_error("Given vertexes must be different");

		if(std::find(adjacencyList[vertex1].begin(), adjacencyList[vertex1].end(), vertex2) != adjacencyList[vertex1].end())
		{
			throw std::logic_error("Can't add edge because it has been already added");
		}
		adjacencyList[vertex1].emplace_back(vertex2);
		adjacencyList[vertex2].emplace_back(vertex1);
		++numberOfEdges;
	}

	void setNumberOfVertexes(size_t numberOfVertexes)
	{
		this->numberOfVertexes = numberOfVertexes;
		adjacencyList.resize(numberOfVertexes);;
	}

	void printExtensiveBridges(std::ostream &os)
	{
		std::vector< std::pair<size_t ,size_t >> extensiveBridges;
		findBridges(extensiveBridges);
		for(auto elem : extensiveBridges)
			os<<"("<<elem.first<<", "<<elem.second<<")"<<std::endl;
	}

	void printEdges()
	{
		for(int i = 0; i<adjacencyList.size(); ++i)
		{
			std::cout<<i<<" : ";
			for(auto vertex : adjacencyList[i])
			{
				std::cout<<vertex<<"| ";
			}
			std::cout<<"\n";
		}
	}
};

#endif //AISDI_BRIDGES_GRAPH_H
