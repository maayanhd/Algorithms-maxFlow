#ifndef __QUEUE_H
#define __QUEUE_H

#include "Node.h"
#include "Pair.h"

class Queue
{
private:

	Node* m_Front;
	Node* m_Rear;

	void NotifyEmptyQueueError();

public:

	Queue();
	~Queue();
	void MakeEmpty();
	bool IsEmpty();
	int Dequeue();
	void Enqueue(int dataToInsert);
	int Front();
	void ClearQueue();
};

#endif