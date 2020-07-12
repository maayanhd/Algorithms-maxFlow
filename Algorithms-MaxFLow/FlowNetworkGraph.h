#pragma once

#include "WeightedDirectedGraph.h"

class FlowNetworkGraph : public WeightedDirectedGraph
{

     private:
	     float** m_CurrentFlowMatrix;
	     int m_S, m_T;
	     float m_MaxFlow;

          float GetResidualCapacityOfPath(int* parentArrPath);
          void UpdateResidualGraphAndFlow(int* parentArrPath, float residualCapacityOfPath, WeightedDirectedGraph& residualGraph);
		  void PrintFulkersonUsingBfsOutput(int* disjoinstSetsArr,int numOfItr);
     public:

	     FlowNetworkGraph(int n,int s,int t);
	     virtual ~FlowNetworkGraph();
	     void MakeEmptyFlow();
	     void AddFlow(int u, int v, float flowToAdd);
	     bool IsFlowToAddIsValid(int u, int v, float flowToAdd);
	     float GetResidualFlow(int u, int v);
         void FordFulkersonUsingBfs(); // Updating MaxFlow
		 void PrintConnectedComponent(int* disjointSetsArr, string repVertexNameStr, int repVertex);
		 void PrintMinCut(int* disjoinstSetsArr);
};

