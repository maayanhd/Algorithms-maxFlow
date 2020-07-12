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
     m_CurrentFlowMatrix = new float*[m_NumOfVertexes + 1];

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

void FlowNetworkGraph::FordFulkersonUsingBfs()
{
     // Creating Residual Graph 
     WeightedDirectedGraph residualGraph((WeightedDirectedGraph)(*this));

     // Creating a parent array to hold the path from s to t
     int* parentArr = new int[m_NumOfVertexes + 1];

     // Checking whether there's a path from s to t in the residual graph, meaning theres augmenting path 
     while (residualGraph.IsThereAPathUsingBFS(m_S, m_T, parentArr))
     {
          float residualCapacityOfPath = GetResidualCapacityOfPath(parentArr);

          // Augmenting flow along the path from s to t - updating flow mat and residual graph
          UpdateResidualGraphAndFlow(parentArr, residualCapacityOfPath, residualGraph);
     }

     delete[]parentArr;
}

void FlowNetworkGraph::UpdateResidualGraphAndFlow(int* parentArrPath, float residualCapacityOfPath, WeightedDirectedGraph& residualGraph)
{

     for (int v = m_T; v != m_S; v = parentArrPath[v])
     {
          // Updating Flow 
          int currentParent = parentArrPath[v];
          AddFlow(currentParent, v, residualCapacityOfPath);

          // Updating flow of Anti-parallel edge 
          AddFlow(v, currentParent, -m_CurrentFlowMatrix[currentParent][v]);

          // Updating residual graph for each edge along the path
          residualGraph.AddCapacity(currentParent, v, GetResidualFlow(currentParent, v));

          // Updating the Anti-parallel edge capacity
          residualGraph.AddCapacity(v, currentParent, GetResidualFlow(v, currentParent));
     }

     // Updating max flow 
     m_MaxFlow += residualCapacityOfPath;
}


float FlowNetworkGraph::GetResidualCapacityOfPath(int* parentArrPath)
{
     // Design by contract- at this point we know there's a path from s to t
     // Finding the minimal residual capacity of all edges in the path from s to t
     float minEdgeResidualCapacity = 0;

     for (int v = m_T; v != m_S; v = parentArrPath[v])
     {
          int currentParent = parentArrPath[v];
          // Updating minimum if needed
          if (m_AdjacentMatrix[currentParent][v] < minEdgeResidualCapacity)
          {
               minEdgeResidualCapacity = m_AdjacentMatrix[currentParent][v];
          }
     }

     return minEdgeResidualCapacity;
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
     if (!IsVertexInRange(u) || !IsVertexInRange(v) || !IsFlowToAddIsValid(u, v, flowToAdd))
     {
          cout << "invalid input" << endl;
          exit(1);
     }

     m_CurrentFlowMatrix[u][v] += flowToAdd;
}