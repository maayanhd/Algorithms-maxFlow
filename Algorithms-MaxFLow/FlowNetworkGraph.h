#pragma once

#include "WeightedDirectedGraph.h"
class FlowNetworkGraph : public WeightedDirectedGraph
{
private:

	float** m_CurrentFlowMatrix;
	int m_S, m_T;
	int m_MaxFlow;

public:

	FlowNetworkGraph(int n,int s,int t);
	virtual ~FlowNetworkGraph();
	void MakeEmptyFlow();
	void AddFlow(int u, int v, float flowToAdd);
	bool IsFlowToAddIsValid(int u, int v, float flowToAdd);
	float GetResidualFlow(int u, int v);
};

