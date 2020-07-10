#pragma once
#include "MaxPriorityQueue.h"


int MaxPriorityQueue::Left(int node)
{
	return (2 * node + 1);
}
int MaxPriorityQueue::Right(int node)
{
	return(2 * node + 2);
}
int MaxPriorityQueue::Parent(int node)
{
	return ((node - 1) / 2);
}

MaxPriorityQueue::~MaxPriorityQueue() {
}
void MaxPriorityQueue::FixHeap(int currentNode)
{
	int max;
	int leftChild = getLeftChild(currentNode);
	int rightChild = getRightChild(currentNode);

	if ((leftChild < heapSize) && maxHeap[leftChild].m_data > maxHeap[currentNode].m_data)
		max = leftChild;
	else
		max = currentNode;
	if ((rightChild < heapSize) && maxHeap[rightChild].m_data > maxHeap[max].m_data)
		max = rightChild;

	if (max != currentNode)
	{
		Swap(currentNode, max);   // Swapping values if necessary and continues fixing the heap recursively
		FixHeap(max);
	}
}

void MaxPriorityQueue::Swap(int node1, int node2)
{
	Pair temp = maxHeap[node1];
	maxHeap[node1] = maxHeap[node2];
	maxHeap[node2] = temp;
}

MaxPriorityQueue::MaxPriorityQueue(Pair* heapArr, int heapSize)
{
	this->heapSize = maxSize = heapSize;
	maxHeap = heapArr;

	

}

void MaxPriorityQueue::BuildHeap()
{
	for (int i = (heapSize / 2) - 1; i >= 0; --i)
		FixHeap(i);
}

Pair MaxPriorityQueue::DeleteMax()
{
	if (heapSize < 1)
	{
		cout << "Error: EMPTY HEAP\n";
		exit(1);
	}
	Person* min = minHeap[0];
	minHeap[0] = minHeap[--HeapSize];
	FixHeap(0, numComp);
	return min;
}
Person* MaxPriorityQueue::min()
{
	return minHeap[0];
}
void MaxPriorityQueue::Insert(Person* person, int& numComp)
{
	int parent;

	if (HeapSize == maxSize)
	{
		cout << "Error: HEAP FULL\n ";
		exit(1);
	}
	int i = HeapSize++;

	while (++numComp && (i > 0) && (minHeap[parent = Parent(i)]->getId() > person->getId())) // Looking for the right place to insert the person in the heap
	{
		// Saving unnecessary multiple calls to parent(i)
		minHeap[i] = minHeap[parent];
		i = parent;
	}
	minHeap[i] = person;
}