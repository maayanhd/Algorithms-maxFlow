#ifndef __MAXPRIORITYQUEUE_H
#define __MAXPRIORITYQUEUE_H

#include "Pair.h"
#include <iostream>
#include <stdio.h>

using namespace std;

class MaxPriorityQueue
{
     private:

	     Pair* m_MaxHeap;
		 int* m_IdxArr; // Array that stores vertexes placements in the heap
		 bool* m_VisitedArr;
	     int m_HeapSize;	// Current Size
	     int m_MaxSize;	// Maximal size of the heap
		 
          // Service functions 
	     static int getLeftChild(int node);  // Returns the index of the left child or -1 if doesn't exist
	     static int getRightChild(int node); // Returns the index of the right child or -1 if doesn't exist
	     static int getParent(int node); // Returns the parent of the node or -1 in case it is a root
	     void FixHeap(int node);
     public:
		 void MarkVertexAsVisited(int v);
		 bool IsHigherPriority(int node1, int node2);
		 inline bool IsEmpty() const { return m_HeapSize == 0; };
		 const int UNDEFINED = -1;
		 int GetVertexIdxInHeap(int v);
		 void IncreaseKey(int place, int newKey);
	     void BuildHeap();
		 MaxPriorityQueue(int* heapArr, bool* visitedArr, int heapSize);
	     ~MaxPriorityQueue();
	     void Swap(int node1, int node2);
	     Pair DeleteMax();
	     Pair Max(); // returns the pair with the maximal key
	     void Insert(Pair pairToInsert);
};

#endif
