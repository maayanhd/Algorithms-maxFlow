#include "FlowNetworkGraph.h"

FlowNetworkGraph::FlowNetworkGraph(int n, int s, int t) : WeightedDirectedGraph(n)
{
	m_S = s;
	m_T = t;
	MakeEmptyFlow();
}
FlowNetworkGraph:: ~FlowNetworkGraph()
{
	for (int i = 0; i <= m_NumOfVertexes; i++)
	{
		delete[] m_CurrentFlowMatrix[i];
	}
	
	delete[] m_CurrentFlowMatrix;
}

void FlowNetworkGraph::MakeEmptyFlow()
{
	m_CurrentFlowMatrix = new float* [m_NumOfVertexes + 1];

	for (int i = 1; i <= m_NumOfVertexes; i++)
	{
		m_CurrentFlowMatrix[i] = new float[m_NumOfVertexes + 1];
		for (int j = 1; j <= m_NumOfVertexes; j++)
		{
			m_CurrentFlowMatrix[i][j] = 0;
		}
	}

	m_MaxFlow = 0;
}

bool FlowNetworkGraph::IsFlowToAddIsValid(int u, int v, float flowToAdd)
{
	return flowToAdd <= GetResidualFlow(u, v);
}

float FlowNetworkGraph::GetResidualFlow(int u, int v)
{
	return m_AdjacentMatrix[u][v] - m_CurrentFlowMatrix[u][v];
}
void FlowNetworkGraph::AddFlow(int u, int v, float flowToAdd)
{
	if (!IsVertexInRange(u) || !IsVertexInRange(v) || !IsFlowToAddIsValid(u,v,flowToAdd))
	{
		cout << "invalid input" << endl;
		exit(1);
	}

	m_CurrentFlowMatrix[u][v] += flowToAdd;
}