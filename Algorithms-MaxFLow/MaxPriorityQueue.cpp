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
}
void MaxPriorityQueue::FixHeap(int currentNode)
{
	int max;
	int leftChild = getLeftChild(currentNode);
	int rightChild = getRightChild(currentNode);

	if ((leftChild < m_HeapSize) && m_MaxHeap[leftChild].m_Data > m_MaxHeap[currentNode].m_Data)
		max = leftChild;
	else
		max = currentNode;
	if ((rightChild < m_HeapSize) && m_MaxHeap[rightChild].m_Data > m_MaxHeap[max].m_Data)
		max = rightChild;

	if (max != currentNode)
	{
		Swap(currentNode, max);   // Swapping values if necessary and continues fixing the heap recursively
		FixHeap(max);
	}
}

void MaxPriorityQueue::Swap(int node1, int node2)
{
	Pair temp = m_MaxHeap[node1];
	m_MaxHeap[node1] = m_MaxHeap[node2];
	m_MaxHeap[node2] = temp;
}

MaxPriorityQueue::MaxPriorityQueue(Pair* heapArr, int m_HeapSize)
{
	this->m_HeapSize = m_MaxSize = m_HeapSize;
	m_MaxHeap = heapArr;

	

}

void MaxPriorityQueue::BuildHeap()
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

	while ((i > 0) && (m_MaxHeap[parent = getParent(i)].m_Data < pairToInsert.m_Data)) // Looking for the right place to insert the pair in the heap
	{
		// Saving unnecessary multiple calls to parent(i)
		m_MaxHeap[i] = m_MaxHeap[parent];
		i = parent;
	}

	m_MaxHeap[i] = pairToInsert;
}