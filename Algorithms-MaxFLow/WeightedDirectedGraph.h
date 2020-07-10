#pragma once

#include "LinkedList.h"

class WeightedDirectedGraph
{
protected:

	float** m_AdjacentMatrix;
	const int m_NumOfVertexes;
	int m_NumOfEdges;

public:

	WeightedDirectedGraph(int n);
	virtual ~WeightedDirectedGraph();
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u,int v);
	LinkedList GetAdjList(int u);
	void AddEdge(int u, int v, float c);
	void RemoveEdge(int u, int v);
	bool IsVertexInRange(int v);
	bool FindPathUsingBFS(int s, int t, int* parentArr);
	bool* InitializeVisitedArr();
};