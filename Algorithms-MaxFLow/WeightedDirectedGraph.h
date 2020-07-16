#ifndef WEIGHTEDDIRECTEDGRAPH_H
#define WEIGHTEDDIRECTEDGRAPH_H


#include "LinkedList.h"
#include "MaxPriorityQueue.h"

class WeightedDirectedGraph
{
     protected:

          int** m_AdjacentMatrix;
          const int m_NumOfVertexes;
          int m_NumOfEdges;

          // Service validation functions
          bool isCapacityValid(int capacity);
          bool isEdgeALoop(int u, int v);
          void InitalizeSingleSource(int s, int** parentArr, int** residualCapacityArr, bool** visitedArr);
          void Relax(int u, int v, int* parentArr, int* residualCapacityArr, bool* visitedArr, MaxPriorityQueue& maxQueue);
          void InitializeVisitedArr(bool* visitedArr);

     public:
          
          WeightedDirectedGraph(int n); //Default c'tor
          WeightedDirectedGraph(const WeightedDirectedGraph & other); // copy c'tor
          virtual ~WeightedDirectedGraph();
          void MakeEmptyGraph(int n);
          bool IsAdjacent(int u, int v);
          LinkedList* GetAdjList(int u);
          void AddEdge(int u, int v, int c);
          void RemoveEdge(int u, int v);
          bool IsVertexInRange(int v) const;
          bool IsThereAPathUsingBFS(int s, int t, int* parentArr, bool* visitedArr);
          bool IsthereAPathUsingGreedyMethod(int s, int t, int** parentArr, int** residualCapacityArr, bool** visitedArr);
          void UpdateCapacity(int u, int v, int capacityToAdd);
          int GetCapacity(int u, int v) const;
          inline int GetNumOfVertexes() const
          {
               return m_NumOfVertexes;
          }
          inline int** GetAdjacentMatrix()const
          {
               return m_AdjacentMatrix;
          }
};

#endif