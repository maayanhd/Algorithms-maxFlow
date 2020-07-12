#ifndef WEIGHTEDDIRECTEDGRAPH_H
#define WEIGHTEDDIRECTEDGRAPH_H


#include "LinkedList.h"

class WeightedDirectedGraph
{
protected:

	float** m_AdjacentMatrix;
	const int m_NumOfVertexes;
	int m_NumOfEdges;

public:
     
    WeightedDirectedGraph(int n); //Default c'tor
    WeightedDirectedGraph(const WeightedDirectedGraph & other); // copy c'tor
    virtual ~WeightedDirectedGraph();
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u,int v);
	LinkedList* GetAdjList(int u);
	void AddEdge(int u, int v, float c);
	void RemoveEdge(int u, int v);
	bool IsVertexInRange(int v) const;
	bool IsThereAPathUsingBFS(int s, int t, int* parentArr, bool* visitedArr);
	void InitializeVisitedArr(bool* visitedArr);
    void UpdateCapacity(int u, int v, float capacityToAdd);
     int GetNumOfVertexes() const
     {
          return m_NumOfVertexes;
     }
     float GetCapacity(int u, int v) const;
     float** GetAdjacentMatrix()const
     {
          return m_AdjacentMatrix;
     }
};

#endif