#ifndef __MAXPRIORITY QUEUE_H
#define __MAXPRIORITY QUEUE_H

#include <iostream>
#include "Pair.h"

class MaxPriorityQueue
{
private:
	Pair* maxHeap;
	int heapSize;	// Current Size
	int maxSize;	// Maximal size of the heap

	static int Left(int node);  // Returns the index of the left child or -1 if doesn't exist
	static int Right(int node); // Returns the index of the right child or -1 if doesn't exist
	static int Parent(int node); // Returns the parent of the node or -1 in case it is a root
	void FixHeap(int node);

public:
	void BuildHeap();
	MaxPriorityQueue(Pair* arr, int n); // Default constructor - not allocated
	~MaxPriorityQueue();
	void Swap(int node, int max);
	Pair DeleteMax();
	Pair Max(); // returns the person with the minimal key
	void Insert(Pair pairToInsert);

};

#endif
