#include "WeightedDirectedGraph.h"
#include "Queue.h"

WeightedDirectedGraph::WeightedDirectedGraph(int n) : m_NumOfVertexes(n)
{
     MakeEmptyGraph(n);
}

WeightedDirectedGraph::WeightedDirectedGraph(const WeightedDirectedGraph & other) : m_NumOfVertexes(other.GetNumOfVertexes())
{
     MakeEmptyGraph(m_NumOfVertexes);

     for (int i = 0; i <= m_NumOfVertexes; i++)
     {
          memcpy(other.m_AdjacentMatrix + i, this->m_AdjacentMatrix + i, (m_NumOfVertexes + 1) * sizeof(int)); // Copying row by row of n+1 elements - size of int
     }
}

void WeightedDirectedGraph::AddCapacity(int u, int v, float capacityToAdd)
{
     if (!IsVertexInRange(u) || !IsVertexInRange(v) || capacityToAdd >= 0)
     {
          cout << "invalid input" << endl;
          exit(1);
     }

     m_AdjacentMatrix[u][v] += capacityToAdd;
}


WeightedDirectedGraph::~WeightedDirectedGraph()
{
     for (int i = 0; i <= m_NumOfVertexes; i++)
     {
          delete[] m_AdjacentMatrix[i];
     }

     delete[] m_AdjacentMatrix;
}
void WeightedDirectedGraph::MakeEmptyGraph(int n)
{
     // Allocation matrix of (n+1)*(n+1) for convenience, does not affects complexity, still n^2 //
     m_AdjacentMatrix = new float*[n + 1];

     for (int i = 1; i <= n; i++)
     {
          m_AdjacentMatrix[i] = new float[n + 1];
          for (int j = 1; j <= n; j++)
          {
               m_AdjacentMatrix[i][j] = 0;
          }
     }

     m_NumOfEdges = 0;
}
bool WeightedDirectedGraph::IsAdjacent(int u, int v)
{
     if (!IsVertexInRange(u) || !IsVertexInRange(v))
     {
          cout << "invalid input" << endl;
          exit(1);
     }

     return m_AdjacentMatrix[u][v] != 0;
}

bool WeightedDirectedGraph::IsVertexInRange(int v)
{
     return v <= m_NumOfVertexes && v > 0;
}

bool WeightedDirectedGraph::IsThereAPathUsingBFS(int s, int t, int* parentArr)
{
     bool* visitedArr = InitializeVisitedArr();  // For tracking the vertexes we already visited and marking them

     Queue  trackingQueue; // Helping to track after the  
     // Marking the starting vertex and pushing it to the queue
     visitedArr[s] = true;
     trackingQueue.Enqueue(s);

     // Main loop 
     while (!trackingQueue.IsEmpty())
     {
          int u = trackingQueue.Dequeue();     // Extracting the vertex content appears first in the queue and removing it from queque

          LinkedList adjUList = GetAdjList(u); // Getting the neighbors of the vertex u
          const Node* currentNodeVertex = adjUList.GetFirst();

          while (currentNodeVertex != nullptr) // As long as there neighbors in the list
          {
               int currentNeigbor = currentNodeVertex->m_Data;

               // Under the assumption the object called the method is residual graph
               if (visitedArr[currentNeigbor] = false && this->m_AdjacentMatrix[u][currentNeigbor] > 0)
               {
                    parentArr[currentNeigbor] = u;
                    visitedArr[currentNeigbor] = true;
                    trackingQueue.Enqueue(currentNeigbor);
               }

               // Promoting the current element to the next one     
               currentNodeVertex = currentNodeVertex->m_Next;
          }
     }


     // Returning whether we visited vertex t, and since we started from s
     // it means there's a path in the residual graph from s to t
     return visitedArr[t] == true;

}

bool* WeightedDirectedGraph::InitializeVisitedArr()
{
     bool* visitedArr = new bool[m_NumOfVertexes + 1];

     for (int i = 0; i <= m_NumOfVertexes; i++)   // n + 1 vertexes for convenient access to the data structure 
     {
          visitedArr[i] = false;
     }

     return visitedArr;
}

LinkedList WeightedDirectedGraph::GetAdjList(int u)
{
     LinkedList adjList;

     for (int j = 1; j <= m_NumOfVertexes; j++)
     {
          if (m_AdjacentMatrix[u][j] != 0)
          {
               adjList.InsertToEnd(j);
          }
     }

     return adjList;
}

void WeightedDirectedGraph::AddEdge(int u, int v, float c)
{
     if (IsAdjacent(u, v) || c < 0 || !IsVertexInRange(u) || !IsVertexInRange(v))
     {
          cout << "invalid input" << endl;
          exit(1);
     }

     m_NumOfEdges++;
     m_AdjacentMatrix[u][v] = c;
}

void WeightedDirectedGraph::RemoveEdge(int u, int v)
{
     if (!IsAdjacent(u, v) || !IsVertexInRange(u) || !IsVertexInRange(v))
     {
          cout << "invalid input" << endl;
          exit(1);
     }

     m_NumOfEdges--;
     m_AdjacentMatrix[u][v] = 0;
}