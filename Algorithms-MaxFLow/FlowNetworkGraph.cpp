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
void FlowNetworkGraph::FordFulkeronsUsingGreedyAlgorithm() {
     // Creating Residual Graph 
     WeightedDirectedGraph residualGraph((WeightedDirectedGraph)(*this));
     int numOfItr = 0;
     // Creating a parent array to hold the path from s to t
     int* parentArr = nullptr, *residualCapacityArr = nullptr;
     bool* visitedArr = new bool[m_NumOfVertexes + 1];

     // Checking whether there's a path from s to t in the residual graph, meaning theres augmenting path 
     //while (residualGraph.IsthereAPathUsingDijkstra(m_S, m_T, &parentArr, &residualCapacityArr, visitedArr))
     //{
     //     int residualCapacityOfPath = GetResidualCapacityOfPath(residualGraph, parentArr);
     //     // Augmenting flow along the path from s to t - updating flow mat and residual graph
     //     UpdateResidualGraphAndFlow(parentArr, residualCapacityOfPath, residualGraph);
     //     numOfItr++;

     //     //delete[] parentArr;
     //     //delete[] residualCapacityArr;
     //}

     PrintFulkersonUsingDijkstraOutput(visitedArr, numOfItr);
     delete[] visitedArr;
}

void FlowNetworkGraph::PrintFulkersonUsingDijkstraOutput(bool* visitedArr, int numOfItr)
{
     cout << "Dijkstra Method:" << endl;
     cout << "Max flow = " << m_MaxFlow << endl;
     PrintMinCutUsingDijkstra(visitedArr);
     cout << "Number of iterations = " << numOfItr << endl;
}
void FlowNetworkGraph::MakeEmptyFlow()
{
     m_CurrentFlowMatrix = new int*[m_NumOfVertexes + 1];

     for (int i = 0; i <= m_NumOfVertexes; i++)
     {
          m_CurrentFlowMatrix[i] = new int[m_NumOfVertexes + 1];
          for (int j = 0; j <= m_NumOfVertexes; j++)
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
     int numOfItr = 0;
     // Creating a parent array to hold the path from s to t
     int* parentArr = new int[m_NumOfVertexes + 1]();
     bool* visitedArr = new bool[m_NumOfVertexes + 1]();

     // Checking whether there's a path from s to t in the residual graph, meaning theres augmenting path 
     while (residualGraph.IsThereAPathUsingBFS(m_S, m_T, parentArr, visitedArr))
     {
          int residualCapacityOfPath = GetResidualCapacityOfPath(residualGraph, parentArr);

          // Augmenting flow along the path from s to t - updating flow mat and residual graph
          UpdateResidualGraphAndFlow(parentArr, residualCapacityOfPath, residualGraph);
          numOfItr++;
     }

     PrintFulkersonUsingBfsOutput(visitedArr, numOfItr);
     delete[] visitedArr;
     delete[] parentArr;
}

void FlowNetworkGraph::PrintFulkersonUsingBfsOutput(bool* visitedArr, int numOfItr)
{
     cout << "BFS Method:" << endl;
     cout << "Max flow = " << m_MaxFlow << endl;
     PrintMinCut(visitedArr);
     cout << "Number of iterations = " << numOfItr << endl;
}
void FlowNetworkGraph::PrintMinCutUsingDijkstra(bool *visitedArr)
{
     PrintMinCut(visitedArr);
}
void FlowNetworkGraph::PrintMinCut(bool* visitedArr)
{
     cout << "Min cut: ";
     PrintVertexesByBoolean(visitedArr, "S", true);
     PrintVertexesByBoolean(visitedArr, "T", false);
     cout << endl;
}

void FlowNetworkGraph::PrintVertexesByBoolean(bool* visitedArr, string vertexNameStr, bool areVertexesAccesibleFromS)
{
     cout << vertexNameStr << " = ";

     for (int i = 1; i <= m_NumOfVertexes; i++)
     {
          if (visitedArr[i] == areVertexesAccesibleFromS)
          {
               cout << i << ",";
          }
     }

     cout << "\b.";
}

void FlowNetworkGraph::UpdateResidualGraphAndFlow(int* parentArrPath, int residualCapacityOfPath, WeightedDirectedGraph& residualGraph)
{

     for (int v = m_T; v != m_S; v = parentArrPath[v])
     {
          // Updating Flow 
          int currentParent = parentArrPath[v];
          UpdateFlow(currentParent, v, residualCapacityOfPath);

          // Updating flow of Anti-parallel edge 

          UpdateFlow(v, currentParent, -residualCapacityOfPath);

          // Updating residual graph for each edge along the path
          residualGraph.UpdateCapacity(currentParent, v, GetResidualFlow(currentParent, v));

          // Updating the Anti-parallel edge capacity
          residualGraph.UpdateCapacity(v, currentParent, GetResidualFlow(v, currentParent));
     }

     // Updating max flow 
     m_MaxFlow += residualCapacityOfPath;
}

int FlowNetworkGraph::GetResidualCapacityOfPath(const WeightedDirectedGraph& residualGraph, int* parentArrPath)
{
     // Design by contract- at this point we know there's a path from s to t
     // Finding the minimal residual capacity of all edges in the path from s to t
     int currentParent = parentArrPath[m_T];
     int**  residualAdjMatrix = residualGraph.GetAdjacentMatrix();
     int minEdgeResidualCapacity = residualAdjMatrix[currentParent][m_T];

     for (int v = currentParent; v != m_S; v = parentArrPath[v])
     {
          currentParent = parentArrPath[v];
          // Updating minimum if needed
          if (residualAdjMatrix[currentParent][v] < minEdgeResidualCapacity)
          {
               minEdgeResidualCapacity = residualAdjMatrix[currentParent][v];
          }
     }

     return minEdgeResidualCapacity;
}

bool FlowNetworkGraph::IsFlowToAddIsValid(int u, int v, int flowToAdd)
{
     return flowToAdd <= GetResidualFlow(u, v);
}

int FlowNetworkGraph::GetResidualFlow(int u, int v)
{
     return m_AdjacentMatrix[u][v] - m_CurrentFlowMatrix[u][v];
}

void FlowNetworkGraph::UpdateFlow(int u, int v, int flowToAdd)
{
     if (!IsVertexInRange(u) || !IsVertexInRange(v) || !IsFlowToAddIsValid(u, v, flowToAdd))
     {
          cout << "invalid input" << endl;
          exit(1);
     }

     m_CurrentFlowMatrix[u][v] += flowToAdd;
}