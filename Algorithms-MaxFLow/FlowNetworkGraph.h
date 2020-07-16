#ifndef __FLOWNETWORKGRAPH_H
#define __FLOWNETWORKGRAPH_H

#include "WeightedDirectedGraph.h"

class FlowNetworkGraph : public WeightedDirectedGraph
{
     private:
	     int** m_CurrentFlowMatrix;
	     int m_S, m_T;
	     int m_MaxFlow;

          //Service functions 
          int GetResidualCapacityOfPath(const WeightedDirectedGraph& residualGraph, int* parentArrPath);
          void UpdateResidualGraphAndFlow(int* parentArrPath, int residualCapacityOfPath, WeightedDirectedGraph& residualGraph);
          void PrintFulkersonUsingBfsOutput(bool* visitedArr, int numOfItr);
          void PrintFulkersonUsingDijkstraOutput(bool* visitedArr, int numOfItr);
          void PrintMinCutUsingDijkstra(bool* visitedArr);
          
     public:
         FlowNetworkGraph(int n,int s,int t);
	     virtual ~FlowNetworkGraph();
	     void MakeEmptyFlow();
	     void AddFlow(int u, int v, int flowToAdd);
	     bool IsFlowToAddIsValid(int u, int v, int flowToAdd);
	     inline int GetResidualFlow(int u, int v);
         void FordFulkersonUsingBfs(); // Updating MaxFlow
         void PrintVertexesByBoolean(bool* visitedArr, string vertexNameStr, bool areVertexesAccesibleFromS);
         void PrintMinCut(bool* visitedArr);
         void FordFulkeronsUsingDijkstra();
     
};

#endif
