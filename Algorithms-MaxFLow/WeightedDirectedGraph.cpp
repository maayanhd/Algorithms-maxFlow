#include "WeightedDirectedGraph.h"

WeightedDirectedGraph::WeightedDirectedGraph(int n) : m_NumOfVertexes(n)
{
	MakeEmptyGraph(n);
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

bool WeightedDirectedGraph::FindPathUsingBFS(int s, int t, int* parentArr)
{
	bool* visitedArr = InitializeVisitedArr();
}

bool* WeightedDirectedGraph:: InitializeVisitedArr()
{
	bool* visitedArr = new bool[m_NumOfVertexes + 1];

	for (int i = 0; i <= m_NumOfVertexes; i++)
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
	if (IsAdjacent(u,v) || c < 0 || !IsVertexInRange(u) || !IsVertexInRange(v) )
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