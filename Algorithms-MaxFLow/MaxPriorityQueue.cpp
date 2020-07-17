#include "MaxPriorityQueue.h"

int MaxPriorityQueue::getLeftChild(int node)
{
	return (2 * node + 1);
}

int MaxPriorityQueue::getRightChild(int node)
{
	return(2 * node + 2);
}

int MaxPriorityQueue::getParent(int node)
{
	return ((node - 1) / 2);
}

MaxPriorityQueue::~MaxPriorityQueue() 
{
	delete[] m_MaxHeap;
	delete[] m_IdxArr;
}

void MaxPriorityQueue::FixHeap(int currentNode)
{
	int max;
	int leftChild = getLeftChild(currentNode);
	int rightChild = getRightChild(currentNode);
	if ((leftChild < m_HeapSize) && IsHigherPriority(leftChild, currentNode))
	{
		max = leftChild;
	}	
	else
	{
		max = currentNode;
	}
	if ((rightChild < m_HeapSize) && IsHigherPriority(rightChild, max))
	{
		max = rightChild;
	}
		

	if (max != currentNode)
	{
		Swap(currentNode, max);   // Swapping values if necessary and continues fixing the heap recursively
		FixHeap(max);
	}
}

void MaxPriorityQueue::Swap(int node1, int node2)
{
	Pair temp = m_MaxHeap[node1];
	int vertex1 = m_MaxHeap[node1].m_Data;
	int vertex2 = m_MaxHeap[node2].m_Data;

	m_IdxArr[vertex1] = node2;
	m_IdxArr[vertex2] = node1;

	m_MaxHeap[node1] = m_MaxHeap[node2];
	m_MaxHeap[node2] = temp;

}

MaxPriorityQueue::MaxPriorityQueue(int* heapArr,bool* visitedArr, int heapSize)
{
	this->m_HeapSize = m_MaxSize = heapSize;
	this->m_IdxArr = new int[heapSize + 1];
	this->m_VisitedArr = visitedArr;

	m_MaxHeap = new Pair[heapSize];
	for (int i = 0; i < m_HeapSize; i++)
	{
		m_MaxHeap[i].m_Data = i + 1;
		m_MaxHeap[i].m_Key = heapArr[i + 1];
		m_IdxArr[i + 1] = i;
	}
    Build();
}

bool MaxPriorityQueue::IsHigherPriority(int node1, int node2)
{
	bool res = false;
	bool isVisited = m_VisitedArr[m_MaxHeap[node2].m_Data];
	int vertex1 = m_MaxHeap[node1].m_Data;
	int vertex2 = m_MaxHeap[node2].m_Data;

	if (m_VisitedArr[vertex1] == false && m_VisitedArr[vertex2] == false)
	{
	}
	else if (m_VisitedArr[vertex1] == false)
	{
		res = false;
	}
	else if (m_VisitedArr[vertex2] == false)
	{
		res = true;
	}
	else
	{
		res = m_MaxHeap[node1].m_Key > m_MaxHeap[node2].m_Key;
	}

	return res;
}

void MaxPriorityQueue::Build()
{
	for (int i = (m_HeapSize / 2) - 1; i >= 0; --i)
		FixHeap(i);
}

Pair MaxPriorityQueue::DeleteMax()
{
	if (m_HeapSize < 1)
	{
		cout << "Error: EMPTY HEAP\n";
		exit(1);
	}
	Pair max = m_MaxHeap[0];
	int vertex = m_MaxHeap[m_HeapSize - 1].m_Data;
	m_IdxArr[max.m_Data] = UNDEFINED;
	m_IdxArr[vertex] = 0;
	m_MaxHeap[0] = m_MaxHeap[--m_HeapSize];
	FixHeap(0);
	
	return max;
}

Pair MaxPriorityQueue::Max()
{
	return m_MaxHeap[0];
}

void MaxPriorityQueue::Insert(Pair pairToInsert)
{
	int parent;

	if (m_HeapSize == m_MaxSize)
	{
		cout << "Error: HEAP FULL\n ";
		exit(1);
	}
	int i = m_HeapSize++;

	while ((i > 0) && (m_MaxHeap[parent = getParent(i)].m_Key < pairToInsert.m_Key)) // Looking for the right place to insert the pair in the heap
	{
		// Saving unnecessary multiple calls to parent(i)
		int parentVertex = m_MaxHeap[parent].m_Data;
		m_MaxHeap[i] = m_MaxHeap[parent];
		m_IdxArr[parentVertex] = i;
		i = parent;
	}
	m_IdxArr[pairToInsert.m_Data];
	m_MaxHeap[i] = pairToInsert;
}
int MaxPriorityQueue::GetVertexIdxInHeap(int v)
{
	return m_IdxArr[v];
}
void MaxPriorityQueue::IncreaseKey(int place, int newKey)
{
	m_MaxHeap[place].m_Key = newKey;
	int i = place;
	int parentIdx = 0;
	while (IsHigherPriority(i, parentIdx = getParent(i)) && i!=0)
	{
		Swap(i, parentIdx);
		i = parentIdx;
	}
}