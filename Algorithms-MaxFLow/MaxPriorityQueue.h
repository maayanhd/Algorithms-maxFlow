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
	     int m_HeapSize;	// Current Size
	     int m_MaxSize;	// Maximal size of the heap

	     static int getLeftChild(int node);  // Returns the index of the left child or -1 if doesn't exist
	     static int getRightChild(int node); // Returns the index of the right child or -1 if doesn't exist
	     static int getParent(int node); // Returns the parent of the node or -1 in case it is a root
	     void FixHeap(int node);

     public:
	     void BuildHeap();
	     MaxPriorityQueue(Pair* arr, int n); // Default constructor - not allocated
	     ~MaxPriorityQueue();
	     void Swap(int node, int max);
	     Pair DeleteMax();
	     Pair Max(); // returns the pair with the maximal key
	     void Insert(Pair pairToInsert);

};

#endif
